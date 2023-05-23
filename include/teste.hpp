//---------------------------------------------------------------------
// Arquivo      : teste.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef TESTE_HPP
#define TESTE_HPP

#include <iostream>

using namespace std;

class Teste
{
public:
  Teste();
  ~Teste();
  void setA(int a);
  int getA();

private:
  int a;
};

#endif