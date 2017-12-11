#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>&act1, const pair<int,int>&act2){
  return act1.second <= act2.second;
}

void act_select(pair<int,int>act[], int n){

  cout<<"("<<act[0].first<<" "<<act[0].second<<") "; //first activity always gets selected

  //to select rest of the activites the start time of the next activity must be greater than or equal to the final time of last selected activity
  int j = 0;
   for(int i = 1; i < n; i++){
     if(act[i].first >= act[j].second){
       cout<<"("<<act[i].first<<" "<<act[i].second<<") ";
       j = i;  
    }
  }
}


int main(){
  int n,start,finish;
  cout<<"enter the total no. of activites:"<<endl;
  cin>>n;
  pair<int,int>act[n];

  //enter the activites with their start and end time
  for(int i = 0; i < n; i++){
    cin>>start>>finish;
    act[i] = {start, finish};
  }

  //function to sort the activities according to their final time
  sort(act, act + n, compare);

  cout<<"the selected activities are : "<<endl;
  //function to calculate maximum no. of activities which can be performed and a vector to store the activities
   act_select(act,n);

}

