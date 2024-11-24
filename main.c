#include <stdio.h>
#include "menuopts.h"

int main(void) {
  dict test;
  test.index = 1;
  test.option = "Hello";

  printf("%d\n", test.index);
  printf("%s\n", test.option);

  return 0;
}
