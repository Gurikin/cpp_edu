#include "Vector.h"

Vector::Vector(int s) : elem{new double[s]}, sz{s} {}

/**
 * Копирующий конструктор
 */
Vector::Vector(const Vector &v) : elem{new double[v.sz]}, sz{v.sz} {
  for (int i = 0; i != sz; i++) {
    elem[i] = v.elem[i];
  }
}

/**
 * Перемещающий конструктор
 * && - ссылка, которую можно связать с rvalue (6.4.1. Страуструп)
 */
Vector::Vector(Vector &&v) : elem{v.elem}, sz{v.sz} {
  v.elem = nullptr;
  v.sz = 0;
}

/**
 * Копирующее присваивание
 */
Vector &Vector::operator=(const Vector &v) {
  double *p = new double[v.sz];
  for (int i = 0; i != v.sz; i++) {
    p[i] = v.elem[i];
  }
  delete[] elem;
  elem = p;
  sz = v.sz;
  return *this;
}

double &Vector::operator[](int i) const { return elem[i]; }

int Vector::size() const { return sz; }
