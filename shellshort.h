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
  int i, j, temp, cycles, gap; //Variable initializer
  cycles = 0; //Cycles variable tracks how many cycles the function takes (for efficiency)
  for (gap = n / 2; gap > 0; gap = gap / 2) //Gap loop starts the gap at half the length of the array, and halves it every cycle
  {
    cycles += 1;
    for (i = gap; i < n; i++) //Starts the comparison algorithm at the end of the first gap, and then moves right until the end of the array
    {
      temp = arr[i]; //Initial value is stored in a temporary variable (for insertion later)
      j = i;
      while (j >= gap && arr[j - gap] > temp) //Compares the target value with different places along the gap trajectory
      {
        arr[j] = arr[j - gap]; //Swaps the current value with an earlier value along the gap trajectory if necessary
        j = j - gap; //Moves the target back one space along the gap trajectory
      }
      arr[j] = temp; //Initial variable is dropped into its place
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
