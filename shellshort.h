#include <stdio.h>

swap(a, b)
int *a;
int *b;
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

shell_sort(arr, n)
int arr[];
int n;
{
  int i, flag = 1, gap = n+1;
  while (flag == 1 || gap > 1) //Ensures that even if the gap is 1, the sort continues until fully sorted
  {
    flag = 0;
    gap = gap/2; //Gap starts at half the length of the array, and halves itself again each cycle
    for (i = 0; i < n-gap; i++) //Halts each sorting cycle before it goes over the edge of the array
    {
      if (arr[i+gap] < arr[i]) //If the second value is smaller than the first value...
      {
        swap(&arr[i+gap],&arr[i]); //Both values are swapped
        flag = 1; //Everytime a swap happens, the flag is triggered to ensure the program runs again
      }
    }
  }
}

main()
{
  int a[16];
  int i;
  initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
  shell_sort(a, 16);
  for (i = 0; i < 17; i++) {
    printf("%d/n", a[i])
}
