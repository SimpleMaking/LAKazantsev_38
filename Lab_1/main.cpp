#include <vector>
#include <iostream>
using namespace std;


vector<float> func_eratosf(int n, float* curr_arr, vector<float> ready_arr)
{
	size_t i = 2, j = 0;
	while (i < pow(n, 0.5))         // �������� �� �������� ��������� ������� �� ������� ���������
	{
		if (curr_arr[i] != 0)         // ���� ������� ��� ���� � �������� ������� 
		{
			j = pow(i, 2);              // �� ������ �������� �� ����������� �� ���� ������ �����, ����� 2,
			                              //� ��� �� ����������� �� ���� ��������� �� �������
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
	short n = 9; // ����������� ����� � �������� �������

	float* curr_arr = new float[n];
	for (size_t i = 0; i <= n; ++i)  // ������������ ���������� �������  
		curr_arr[i] = i;

	curr_arr[1] = 0;              // ���������� ���������                                   
	ready_arr = func_eratosf(n, curr_arr, ready_arr); 

	for (size_t i = 0; i < ready_arr.size(); ++i) // ����� ������� ������ 
		cout << ready_arr[i] << " ";

	return 0;
}