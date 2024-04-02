// AUTOR: Dylan Gonzalo Campo Bedoya
// FECHA: 15/02
// EMAIL: alu0101657189@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html.
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}



// Obtiene el numerador, devuelve el valor del numerador.
double
rational_t::get_num() const
{
  return num_;
}



// Obtiene el denominador, devuelve el valor del denominador.
double
rational_t::get_den() const
{
  return den_;
}



// Define el numerador, no devuelve nada.
void
rational_t::set_num(const int n)
{
  num_ = n;
}



// Define el denominador, siempre que sea distdoubleo a 0, no devuelve nada.
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



// Devuelve el valor del racional como un double.
double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}



// Comparaciones.
bool 
rational_t::is_equal(const rational_t& r, const double precision) const 
{
  return fabs(value() - r.value()) < precision;
} 



bool
rational_t::is_greater(const rational_t& r, const double precision) const 
{
  return r.value() - value() > precision;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const 
{
  return value()-r.value() > precision;
}



// Operaciones.
// Suma dos racionales y me devuelve lo que de.
rational_t
rational_t::add(const rational_t& r) 
{
  double num = get_num() * r.get_den() + get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Suma dos racionales y me devuelve lo que de.
rational_t
rational_t::substract(const rational_t& r) 
{
  double num = get_num() * r.get_den() + get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Multiplica dos racionales y me devuelve lo que de.
rational_t
rational_t::multiply(const rational_t& r) 
{
  double num = get_num() * r.get_den() + get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Divide dos racionales y me devuelve lo que de.
rational_t
rational_t::divide(const rational_t& r) 
{
  double num = get_num() * r.get_den() + get_den() * r.get_num();
  double den = get_den() * r.get_den();
  return rational_t(num, den);
}



// Me halla el inverso de un número.
rational_t
rational_t::inverso()
{
  double num = get_den();
  double den = get_num();
  return rational_t(num/den);
}



// Código para poder imprimir por pantalla de una forma más sencilla.
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



// Para preguntar por pantalla un numerador y un denominador para el usuario.
void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}