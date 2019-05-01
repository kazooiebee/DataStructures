#include <vector>
#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

int main(){
     Point2D lowerLeft(2,1);
     Point2D upperRight(4,3);
     Rectangle testRect(lowerLeft,upperRight);

     std::cout << std::endl;
     print_rectangle(testRect);
     std::cout << std::endl;

     std::cout << "lower left is " << testRect.lower_left_corner().x() << "," << testRect.lower_left_corner().y() <<std::endl;
     std::cout << "upper right is " << testRect.upper_right_corner().x() << "," << testRect.upper_right_corner().y() <<std::endl;

     Point2D p1(1,1);
     Point2D p2(2,1);
     Point2D p3(3,2);
     std::cout<< "testing points within for (1,1) (2,1) (3,2) " <<
     testRect.is_point_within(p1) << " " <<
     testRect.is_point_within(p2) << " " <<
     testRect.is_point_within(p3) << " " << std::endl;

     testRect.add_point(p1);
     testRect.add_point(p2);
     testRect.add_point(p3);

     std::cout << "testing points_contained: " << std::endl;
     std::vector<Point2D> points_inside = testRect.points_contained();
     for (int i = 0; i < points_inside.size(); i++){
          std::cout << points_inside[i].x() << "," << points_inside[i].y() << std::endl;
     }

     Rectangle testRect2(p1,p3);
     testRect2.add_point(p1);
     testRect2.add_point(p2);
     testRect2.add_point(p3);

     std::cout << "testing points in both: " << std::endl;
     std::vector<Point2D> points_inside_both = points_in_both(testRect, testRect2);
     for (int i = 0; i < points_inside_both.size(); i++){
          std::cout << points_inside_both[i].x() << "," << points_inside_both[i].y() << std::endl;
     }

     std::cout << "testing print: " << std::endl;
     std::cout << std::endl;
     print_rectangle(testRect);
     std::cout << std::endl;
     print_rectangle(testRect2);
     std::cout << std::endl;

     return 0;
}
