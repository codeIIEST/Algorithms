#include<iostream>
using namespace std;

int main(){
  int size;
  cout<<"Enter the size of Array :"<<endl;
  cin>>size;
  int arr[size];
  cout<<"Enter the Array Elements :"<<endl;
  for(int i = 0; i < size; i++)
    cin>>arr[i];
  
  //selection sort algo
  for(int i = 0; i < size-1; i++){
    for(int j = i+1; j < size; j++){
      if(arr[i] > arr[j]){
        //swap the elements
        int temp =  arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  cout<<"The Array after sorting : ";
  for(int i = 0; i < size; i++)
    cout<<arr[i]<<" ";

}
