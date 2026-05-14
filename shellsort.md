# Shell Sort Overview
---
A shell sort is very similar to an insertion sort, except it uses an algorithm similar to a jump search before implementing the insertion sort. This jump search-esque algorithm orders faraway values in relation to their positions within the array, so that when the insertion sort begins the values are more likely to be closer to their destinations. As a result, the insertion part of the sort requires less iterations to order. The worst possible scenario of a shell sort is O(nlog^2n), while the best possible scenario is ~O(nlogn).

### Shell Sort Example
---
Say you had the unordered list [9, 5, 1, 8, 4, 7, 2, 3]. The first thing the program does is split the length of the array in two using `
