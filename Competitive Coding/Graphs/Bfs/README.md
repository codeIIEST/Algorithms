----------------------------------------------------------------------------------------------------------------------
##  search Algorithm for Graphs

### Breadth First Search Algorithm
### From [Wikipedia](https://en.wikipedia.org/wiki/Breadth-first_search):
Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures.<br>
It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes first, before moving to the next level neighbours.A queue is used in this method to search for the nodes in the tree.<br>
[visualize Bfs algorithm](https://www.cs.usfca.edu/~galles/visualization/BFS.html)
<br>
__Time Complexity__
It is correct to say that the complexity is O(V+E). Consider the case where the number of edges is way smaller than the number of vertices, i.e., E=o(V). As always, BFS will visit every vertex for each component. Here O(V+E)≠O(E).

The take home message is that for sparse graph, O(V+E) is not the same as O(E). In all other cases, you can safely assume that the complexity of BFS is O(E).
