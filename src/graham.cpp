//---------------------------------------------------------------------
// Arquivo      : graham.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#include "graham.hpp"

Graham::Graham(Stack *stack)
{
  this->stack = stack;

  this->convexHullStack = new Stack(stack->getSize());
}

Graham::~Graham()
{
  delete this->convexHullStack;
}

int orientation(Point p, Point q, Point r)
{
  int val = (q.getY() - p.getY()) * (r.getX() - q.getX()) -
            (q.getX() - p.getX()) * (r.getY() - q.getY());

  if (val == 0)
  {
    return 0;
  }
  return (val > 0) ? 1 : 2;
}

void merge(Stack *stack, int left, int middle, int right)
{
  int n1 = middle - left + 1;
  int n2 = right - middle;

  int indexStart = 0;
  int indexEnd = 0;
  int indexMerged = left;

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

  while (indexStart < n1 && indexEnd < n2)
  {
    if (leftArray[indexStart].getY() < rightArray[indexEnd].getY())
    {
      stack->setPoint(indexMerged, leftArray[indexStart]);
      indexStart++;
    }

    else if (leftArray[indexStart].getY() == rightArray[indexEnd].getY())
    {
      if (leftArray[indexStart].getX() < rightArray[indexEnd].getX())
      {
        stack->setPoint(indexMerged, leftArray[indexStart]);
        indexStart++;
      }
      else
      {
        stack->setPoint(indexMerged, rightArray[indexEnd]);
        indexEnd++;
      }
    }
    else
    {
      stack->setPoint(indexMerged, rightArray[indexEnd]);
      indexEnd++;
    }
    indexMerged++;
  }

  while (indexStart < n1)
  {
    stack->setPoint(indexMerged, leftArray[indexStart]);
    indexStart++;
    indexMerged++;
  }

  while (indexEnd < n2)
  {
    stack->setPoint(indexMerged, rightArray[indexEnd]);
    indexEnd++;
    indexMerged++;
  }

  for (int i = left + 1; i <= right; i++)
  {
    for (int j = i + 1; j <= right; j++)
    {
      double a1 = stack->getPoint(i).getAngle();
      double a2 = stack->getPoint(j).getAngle();

      if (a1 > a2)
      {
        Point aux = stack->getPoint(i);
        stack->setPoint(i, stack->getPoint(j));
        stack->setPoint(j, aux);
      }
    }
  }

  delete[] leftArray;
  delete[] rightArray;
}

void mergeSort(Stack *stack, int left, int right)
{
  if (left < right)
  {
    int middle = left + (right - left) / 2;

    mergeSort(stack, left, middle);
    mergeSort(stack, middle + 1, right);

    merge(stack, left, middle, right);
  }
}

void Graham::convexHullGrahamMergeSort()
{
  int n = this->stack->getSize();
  int yMin = this->stack->getPoint(0).getY();
  int indexYMin = 0;

  for (int i = 1; i < n; i++)
  {
    if (this->stack->getPoint(i).getY() < yMin)
    {
      yMin = this->stack->getPoint(i).getY();
      indexYMin = i;
    }
  }

  this->stack->swap(0, indexYMin);

  Point p0 = this->stack->getPoint(0);

  mergeSort(this->stack, 0, n - 1);

  int m = 1;

  for (int i = 1; i < n; i++)
  {
    while (i < n - 1 && orientation(p0, this->stack->getPoint(i), this->stack->getPoint(i + 1)) == 0)
    {
      i++;
    }

    this->stack->setPoint(m, this->stack->getPoint(i));
    m++;
  }

  if (m < 3)
  {
    return;
  }

  this->convexHullStack->push(this->stack->getPoint(0));
  this->convexHullStack->push(this->stack->getPoint(1));
  this->convexHullStack->push(this->stack->getPoint(2));

  for (int i = 3; i < m; i++)
  {
    while (this->convexHullStack->getSize() > 1 && orientation(this->convexHullStack->peekNextToTop(), this->convexHullStack->peek(), this->stack->getPoint(i)) != 2)
    {
      this->convexHullStack->pop();
    }

    this->convexHullStack->push(this->stack->getPoint(i));
  }
}

void insertionSort()
{
}

void Graham::convexHullGrahamInsertionSort()
{
}

void countingSort()
{
}

void Graham::convexHullGrahamCountingSort()
{
}

void Graham::print()
{
  cout << endl;
  cout << "FECHO CONVEXO:" << endl;
  this->convexHullStack->print();
  cout << endl;
}
