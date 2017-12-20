## Bellman Ford Algorithm

#### Description
This is a dynamic programming based algorithm, this algorithm gives shortest distance from a particular source in a graph to all its other vertices.

---------
![](http://users.informatik.uni-halle.de/~jopsi/dssea/bellman_ford.gif)

-----------
#### Working
We initialize the distance of source as '0' and all other vertices as 'INFINITE'. Now if the number of vertices in a graph is 'V' , then all the vertices are processed 'V-1' times, at each iteration for an edge 'uv' if 'dist[v]>dist[u]+weight of uv' , then update dist[v]=dist[u]+weight of uv.

[More info](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
