#include <stdio.h>
#include <stdlib.h>

/* Macros to get the index of left and right children
 * of node 'i'. Indexing starts with 0 */

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)


void max_heapify(int *arr, int n, int i) {

	int largest, right, left;

	largest = i;
	right = RIGHT(i);
	left = LEFT(i);

	/* Find largest among arr[i], arr[right]
	 * and arr[left]. Then swap */
	if(left < n && arr[largest] < arr[left])
		largest = left;
	if(right < n && arr[largest] < arr[right])
		largest = right;

	if(largest!=i) {
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;

		/* Recursive call to fix possibly violated subtree */
		max_heapify(arr, n, largest);
	}
}

void build_max_heap(int *arr, int n) {

	int i;

	/* Loop goes from n/2 down to 0 because
	 * last n/2 nodes are leaves */
	for(i=n/2; i>=0; --i)
		max_heapify(arr, n, i);
}

void heap_sort(int *arr, int n) {

	int i;
	build_max_heap(arr, n);

	/* Swap root node with last node
	 * and decrement size */
	for(i=n-1; i>=0; --i) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		/* Note : i itself behaves as the size of arr */
		max_heapify(arr, i, 0);
	}
}

int main() {

	int i, n;

	int arr[] = { 56, -45, 235, 146, -85, 0};
	n = sizeof(arr)/sizeof(int);

	heap_sort(arr, n);

	printf("Sorted : ");
	for(i=0; i<n; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
