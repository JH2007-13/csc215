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
  int i, flag, gap, cycles;
  flag = 1;
  gap = n+1;
  cycles = 0;
  while (flag == 1 || gap > 1) /*Ensures that even if the gap is 1, the sort continues until fully sorted*/
  {
    cycles += 1;
    flag = 0;
    gap = gap/2; /*Gap starts at half the length of the array, and halves itself again each cycle*/
    for (i = 0; i < n-gap; i++) /*Halts each sorting cycle before it goes over the edge of the array*/
    {
      if (arr[i+gap] < arr[i]) /*If the second value is smaller than the first value...*/
      {
        swap(&arr[i+gap],&arr[i]); /*Both values are swapped*/
        flag = 1; /*Everytime a swap happens, the flag is triggered to ensure the program runs again*/
      }
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
