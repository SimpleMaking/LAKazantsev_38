#include <vector>
#include <iostream>
using namespace std;


/*
 * algorithm of the sieve of Eratosthene with subsequent display of elements on the screen
 *
 * @param n count of elements in initial arr.
 */

void func_eratosf(int n)
{
	vector<float> ready_arr;
	float* curr_arr = new float[n];

	// formation of the initial arr  
	for (size_t i = 0; i <= n; ++i)  
		curr_arr[i] = i;

	size_t i = 2, j = 0;
	// iterate up to half of the original arr by the first iterator
	while (i < pow(n, 0.5))         
	{
		// if the element is still in the original arr 
		if (curr_arr[i] != 0)        
		{
			// on the first itter: all even numbers except 2
			// on all remain: all non-prime numbers
			j = pow(i, 2);              
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

	// ready data output
	for (size_t i = 0; i < ready_arr.size(); ++i) 
		cout << ready_arr[i] << " ";

	ready_arr.clear();
}


int main(void)
{
	// count of numbers in the original arr
	short n = 29;  
	// call function of the algorithm         
	func_eratosf(n);                         

	return 0;
}