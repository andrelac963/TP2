//---------------------------------------------------------------------
// Arquivo      : jarvis.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#include "jarvis.hpp"

Jarvis::Jarvis(Stack *stack)
{
  this->stack = stack;
  this->convexHull = new Stack(stack->getSize());
}

Jarvis::~Jarvis()
{
  delete this->convexHull;
}

int Jarvis::orientation(Point p, Point q, Point r)
{
  int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
            (q.getX() - p.getX()) * (r.getY() - q.getY());

  if (val == 0)
    return 0;
  return (val > 0) ? 1 : 2;
}

void Jarvis::convexHullJarvis()
{
  int n = this->stack->getSize();

  if (n < 3)
    return;

  int lowestIndex = 0;

  for (int i = 1; i < n; i++)
  {
    if (this->stack->getPoint(i).getX() < this->stack->getPoint(lowestIndex).getX())
    {
      lowestIndex = i;
    }
  }

  int currentPointIndex = lowestIndex, nextPointIndex;

  do
  {
    this->convexHull->push(this->stack->getPoint(currentPointIndex));
    nextPointIndex = (currentPointIndex + 1) % n;
    for (int i = 0; i < n; i++)
    {
      if (this->orientation(this->stack->getPoint(currentPointIndex), this->stack->getPoint(i), this->stack->getPoint(nextPointIndex)) == 2)
        nextPointIndex = i;
    }
    currentPointIndex = nextPointIndex;
  } while (currentPointIndex != lowestIndex);
}

void Jarvis::printConvexHull()
{
  cout << endl;
  cout << "FECHO CONVEXO:" << endl;
  this->convexHull->print();
  cout << endl;
}