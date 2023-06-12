//---------------------------------------------------------------------
// Arquivo      : graham.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include <iostream>
#include "pointcollection.hpp"

using namespace std;

class Graham
{
private:
  PointCollection *pointCollection;
  PointCollection *convexHull;

public:
  Graham(PointCollection *pointCollection);
  ~Graham();
  int orientation(Point p, Point q, Point r);
  void run();
  void print();
};

#endif