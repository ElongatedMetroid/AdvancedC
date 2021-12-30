#include <stdlib.h>
#include <stdio.h>

#ifdef DEBON
  #define DEBUG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
  #define DEBUG(tmp, ...) do{}while(0)
#endif //DEBON

int sum(int x, int y, int z) {
  char c = 2;
  int *a = NULL;

  DEBUG("x = %d\n", x);
  DEBUG("y = %d\n", y);
  DEBUG("z = %d\n", z);
  DEBUG("a = %ld\n", (long)a);

  a = (int*)malloc(sizeof(int));

  *a = 5;

  DEBUG("*a = %d\n", *a);

  int sum = (c + x + y + z + *a) / 3;

  free(a);
  a = NULL;

  return sum;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  DEBUG("Number of params = %d\n", argc);

  if (argc == 1) {
    printf("Please specify three numbers as parameters.\n");
    exit(1);
  }

  i = atoi(argv[1]);
  DEBUG("i = %d\n", i);
  j = atoi(argv[2]);
  DEBUG("j = %d\n", j);
  k = atoi(argv[3]);
  DEBUG("k = %d\n", k);

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}
