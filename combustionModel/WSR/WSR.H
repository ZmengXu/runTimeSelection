#ifndef WSR_H
#define WSR_H

#include "combustionModel.H"

class WSR
:
    public combustionModelBase
{
    public: 

        // Declare the static variable typeName of the class WSR.
        //TypeName ("WSR");
        static const char* typeName_() { return "WSR"; }
        static const ::Foam::word typeName;
        static int debug;
        virtual const word& type() const { return typeName; }

        // Empty constructor. 
        WSR ()
        {
            Info << "Constructing " << typeName
            << " using Empty constructor." << endl;
        };

        // Word constructor.
        WSR (const word& modelName)
        {
            Info << "Constructing " << typeName
            << " using Word constructor." << endl;
        };

        // Destructor
        ~WSR(){};

        // Make the class callable (function object) 
        virtual void correct()
        {
            Info << "WSR::correct()" << endl;
        }
};
#endif
