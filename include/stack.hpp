//---------------------------------------------------------------------
// Arquivo      : stack.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
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
  void swap(const int &index1, const int &index2);
  void setPoint(const int &index, Point point);
  Point getPoint(const int &index);
  Point *getPoints();
  Point pop();
  Point peek();
  Point peekNextToTop();
  int getSize();
  int getTop();
  bool isEmpty();
  bool isFull();
  void print();
};

#endif