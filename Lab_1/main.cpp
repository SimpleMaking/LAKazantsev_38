#include <vector>
#include <iostream>
using namespace std;


void func_eratosf(int n)
{
	vector<float> ready_arr;
	float* curr_arr = new float[n];

	for (size_t i = 0; i <= n; ++i)  // formation of the initial arr  
		curr_arr[i] = i;

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

	for (size_t i = 0; i < ready_arr.size(); ++i) // ready data output
		cout << ready_arr[i] << " ";

	ready_arr.clear();
}


int main(void)
{
	short n = 9;  // count of numbers in the original arr
	func_eratosf(n);  // application of the algorithm                                 

	return 0;
}