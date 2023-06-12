//---------------------------------------------------------------------
// Arquivo      : point.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#include "point.hpp"

Point::Point()
{
}

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}

Point::~Point()
{
}

void Point::setX(int x)
{
  this->x = x;
}

void Point::setY(int y)
{
  this->y = y;
}

int Point::getX()
{
  return this->x;
}

int Point::getY()
{
  return this->y;
}

double Point::getAngle()
{
  return atan2(this->y, this->x);
}