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
#include "jarvis.hpp"
#include "graham.hpp"

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
    //
    struct rusage start, end;

    Stack *stack = new Stack("ENTRADA10.txt");

    //
    getrusage(RUSAGE_SELF, &start);

    Graham *graham = new Graham(stack);

    graham->convexHullGrahamMergeSort();

    delete graham;

    getrusage(RUSAGE_SELF, &end);

    cout << "GRAHAM+MERGESORT: " << difTempoUsuario(&start, &end) << "s" << endl
         << endl;

    //
    getrusage(RUSAGE_SELF, &start);

    Graham *graham = new Graham(stack);

    graham->convexHullGrahamInsertionSort();

    delete graham;

    getrusage(RUSAGE_SELF, &end);

    cout << "GRAHAM+INSERTIONSORT: " << difTempoUsuario(&start, &end) << "s" << endl
         << endl;

    //
    getrusage(RUSAGE_SELF, &start);

    Graham *graham = new Graham(stack);

    graham->convexHullGrahamCountingSort();

    delete graham;

    getrusage(RUSAGE_SELF, &end);

    cout << "GRAHAM+LINEAR: " << difTempoUsuario(&start, &end) << "s" << endl
         << endl;

    //
    getrusage(RUSAGE_SELF, &start);

    Jarvis *jarvis = new Jarvis(stack);

    jarvis->convexHullJarvis();

    delete jarvis;

    getrusage(RUSAGE_SELF, &end);

    cout << "JARVIS: " << difTempoUsuario(&start, &end) << "s" << endl
         << endl;
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