// AUTOR: Dylan Gonzalo Campo Bedoya
// FECHA: 15/02
// EMAIL: alu0101657189@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(1,3), c; // Declaración de tres racionales.

  cout << "a.value()= " << a.value() << endl; // Escribe el valor de a.
  cout << "b.value()= " << b.value() << endl; // Escribe el valor de b.
  cout << "c.value()= " << c.value() << endl; // Escribe el valor de c.
  
  // Escribir los racionales en pantalla.
  cout << "a: "; 
  a.write(); // Escribe el racional a.
  cout << "b: ";
  b.write(); // Escribe el racional b.
  c.read(); // Lee el racional c, desde teclado.
  cout << "c: ";
  c.write(); // Escribe el racional c.

  // FASE II
  rational_t x(1, 2), y(1, 3); // Declaración de dos racionales.
  x.write(); // Escribe el racional x.
  y.write(); // Escribe el racional y.
  cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << endl; // Compara x es igual que y, escribe el resultado: true o false.
  cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << endl; // Compara x es menor que y, escribe el resultado: true o false.
  cout << "x > y? " << (x.is_less(y) ? "true" : "false") << endl; // Compara x es mayor que y, escribe el resultado: true o false.

  // FASE III
  cout << "a + b: "; 
  a.add(b).write(); // Hace la suma de a y b.
  
  cout << "b - a: "; 
  b.substract(a).write(); // Hace la resta de a sobre b.

  cout << "a * b: ";
  a.multiply(b).write(); // Mutiplica a por b.
  
  cout << "a / b: ";
  a.divide(b).write(); // Divide b sobre a.
  
  cout << "El inverso es: ";
  b.inverso().write(); // Me halla el inverso de c en este caso
  
  return 0;
}