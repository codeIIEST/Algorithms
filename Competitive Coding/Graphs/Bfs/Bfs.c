#include <stdio.h>
#define QUEUE_SIZE 20
#define MAX 20
int queue[QUEUE_SIZE];
int queue_front, queue_end;
void enqueue(int v);
int dequeue();
void bfs(int Adj[][MAX], int n, int source);
int main(void) {
	int Adj[][MAX] = {
		{0,1,0,0},
		{0,1,1,1},
		{1,0,0,1},
		{0,0,1,0}
	};
	int n = 4;
	int starting_vertex = 2;
	bfs(Adj, n, starting_vertex);
	return 0;
}
void bfs(int Adj[][MAX], int n, int source) {
	int i, j;
	int visited[MAX];
	queue_front = 0;
	queue_end = 0;
	for(i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
	visited[source] = 1;
	enqueue(source);
	printf("%d ", source);
	while(queue_front <= queue_end) {
		i = dequeue();
		for(j = 0; j < n; j++) {
			if(visited[j] == 0 && Adj[i][j] == 1) {
				visited[j] = 1;
				enqueue(j);
				printf("%d ", j);
			}
		}
	}
	printf("\n");
}
void enqueue(int v) {
	queue[queue_end] = v;
	queue_end++;
}
int dequeue() {
	int index = queue_front;
	queue_front++;
	return queue[index];
}
