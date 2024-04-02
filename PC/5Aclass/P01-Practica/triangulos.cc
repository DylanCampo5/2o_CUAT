#include <iostream>

int main () {
  int a, b, c;
  std::cin >> a >> b >> c;
  
  if (a == b) {
    if (b == c) 
      std::cout << "equi"<< std::endl;
    else 
      std::cout << "iso" << std::endl;
  }

  else {
    if (a == c)
      std::cout << "iso" << std::endl;
    if (a != c) {
      if (a + b <= c)
        std::cout << "NO" << std::endl;
      else if (a + c <= b)
        std::cout << "NO" << std::endl;
      else if (c + b <= a)
        std::cout << "NO" << std::endl;
      else if (c != b)
        std::cout << "Escaleno" << std::endl;
    }
    if (b == c) {
      std::cout << "iso" << std::endl;
    }
  }
  
  return 0;
}      
