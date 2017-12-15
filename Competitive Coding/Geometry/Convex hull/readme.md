# Convex Hull (Jarvis March)

Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.

![alt text](http://www.geeksforgeeks.org/wp-content/uploads/convexHull1.png)

The idea of Jarvis’s Algorithm is simple, we start from the leftmost point (or point with minimum x coordinate value) and we keep wrapping points in counterclockwise direction. 
The big question is, given a point p as current point, how to find the next point in output? The idea is to use orientation() here.
Next point is selected as the point that beats all other points at counterclockwise orientation, i.e., next point is q if for any other point r, we have “orientation(p, r, q) = counterclockwise”. Following is the detailed algorithm.

1) Initialize p as leftmost point.
2) Do following while we don’t come back to the first (or leftmost) point.
…..a) The next point q is the point such that the triplet (p, q, r) is counterclockwise for any other point r.
…..b) next[p] = q (Store q as next of p in the output convex hull).
…..c) p = q (Set p as q for next iteration).

The below Gif may help:

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9c/Animation_depicting_the_gift_wrapping_algorithm.gif/330px-Animation_depicting_the_gift_wrapping_algorithm.gif)