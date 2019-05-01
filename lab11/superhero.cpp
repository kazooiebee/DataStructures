#include <cassert>
#include <iostream>
#include <string>
#include "superhero.h"

bool Superhero::operator>(const Superhero& s)const{
     if(power == "Fire" && s.power == "Wood") return true;
     if(power == "Wood" && s.power == "Water") return true;
     if(power == "Water" && s.power == "Fire") return true;
     return false;
}


std::ostream& operator<<(std::ostream& out, const Superhero& s){
     if(s.isGood()){
          out << "Superhero ";
     }
     else{
          out << "Supervillian ";
     }
     out << s.getName() << " has power " << s.getPower() << std::endl;
     return out;
}
