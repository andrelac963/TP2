//---------------------------------------------------------------------
// Arquivo      : point.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef POINT_HPP
#define POINT_HPP

#include <math.h>

class Point
{
private:
  int x;
  int y;

public:
  Point();
  Point(int x, int y);
  ~Point();
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();
  double getAngle();
};

#endif