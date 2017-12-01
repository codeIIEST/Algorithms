//C++ code to find a pattern in a given text using KMP algorithm in linear time.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string text;
	string pattern;

	cout<<"Enter the text : ";//inputting text
	cin>>text;
	cout<<endl;

	cout<<"Enter the pattern : ";//inputting pattern
	cin>>pattern;
	cout<<endl;

	int pattern_length=pattern.size();//variable to store length of pattern string
	int text_length=text.size();//variable to store length of text string     

	if(pattern_length>text_length)
	{
		cout<<"Not Found"<<endl;
		exit(0);
	}

	int temp[pattern_length];//i th element in the temp array will store the length of the longest suffix which is equal to the prefix in pattern array upto i th position

	int i=1,j=0;

	temp[0]=0;
	while(i<pattern_length)
	{
		if(pattern[i]==pattern[j])
		{
			temp[i]=j+1;
			i++;
			j++;
		}
		else if(pattern[i]!=pattern[j] && j==0)
		{
			temp[i]=0;
			i++;
		}
		else
		{
			j=temp[j-1];
		}
	}

	i=0;
	j=0;

	while(j<pattern_length && i<text_length)  //implementing the KMP alogorithm
	{
		if(pattern[j]==text[i])
		{
				j++;
				i++;
		}
		else if(pattern[j]!=text[i] && j==0)
		{
			i++;
		}
		else
		{
			j=temp[j-1];
		}
	}

	if(j==pattern_length)
		cout<<"Match Found and the starting index is "<<i-pattern_length<<endl;
	else 
		cout<<"Not Found"<<endl;

	return 0;
}