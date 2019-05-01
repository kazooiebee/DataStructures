#include <iostream>
#include <list>
#include <vector>
#include <cassert>



void print(const std::string &label, const std::list<std::string> &data) {
  std::cout << label;
  for (std::list<std::string>::const_iterator itr = data.begin();
       itr != data.end(); itr++) {
    std::cout << " " << *itr;
  }
  std::cout << std::endl;
}

void update(std::list<std::string>& l, const std::vector<std::string>& v_add, const std::vector<std::string>& v_remove){
     std::list<std::string>::iterator next = l.begin();
     int i = 0;
     int j = 0;
     for(std::list<std::string>::iterator itr = l.begin(); itr != l.end(); itr++){
          i++;
          if(next==l.begin()){
               itr=l.begin(); i=0;
          }
          next++; j++;
          for(int k = 0; k < v_add.size(); k++){
               if(v_add[k] >= *itr && v_add[k] != *itr && *next!=v_add[k] && ( (next != l.end() && v_add[k] < *next) || next==l.end() ) ){
                    l.insert(itr, v_add[k]);
                    i++;j++;
               }
          }
          for(int k = 0; k < v_remove.size(); k++){
               if((std::string(*itr)).find(std::string(v_remove[k])) != std::string::npos){
                    l.remove(*itr); j--;
                    itr = next; i = j;
                    itr--; i--;
                    break;
               }
          }
          std::cout << i << "   " << j << std::endl;
     }
}

int main() {


  // Examples demonstrating STL string find:
  // catfish contains the substring fish
  assert (std::string("catfish").find(std::string("fish")) != std::string::npos);
  // fish contains the substring fish
  assert (std::string("fish").find(std::string("fish")) != std::string::npos);
  // fish does not contain the substring catfish
  assert (std::string("fish").find(std::string("catfish")) == std::string::npos);


  // A simple example:
  std::list<std::string> data;
  data.push_back("antelope");
  data.push_back("catfish");
  data.push_back("giraffe");
  data.push_back("llama");
  data.push_back("jellyfish");
  data.push_back("whale_shark");
  data.push_back("zebra");

  std::vector<std::string> add;
  add.push_back("tiger");
  add.push_back("llama");
  add.push_back("elephant");

  std::vector<std::string> remove;
  remove.push_back("fish");
  remove.push_back("bear");
  remove.push_back("whale");

  print ("before:",data);
  update(data,add,remove);
  print ("after: ",data);

  // at the end, data should contain: antelope elephant giraffe llama tiger zebra
  assert (data.size() == 6);

}
