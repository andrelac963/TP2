//---------------------------------------------------------------------
// Arquivo      : stack.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-06-12 - arquivo finalizado
//---------------------------------------------------------------------

#include "stack.hpp"

Stack::Stack(const int size)
{
  if (size <= 0)
  {
    throw OutOfRange{"O tamanho da pilha deve ser maior que zero."};
  }

  this->size = size;
  this->points = new Point[size];
  this->top = -1;
}

Stack::Stack(const string &filename)
{
  ifstream file(filename);
  string line;
  int lineCount = 0;

  if (file.is_open())
  {
    while (getline(file, line))
    {
      lineCount++;
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile{filename};
  }

  this->size = lineCount;
  this->points = new Point[this->size];
  this->top = -1;

  file.open(filename);

  if (file.is_open())
  {
    while (getline(file, line))
    {
      try
      {
        Point point;
        point.setX(stoi(line.substr(0, line.find(" "))));
        point.setY(stoi(line.substr(line.find(" ") + 1, line.length())));
        this->push(point);
      }
      catch (const exception &e)
      {
        throw FailedToReadFile{filename};
      }
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile{filename};
  }
}

Stack::~Stack()
{
  delete[] this->points;
}

void Stack::push(Point point)
{
  if (this->isFull())
  {
    throw OutOfRange{"A pilha está cheia."};
  }

  this->points[++this->top] = point;
}

void Stack::setPoint(const int &index, const Point &point)
{
  if (index < 0 || index > this->top)
  {
    throw OutOfRange{"A posição " + to_string(index) + " não existe na pilha."};
  }

  this->points[index] = point;
}

void Stack::swap(const int &index1, const int &index2)
{
  if (index1 < 0 || index1 > this->top)
  {
    throw OutOfRange{"A posição " + to_string(index1) + " não existe na pilha."};
  }

  if (index2 < 0 || index2 > this->top)
  {
    throw OutOfRange{"A posição " + to_string(index2) + " não existe na pilha."};
  }

  Point aux = this->points[index1];
  this->points[index1] = this->points[index2];
  this->points[index2] = aux;
}

Point Stack::getPoint(const int &index)
{
  if (index < 0 || index > this->top)
  {
    throw OutOfRange{"A posição " + to_string(index) + " não existe na pilha."};
  }

  return this->points[index];
}

Point *Stack::getPoints()
{
  return this->points;
}

Point Stack::pop()
{
  if (this->isEmpty())
  {
    throw OutOfRange{"A pilha está vazia."};
  }

  return this->points[this->top--];
}

Point Stack::peek()
{
  if (this->isEmpty())
  {
    throw OutOfRange{"A pilha está vazia."};
  }

  return this->points[this->top];
}

Point Stack::peekNextToTop()
{
  if (this->isEmpty())
  {
    throw OutOfRange{"A pilha está vazia."};
  }

  return this->points[this->top - 1];
}

int Stack::getSize()
{
  return this->top + 1;
}

int Stack::getTop()
{
  return this->top;
}

bool Stack::isEmpty()
{
  return this->top == -1;
}

bool Stack::isFull()
{
  return this->top == this->size - 1;
}

void Stack::print()
{
  if (this->isEmpty())
  {
    throw OutOfRange{"A pilha está vazia."};
  }

  for (int i = 0; i <= this->top; i++)
  {
    cout << this->points[i].getX() << " " << this->points[i].getY() << endl;
  }
}