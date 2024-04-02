// AUTOR: Dylan Gonzalo Campo Bedoya 
// FECHA: 26/02
// EMAIL: alu0101657189@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#include <iostream>
#include <cmath>
#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3); // Se crea un racional con numerador 1 y denominador 2 y otro con numerador 3 y denominador 1

  // FASE I
  cout << "a + b: "; // Se muestra por pantalla la suma de los racionales
  (a+b).write();

  cout << "b - a: "; // Se muestra por pantalla la resta de los racionales
  (b-a).write();

  cout << "a * b: "; // Se muestra por pantalla el producto de los racionales
  (a*b).write();
  
  cout << "a / b: "; // Se muestra por pantalla la división de los racionales
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  matrix_t<double> A, B, C; // Se crean matrices de tipo double
    A.read(), A.write(); // Se leen y muestran por pantalla las matrices
    B.read(), B.write();

    C.diagonal_sec(A); // Calcula la diagonal secundaria de la matriz A y la guarda en C
    cout << "Diagonal secundaria de C: " << endl; // Se muestra por pantalla la diagonal secundaria de la matriz C
    C.write(); // Escribe la matriz C

    cout << "Suma de la diagonal secundaria de C: " << C.sum_diagonal_sec() << endl; // Suma de la diagonal secundaria de la matriz C

    return 0;
  
}