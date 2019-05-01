#ifndef _SUPERHERO_H_
#define _SUPERHERO_H_

#include <string>
#include <iostream>


class Superhero {

public:
     friend class Team;

     Superhero(const std::string& n, const std::string& r, const std::string& p) :
          name(n), power(p), realIdentity(r), good(true) {}

     const std::string& getName() const { return name; }
     const std::string& getPower() const { return power; }
     bool isGood() const { return good; }

     bool operator==(const Superhero& s) const { return s.name == name && s.power == power && s.realIdentity == realIdentity && s.good == good; }

     bool operator==(const std::string& r) const { return r == realIdentity; }
     bool operator!=(const std::string& r) const { return r != realIdentity; }

     const Superhero& operator-(){ good = !good; return *this; }

     bool operator>(const Superhero& s) const;

private:
     //REPRESENATION
     std::string name;
     std::string power;
     std::string realIdentity;
     bool good;

     const std::string& getTrueIdentity() const { return realIdentity; }
};

std::ostream& operator<<(std::ostream& out, const Superhero& s);

#endif
