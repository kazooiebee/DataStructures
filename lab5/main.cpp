#include <vector>
#include <iostream>
#include <list>

void reverse_vector(std::vector<int>& v){
     for(int i = 0; i < v.size()/2; i++){
          int temp = v[i];
          v[i] = v[v.size()-i-1];
          v[v.size()-i-1] = temp;
     }
}

void reverse_list(std::list<int>& l){
     std::list<int>::iterator begin = l.begin();
     std::list<int>::iterator end = l.end();
     end--;
     for(int i = 0; i < l.size()/2; i++){
          int temp = *begin;
          *begin = *end;
          *end = temp;
          begin++;
          end--;
     }
}

void print(const std::list<int>& l){
     std::cout << "list: size " << l.size() << ", ";
     std::list<int>::const_iterator begin = l.begin();
     for(int i = 0; i < l.size(); i++){
          std::cout<< "  " << *begin;
          begin++;
     }
     std::cout << std::endl;
}

int main(){
     std::list<int> a;
     a.push_back(2);
     a.push_back(8);
     a.push_back(4);
     a.push_back(7);
     a.push_back(4);
     a.push_back(3);
     a.push_back(1);
     a.push_back(0);
     a.push_back(8);
     std::cout<< "a ";
     print(a);
     reverse_list(a);
     std::cout<< "reversed a ";
     print(a);
     std::cout << std::endl;

     std::list<int> b;
     b.push_back(2);
     b.push_back(8);
     b.push_back(4);
     b.push_back(7);
     b.push_back(4);
     b.push_back(3);
     b.push_back(1);
     b.push_back(0);
     std::cout<< "b ";
     print(b);
     reverse_list(b);
     std::cout<< "reversed b ";
     print(b);
     std::cout << std::endl;

     std::list<int> c;
     c.push_back(2);
     c.push_back(8);
     std::cout<< "c ";
     print(c);
     reverse_list(c);
     std::cout<< "reversed c ";
     print(c);
     std::cout << std::endl;

     std::list<int> d;
     d.push_back(2);
     std::cout<< "d ";
     print(d);
     reverse_list(d);
     std::cout<< "reversed d ";
     print(d);
     std::cout << std::endl;

     std::list<int> e;
     std::cout<< "e ";
     print(e);
     reverse_list(e);
     std::cout<< "reversed e ";
     print(e);
     std::cout << std::endl;
}
