#include <iostream>
 
// unscoped enumeration
enum ITEMTYPE : short
{
    WEAPON,
    EQUIPMENT,
    GEM                          = 10,
    DEFENSE,
};
 
// scoped enumeration
enum class CHARACTER_CLASS : short
{
    WARRIOR                    = 1,     
    MONK,
    FIGHTER,
};
 
enum struct BATTLE_TYPE : short
{
    DEATH_MATCH              = 1,     
    TEAM,
};
 

int main()
{
    // unscoped enumeration
    std::cout << "ITEM WEAPON의 Type 번호 : " << ITEMTYPE::WEAPON << std::endl;
 
    short ItemType = EQUIPMENT;
    std::cout << "ITEM EQUIPMENT의 Type 번호 : " << ItemType << std::endl;
 
 
 
    /// scoped enumerations
    short CharClassType3 = (short)CHARACTER_CLASS::FIGHTER;
 
    CHARACTER_CLASS CharClass = CHARACTER_CLASS::WARRIOR;
          
    //short   CharClassType    = FIGHTER;                                  // 에러                                            
 
    //short   CharClassType2   = CHARACTER_CLASS::FIGHTER; // 에러
          
    //CHARACTER_CLASS       CharClass2    = WARRIOR;            // 에러
                            
    return 0;
}
