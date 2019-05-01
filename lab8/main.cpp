#include <iostream>
#include <map>
#include <vector>
#include <fstream>

int main(int argc, char* argv[]){

     std::ifstream istr(argv[1]);
     if (!istr) {
       std::cerr << "Could not open " << argv[1] << std::endl;
       return 1;
     }

     int temp;
     std::map<int, int> nums;

     while(istr >> temp){
          // ++nums[temp];// FIRST LAB
          nums.insert(std::make_pair(temp, 0)).first->second++; //SECOND LAB
     }

     std::map<int, int>::const_iterator it;
     std::vector<int> modes;
     int max_val = -2147483646;

     for(it = nums.begin(); it != nums.end(); ++it){
          if(it->second > max_val){
               max_val = it->second;
               modes.clear();
               modes.push_back(it->first);
          }
          else if(it->second == max_val){
               modes.push_back(it->first);
          }
     }
     if(max_val == -2147483646){
          std::cout<< "No modes" << std::endl;
     }
     else{
          std::cout << "Modes occur: " << max_val << " times and are: ";
          for(int i = 0; i < modes.size(); i++){
               std::cout << modes[i] << " ";
          }
          std::cout << std::endl;
          return 0;
     }
}
