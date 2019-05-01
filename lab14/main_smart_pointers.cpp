#include <iostream>
#include <cassert>
#include <string>
#include <set>

// simple homemade smart pointers
#include "ds_smart_pointers.h"


// ====================================================
// BALLOON: a toy class with dynamically allocated memory
// ====================================================

#define MAX_NUM_ROPES 10

class Balloon {
public:
  // CONSTRUCTOR & DESTRUCTOR
  Balloon(const std::string& name_) : name(name_) {
    std::cout << "Balloon constructor " << name << std::endl;
    num_ropes = 0;
    ropes = new Balloon*[MAX_NUM_ROPES];
  }
  ~Balloon() {
    std::cout << "Balloon destructor " << name << std::endl;
    // don't try to destroy attached balloons, just delete array
    delete [] ropes;
  }

  // ACCESSORS
  const std::string& getName() const { return name; }
  int numRopes() const { return num_ropes; }
  Balloon* getRope(int i) const { return ropes[i]; }

  // print the balloons we are attached to
  void print() {
    std::cout << "Balloon " << name << " is connected to: ";
    for (int i = 0; i < num_ropes; i++) {
      std::cout << ropes[i]->name << " ";
    }
    if (num_ropes == 0) std::cout << "nothing";
    std::cout << std::endl;
  }
  // add a rope connecting this balloon to another
  void addRope(Balloon* b) {
    assert (num_ropes < MAX_NUM_ROPES);
    ropes[num_ropes] = b;
    num_ropes++;
  }
  // detach a rope connecting this balloon to another
  void removeRope(Balloon* b) {
    for (int i = 0; i < MAX_NUM_ROPES; i++) {
      if (ropes[i] == b) { ropes[i] = ropes[num_ropes-1]; num_ropes--; break; }
    }
  }

private:
  std::string name;
  int num_ropes;
  // a dynamically allocated C-style array of ropes connecting to other Balloons
  Balloon** ropes;
};


void addAllRopes(Balloon* a, std::set<Balloon*>& balloons){
     for(int i = 0; i < a->numRopes(); i++){
          if( balloons.insert(a->getRope(i)).second==true ) {
               addAllRopes(*(balloons.insert(a->getRope(i)).first), balloons);
          }
          else{
               std::cout << "inserted";
          }
     }
}

void deleteAll(Balloon* a){
     std::set<Balloon*> balloons;
     addAllRopes(a, balloons); //recursive

     for(std::set<Balloon*>::iterator itr = balloons.begin(); itr != balloons.end(); ++itr){
          delete *itr;
          //std::cout << "deleted";
     }
}

class Balloon2 {
public:
  // CONSTRUCTOR & DESTRUCTOR
  Balloon2(const std::string& name_) : name(name_) {
    std::cout << "Balloon2 constructor " << name << std::endl;
    num_ropes = 0;
    ropes = new dsSharedPtr<Balloon2>[MAX_NUM_ROPES];
  }
  ~Balloon2() {
    std::cout << "Balloon2 destructor " << name << std::endl;
    // don't try to destroy attached balloons, just delete array
    delete [] ropes;
  }

  // ACCESSORS
  const std::string& getName() const { return name; }
  int numRopes() const { return num_ropes; }
  const dsSharedPtr<Balloon2> getRope(int i) const { return ropes[i]; }

  // print the balloons we are attached to
  void print() {
    std::cout << "Balloon2 " << name << " is connected to: ";
    for (int i = 0; i < num_ropes; i++) {
      std::cout << ropes[i]->name << " ";
    }
    if (num_ropes == 0) std::cout << "nothing";
    std::cout << std::endl;
  }
  // add a rope connecting this balloon to another
  void addRope(dsSharedPtr<Balloon2> b) {
    assert (num_ropes < MAX_NUM_ROPES);
    ropes[num_ropes] = b;
    num_ropes++;
  }
  // detach a rope connecting this balloon to another
  void removeRope(dsSharedPtr<Balloon2> b) {
    for (int i = 0; i < MAX_NUM_ROPES; i++) {
      if (ropes[i] == b) { ropes[i] = ropes[num_ropes-1]; num_ropes--; break; }
    }
  }

private:
  std::string name;
  int num_ropes;
  // a dynamically allocated C-style array of ropes connecting to other Balloons
  dsSharedPtr<Balloon2>* ropes;
};

// ====================================================
// ====================================================

int main() {

  std::cout << "start of main" << std::endl;

  // ====================================================
  // SINGLE OWNER SMART POINTERS
  // ====================================================

  // first, without smart pointers!
  Balloon* alice(new Balloon("Hello Kitty"));

  // now, with our homemade single owner smart pointer
  dsAutoPtr<Balloon> bob(new Balloon("Spiderman"));

  // both alice & bob work like regular pointers...
  alice->print();
  bob->print();



  //
  // CHECKPOINT 2A: INSERT NECESSARY EXPLICIT DEALLOCATION
  //

  delete alice;

  // ====================================================
  // SIMPLE SHARED POINTERS
  // ====================================================

  // first, without smart pointers
  Balloon* cathy(new Balloon("Buzz Lightyear"));
  Balloon* daniel(cathy);
  Balloon* elaine(new Balloon("Pokemon"));
  Balloon* fred(elaine);
  daniel = fred;
  fred = NULL;
  elaine = cathy;
  cathy = NULL;



  //
  // CHECKPOINT 2B: INSERT NECESSARY EXPLICIT DEALLOCATION
  //

   delete daniel;
   delete elaine;

  daniel = NULL;
  elaine = NULL;


  // now, with our homemade shared pointer
  dsSharedPtr<Balloon2> cathy2(new Balloon2("Buzz Lightyear2"));
  dsSharedPtr<Balloon2> daniel2(cathy2);
  dsSharedPtr<Balloon2> elaine2(new Balloon2("Pokemon2"));
  dsSharedPtr<Balloon2> fred2(elaine2);
  daniel2 = fred2;
  fred2 = NULL;
  elaine2 = cathy2;
  cathy2 = NULL;
   // NOTE:  no explicit destruction required!
  daniel2 = NULL;
  elaine2 = NULL;


  // ====================================================
  // SHARED POINTERS WITH INTERCONNECTED STRUCTURES
  // ====================================================

  dsSharedPtr<Balloon2> georgette(new Balloon2("Mr Potato Head"));
  dsSharedPtr<Balloon2> henry(new Balloon2("Snoopy"));

  georgette->addRope(henry);
  henry = new Balloon2("Tigger");
  georgette->addRope(henry);
  georgette->print();
  henry->print();

  dsSharedPtr<Balloon2> isabelle(new Balloon2("Shrek"));
  henry->addRope(isabelle);
  isabelle = new Balloon2("Barney the Purple Dinosaur");
  georgette->addRope(isabelle);

  henry->print();
  georgette->print();
  isabelle->print();


  //
  // CHECKPOINT 2C: REWRITE THE ABOVE EXAMPLE TO USE SHARED POINTERS
  //



  // ====================================================
  // CYCLIC STRUCTURES
  // ====================================================


  // FOR CHECKPOINT 3



  Balloon* jacob(new Balloon("Dora the Explorer"));
  Balloon* katherine(new Balloon("Kung Fu Panda"));
  Balloon* larry(new Balloon("Scooby Doo"));
  Balloon* miranda(new Balloon("SpongeBob SquarePants"));
  Balloon* nicole(new Balloon("Papa Smurf"));

  jacob->addRope(katherine);
  katherine->addRope(larry);
  larry->addRope(jacob);
  miranda->addRope(jacob);
  nicole->addRope(miranda);
  larry->addRope(nicole);

  katherine = NULL;
  larry = NULL;
  miranda = NULL;
  nicole = NULL;

  // jacob points to a cyclic structure!

  // to cleanup this structure:
  deleteAll(jacob);

  jacob = NULL;




  std::cout << "end of main" << std::endl;
  return 0;

  //
  // NOTE: when smart pointers go out of scope, the destructors for
  //       those objects will be called automatically
  //
}

// ====================================================
