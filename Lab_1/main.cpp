#include <vector>
#include <iostream>
using namespace std;


vector<float> func_eratosf(int n, float* curr_arr, vector<float> ready_arr)
{
	size_t i = 2, j = 0;
	while (i < pow(n, 0.5))         // проходим до половины исходного массива по первому итератору
	{
		if (curr_arr[i] != 0)         // если элемент еще есть в исходном массиве 
		{
			j = pow(i, 2);              // на первой итерации мы избавляемся от всех четных чисел, кроме 2,
			                              //а уже на последующих от всех остальных не простых
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
	short n = 9; // колличество чисел в исходном массиве

	float* curr_arr = new float[n];
	for (size_t i = 0; i <= n; ++i)  // формирование начального массива  
		curr_arr[i] = i;

	curr_arr[1] = 0;              // применение алгоритма                                   
	ready_arr = func_eratosf(n, curr_arr, ready_arr); 

	for (size_t i = 0; i < ready_arr.size(); ++i) // вывод готовых данных 
		cout << ready_arr[i] << " ";

	return 0;
}