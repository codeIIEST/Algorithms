//C++ code to find a pattern in a given text using KMP algorithm in linear time.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string text;
	string pattern;

	cin>>text;//inputting text	
	cout<<endl;

	cin>>pattern;//inputting pattern
	cout<<endl;

	int pattern_length=pattern.size();//variable to store length of pattern string
	int text_length=text.size();//variable to store length of text string     

	if(pattern_length>text_length)//if pattern_length is greater than text it is not possible to find pattern in text.
	{
		cout<<"Not Found"<<endl;
		exit(0);
	}

	int temp[pattern_length];//i th element in the temp array will store the length of the longest suffix which is equal to the prefix in pattern array upto i th index.

	int i=1,j=0;

	/*Suppose the patteren is ababa then temp[4] would store value 3 as the length of longest prefix(aba) which is equal 
	to the longest suffix(aba) is 3 upto 4 th index in the pattern.The entire temp array would look like 0 0 1 2 3.*/
	temp[0]=0;
	while(i<pattern_length)//Building the temp array.
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
/*Suppose our text is abacd and our pattern is abad.During our first mismatch that is at d(j=3)in pattern and c(i=3)in text,
unlike the naive string search we won't start again from i=1 in text and j=0 in pattern instead we look in temp[2] which will
have value 1 and we set j to 1 and we will again start doing search from i=3 and j=1.*/
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
