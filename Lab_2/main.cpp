#include <iostream>
#include <time.h>
#include <tuple>

const size_t P = 8;
using namespace std;
using arrs = tuple<double**, double**, double**>;


/*
 * matrix addition
 *
 * @param N dimension
 * @param matrix_1 first matrix
 * @param matrix_2 second matrix
 * @param result_matrix matrix for the result
 * @return returns the result of adding two matrices
 */
double** matrix_addition(size_t N, double** matrix_1, double** matrix_2, double** result_matrix)
{

	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N; ++j)
			result_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];

	return result_matrix;
}


/*
 * matrix multiplication
 *
 * @param N dimension
 * @param matrix_1 first matrix
 * @param matrix_2 second matrix
 * @param result_matrix matrix for the result
 * @return returns the result of multiplication two matrices
 */
double** matrix_multiplication(size_t N, double** matrix_1, double** matrix_2, double** result_matrix)
{

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			for (size_t k = 0; k < N; k++)
				result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
		}
	}
	return result_matrix;
}


/*
 * matrix transposition
 *
 * @param N dimension
 * @param matrix matrix for transposition 
 * @param result_matrix matrix for the result
 * @return returns the result of matrix transposition
 */
double** matrix_transposition(size_t N, double** matrix, double** result_matrix)
{
	double temp;
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = i; j < N; ++j)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			result_matrix[i][j] = matrix[i][j];
			matrix[j][i] = temp;
			result_matrix[j][i] = matrix[j][i];
		}
	}
	return matrix;
}


/*
 * getting matrix without i row and j column
 *
 * @param matrix matrix for deliverance
 * @param p matrix for the result
 * @param i indexes
 * @param j indexes
 * @param m dimension
 * @return returns the result of adding two matrices
 */
void GetMatrix(double** matrix, double** p, int i, int j, int m) {
	short di, dj;
	di = 0;
	for (size_t ki = 0; ki < m - 1; ki++)  //check row index
	{
		if (ki == i) 
			di = 1;

		dj = 0;
		for (size_t kj = 0; kj < m - 1; kj++) //check column index
		{ 
			if (kj == j) 
				dj = 1;

			p[ki][kj] = matrix[ki + di][kj + dj];
		}
	}
}


/*
 * getting matrix determinant
 *
 * @param N dimension
 * @param matrix matrix for the result
 * @return returns matrix determinant via recursion
 */
double matrix_determinant(size_t N, double** matrix)
{
	double determinant = 0;
	double** p = new double* [N];

	for (size_t i = 0; i < N; i++)
		p[i] = new double[N];
	short j = 0, d = 0, k = 1, m; 

	m = N - 1;

	if (N < 1) 
		cout << "determinant cannot be calculated!";

	if (N == 1) 
	{
		determinant = matrix[0][0];
		return determinant;
	}

	if (N == 2) 
	{
		determinant = matrix[0][0] * matrix[1][1] - (matrix[1][0] * matrix[0][1]);
		return determinant;
	}

	if (N > 2) {
		for (size_t i = 0; i < N; i++) {
			GetMatrix(matrix, p, i, 0, N);
			determinant = determinant + k * matrix[i][0] * matrix_determinant(m, p);
			k = -k;
		}
	}

	for (size_t i = 0; i < N; ++i)
	   delete[] p[i];
	delete[] p;

	return determinant;
}


/*
 * getting 3 matrices N*N
 *
 * @param N dimension
 * @return returns 3 matrices
 */
arrs get_arrs(size_t N)
{
	double** arr_1 = new double* [N];
	double** arr_2 = new double* [N];
	double** arr_3 = new double* [N];

	for (size_t i = 0; i < N; ++i)
		arr_1[i] = new double[N];

	for (size_t i = 0; i < N; ++i)
		arr_2[i] = new double[N];

	for (size_t i = 0; i < N; ++i)
		arr_3[i] = new double[N];
	
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N; ++j)
			arr_1[i][j] = rand() % 11;

	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N; ++j)
			arr_2[i][j] = rand() % 11;

	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < N; ++j)
			arr_3[i][j] = rand() % 11;

	return { arr_1, arr_2, arr_3 };
}


/*
 * main function that describes the logic of user interaction
 *
 */
int main(void)
{
	srand(time(0));
	size_t N = 0, W = 0;
	cout << "enter a number between 1 and 8\n"; 
	cin >> N;
	do
	{
		if (N <= 0 || N > P)
		{
			cout << "enter a number between 1 and 8\n";
			cin >> N;
		}

		if (N > 0 && N <= P)
		{
			bool flag = 0;
			auto [arr_1, arr_2, arr_3] = get_arrs(N);
			cout << "enter a number between 1 and 4 where:\n1 - matrix addition\n2 - matrix multiplication\n3 - matrix transposition\n4 - matrix determinant\n";
			cin >> W;
			do
			{
				switch (W)
				{
				case 1:
				{
					double** result_matrix = matrix_addition(N, arr_1, arr_2, arr_3);
					cout << "A:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << arr_1[i][j] << " ";
						cout << "\n";
					}
					cout << "\n";
					cout << "B:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << arr_2[i][j] << " ";
						cout << "\n";
					}
					cout << "\n";
					cout << "result:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << result_matrix[i][j] << " ";
						cout << "\n";
					}
					flag = 1;
					break;
				}
				case 2:
				{
					double** result_matrix = matrix_multiplication(N, arr_1, arr_2, arr_3);
					cout << "A:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << arr_1[i][j] << " ";
						cout << "\n";
					}
					cout << "\n";
					cout << "B:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << arr_2[i][j] << " ";
						cout << "\n";
					}
					cout << "\n";
					cout << "result:\n";
					for (size_t i = 0; i < N; ++i)
					{
						for (size_t j = 0; j < N; ++j)
							cout << result_matrix[i][j] << " ";
						cout << "\n";
					}
					flag = 1;
					break;
				}
				case 3:
				{
					char R = 0;
					bool flag_ = 0;
					cout << "a or b matrix? a/b\n";
					cin >> R;
					do
					{
						if (R == "a"[0])
						{
							cout << "A:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << arr_1[i][j] << " ";
								cout << "\n";
							}
							cout << "\n";
							double** result_matrix = matrix_transposition(N, arr_1, arr_3);
							cout << "result:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << result_matrix[i][j] << " ";
								cout << "\n";
							}
							flag = 1;
						}
						else if (R == "b"[0])
						{
							cout << "B:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << arr_2[i][j] << " ";
								cout << "\n";
							}
							cout << "\n";
							double** result_matrix = matrix_transposition(N, arr_2, arr_3);
							cout << "result:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << result_matrix[i][j] << " ";
								cout << "\n";
							}
							flag = 1;
						}
						else
						{
							cout << "enter letter a or b\n";
							cin >> R;
						}

					} while ((R != "a"[0] && R != "b"[0]) || !flag);
					flag = 1;
					break;
				}
				case 4:
				{
					char R = 0;
					bool flag_ = 0;
					cout << "a or b matrix? a/b\n";
					cin >> R;
					do
					{
						if (R == "a"[0])
						{
							cout << "A:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << arr_1[i][j] << " ";
								cout << "\n";
							}
							cout << "\n";
							double determinant = matrix_determinant(N, arr_1);
							cout << "result: " << determinant << "\n";
							flag = 1;
						}
						else if (R == "b"[0])
						{
							cout << "B:\n";
							for (size_t i = 0; i < N; ++i)
							{
								for (size_t j = 0; j < N; ++j)
									cout << arr_2[i][j] << " ";
								cout << "\n";
							}
							cout << "\n";
							double determinant = matrix_determinant(N, arr_2);
							cout << "result: " << determinant << "\n";
							flag = 1;
						}
						else
						{
							cout << "enter letter a or b\n";
							cin >> R;
						}

					} while ((R != "a"[0] && R != "b"[0]) || !flag);
					flag = 1;
					break;
				}
				default:
				{
					cout << "enter a number between 1 and 4\n";
					cin >> W;
				}
				}
				
			} while ((W != 1 && W != 2 && W != 3 && W != 4) || !flag);
		}
	} 
	while (N <= 0 || N > P);

	return 0;
}