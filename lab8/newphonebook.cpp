#include <iostream>
#include <map>
#include <string>

// add a number, name pair to the phonebook
void add(std::map<int, std::string> &phonebook, int number, std::string const& name) {
  phonebook[number] = name;
}

// given a phone number, determine who is calling
void identify(const std::map<int, std::string> & phonebook, int number) {
  if (phonebook.find(number) == phonebook.end())
    std::cout << "unknown caller!" << std::endl;
  else
    std::cout << phonebook.find(number)->second << " is calling!" << std::endl;
}


int main() {
  // create the phonebook; initially all numbers are unassigned
  std::map<int, std::string> phonebook;

  // add several names to the phonebook
  add(phonebook, 1111, "fred");
  add(phonebook, 2222, "sally");
  add(phonebook, 3333, "george");

  // test the phonebook
  identify(phonebook, 2222);
  identify(phonebook, 4444);
}
