//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <sys/resource.h>
#include "stack.hpp"
#include "point.hpp"

using namespace std;

float difTempoUsuario(struct rusage *start, struct rusage *end)
{
  return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
         1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

int main(int argc, char **argv)
{
  try
  {
    Stack *stack = new Stack(argv[1]);

    stack->print();
  }
  catch (FailedToOpenFile e)
  {
    cout << "Erro ao abrir o arquivo " << e.filename << endl
         << endl;
  }
  catch (FailedToReadFile e)
  {
    cout << "Erro ao ler o arquivo " << e.filename << endl
         << endl;
  }
  catch (OutOfRange e)
  {
    cout << e.error << endl
         << endl;
  }
  catch (exception e)
  {
    cout << "Erro desconhecido" << endl
         << endl;
  }

  return 0;
}