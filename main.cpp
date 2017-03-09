#include <stdlib.h>
#include <stdio.h>

int myrandom(int min, int max)
{
  int tmp;
  if (max >= min)
  {
    max -= min;
  }
  else
  {
    tmp = min - max;
    min = max;
    max = tmp;
  }
  return max ? (rand() % max + min) : min;
}

int f()
{
  const int N = 17;
  int* x = (int *)malloc(N * sizeof(int));
  int i;
  int mean = 0;
  for (i = 0; i < N; ++i)
  {
    int val = myrandom(0, 100);
#if _DEBUG
    printf("%02d: %d\n", i, val);
#endif
    x[i] = val;
  }
  for (i = 0; i < N; ++i)
  {
    mean += x[i];
  }
  free x;
  mean /= N;
  return mean;
}

int main(int argc, char * argv[])
{
  int val = f();
  printf("Mean: %d\n", val);
  return 0;
}
