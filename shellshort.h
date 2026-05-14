#include <stdio.h>

shell_sort(arr, n)
int arr[];
int n;
{
  int i, gap = 2, flag = 1, arrL = n;
  while (flag == 1 || gap > 1)
  {
    flag = 0;
    gap = arrL/2;
    for (i = 0; i < arrL-gap; i++)
    {
      if (arr[i+gap] < arr[i])
      {
        swap(&arr[i+gap],&arr[i]);
        flag = 1;
      }
    }
  }
}
