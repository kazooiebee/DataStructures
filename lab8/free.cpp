#include <list>
#include <iostream>
#include <cassert>

template <class T>
bool reverse_splice(std::list<T>& list, typename std::list<T>::iterator& i, typename std::list<T>::iterator& j){
     if(i==j){
          return false;
     }
     for(typename std::list<T>::iterator tmp = i; tmp!=j; ++tmp){
          if(list.end()==tmp) return false;
     }

     int counter = 0;
     typename std::list<T>::iterator after = j;
     while(i!=j && after != i){
          list.insert(i, *j);
          list.insert(j, *i);
          i = list.erase(i);
          j = list.erase(j);
          j--;after = j;j--;
          counter++;
     }

     for(int k = 0; k < counter; k++){
          j++;
          i--;
     }
     return true;
}

int main() {

  std::list<int> data;

  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);
  data.push_back(8);
  data.push_back(9);

  std::list<int>::iterator i;
  i = data.begin();
  i++;i++;
  std::list<int>::iterator j;
  j = data.begin();
  j++;j++;
  j++;j++;
  j++;j++;

  // verify the iterators
  assert (*i == 3);
  assert (*j == 7);

  // print the initial data
  for (std::list<int>::iterator k = data.begin(); k != data.end(); k++) {
    std::cout << " " << *k;
  }
  std::cout << std::endl;

  bool success = reverse_splice(data,i,j);
  assert (success);

  // print the data after the operation
  for (std::list<int>::iterator k = data.begin(); k != data.end(); k++) {
    std::cout << " " << *k;
  }
  std::cout << std::endl;

  // verify the iterators
 //std::cout<< "its are ! : " << *i << " " << *j << std::endl;
  assert (*i == 7);
  assert (*j == 3);

}

/* //my test function
int main(){
     std::list<int> list;
     for(int i = 0; i < 10; i++){
          list.push_back(i);
     }
     std::list<int>::iterator i = list.begin();
     std::list<int>::iterator j = list.begin();
     for(int k = 0; k < 0; k++) i++;
     for(int k = 0; k < 9; k++) j++;

     std::cout << "Reverse from " << *i << " to " << *j << std::endl;
     reverseSplice(list, i, j);

     std::cout << "List: ";
     for(std::list<int>::iterator tmp = list.begin(); tmp != list.end(); ++tmp){
          std::cout << *tmp << " ";
     }
     std::cout << std::endl;
}
*/
