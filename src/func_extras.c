#include "func_extras.h"

int *split_credit(double credit)
{
  static int array[2];
  int intpart = 0;
  int decpart = 0;  

  intpart = (int) credit;
  decpart = (credit - intpart) * 10;

  array[0] = intpart;
  array[1] = decpart;

  return array;
}