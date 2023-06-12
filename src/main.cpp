//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include "pointcollection.hpp"
#include "jarvis.hpp"

using namespace std;

int main(int argc, char **argv)
{
  try
  {
    PointCollection *pointCollection = new PointCollection();

    pointCollection->readFile("pontos.txt");

    pointCollection->print();

    pointCollection->~PointCollection();

    Jarvis *jarvis = new Jarvis(pointCollection);

    jarvis->run();

    jarvis->print();

    delete pointCollection;
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
  catch (exception e)
  {
    cout << "Erro desconhecido" << endl
         << endl;
  }

  return 0;
}