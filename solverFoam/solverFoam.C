#include "combustionModel.H"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
using namespace Foam;

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("usage: %s <modelname> <library>\n", argv[0]);
        exit(1);
    }

    // Get the name of the model from the arguments passed to the
    // application. 
    const word modelName = argv[1];

    if(argc==2)
    {
        // RTS call. 
        autoPtr<combustionModelBase> modelPtr = combustionModelBase::New(modelName);

        // Get the reference to the algorithm from the smart pointer.
        combustionModelBase& model = modelPtr(); 

        // Call the modle correct function.
        model.correct();
    }
    else
    {
        char *librarypath = argv[2];

        void *libhandle = dlopen(librarypath, RTLD_LAZY);

        if(libhandle == NULL)
        {
            perror("dlopen");
        }
        // This blanck is important
        // Since we must destroy the combustionModelBase model object
        // before close the libhandle, e.g. call deconstructor to delete
        // WordConstructorTablePtr_
        {
            // RTS call. 
            autoPtr<combustionModelBase> modelPtr = combustionModelBase::New(modelName);

            // Get the reference to the algorithm from the smart pointer.
            combustionModelBase& model = modelPtr(); 

            // Call the algorithm.
            model.correct(); 
        }
        dlclose(libhandle);
    }

    Info<< "\nEnd\n" << endl;

    return 0;
}

// ************************************************************************* //
