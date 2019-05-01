#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cassert>

//==============================================


void letter_converter(std::string & msg, char orig_char, char new_char){
     for(unsigned int i = 0; i < msg.size(); i = i + 1){
          if(char(msg[i]) == orig_char){
               msg[i] = new_char;
          }
     }
}

bool readLetter(int ascii_num, std::vector<std::string> &output_lines){
     //SETS UP THE STREAM
     std::ifstream istr("simple_font.txt");
     if(!istr){
          std::cerr << "ERROR: cannot open font file " << "simple_font.txt" << std::endl;
          return false;
     }

     std::string junk;
     istr >> junk;
     istr >> junk;//skips forward the reading to the correct starting place (or i could modify the text file to get rid of the 6 and 7)

     //gets to the correct place in the reading, the number before the character and bitmap
     int curr_ascii = -1;

     istr >> curr_ascii;
     while (curr_ascii != ascii_num) {
          if(curr_ascii == 32)istr >> junk;
          for(int i = 0; i < 8; i = i + 1){
               istr >> junk;
          }

          istr >> curr_ascii;
     }

     istr >> junk;//skips forward 1 so the next 7 reads are the 7 lines of big font
     if(curr_ascii == 32)istr >> junk;

     for (int i = 0; i < 7; i = i + 1){
          istr>>junk;
          output_lines[i] = output_lines[i]+junk+".";
     }

     return true;
}

//main method to take inputs
int main(int argc, char* argv[]){//sets up the arguments for the main method
     if(std::string(argv[1])==std::string("display")){//regular credit section
          //check for the correct arguments
          if(argc!=6){
               std::cerr << "ERROR: Must have 5 arguments" <<std::endl;
               return 1;
          }

          if(std::string(argv[2]).substr(std::string(argv[2]).size()-4) != ".txt"){
               std::cerr << "ERROR: not a valid text file \nplease enter a .txt filename\n"<<std::endl;
               return 1;
          }//checks for file name to be an actual text file

          if(std::string(argv[4]).size()!=1||std::string(argv[5]).size()!=1){
               std::cerr << "ERROR: arg 4 and 5 mush be chars\n";
               return 1;
          }
          char foreground = argv[4][0];
          char background = argv[5][0];
          std::string message = argv[3];
          std::string textfile = argv[2];
          //actual problem solving starting here

          std::vector<std::string> output_lines(7,""); //the output lines

          //READ THE CORRECT STRINGS FROM THE TEXT FILE
          //put the next line in a for loop
          for(unsigned int i = 0; i < message.size(); i = i + 1){
               readLetter(int(message[i]), output_lines);
          }

          //Conversion of background and forground chars
          for(unsigned int i = 0; i < output_lines.size(); i = i + 1){
               letter_converter(output_lines[i], '#', foreground);
               letter_converter(output_lines[i], '.', background);
          }

          //Output
          for(unsigned int i = 0; i < output_lines.size(); i = i+1){
               std::cout << output_lines[i] << "\n";
          }

     }
     else if(std::string(argv[1])==std::string("read"))//extracredit section
     {
             std::cout << std::string(argv[2]) <<"\n";
     }
     else{//if a type other than read or display is selected
          std::cerr << "ERROR: not a valid type selected \nplease choose display or read\n";
          return 1; //returns 1 becuase it was an error
     }
     return 0; //succesfull compeltion of code
}
