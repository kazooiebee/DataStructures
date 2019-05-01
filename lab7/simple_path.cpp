#include <iostream>

int num_paths(int x, int y){
     if(x == 0 || y == 0){
          return 1;
     }
     return num_paths(x-1, y) + num_paths(x, y-1);
}

int main(){

     std::cout << "0,0 has: " << num_paths(0,0) << std::endl;
     std::cout << "3,0 has: " << num_paths(3,0) << std::endl;
     std::cout << "0,4 has: " << num_paths(0,4) << std::endl;
     std::cout << "2,3 has: " << num_paths(2,3) << std::endl;
     std::cout << "1,1 has: " << num_paths(1,1) << std::endl;
     std::cout << "1,2 has: " << num_paths(1,2) << std::endl;
     std::cout << "2,2 has: " << num_paths(2,2) << std::endl;

     return 0;
}
