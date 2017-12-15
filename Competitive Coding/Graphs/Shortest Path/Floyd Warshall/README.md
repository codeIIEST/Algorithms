## Floyd–Warshall algorithm
An algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles). A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between all pairs of vertices.

------------------------------
![](https://ds055uzetaobb.cloudfront.net/image_optimizer/bec3c44826d7cab9b828f339e4844b5a09df5fce.png)

  ### Algorithm

  If w(i,j) is the weight of the edge between
  vertices i and j, we can define shortestPath (i,j,k) in terms of the following recursive formula: the base case is  shortestPath   (i,j,0)=w(i,j) and the recursive case is  shortestPath (i,j,k) =  min( shortestPath (i,j,k-1), shortestPath (i,k,k-1)+ shortestPath (k,j,k-1)).
  This formula is the heart of the Floyd–Warshall algorithm. The algorithm works by first computing shortestPath (i,j,k) for all (i,j) pairs for  k=1, then  k=2, etc. This process continues until k=N, and we have found the shortest path for all (i,j) pairs using any intermediate vertices.

----------------------------
### Performance Analysis
* Worst-case performance	 O(|V|^3)
* Best-case performance	   O(|V|^3)
* Average performance	     O(|V|^3)
