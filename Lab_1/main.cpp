#include <vector>
#include <iostream>
using namespace std;


vector<float> func_eratosf(int n, float* curr_arr, vector<float> ready_arr)
{
	size_t i = 2, j = 0;
	while (i < pow(n, 0.5))         // iterate up to half of the original arr by the first iterator
	{
		if (curr_arr[i] != 0)         // if the element is still in the original arr 
		{
			j = pow(i, 2);              // on the first itter: all even numbers except 2
			                              // on all remain: all non-prime numbers
			while (j <= n)
			{
				curr_arr[j] = 0;
				j = j + i;
			}
		}
		i = i + 1;

	}
	for (size_t i = 0; i < n; ++i) 
		if (curr_arr[i] != 0)
			ready_arr.push_back(curr_arr[i]);
	
	return ready_arr;
}


int main(void)
{
	vector<float> ready_arr;
	short n = 9; // count of numbers in the original arr

	float* curr_arr = new float[n];
	for (size_t i = 0; i <= n; ++i)  // formation of the initial arr  
		curr_arr[i] = i;

	curr_arr[1] = 0;              // application of the algorithm                                 
	ready_arr = func_eratosf(n, curr_arr, ready_arr); 

	for (size_t i = 0; i < ready_arr.size(); ++i) // ready data output
		cout << ready_arr[i] << " ";
    
	ready_arr.clear();
	
	return 0;
}