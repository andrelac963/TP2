//---------------------------------------------------------------------
// Arquivo      : jarvis.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef JARVIS_HPP
#define JARVIS_HPP

#include <iostream>
#include "stack.hpp"

using namespace std;

class Jarvis
{
private:
  Stack *stack;
  Stack *convexHull;

public:
  Jarvis(Stack *stack);
  ~Jarvis();
  void run();
  void print();
};

#endif