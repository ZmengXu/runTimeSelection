#include "combustionModel.H"

//defineTypeNameAndDebug(combustionModelBase, 0);
const ::Foam::word combustionModelBase::typeName(combustionModelBase::typeName_());
int combustionModelBase::debug(::Foam::debug::debugSwitch(combustionModelBase::typeName_(), 0));

class addcombustionModelBaseToDebug                                                    
:                                                                          
    public ::Foam::simpleRegIOobject                                       
{                                                                          
public:                                                                    
    addcombustionModelBaseToDebug(const char* name)                                    
    :                                                                      
        ::Foam::simpleRegIOobject(Foam::debug::addDebugObject, name)       
    {}                                                                     
    virtual ~addcombustionModelBaseToDebug()                                           
    {}                                                                     
    virtual void readData(Foam::Istream& is)                               
    {                                                                      
        combustionModelBase::debug = readLabel(is);                                       
    }                                                                      
    virtual void writeData(Foam::Ostream& os) const                        
    {                                                                      
        os << combustionModelBase::debug;                                                 
    }                                                                      
};                                                                         
addcombustionModelBaseToDebug addcombustionModelBaseToDebug_(combustionModelBase::typeName_());


//defineRunTimeSelectionTable(combustionModelBase, Word);
combustionModelBase::WordConstructorTable* combustionModelBase::WordConstructorTablePtr_ = __null;
    void combustionModelBase::constructWordConstructorTables() {
        static bool constructed = false;
        if (!constructed) {
            constructed = true;
            combustionModelBase::WordConstructorTablePtr_ = new combustionModelBase::WordConstructorTable;
        }
    };
    
    void combustionModelBase::destroyWordConstructorTables() {
        if (combustionModelBase::WordConstructorTablePtr_) {
            delete combustionModelBase::WordConstructorTablePtr_;
            combustionModelBase::WordConstructorTablePtr_ = __null;
        }
    };

//addToRunTimeSelectionTable(combustionModelBase, combustionModelBase, Word);
combustionModelBase::addWordConstructorToTable< combustionModelBase > addcombustionModelBaseWordConstructorTocombustionModelBaseTable_;
