MAX holds the maximum number of vertices possible in the graph, if you want more than 100 vertices chnge the value of MAX on line 4.
The first function called in the main is the create_graph(), which creates i.e. stores every edge along with its direction present in the graph.
After this we calculate the in degree for each vertex and store it in the array indegree[i].
If for any vertex the in-degree is 0 , it signifies that all the prerequisites of that vertex are considered and it is safe to be added in the queue 
Then a loop continues till the queue is empty or count==total vertices.
Inside the loop a vertex is deleted from the queue and all the outgoing edges are considered ,as the indegree of all the destination vertices
with this particular vertex(deleted vertex) as origin is decremented by 1.
After the loop is completed it is checked if the count==total vertices.
If yes a proper topological sort obtained is printed else it can be concluded that there exists a cycle in the graph and topological sort can't
be obtained.
