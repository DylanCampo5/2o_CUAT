// AUTOR: Dylan Gonzalo Campo Bedoya. 
// FECHA: 05/02.
// EMAIL: alu0101657189@ull.edu.es.
// VERSION: 1.0.
// ASIGNATURA: Algoritmos y Estructuras de Datos.
// PRÁCTICA Nº: 1.
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html.

// Pauta de estilo [92]: comentarios multilínea usando solo "//".

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// Pauta de estilo [87]: 3 líneas de separación entre métodos.

// Pauta de estilo [83]: tipo retornado en línea anterior al método.
int
rational_t::get_num() const
{
  return num_;
}



int
rational_t::get_den() const
{
  return den_;
}


  
void
rational_t::set_num(const int n)
{
  num_ = n;
}


  
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



double
rational_t::value() const
{ 
  return double(get_num()) / get_den();
}



// Comparaciones.
bool 
rational_t::is_equal(const rational_t& r, const double precision) const 
{
  bool solucion;
  if ((fabs(n - d)) < precision)
    solucion = true;
  else
    solucion = false;
  return solucion;
} 



bool
rational_t::is_greater(const rational_t& r, const double precision) const 
{
  bool solucion;                                                                                    
  if ((n - d) < precision)                                                                      
    solucion = true;                                                                                
  else                                                                                              
    solucion = false;                                                                               
  return solucion;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const {}



// Operaciones.
//rational_t
//rational_t::add(const rational_t& r) {}



//rational_t
//rational_t::substract(const rational_t& r) {}



//rational_t
//rational_t::multiply(const rational_t& r) {}



//rational_t
//rational_t::divide(const rational_t& r) {}



//E/S



void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void 
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
