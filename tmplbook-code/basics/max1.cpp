#include "max1.hpp"
#include <iostream>
#include <string>

int main()
{
  int i = 42;
  std::cout << "max(7,i):   " << ::max(7,i) << '\n'; // ::, global namespace.
  // Instantiation, int max(int a, int b)
  // Void is also possible, in some cases like T foo(T*)

  double f1 = 3.4;
  double f2 = -6.7;
  std::cout << "max(f1,f2): " << ::max(f1,f2) << '\n';

  std::string s1 = "mathematics";
  std::string s2 = "math";
  std::cout << "max(s1,s2): " << ::max(s1,s2) << '\n';
}
