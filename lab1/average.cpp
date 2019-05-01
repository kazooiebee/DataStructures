#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>

int main(){

     int count;
     std::cout << "Enter the number of numbers you want to enter: ";
     std::cin >> count;

     float nums[100];
     float sum = 0.0;
     for (int i = 0; i < count; i = i +1){
          std::cin >> nums[i];
          sum = sum + nums[i];
     }

     float average = sum/float(count);
     std::cout << "The average is " << average << std::endl;
     std::cout << "The numbers that are less than the average are " << std::endl;
     for (int i = 0; i < count; i = i + 1){
          if(nums[i]<average){
               std::cout << nums[i] << std::endl;
          }
     }
}
