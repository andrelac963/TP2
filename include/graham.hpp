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

public:
  Graham(Stack *stack);
  ~Graham();
  void convexHullGrahamMergeSort();
  void convexHullGrahamInsertionSort();
  void convexHullGrahamCountingSort();
  void print();
};

#endif