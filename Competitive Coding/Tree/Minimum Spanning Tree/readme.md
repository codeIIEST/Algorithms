## Minimum spanning tree ##

A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of 
a connected, edge-weighted (un)directed graph that connects all the vertices together, 
without any cycles and with the minimum possible total edge weight.

That is, it is a spanning tree whose sum of edge weights is as small as possible.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/d/d2/Minimum_spanning_tree.svg"/>
</p>

> Properties :
* A connected graph G can have more than one spanning tree.
* All possible spanning trees of graph G, have the same number of edges and vertices.
* Removing one edge from the spanning tree will make the graph disconnected, i.e. the spanning tree is minimally connected.
* Adding one edge to the spanning tree will create a circuit or loop, i.e. the spanning tree is maximally acyclic.
* A spanning tree does not have cycles and it cannot be disconnected.

> Mathematical Properties of Spanning Tree :
* Spanning tree has n-1 edges, where n is the number of nodes (vertices).
* From a complete graph, by removing maximum e - n + 1 edges, we can construct a spanning tree.
* A complete undirected graph can have maximum n^(n-2) number of spanning trees.

> Application of Minimum spanning tree :-
* Design of networks in telephone, electrical, hydraulic, TV cable, computer, road etc.
* Cluster Analysis
* Traveling salesman problem
* Handwriting recognition

> There are two most important & famous spanning tree algorithm :
1. Kruskal's Algorithm
2. Prim's Algorithm
