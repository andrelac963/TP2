//---------------------------------------------------------------------
// Arquivo      : teste.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef POINTCOLLECTION_HPP
#define POINTCOLLECTION_HPP

#include <iostream>
#include <fstream>

using namespace std;

// Exceção para erros de abertura de arquivo
struct FailedToOpenFile
{
  string filename;
};

struct Point
{
  int x;
  int y;
};

struct Node
{
  Point point;
  Node *next;
};

class PointCollection
{
private:
  Node *head;
  Node *tail;
  int size;

public:
  PointCollection();
  ~PointCollection();
  void readFile(string filename);
  void add(Point point);
  void remove(Point point);
  void print();
  int getSize();
  bool isEmpty();
  bool contains(Point point);
  Point *toArray();
  void clear();
};

#endif