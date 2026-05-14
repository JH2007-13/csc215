#include "SORT.H"
#include "BDSCTEST.H"

int is_heap(arr, i, size)
int arr[];
int i, size;
{
  int lchild, rchild;
  lchild = 2 * i + 1;
  rchild = 2 * i + 2;
  if (lchild >= size) return TRUE; /* It's a leaf node */
  if (rchild >= size) return arr[i] >= arr[lchild]; /* Only has left child */
  if ((arr[i] < arr[lchild]) || (arr[i] < arr[rchild])) return FALSE;
  return is_heap(arr, lchild, size) && is_heap(arr, rchild, size);
}

main()
{
  int a[16];
  int b[7];
  int c[9];

  START_TESTING("SORTTEST.C");

  TEST_CASE("Bubble Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    bubble_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Insertion Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    insertion_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Selection Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    selection_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Merge Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    merge_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Quick Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    quick_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Radix Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    radix_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }
  TEST_CASE("Test is_heap") {
    initw(b, "13, 8, 11, 4, 2, 7, 9");
    ASSERT(is_heap(b, 0, 7), "13, 8, 11, 4, 2, 7, 9 is a heap");
    initw(b, "8, 13, 11, 4, 2, 7, 9");
    ASSERT(!is_heap(b, 0, 7), "8, 13, 11, 4, 7, 9 is a not a heap");
    initw(a, "42, 30, 36, 20, 8, 17, 12, 3, 9, 6, 7, 13, 5, 4, 11, 2");
    ASSERT(is_heap(a, 0, 16),
           "42, 30, 36, 20, 8, 17, 12, 3, 9, 6, 7, 13, 5, 4, 11, 2 is heap");
    initw(c, "13, 8, 11, 4, 2, 7, 9, 12, 42");
    ASSERT(is_heap(c, 0, 7), "13, 8, 11, 4, 2, 7, 9, 12 is heap");
    ASSERT(!is_heap(c, 0, 8), "13, 8, 11, 4, 2, 7, 9, 12, 42 is not heap");
  }
  TEST_CASE("Test reheap_up") {
    initw(c, "13, 8, 11, 4, 2, 7, 9, 12, 42");
    ASSERT(!is_heap(c, 0, 8), "13, 8, 11, 4, 2, 7, 9, 12, 42 is not a heap");
    reheap_up(c, 8);
    ASSERT(is_heap(c, 0, 8), "It's a heap now after reheap_up called");
    ASSERT(!is_heap(c, 0, 9), "Not a heap if last element is included");
    reheap_up(c, 9);
    ASSERT(is_heap(c, 0, 9), "It is now again after reheap_up");
  }
  TEST_CASE("Test heapify") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    ASSERT(!is_heap(a, 0, 16), "Array a is not a heap");
    heapify(a, 16);
    ASSERT(is_heap(a, 0, 16), "Array a after heapify is a heap");
    initw(c, "42, 13, 8, 11, 4, 2, 7, 9, 12");
    heapify(c, 9);
    ASSERT(is_heap(c, 0, 9), "heapify makes array c an array too");
  }
  TEST_CASE("Test reheap_down") {
    initw(a, "42, 30, 36, 20, 8, 17, 12, 3, 9, 6, 7, 13, 5, 4, 11, 2");
    ASSERT(is_heap(a, 0, 16), "Array a is a heap");
    swap(&a[0], &a[15]);
    ASSERT(!is_heap(a, 0, 16), "a is not a heap after swap 1st and last");
    reheap_down(a, 15);
    ASSERT(is_heap(a, 0, 15), "It's a heap again after reheap_down");
    swap(&a[0], &a[14]);
    reheap_down(a, 14);
    ASSERT(is_heap(a, 0, 14),
           "Swap, reheap_down, and 14 elements still a heap");
  }
  TEST_CASE("Heap Sort") {
    initw(b, "1, 2, 3, 4, 5, 6, 7");
    heap_sort(b, 7);
    ARR_INCR(b, 7, "Array b now sorted");
    initw(c, "42, 13, 8, 11, 4, 2, 7, 9, 12");
    heap_sort(c, 9);
    ARR_INCR(c, 9, "Array c now sorted");
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    heap_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
    initw(c, "5, 4, 3, 1, 2, 6, 8, 7");
    heap_sort(c, 8);
    ARR_INCR(c, 8, "Array c now sorted");
  }
  TEST_CASE("Tree Sort") {
    initw(a, "31, 4, 15, 9, 26, 5, 35, 8, 97, 23, 84, 62, 64, 38, 35, 27");
    tree_sort(a, 16);
    ARR_INCR(a, 16, "Array a now sorted");
  }

  END_TESTING();
}
