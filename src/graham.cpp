#include "graham.hpp"

Graham::Graham(Stack *stack)
{
  this->stack = stack;
  this->convexHull = new Stack(stack->getSize());
}

Graham::~Graham()
{
  delete this->convexHull;
}