#include "Main_Header.h"


NumberDivisors::NumberDivisors(int number) : number(number)
{
	for (size_t i = 1; i <= number; ++i)
	{
		if (number % i == 0)
		{
			divisor_list.push_back(i);
		}	
	}
}


bool NumberDivisors::divCounter(size_t number)
{
	int count_of_elems = count_if(divisor_list.begin(), divisor_list.end(), [number](int vector_div) {return number == vector_div;});
	return count_of_elems > 0;
}


double NumberDivisors::averageValue()
{
	size_t sum = std::accumulate(divisor_list.begin(), divisor_list.end(), 0);
	return sum / (double)divisor_list.size();
}


void NumberDivisors::copy(NumberDivisors& obj)
{
	obj.divisor_list = this->divisor_list;
	obj.number = this->number;
}


int main(void)
{
	srand(time(0));
	vector<NumberDivisors> list_of_obj;
	/*NumberDivisors p(4);
	NumberDivisors g(2);
	p.copy(g);*/

	vector<double> average_list;
	size_t count_of_nums = 0;
	int n;
	cout << "input some number\n";
	cin >> n;
	do
	{
		if (n > 0)
			break;
		else
		{
			cout << "try again input some number\n";
			cin >> n;
		}
	} while (true);
	cout << "\n";
	for (size_t i = 0; i < N; ++i)
	{
		list_of_obj.push_back(NumberDivisors(1 + rand() % 15));
		average_list.push_back(list_of_obj[i].averageValue());
		if (list_of_obj[i].divCounter(n))
			count_of_nums += 1;
	}
	size_t counter = 0;
	for (auto value : list_of_obj)
	{

		std::cout << value;
		std::cout << average_list[counter++] << "\n\n";
	}
	std::cout << "count of numbers that have the entered divisor: " << count_of_nums << "\n";
	std::cout << "largest common divisor: " << findNOD(list_of_obj[0].divisor_list, list_of_obj[1].divisor_list) << "\n";
	std::cout << "largest common divisor: " << findNODWithBind(list_of_obj[8].divisor_list, list_of_obj[9].divisor_list) << "\n";
	return EXIT_SUCCESS;
}