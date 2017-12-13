## Documentation for HeapSort
* Heap sort is a comparison based sorting technique based on Binary Heap data structure.
* Heapsort is an in-place algorithm, but it is not a stable sort.
* Heap Sort is one of the best sorting methods being in-place and with no quadratic worst-case scenarios.
* In max-heaps, maximum element will always be at the root. Heap Sort uses this property of heap to sort the array.

Heap sort algorithm is divided into two basic parts :

* Creating a Heap of the unsorted list.

* Then a sorted array is created by repeatedly removing the largest/smallest element from the heap, and inserting it into the array.

* The heap is reconstructed after each removal.

### Complexity of HeapSort

Here, Time complexity of heapify is O(logn) and time complexity of BUILD-MAX-HEAP(A) is O(n) and we run max_heapify N−1 times in heap_sort function, therefore complexity of heap_sort function in each case (Best, worst and average) is O(nlogn).

* Time Complexity: O(nlogn)

* Space Complexity: O(1)

<img align="center" src="https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif">
