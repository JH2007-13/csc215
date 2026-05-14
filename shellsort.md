# Shell Sort Overview
---
A shell sort is very similar to an insertion sort, except it uses an algorithm similar to a jump search before implementing the insertion sort. This jump search-esque algorithm orders faraway values in relation to their positions within the array, so that when the insertion sort begins the values are more likely to be closer to their destinations. As a result, the insertion part of the sort requires less iterations to order. The worst possible scenario of a shell sort is O(nlog^2n), while the best possible scenario is ~O(nlogn).

### Shell Sort Example
---
Say you had the unordered list [9, 5, 1, 8, 4, 7, 2, 3]. The first thing the program does is split the length of the array in two using `gap = gap/2`, which will act as the first distance between swaps. The program swaps as long as the swap distance does not exceed the length of the array with `for (i = 0; i < n-gap; i++)`, during which if the second value is smaller than the first value, they are switched. This cycle continues until the value is sorted.
Visually, the array would move like this:
1. [8, 5, 1, 3, 4, 7, 2, 9] (1st and 4th values get swapped)
2. [3, 4, 1, 2, 5, 7, 8, 9] (1st, 2nd, 4th values get swapped, etc.)
3. [1, 2, 3, 4, 5, 7, 8, 9] (No more swaps occur but the gap is still greater than one, so the loop continues)
4. [1, 2, 3, 4, 5, 7, 8, 9] (Gap finally reaches one, so the program ends)
