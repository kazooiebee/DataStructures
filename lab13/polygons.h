#include <string>
#include "utilities.h"

class Polygon {
public:
     Polygon(std::string n, std::vector<Point> p) {
          if(p.size() == 0) throw 1;
          name = n;
          for(int i = 0; i < p.size(); i++){
               points.push_back(p[i]);
          }
      }
      std::string getName() const { return name; }
     virtual ~Polygon() {}
     bool HasAllEqualSides() const {
          bool equal = true;
          for(int i = 0; i < points.size()-2; i++){
               if(DistanceBetween(points[i],points[i+1]) != DistanceBetween(points[i+1],points[i+2])) {
                    equal = false;
               }
          }
          if(DistanceBetween(points[points.size()-2],points[points.size()-1]) != DistanceBetween(points[points.size()-1],points[0])){
               equal = false;
          }
          return equal;
     }
protected:
     std::string name;
     std::vector<Point> points;
};

class Triangle : public Polygon {
public:
     Triangle(std::string n, std::vector<Point> p) : Polygon(n, p) {
          if(p.size() != 3) throw 1; }
};

class Quadrilateral : public Polygon {
public:
     Quadrilateral(std::string n, std::vector<Point> p) : Polygon(n, p) {
          if(p.size() != 3) {throw 1;} {
          if(p.size() != 4) throw 1; }
     }
};

class IsoscelesTriangle : public Triangle {
public:
     IsoscelesTriangle(std::string n, std::vector<Point> p) : Triangle(n,  p) {
          if(p.size() != 3) {throw 1;}
          else if(DistanceBetween(p[0],p[1]) != DistanceBetween(p[1],p[2])
          && DistanceBetween(p[0],p[1]) != DistanceBetween(p[0],p[2])
          && DistanceBetween(p[1],p[2]) != DistanceBetween(p[0],p[2])){
               throw 1;
          }
     }
};

class EquilateralTriangle : public Triangle {
public:
     EquilateralTriangle(std::string n, std::vector<Point> p) : Triangle( n,  p) {
          if(p.size() != 3) {throw 1;}
          else if(DistanceBetween(p[0],p[1]) == DistanceBetween(p[1],p[2])
          && DistanceBetween(p[0],p[1]) == DistanceBetween(p[0],p[2])
          && DistanceBetween(p[1],p[2]) == DistanceBetween(p[0],p[2])){}
          else{throw 1;}
     }
};

class Rectangle : public Quadrilateral {
public:
     Rectangle(std::string n, std::vector<Point> p) : Quadrilateral( n, p){
          if(p.size() != 4) {throw 1;}
          else if(RightAngle(Angle(p[0],p[1],p[2]))
          && RightAngle(Angle(p[1],p[2],p[3]))
          && RightAngle(Angle(p[2],p[3],p[0]))
          && RightAngle(Angle(p[3],p[0],p[1]))) {}
          else{throw 1;}
     }
};

class Square : public Rectangle {
public:
     Square(std::string n, std::vector<Point> p) : Rectangle( n, p){
          if(p.size() != 4) {throw 1;}
          else if(DistanceBetween(p[0],p[1]) == DistanceBetween(p[1],p[2])
          && DistanceBetween(p[1],p[2]) == DistanceBetween(p[2],p[3])
          && DistanceBetween(p[2],p[3]) == DistanceBetween(p[3],p[0])
          && DistanceBetween(p[3],p[0]) == DistanceBetween(p[0],p[1])){}
          else{throw 1;}
     }
};
