//---------------------------------------------------------------------
// Arquivo      : pointcollection.hpp
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

// Exceção para erros de leitura de arquivo
struct FailedToReadFile
{
  string filename;
};

// Estrutura para armazenar um ponto
struct Point
{
  int x;
  int y;
};

// Estrutura para armazenar um nó da lista encadeada
struct Node
{
  Point point;
  Node *next;
};

// Classe para armazenar uma coleção de pontos
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