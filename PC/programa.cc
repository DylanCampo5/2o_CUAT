//Pedir dos enteros, un dividendo y un divisor
//Que me calcule el cociente y el resto
//Si el resto no es cero, que me calcule el valor real de la division
//Si pongo 0 abajo que te pregunte de nuevo

#include <iostream>

int main() {
  int num, den, den2, cociente, resto;
  std::cout << "Dime un numerado: " << std::endl;
  std::cin >> num;
  std::cout << "Dime un denominador: " << std::endl;
  std::cin >> den;
  if (den == 0) {
    std::cout << "ERROR, dime otro denominador: "
    std::cin >> den;
  }
  cociente = num / den;
  resto = num % den;
  if (resto =! 0) {
    resto(double) = num % den;
  }
  std::cout << "El cociente es: " << cociente << ", y el resto es: " << resto << std::endl;
  resturn 0;
