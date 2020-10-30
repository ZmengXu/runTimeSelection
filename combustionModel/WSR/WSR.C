#include "WSR.H"

//defineTypeNameAndDebug(WSR, 0);
const ::Foam::word WSR::typeName(WSR::typeName_());
int WSR::debug(::Foam::debug::debugSwitch(WSR::typeName_(), 0));

class addWSRToDebug                                                    
:                                                                          
    public ::Foam::simpleRegIOobject                                       
{                                                                          
public:                                                                    
    addWSRToDebug(const char* name)                                    
    :                                                                      
        ::Foam::simpleRegIOobject(Foam::debug::addDebugObject, name)       
    {}                                                                     
    virtual ~addWSRToDebug()                                           
    {}                                                                     
    virtual void readData(Foam::Istream& is)                               
    {                                                                      
        WSR::debug = readLabel(is);                                       
    }                                                                      
    virtual void writeData(Foam::Ostream& os) const                        
    {                                                                      
        os << WSR::debug;                                                 
    }                                                                      
};                                                                         
addWSRToDebug addWSRToDebug_(WSR::typeName_());




//addToRunTimeSelectionTable(combustionModelBase, WSR , Word);
WSR::addWordConstructorToTable< WSR > addWSRWordConstructorTocombustionModelBaseTable_;