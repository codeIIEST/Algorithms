Topological sort
    In this code the main functions are create_graph() and find_indegree_of_vertex(int vertex). In the adjacent_matrix the[i][j] term 
is 1 if edge exists from i directed to j else the value is 0 (if such edge doeds not exist).The array indegree[i] contains the number of 
edges that are incoming in vertex i.When indegree[i]=0, signifies that all the prerequisites for the ith vertex are fulfilled and it is thus
added in the queue using the add function. Array topological_sort[] holds the reqired answer. If the count reaches the number of vertices ,
it indicates that a proper topological sort is obtained or else there exists a cycle in the graph in which case a topological sort is not 
possible.
