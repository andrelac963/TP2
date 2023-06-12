//---------------------------------------------------------------------
// Arquivo      : stack.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <fstream>
#include "point.hpp"

using namespace std;

// Exceção para erros de abertura de arquivo
struct FailedToOpenFile
{
  string filename;
};

// Exceção para erros de leitura de arquivo
struct FailedToReadFile
{
  string filename;
};

// Exceção para erros de acesso a posições inválidas
struct OutOfRange
{
  string error;
};

class Stack
{
private:
  Point *points;
  int size;
  int top;

public:
  Stack(const int &size);
  Stack(const string &filename);
  ~Stack();
  void push(Point point);
  Point pop();
  Point peek();
  int getSize();
  bool isEmpty();
  bool isFull();
  void print();
};

#endif