#include <stdio.h>

int swap();
int shell_sort();

swap(a, b)
int *a;
int *b;
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int shell_sort(arr, n)
int arr[];
int n;
{
  int i, j, temp, cycles, gap;
  cycles = 0;
  for (gap = n / 2; gap > 0; gap = gap / 2)
  {
    cycles += 1;
    for (i = gap; i < n; i++)
    {
      temp = arr[i];
      j = i;
      while (j >= gap && arr[j - gap] > temp)
      {
        arr[j] = arr[j - gap];
        j = j - gap;
      }
      arr[j] = temp;
    }
  }   
  return cycles;
}

main()
{
  int a[16];
  int i, j;
  printf("Using shell sort on a 16 integer array\n");
  printf("Before sorting: 31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27\n");
  initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
  printf("After sorting: ");
  j = shell_sort(a, 16);
  for (i = 0; i < 16; i++) {
    printf("%d, ", a[i]);
  }
  printf("Cycle count: %d\n", j);
}
