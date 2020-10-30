#ifndef combustionModel_H
#define combustionModel_H


#include "word.H"

using namespace Foam;

//#include "typeInfo.H"
//#include "runTimeSelectionTables.H"
#include "autoPtr.H"
#include "HashTable.H"

//#include "addToRunTimeSelectionTable.H"
// Main program:
class combustionModelBase
{
    public: 

        // Declare the static variable typeName of the class combustionModelBase.
//        TypeName ("base");
        static const char* typeName_() { return "base"; }
        static const ::Foam::word typeName;
        static int debug;
        virtual const word& type() const { return typeName; }


        // Empty constructor. 
        combustionModelBase () {};

        // Word constructor.
        combustionModelBase (const word& modelName) {};

        // Destructor: needs to be declared virtual since 
        virtual ~combustionModelBase() {};
/*
        // Macro for declaring stuff required for RTS 
        declareRunTimeSelectionTable
        (
            autoPtr, 
            combustionModelBase, 
            Word, 
            (
                const word& modelName
            ),
            (modelName)
        )
*/
        typedef autoPtr< combustionModelBase > (*WordConstructorPtr)( const word& modelName );
           
        typedef HashTable< WordConstructorPtr, word, string::hash > WordConstructorTable;
        static WordConstructorTable* WordConstructorTablePtr_;
        static void constructWordConstructorTables();
        static void destroyWordConstructorTables();
        template< class combustionModelBaseType >
        class addWordConstructorToTable
        {
            public:
            static autoPtr< combustionModelBase > New ( const word& modelName )
            {
                return autoPtr< combustionModelBase >(new combustionModelBaseType (modelName));
            }
            addWordConstructorToTable ( const word& lookup = combustionModelBaseType::typeName )
            {
                constructWordConstructorTables();
                if (!WordConstructorTablePtr_->insert(lookup, New))
                {
                    std::cerr<< "Duplicate entry "
                        << lookup << " in runtime selection table "
                        << "combustionModelBase" << std::endl;
                    error::safePrintStack(std::cerr);
                }
            }
            
            ~addWordConstructorToTable()
            {
                destroyWordConstructorTables();
            }
        };
        template< class combustionModelBaseType >
        class addRemovableWordConstructorToTable
        {
            const word& lookup_;
            
            public:
            static autoPtr< combustionModelBase > New ( const word& modelName )
            {
                return autoPtr< combustionModelBase >(new combustionModelBaseType (modelName));
            }
            addRemovableWordConstructorToTable ( const word& lookup = combustionModelBaseType::typeName )
            : lookup_(lookup)
            {
                constructWordConstructorTables();
                WordConstructorTablePtr_->set(lookup, New);
            }
           
            ~addRemovableWordConstructorToTable()
            {
                if (WordConstructorTablePtr_)
                {
                    WordConstructorTablePtr_->erase(lookup_);
                }
            }
        };

        // static Factory Method (selector)
        static Foam::autoPtr<combustionModelBase> New (const word& modelName);

        // Make the class callable (function object) 
        virtual void correct() 
        {
            // Overridable default implementation
            Info << "combustionModelBase::correct()" << endl;
        }
};

#endif

// ************************************************************************* //
