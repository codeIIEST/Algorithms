#include<bits/stdc++.h>

using namespace std;

void printArray (int arg[], int length) {
  for (int n = 0; n < length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

void selectionSort(int array [], int size){
    for (int i = 0; i < size -1; i++) {
			int less = i;
			for (int j = i + 1; j < size; j++) {
				if (array[less] > array[j]) {
					less = j;
				}
			}
			
            int aux = array[i];
		    array[i] = array[less];
	        array[less] = aux;
		}
    printArray(array,size);
}

int main(){
    int array[] = {7,5,1,10,2};
    int size = sizeof(array) / sizeof(array[0]);
    selectionSort(array, size);
    
}

