#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <cstdlib>    // library with the exit function


// Returns true if the candidate root is indeed a root of the polynomial a*x*x + b*x + c = 0
bool check_root(int a, int b, int c, float root) {
  // plug the value into the formula
  float check = a * root * root + b * root + c;
  // see if the absolute value is zero (within a small tolerance)
  if (fabs(check) > 0.0001) {
    std::cerr << "ERROR:  " << root << " is not a root of this formula." << std::endl;
    return false;
  } else {
    return true;
  }
}

/* Use the quadratic formula to find the two real roots of polynomial.   Returns
true if the roots are real, returns false if the roots are imaginary.  If the roots
are real, they are returned through the reference parameters root_pos and root_neg. */
bool find_roots(int a, int b, int c, float &root_pos, float &root_neg, float &small_root ) {
  // compute the quantity under the radical of the quadratic formula
  int radical = b*b - 4*a*c;
  //std::cout << "radical is " << radical << std::endl;
  // if the radical is negative, the roots are imaginary
  if (radical < 0) {
    std::cerr << "ERROR:  Imaginary roots" << std::endl;
    return false;
  }
  float sqrt_radical = sqrt(radical);
//  std::cout << "sqrtradical is " << sqrt_radical << std::endl;

  // compute the two roots
  root_pos = (-b + sqrt_radical) / (2*a);
  root_neg = (-b - sqrt_radical) / (2*a);
  if(root_pos>root_neg){
       small_root = root_neg;
 }
 else{
      small_root = root_pos;
}
  //std::cout << "roots is " << root_pos << " and " << root_neg << std::endl;

  return true;
}

int main() {
  // We will loop until we are given a polynomial with real roots


       int my_cs[5];
       int my_bs[5];
       for(int i = 0; i < 5; i = i+1){
           std::cout << "Enter 2 integer coefficients to a quadratic function: 1*x*x + b*x + c = 0" << std::endl;

           std::cin >> my_bs[i] >> my_cs[i];
      }
    // create a place to store the roots
    float smaller_roots[5];
    float root_1;
    float root_2;

    for(int i = 0; i < 5; i = i +1){

          bool success = find_roots(1,my_bs[i],my_cs[i], root_1,root_2, smaller_roots[i]);
    // If the polynomial has imaginary roots, skip the rest of this loop and start over
          if (!success) continue;
          std::cout << "for number "<< i+1 << " The roots are: " << root_1 << " and " << root_2 << std::endl;
          std::cout << "The smaller root is " << smaller_roots[i] << std::endl;
    // Check our work...
          if (check_root(1,my_bs[i],my_cs[i], root_1) && check_root(1,my_bs[i],my_cs[i], root_2)) {
      // Verified roots, break out of the while loop

          } else {
         std::cerr << "ERROR:  Unable to verify one or both roots." << std::endl;
      // if the program has an error, we choose to exit with a
      // non-zero error code
          exit(1);
     }
    }

  // by convention, main should return zero when the program finishes normally
  return 0;
}
