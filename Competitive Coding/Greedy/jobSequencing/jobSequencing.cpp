#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
	char title;
	int dead;
	int profit;
};

bool compare(job a,job b)
{
	return (a.profit > b.profit);
}

int main()
{
	int n;
	printf("Example Input:\n");
	printf("4\n");
	printf("a 4 20\n");
	printf("b 1 10\n");
	printf("c 1 40\n");
	printf("d 1 30\n");
	printf("Enter no of activities\n");
	cin>>n;
	job j[n];
	printf("Enter\n");
	printf("JobID  Deadline  Profit\n");
	for(int i=0;i<n;i++)			//user input
	{
		cin>>j[i].title;
		cin>>j[i].dead;
		cin>>j[i].profit;
	}
	sort(j,j+n,compare);
	printf("Max sequence of jobs is\n");

	cout<<j[0].title<<" ";			//selecting the first job with highest profit
	int count=1;					//count of number of jobs completed
	for(int i=1;i<n;i++)			//look for other jobs within the timeline
	{
		if(j[i].dead > count)		//If current job can be accocmodated take it
		{
			cout<<j[i].title<<" ";
			count++;
		}
	}
	return 0;
}
