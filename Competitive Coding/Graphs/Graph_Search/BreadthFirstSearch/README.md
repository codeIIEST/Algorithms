## Breadth-first search (BFS)
 An algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes first, before moving to the next level neighbours.

--------------------
![](https://upload.wikimedia.org/wikipedia/commons/4/46/Animated_BFS.gif)

--------------------
This is the algorithm for Breadth First Search in a given graph.

* We take a starting vertex , and push all its adjacent vertexes in a queue.
* Now we pop an element from a queue and push all its vertexes in the queue , and we also mark down these vertexes as visited.
* After executing the code, we will get the vertex visited in a breadth first manner.

Some Common Applications of BFS are:

1.GPS Navigation systems: Navigation systems such as the Google Maps, which can give directions to reach from one place to another use BFS. They take your location to be the source node and your destination as the destination node on the graph. (A city can be represented as a graph by taking landmarks as nodes and the roads as the edges that connect the nodes in the graph.) BFS is applied and the shortest route is generated which is used to give directions or real time navigation.
2.Computer Networks: Peer to peer (P2P) applications such as the torrent clients need to locate a file that the client (one who wants to download the file) is requesting. This is achieved by applying BFS on the hosts (one who supplies the file) on a network. Your computer is the host and it keeps traversing through the network to find a host for the required file (maybe your favourite movie).
3.Facebook: It treats each user profile as a node on the graph and two nodes are said to be connected if they are each other's friends. Infact, apply BFS on the facebook graph and you will find that any two people are connected with each other by atmost five nodes in between. To say, that you can reach any random person in the world by traversing 5 nodes in between. (I did not run BFS on facebook graph, it is a well known fact). What do you think is the new facebook "Graph Search"? (It is not directly BFS, but a lot of modifications over classic graph search algorithms.)
4.Web Crawlers: It is quite an interesting application. They can be used to analyze what all sites you can reach by following links randomly on a particular website. (Even if you are mildly interested, look into it. It is fun).


[More info](https://en.wikipedia.org/wiki/Breadth-first_search)
