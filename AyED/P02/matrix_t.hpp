// AUTOR: Dylan Gonzalo Campo Bedoya 
// FECHA: 26/02
// EMAIL: alu0101657189@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2


#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0);  // Constructor
  ~matrix_t(); // Destructor
  
  void resize(const int, const int); // Redimensiona la matriz
  
  // getters
  int get_m(void) const; // Devuelve el número de filas
  int get_n(void) const; // Devuelve el número de columnas
  
  // getters-setters
  T& at(const int, const int); // Devuelve el elemento de la posición (i, j)
  T& operator()(const int, const int); // Sobreescritura del operador () para devolver el elemento de la posición (i, j)
  
  // getters constantes
  const T& at(const int, const int) const; // Devuelve el elemento de la posición (i, j)
  const T& operator()(const int, const int) const; // Sobreescritura del operador () para devolver el elemento de la posición (i, j)
  
  // operaciones y operadores
  T sum_diagonal_sec() const; //Método que calcula la diagonal secundaria
  void diagonal_sec(const matrix_t<T>&); //Método que calcula la diagonal secundaria
  
  void write(ostream& = cout) const; // Escribe la matriz
  void read(istream& = cin); // Lee la matriz

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_; // Vector de elementos
  
  int pos(const int, const int) const; // Devuelve la posición del elemento (i, j)
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n) // Constructor
{ 
  m_ = m; // Asigna el número de filas
  n_ = n; // Asigna el número de columnas
  v_.resize(m_ * n_); // Redimensiona el vector
}



template<class T>
matrix_t<T>::~matrix_t() // Destructor
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n) // Redimensiona la matriz
{
  assert(m > 0 && n > 0); // Comprueba que las dimensiones son correctas
  m_ = m; // Asigna el número de filas
  n_ = n; // Asigna el número de columnas
  v_.resize(m_ * n_); // Redimensiona el vector
}



template<class T>
inline int
matrix_t<T>::get_m() const // Devuelve el número de filas
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const // Devuelve el número de columnas
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j) // Devuelve el elemento de la posición (i, j)
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j) // Devuelve el elemento de la posición (i, j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const // Devuelve el elemento de la posición (i, j)
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return v_[pos(i, j)];
}



template<class T>
const T& 
matrix_t<T>::operator()(const int i, const int j) const // Devuelve el elemento de la posición (i, j)
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl; // Escribe el número de filas y columnas
  for (int i = 1; i <= get_m(); ++i) { 
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is) // Lee una matriz
{
  is >> m_ >> n_; // Lee el número de filas y columnas
  resize(m_, n_); // Redimensiona la matriz
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const // Devuelve la posición de la matriz
{
  assert(i > 0 && i <= get_m()); // Comprueba que la fila está dentro de los límites
  assert(j > 0 && j <= get_n()); // Comprueba que la columna está dentro de los límites
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
T matrix_t<T>::sum_diagonal_sec() const
{
  assert(get_m() == get_n()); // Comprueba que la matriz es cuadrada
  T sum = 0; // Crea con lo que vamos a sumar los elementos
  for (int i = 1, j = get_n(); i <= get_m(); i++,j--) {
    sum += at(i, j);
  }
  return sum;
}