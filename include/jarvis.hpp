//---------------------------------------------------------------------
// Arquivo      : jarvis.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef JARVIS_HPP
#define JARVIS_HPP

#include <iostream>
#include "pointcollection.hpp"

using namespace std;

class Jarvis
{
private:
  PointCollection *pointCollection;
  PointCollection *convexHull;

public:
  Jarvis(PointCollection *pointCollection);
  ~Jarvis();
  int orientation(Point p, Point q, Point r);
  void run();
  void print();
};

#endif