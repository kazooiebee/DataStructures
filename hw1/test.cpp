#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

/**
int main(){
     std::ifstream istr("simple_font.txt");
     if(!istr){
          std::cerr << "ERROR: cannot open font file " << "simple_font.txt" << std::endl;
          return 1;
     }

     std::string output;
     while(istr >> output)
     {
          std::cout << output << std::endl;
     }


     return 0;
}
*/
int main(){
     int ascii_num = 78;
     std::ifstream istr("simple_font.txt");
     if(!istr){
          std::cerr << "ERROR: cannot open font file " << "simple_font.txt" << std::endl;
          return false;
     }

     std::string junk;
     istr >> junk;
     istr >> junk;

     int curr_ascii = -1;

     while (curr_ascii != ascii_num){
          istr >> curr_ascii;
          std::cout << curr_ascii << std::endl;
          for(int i = 0; i < 8; i = i + 1){
               istr >> junk;
          }
     }

     return true;
}
