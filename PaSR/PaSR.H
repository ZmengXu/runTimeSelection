#ifndef PaSR_H
#define PaSR_H

#include "WSR.H"

using namespace Foam;

class PaSR
:
    public WSR 
{
    public: 

        // Declare the static variable typeName of the class PaSR.
        TypeName ("PaSR");

        // Empty constructor. 
        PaSR ()
        {
            Info << "Constructing " << typeName
            << " using Empty constructor." << endl;
        };
        // Word constructor.
        PaSR (const word& modelName)
        {
            Info << "Constructing " << typeName
            << " using Word constructor." << endl;
        };

        // Destructor
        ~PaSR(){};

        // Make the class callable (function object) 
        virtual void correct()
        {
            // Call base operator explicitly.
            WSR::correct();
            // Perform additional operations.
            Info << "PaSR::correct()" << endl;
        }
};

#endif

// ************************************************************************* //
