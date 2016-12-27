---

## Sorting

date: 2016-12-27 08:28:45

- [ ] Notes:
    - Implement sorts & know best case/worst case, average complexity of each:
        - no bubble sort - it's terrible - O(n^2), except when n <= 16
    - [ ] stability in sorting algorithms ("Is Quicksort stable?")
        - [Sorting Algorithm Stability](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability)
        - [Stability In Sorting Algorithms](http://stackoverflow.com/questions/1517793/stability-in-sorting-algorithms)
        - [Stability In Sorting Algorithms](http://www.geeksforgeeks.org/stability-in-sorting-algorithms/)
        - [Sorting Algorithms - Stability](http://homepages.math.uic.edu/~leon/cs-mcs401-s08/handouts/stability.pdf)
    - [ ] Which algorithms can be used on linked lists? Which on arrays? Which on both?
        - I wouldn't recommend sorting a linked list, but merge sort is doable.
        - [Merge Sort For Linked List](http://www.geeksforgeeks.org/merge-sort-for-linked-list/)

- For heapsort, see Heap data structure above. Heap sort is great, but not stable.

- [ ] [Bubble Sort (video)](https://www.youtube.com/watch?v=P00xJgWzz2c&index=1&list=PL89B61F78B552C1AB)
- [ ] [Analyzing Bubble Sort (video)](https://www.youtube.com/watch?v=ni_zk257Nqo&index=7&list=PL89B61F78B552C1AB)
- [ ] [Insertion Sort, Merge Sort (video)](https://www.youtube.com/watch?v=Kg4bqzAqRBM&index=3&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
- [ ] [Insertion Sort (video)](https://www.youtube.com/watch?v=c4BRHC7kTaQ&index=2&list=PL89B61F78B552C1AB)
- [ ] [Merge Sort (video)](https://www.youtube.com/watch?v=GCae1WNvnZM&index=3&list=PL89B61F78B552C1AB)
- [ ] [Quicksort (video)](https://www.youtube.com/watch?v=y_G9BkAm6B8&index=4&list=PL89B61F78B552C1AB)
- [ ] [Selection Sort (video)](https://www.youtube.com/watch?v=6nDMgr0-Yyo&index=8&list=PL89B61F78B552C1AB)

- [ ] Stanford lectures on sorting:
    - [ ] [Lecture 15 | Programming Abstractions (video)](https://www.youtube.com/watch?v=ENp00xylP7c&index=15&list=PLFE6E58F856038C69)
    - [ ] [Lecture 16 | Programming Abstractions (video)](https://www.youtube.com/watch?v=y4M9IVgrVKo&index=16&list=PLFE6E58F856038C69)

- [ ] Shai Simonson, [Aduni.org](http://www.aduni.org/):
    - [ ] [Algorithms - Sorting - Lecture 2 (video)](https://www.youtube.com/watch?v=odNJmw5TOEE&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=2)
    - [ ] [Algorithms - Sorting II - Lecture 3 (video)](https://www.youtube.com/watch?v=hj8YKFTFKEE&list=PLFDnELG9dpVxQCxuD-9BSy2E7BWY3t5Sm&index=3)

- [ ] Steven Skiena lectures on sorting:
    - [ ] [lecture begins at 26:46 (video)](https://youtu.be/ute-pmMkyuk?list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&t=1600)
    - [ ] [lecture begins at 27:40 (video)](https://www.youtube.com/watch?v=yLvp-pB8mak&index=8&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
    - [ ] [lecture begins at 35:00 (video)](https://www.youtube.com/watch?v=q7K9otnzlfE&index=9&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b)
    - [ ] [lecture begins at 23:50 (video)](https://www.youtube.com/watch?v=TvqIGu9Iupw&list=PLOtl7M3yp-DV69F32zdK7YJcNXpTunF2b&index=10)

- [ ] UC Berkeley:
    - [ ] [CS 61B Lecture 29: Sorting I (video)](https://www.youtube.com/watch?v=EiUvYS2DT6I&list=PL4BBB74C7D2A1049C&index=29)
    - [ ] [CS 61B Lecture 30: Sorting II (video)](https://www.youtube.com/watch?v=2hTY3t80Qsk&list=PL4BBB74C7D2A1049C&index=30)
    - [ ] [CS 61B Lecture 32: Sorting III (video)](https://www.youtube.com/watch?v=Y6LOLpxg6Dc&index=32&list=PL4BBB74C7D2A1049C)
    - [ ] [CS 61B Lecture 33: Sorting V (video)](https://www.youtube.com/watch?v=qNMQ4ly43p4&index=33&list=PL4BBB74C7D2A1049C)

- [ ] - Merge sort code:
    - [ ] [Using output array](http://www.cs.yale.edu/homes/aspnes/classes/223/examples/sorting/mergesort.c)
    - [ ] [In-place](https://github.com/jwasham/practice-cpp/blob/master/merge_sort/merge_sort.cc)
- [ ] - Quick sort code:
    - [ ] [Implementation](http://www.cs.yale.edu/homes/aspnes/classes/223/examples/randomization/quick.c)
    - [ ] [Implementation](https://github.com/jwasham/practice-c/blob/master/quick_sort/quick_sort.c)

- [ ] Implement:
    - [ ] Mergesort: O(n log n) average and worst case
    - [ ] Quicksort O(n log n) average case
    - Selection sort and insertion sort are both O(n^2) average and worst case
    - For heapsort, see Heap data structure above.

- [ ] For curiosity - not required:
    - [ ] [Radix Sort](http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html#radixSort)
    - [ ] [Radix Sort (video)](https://www.youtube.com/watch?v=xhr26ia4k38)
    - [ ] [Radix Sort, Counting Sort (linear time given constraints) (video)](https://www.youtube.com/watch?v=Nz1KZXbghj8&index=7&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
    - [ ] [Randomization: Matrix Multiply, Quicksort, Freivalds' algorithm (video)](https://www.youtube.com/watch?v=cNB2lADK3_s&index=8&list=PLUl4u3cNGP6317WaSNfmCvGym2ucw3oGp)
    - [ ] [Sorting in Linear Time (video)](https://www.youtube.com/watch?v=pOKy3RZbSws&list=PLUl4u3cNGP61hsJNdULdudlRL493b-XZf&index=14)
    
    
Author : Prateek Chanda

---

