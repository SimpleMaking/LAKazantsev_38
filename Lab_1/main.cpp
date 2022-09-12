#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
	vector<float> arr;
	short n = 100; // колличество чисел 
	float* curr_arr = new float[n];
	for (size_t i = 0; i <= n; ++i)
		curr_arr[i] = i;

	curr_arr[1] = 0;
	size_t i = 2, j = 0;
	while (i < pow(n, 0.5))
	{
		if (curr_arr[i] != 0)
		{
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
			arr.push_back(curr_arr[i]);

	for (size_t i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";

	return 0;
}