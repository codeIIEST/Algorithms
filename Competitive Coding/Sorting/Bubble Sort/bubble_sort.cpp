/* Part of Cosmos by OpenGenus Foundation */
#include <iostream>
#include <vector>
#include <algorithm>

void bubble_sort(std::vector<int> &v)
{
	for(int i=0; i < v.size(); ++i)
		for(int j=i+1; j < v.size(); ++j)
		{
			if (v[i] > v[j])
				std::swap(v[i],v[j]);
		}
}
int main()
{
	std::vector<int> input_array;
	std::cout<<"Enter the number of items in the array: ";
	int array_size;
	std::cin>>array_size;
	for(int i=0;i<array_size;i++){
		int input_number;
		std::cin>>input_number;
		input_array.push_back(input_number);
	}
	bubble_sort(input_array);
	for(auto x :input_array)
		std::cout<<x<<" ";
	std::cout<<"\n";
	return 0;
}
