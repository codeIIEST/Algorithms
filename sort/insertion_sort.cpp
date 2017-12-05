#include<iostream>
using namespace std;

int main(){
  int size;
  cout<<"enter the size of array :";
  cin>>size;
  int arr[size];
  cout<<"enter the array elments :";
  for(int i = 0; i < size; i++)
    cin>>arr[i];
   
  //insertion sort
  for(int i = 0; i < size-1; i++){
    if(arr[i] > arr[i+1]){
      int temp = arr[i+1];
      int j = i;
      while(temp < arr[j] && j >= 0){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = temp;
    }
  }

  cout<<"array after sorting is :";
  for(int i = 0; i < size; i++)
    cout<<arr[i]<<" ";
}
