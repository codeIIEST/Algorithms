#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* Algo :
bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
.......a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.
*/

// Generally used for floating point numbers.


void bucketSort(float a[],int n){
vector<float> buckets[n];
int i,j;
for(i=0;i<n;i++){
    buckets[(int)(n*a[i])].push_back(a[i]);
}
for(i=0;i<n;i++){
    sort(buckets[i].begin(),buckets[i].end());
}
int index=0;
for(i=0;i<n;i++){
    for(j=0;j<buckets[i].size();j++){
        a[index++]=buckets[i][j];
    }
}

}



//-------------------------------print function
void print(float *a,int n){
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "<<endl;
}

int main(){
float a[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
int n = sizeof(a)/sizeof(float);
bucketSort(a,n);
print(a,5);
return 0;
}

