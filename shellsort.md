# Shell Sort Overview
---
A shell sort is very similar to an insertion sort, except it uses an algorithm similar to a jump search before implementing the insertion sort. This jump search orders faraway values in relation to their positions within the array, so that when the insertion sort begins the values are more likely to be closer to their destinations, therefore requiring less iterations to order. The worst possible scenario of a shell sort is O(nlog^2n), while the best possible scenario is ~O(nlogn).
