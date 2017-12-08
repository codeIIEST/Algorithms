#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100
 
void create_graph();
void add(int vertex);
int del();
int isEmpty();
int find_indegree_of_vertex(int vertex);
 
int total_vertices;
int adjacent_matrix[MAX][MAX];
int queue[MAX];
int front = -1;
int rear = -1;
 
int main()
{
	int i, vertex, count, topological_sort[MAX], indegree[MAX];
	create_graph();
	for(i = 0; i < total_vertices; i++)
	{
		indegree[i] = find_indegree_of_vertex(i);
		if(indegree[i] == 0)
		{
			add(i);
		}
	}
	count = 0;
	while(!isEmpty() && count < total_vertices)
	{
		vertex = del();
    		topological_sort[++count] = vertex;
		for(i = 0; i < total_vertices; i++)
		{
			if(adjacent_matrix[vertex][i] == 1)
			{
				adjacent_matrix[vertex][i] = 0;
				indegree[i] = indegree[i] - 1;
				if(indegree[i] == 0)
				{
					add(i);
				}
			}
		}
	}
	if(count < total_vertices)
	{
		printf("Graph is Cyclic. Therefore, Topological Ordering Not Possible\n");
		exit(1);
	}
	printf("Topological Order of Vertices\n");
	for(i = 1; i <= count; i++)
	{
		printf("%3d", topological_sort[i]);
	}
	printf("\n");
	return 0;
}
 
void add(int vertex)
{
	if(rear == MAX - 1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		if (front == -1) 
		{
			front = 0;
		}
		rear = rear + 1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty()
{
	if(front == -1 || front > rear )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
int del()
{
	int element;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	else
	{
		element = queue[front];
		front = front+1;
		return element;
	}
}
 
int find_indegree_of_vertex(int vertex)
{
	int count, total_indegree = 0;
	for(count = 0; count < total_vertices; count++)
	{
		if(adjacent_matrix[count][vertex] == 1)
		{
			total_indegree++;
		}
	}
	return total_indegree;
}
 
void create_graph()
{
	int count, maximum_edges, origin_vertex, destination_vertex;
	printf("Enter number of vertices:\t");
	scanf("%d", &total_vertices);
	maximum_edges = total_vertices * (total_vertices - 1);
	for(count = 1; count <= maximum_edges; count++)
	{
		printf("Enter Edge [%d] co-ordinates (-1 -1 to quit)\n", count);
		printf("Enter Origin Vertex:\t");
		scanf("%d", &origin_vertex);
		printf("Enter Destination Vertex:\t");
		scanf("%d", &destination_vertex);
		if((origin_vertex == -1) && (destination_vertex == -1))
		{
			break;
		}
		if(origin_vertex >= total_vertices || destination_vertex >= total_vertices || origin_vertex < 0 || destination_vertex < 0)
		{
			printf("Edge Co-ordinates are Invalid\n");
			count--;
		}
		else
			adjacent_matrix[origin_vertex][destination_vertex] = 1;
	}
}
