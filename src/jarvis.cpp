#include "jarvis.hpp"

Jarvis::Jarvis(Stack *stack)
{
  this->stack = stack;
  this->convexHull = new Stack(stack->getSize());
}

Jarvis::~Jarvis()
{
  delete this->stack;
  delete this->convexHull;
}
