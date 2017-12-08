## Search Algorithms

### Linear
![alt text](https://camo.githubusercontent.com/c05ad3f2178af2f16ebe2c04eb122e1e0c6a055b/687474703a2f2f7777772e7475746f7269616c73706f696e742e636f6d2f646174615f737472756374757265735f616c676f726974686d732f696d616765732f6c696e6561725f7365617263682e676966)

From [Wikipedia](https://en.wikipedia.org/wiki/Linear_search): linear search or sequential search is a method for finding a target value within a list. It sequentially checks each element of the list for the target value until a match is found or until all the elements have been searched.
  Linear search runs in at worst linear time and makes at most n comparisons, where n is the length of the list.

__Properties__
* Worst case performance	O(n)
* Best case performance	O(1)
* Average case performance	O(n)
* Worst case space complexity	O(1) iterative

### Binary
![alt text](https://camo.githubusercontent.com/1cd853b57885449a176810b3e967167fb9fbf3b3/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f662f66372f42696e6172795f7365617263685f696e746f5f61727261792e706e67)

From [Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm): Binary search, also known as half-interval search or logarithmic search, is a search algorithm that finds the position of a target value within a sorted array. It compares the target value to the middle element of the array; if they are unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful.

__Properties__
* Worst case performance	O(log n)
* Best case performance	O(1)
* Average case performance	O(log n)
* Worst case space complexity	O(1) 

### Interpolation
Interpolation search is an improved version of binary search algorithm.

![alt text](https://qph.ec.quoracdn.net/main-qimg-02f1f050de01608b9b1f2f27155d1b17)

Even when the data is sorted, binary search does not take advantage of that to probe the position of desired data.
Position Probing in Interpolation 
SearchInterpolation search search a particular item by computing the probe position. Initially probe position is the position of the middle most item of the collection.If middle item is greater than item then probe position is again calculated in the sub-array to the right of the middle item other wise item is search in sub-array to the left of the middle item. This process continues on sub-array as well until the size of subarray reduces to zero.


__Properties__
* Worst case performance O(n)
* Best case performance O(1)
* Average case performance O(log(logn))
* Worst case space cmplexity O(1)
