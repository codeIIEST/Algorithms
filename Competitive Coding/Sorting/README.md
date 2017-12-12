## Sort Algorithms


### Bubble
![alt text](https://camo.githubusercontent.com/40b8099e638526dce298f8dc91246173d56e389a/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f382f38332f427562626c65736f72742d6564697465642d636f6c6f722e7376672f32323070782d427562626c65736f72742d6564697465642d636f6c6f722e7376672e706e67)

From [Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort): Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.

__Properties__
* Worst case performance	O(n^2)
* Best case performance	O(n)
* Average case performance	O(n^2)

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/bubble-sort)



### Insertion
![alt text](https://camo.githubusercontent.com/a7657e625281b63ca552a40c099c9331ce79f6a1/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f372f37652f496e73657274696f6e736f72742d6564697465642e706e67)

From [Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort): Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

__Properties__
* Worst case performance	O(n^2)
* Best case performance	O(n)
* Average case performance	O(n^2)

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/insertion-sort)


### Merge
![alt text](https://camo.githubusercontent.com/64ba2bcbd5c11779657e40a1d03d0ea691f6fa57/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f632f63632f4d657267652d736f72742d6578616d706c652d33303070782e676966)

From [Wikipedia](https://en.wikipedia.org/wiki/Merge_sort): In computer science, merge sort (also commonly spelled mergesort) is an efficient, general-purpose, comparison-based sorting algorithm. Most implementations produce a stable sort, which means that the implementation preserves the input order of equal elements in the sorted output. Mergesort is a divide and conquer algorithm that was invented by John von Neumann in 1945.

__Properties__
* Worst case performance	O(n log n)
* Best case performance	O(n)
* Average case performance	O(n)


###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/merge-sort)

### Quick
![alt text](https://camo.githubusercontent.com/2499d89bbb30337a5d2d7770cc034b4b71fbfdc6/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f362f36612f536f7274696e675f717569636b736f72745f616e696d2e676966)

From [Wikipedia](https://en.wikipedia.org/wiki/Quicksort): Quicksort (sometimes called partition-exchange sort) is an efficient sorting algorithm, serving as a systematic method for placing the elements of an array in order.

__Properties__
* Worst case performance	O(n^2)
* Best case performance	O(n log n) or O(n) with three-way partition
* Average case performance	O(n log n)

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/quick-sort)

### Selection
![alt text](https://camo.githubusercontent.com/3174db3ca6ed6da3159b4bbc18f73359f0ab33ae/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f622f62302f53656c656374696f6e5f736f72745f616e696d6174696f6e2e6769662f32353070782d53656c656374696f6e5f736f72745f616e696d6174696f6e2e676966)

From [Wikipedia](https://en.wikipedia.org/wiki/Selection_sort): The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.

__Properties__
* Worst case performance	O(n^2)
* Best case performance	O(n^2)
* Average case performance	O(n^2)

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/selection-sort)

### Shell
![alt text](https://camo.githubusercontent.com/e80043bbd0ce86517a91198be315740504c6980e/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f642f64382f536f7274696e675f7368656c6c736f72745f616e696d2e676966)

From [Wikipedia](https://en.wikipedia.org/wiki/Shellsort):  Shellsort is a generalization of insertion sort that allows the exchange of items that are far apart.  The idea is to arrange the list of elements so that, starting anywherem considereing every nth element gives a sorted list.  Such a list is said to be h-sorted.  Equivanelty, it can be thought of as h intterleaved lists, each individually sorted.

__Properties__
* Worst case performance O(nlog2 2n)
* Best case performance O(n log n)
* Average case performance depends on gap sequence

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/shell-sort)

### Heap
![](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)

From [Wikipedia](https://en.wikipedia.org/wiki/Heapsort):  Heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: like that algorithm, it divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. The improvement consists of the use of a heap data structure rather than a linear-time search to find the maximum.

__Properties__
* Worst case performance O(n log n)
* Best case performance O(n log n)
* Average case performance O(n log n)

###### View the algorithm in [action](https://www.toptal.com/developers/sorting-algorithms/heap-sort)

### Radix
From [Wikipedia](https://en.wikipedia.org/wiki/Radix_sort): Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. A positional notation is required, but because integers can represent strings of characters (e.g., names or dates) and specially formatted floating point numbers, radix sort is not limited to integers. Radix sort dates back as far as 1887 to the work of Herman Hollerith on tabulating machines.

__Properties__
* Worst case performance O(wn)
* Best case performance O(w + N)
* Average case performance depends on gap sequence

### Counting
From [Wikipedia](https://en.wikipedia.org/wiki/Counting_sort): Counting sort is an algorithm for sorting a collection of objects according to keys that are small integers; that is, it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value(k: max key value), and using arithmetic on those counts to determine the positions of each key value in the output sequence.

__Properties__
* Worst case performance O(n + k)
* Best case performance O(n + k)
* Average case performance O(n + k)

### Time-Compexity Graphs

Comparing the complexity of sorting algorithms (Bubble Sort, Insertion Sort, Selection Sort)

[Complexity Graphs](https://github.com/prateekiiest/Python/blob/master/sorts/sortinggraphs.png)
