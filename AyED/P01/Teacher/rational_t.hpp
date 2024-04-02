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

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

using namespace std;

class rational_t
{
public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}
  
  // Getters.
  double get_num() const; // Método para obtener el numerador y denominador respectivamente.
  double get_den() const;
  
  // Setters.
  void set_num(const int); //Metodo para modificar el numerador y denominador respectivamente.
  void set_den(const int);

  double value(void) const;

  // Fase II.
  bool is_equal(const rational_t&, const double precision = EPSILON) const; // Tres metodos para comparar dos racionales.
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  bool is_less(const rational_t&, const double precision = EPSILON) const;
  
  // Fase III.
  rational_t add(const rational_t&); // Metodo para sumar dos racionales.
  rational_t substract(const rational_t&); // Metodo para restar dos racionales.
  rational_t multiply(const rational_t&); // Metodo para multiplicar dos racionales.
  rational_t divide(const rational_t&); // Metodo para dividir dos racionales.
  rational_t inverso(); // Metodo para hacer el inverso de un racional.

  void write(ostream& = cout) const; //metodo para escribir un racional mediante tecleado.
  void read(istream& = cin); //metodo para leer un racional.
  
private:
  int num_, den_;
};
