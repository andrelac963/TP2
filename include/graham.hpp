//---------------------------------------------------------------------
// Arquivo      : graham.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#ifndef GRAHAM_HPP
#define GRAHAM_HPP

#include <iostream>
#include <math.h>
#include "stack.hpp"

using namespace std;

class Graham
{
private:
  Stack *stack;
  Stack *convexHullStack;

  int orientation(Point p, Point q, Point r);
  int getMinIndex(int n);

public:
  Graham(Stack *stack);
  ~Graham();
  void convexHullGraham(int n, Point p0);
  void convexHullGrahamMergeSort();
  void convexHullGrahamInsertionSort();
  void convexHullGrahamCountingSort();
  void printConvexHull();
};

#endif