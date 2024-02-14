//Pedir dos enteros, un dividendo y un divisor
//Que me calcule el cociente y el resto
//Si el resto no es cero, que me calcule el valor real de la division
//Si pongo 0 abajo que te pregunte de nuevo

#include <iostream>

int main() {
  int num, den, cociente, resto;
  std::cout << "Dime un numerado: " << std::endl;
  std::cin >> num;
  std::cout << "Dime un denominador: " << std::endl;
  std::cin >> den;
  while (den == 0) {
    std::cout << "ERROR, dime otro denominador: ";
    std::cin >> den;
  }
  cociente = num / den;
  resto = num % den;
  if (resto =! 0) {
    double num2, den2;
    num2 = num;
    den2 = den;
    double resto2;
    resto2 = num2 / den2;
    std::cout << "El resto es: " << resto2;
  }
  std::cout << ", y el cociente es: " << cociente << std::endl;
  return 0;
}
