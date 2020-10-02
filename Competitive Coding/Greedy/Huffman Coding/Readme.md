Python Implementation of Huffman Coding using Greedy Approach.
Huffman Coding is a technique of compressing data to reduce its size without loss of data. It is generally useful to compress the data in which there are frequently occurring characters.
It follows a Greedy approach since it deals with generating minimum length prefix-free binary codes.
It uses variable-length encoding scheme for assigning binary codes to characters depending on how frequently they occur in the given text.
Priority Queue is used for building the Huffman tree such that the character that occurs most frequently is assigned the smallest code and the one that occurs least frequently gets the largest code.
It follows this procedure: -

Create a leaf node for each character and build a min heap using all the nodes (The frequency value is used to compare two nodes in min heap)

Repeat Steps 3 to 5 while heap has more than one node

Extract two nodes, say x and y, with minimum frequency from the heap

Create a new internal node z with x as its left child and y as its right child. Also frequency(z)= frequency(x)+frequency(y)

Add z to min heap

Last node in the heap is the root of Huffman tree
