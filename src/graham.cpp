//---------------------------------------------------------------------
// Arquivo      : graham.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#include "graham.hpp"

// Construtor
Graham::Graham(Stack *stack)
{
  this->stack = stack;
  this->convexHullStack = new Stack(stack->getSize());
}

// Destrutor
Graham::~Graham()
{
  delete this->convexHullStack;
}

// Retorna a orientação de três pontos
int Graham::orientation(Point p, Point q, Point r)
{
  int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
            (q.getX() - p.getX()) * (r.getY() - q.getY());

  if (val == 0)
  {
    return 0;
  }
  return (val > 0) ? 1 : 2;
}

// Retorna o índice do ponto com menor coordenada Y
int Graham::getMinIndex(int n)
{
  int minIndex = 0;

  for (int i = 0; i < n; i++)
  {
    if (this->stack->getPoint(i).getY() < this->stack->getPoint(minIndex).getY() || (this->stack->getPoint(i).getY() == this->stack->getPoint(minIndex).getY() && this->stack->getPoint(i).getX() < this->stack->getPoint(minIndex).getX()))
    {
      minIndex = i;
    }
  }

  return minIndex;
}

// Implementação do algoritmo de Graham utilizando
void Graham::convexHullGraham(int n, Point p0)
{
  int m = 1;

  for (int i = 1; i < n; i++)
  {
    while (i < n - 1 && this->orientation(p0, this->stack->getPoint(i), this->stack->getPoint(i + 1)) == 0)
      i++;
    this->stack->setPoint(m, this->stack->getPoint(i));
    m++;
  }

  if (m < 2)
  {
    return;
  }

  this->convexHullStack->push(this->stack->getPoint(0));
  this->convexHullStack->push(this->stack->getPoint(1));
  this->convexHullStack->push(this->stack->getPoint(2));

  for (int i = 3; i < m; i++)
  {

    while (this->convexHullStack->getSize() > 1 && this->orientation(this->convexHullStack->peekNextToTop(), this->convexHullStack->peek(), this->stack->getPoint(i)) != 2)
      this->convexHullStack->pop();

    this->convexHullStack->push(this->stack->getPoint(i));
  }
}

void merge(Stack *stack, int left, int middle, int right)
{
  int n1 = middle - left + 1;
  int n2 = right - middle;

  Point *leftArray = new Point[n1];
  Point *rightArray = new Point[n2];

  for (int i = 0; i < n1; i++)
  {
    leftArray[i] = stack->getPoint(left + i);
  }

  for (int j = 0; j < n2; j++)
  {
    rightArray[j] = stack->getPoint(middle + 1 + j);
  }

  int indexLeft = 0;
  int indexRight = 0;
  int indexMerged = left;

  while (indexLeft < n1 && indexRight < n2)
  {
    if (leftArray[indexLeft].getY() < rightArray[indexRight].getY())
    {
      stack->setPoint(indexMerged, leftArray[indexLeft]);
      indexLeft++;
    }

    else if (leftArray[indexLeft].getY() == rightArray[indexRight].getY())
    {
      if (leftArray[indexLeft].getX() < rightArray[indexRight].getX())
      {
        stack->setPoint(indexMerged, leftArray[indexLeft]);
        indexLeft++;
      }
      else
      {
        stack->setPoint(indexMerged, rightArray[indexRight]);
        indexRight++;
      }
    }
    else
    {
      stack->setPoint(indexMerged, rightArray[indexRight]);
      indexRight++;
    }
    indexMerged++;
  }

  while (indexLeft < n1)
  {
    stack->setPoint(indexMerged, leftArray[indexLeft]);
    indexLeft++;
    indexMerged++;
  }

  while (indexRight < n2)
  {
    stack->setPoint(indexMerged, rightArray[indexRight]);
    indexRight++;
    indexMerged++;
  }

  for (int i = left + 1; i <= right; i++)
  {
    for (int j = i + 1; j <= right; j++)
    {
      double angle1 = stack->getPoint(i).getAngle();
      double angle2 = stack->getPoint(j).getAngle();

      if (angle1 > angle2)
      {
        stack->swap(i, j);
      }
    }
  }

  delete[] leftArray;
  delete[] rightArray;
}

// Implementação do algoritmo de ordenação merge sort
void mergeSort(Stack *stack, int left, int right)
{
  int middle;
  if (left < right)
  {
    middle = floor(left + (right - left) / 2);

    mergeSort(stack, left, middle);
    mergeSort(stack, middle + 1, right);

    merge(stack, left, middle, right);
  }
}

// Implementação do algoritmo de Graham utilizando o merge sort
void Graham::convexHullGrahamMergeSort()
{
  int n = this->stack->getSize();

  int minIndex = getMinIndex(n);

  this->stack->swap(0, minIndex);

  Point p0 = this->stack->getPoint(0);

  mergeSort(this->stack, 0, n - 1);

  this->convexHullGraham(n, p0);
}

// Implementação do algoritmo de ordenação por inserção
void insertionSort(Stack *stack, int n)
{
  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (stack->getPoint(i).getAngle() > stack->getPoint(j).getAngle())
        stack->swap(i, j);
    }
  }
}

// Implementação do algoritmo de Graham utilizando o insertion sort
void Graham::convexHullGrahamInsertionSort()
{
  int n = this->stack->getSize();

  int minIndex = getMinIndex(n);

  this->stack->swap(0, minIndex);

  Point p0 = this->stack->getPoint(0);

  insertionSort(this->stack, n);

  this->convexHullGraham(n, p0);
}

// Implementação do algoritmo de ordenação por contagem
void countingSort(Stack *stack, int n)
{
  int max = stack->getPoint(0).getY();

  for (int i = 1; i < n; i++)
  {
    if (stack->getPoint(i).getY() > max)
    {
      max = stack->getPoint(i).getY();
    }
  }

  int *count = new int[max + 1];

  for (int i = 0; i <= max; i++)
  {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++)
  {
    count[stack->getPoint(i).getY()]++;
  }

  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }

  Point *output = new Point[n];

  for (int i = n - 1; i >= 0; i--)
  {
    output[count[stack->getPoint(i).getY()] - 1] = stack->getPoint(i);
    count[stack->getPoint(i).getY()]--;
  }

  for (int i = 0; i < n; i++)
  {
    stack->setPoint(i, output[i]);
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double a1 = stack->getPoint(i).getAngle();
      double a2 = stack->getPoint(j).getAngle();

      if (a1 > a2)
      {
        stack->swap(i, j);
      }
    }
  }

  delete[] count;
  delete[] output;
}

// Implementação do algoritmo de Graham utilizando o counting sort
void Graham::convexHullGrahamCountingSort()
{
  int n = this->stack->getSize();

  int minIndex = getMinIndex(n);

  this->stack->swap(0, minIndex);

  Point p0 = this->stack->getPoint(0);

  countingSort(this->stack, n);

  this->convexHullGraham(n, p0);
}

// Imprime o fecho convexo
void Graham::printConvexHull()
{
  cout << endl;
  cout << "FECHO CONVEXO:" << endl;
  this->convexHullStack->print();
  cout << endl;
}