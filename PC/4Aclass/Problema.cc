//1.- Preguntar por un numero
//2.- Si el numero es 0 terminar
//3.- Probar de 2 a n-1 si es divisible
//4.- Si no es divisible por ninguno, demostrar que es primo
//5.- Caso contrario, mostrar el numero que lo comprueba
//6.- Volver a 1

#include <iostream>

int main() {
  int num;
  std::cout << "Mete un número: ";
  std::cin >> num;
  
  for (int i = 2; i <= num; i++) {
    if ((num % i) == 0) {
      std::cout << "Tu número SI primo." << std::endl;
    }
    break;
    if ((num % i) != 0) {
      std::cout << "Es divisible entre: " << i << std::endl;
    }
  }

  return 0;
}
