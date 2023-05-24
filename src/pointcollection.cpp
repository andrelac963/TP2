//---------------------------------------------------------------------
// Arquivo      : pointcollection.cpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#include "pointcollection.hpp"

PointCollection::PointCollection()
{
  this->head = NULL;
  this->tail = NULL;
  this->size = 0;
}

PointCollection::~PointCollection()
{
  this->clear();

  delete this->head;
  delete this->tail;
}

void PointCollection::readFile(string filename)
{
  ifstream file(filename);
  Point point;
  string line;

  if (file.is_open())
  {
    while (getline(file, line))
    {
      point.x = stoi(line.substr(0, line.find(" ")));
      point.y = stoi(line.substr(line.find(" ") + 1, line.length()));
      this->add(point);
    }

    file.close();
  }
  else
  {
    throw FailedToOpenFile{filename};
  }
}

void PointCollection::add(Point point)
{
  Node *node = new Node;
  node->point = point;
  node->next = NULL;

  if (this->isEmpty())
  {
    this->head = node;
    this->tail = node;
  }
  else
  {
    this->tail->next = node;
    this->tail = node;
  }

  this->size++;
}

void PointCollection::remove(Point point)
{
  Node *node = this->head;
  Node *previous = NULL;

  while (node != NULL)
  {
    if (node->point.x == point.x && node->point.y == point.y)
    {
      if (previous == NULL)
      {
        this->head = node->next;
      }
      else
      {
        previous->next = node->next;
      }

      if (node->next == NULL)
      {
        this->tail = previous;
      }

      delete node;
      this->size--;
      break;
    }

    previous = node;
    node = node->next;
  }
}

void PointCollection::print()
{

  if (this->isEmpty())
  {
    cout << "Lista vazia." << endl;
    return;
  }

  Node *node = this->head;

  while (node != NULL)
  {
    cout << "(" << node->point.x << ", " << node->point.y << ")" << endl;
    node = node->next;
  }
}

int PointCollection::getSize()
{
  return this->size;
}

bool PointCollection::isEmpty()
{
  return this->size == 0;
}

bool PointCollection::contains(Point point)
{
  Node *node = this->head;

  while (node != NULL)
  {
    if (node->point.x == point.x && node->point.y == point.y)
    {
      return true;
    }

    node = node->next;
  }

  return false;
}

Point *PointCollection::toArray()
{
  Point *points = new Point[this->size];
  Node *node = this->head;

  for (int i = 0; i < this->size; i++)
  {
    points[i] = node->point;
    node = node->next;
  }

  return points;
}

void PointCollection::clear()
{
  Node *node = this->head;
  Node *next = NULL;

  while (node != NULL)
  {
    next = node->next;
    delete node;
    node = next;
  }

  this->head = NULL;
  this->tail = NULL;
  this->size = 0;
}