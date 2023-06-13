//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
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
    struct rusage start, end;

    float tempGM, tempGI, tempGC, tempJV;

    // Implementa o algoritmo de Graham com o método de ordenação mergesort
    getrusage(RUSAGE_SELF, &start);

    Stack *stackGM = new Stack(argv[1]);

    Graham *grahamMergeSort = new Graham(stackGM);

    grahamMergeSort->convexHullGrahamMergeSort();

    delete grahamMergeSort;
    delete stackGM;

    getrusage(RUSAGE_SELF, &end);

    tempGM = difTempoUsuario(&start, &end);

    // Implementa o algoritmo de Graham com o método de ordenação insertion sort
    getrusage(RUSAGE_SELF, &start);

    Stack *stackGI = new Stack(argv[1]);

    Graham *grahamInsertionSort = new Graham(stackGI);

    grahamInsertionSort->convexHullGrahamInsertionSort();

    delete grahamInsertionSort;
    delete stackGI;

    getrusage(RUSAGE_SELF, &end);

    tempGI = difTempoUsuario(&start, &end);

    // Implementa o algoritmo de Graham com o método de ordenação counting sort
    getrusage(RUSAGE_SELF, &start);

    Stack *stackGC = new Stack(argv[1]);

    Graham *grahamCountingSort = new Graham(stackGC);

    grahamCountingSort->convexHullGrahamCountingSort();

    delete grahamCountingSort;
    delete stackGC;

    getrusage(RUSAGE_SELF, &end);

    tempGC = difTempoUsuario(&start, &end);

    // Implementa o algoritmo de Jarvis
    getrusage(RUSAGE_SELF, &start);

    Stack *stackJV = new Stack(argv[1]);

    Jarvis *jarvis = new Jarvis(stackJV);

    jarvis->convexHullJarvis();

    jarvis->printConvexHull();

    delete jarvis;
    delete stackJV;

    getrusage(RUSAGE_SELF, &end);

    tempJV = difTempoUsuario(&start, &end);

    cout << "GRAHAM+MERGESORT: " << tempGM << "s" << endl;
    cout << "GRAHAM+INSERTIONSORT: " << tempGI << "s" << endl;
    cout << "GRAHAM+LINEAR: " << tempGC << "s" << endl;
    cout << "JARVIS: " << tempJV << "s" << endl
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