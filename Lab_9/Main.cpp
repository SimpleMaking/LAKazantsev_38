#include "Main_Header.h"

/*
 * class NumberDivisors constructor
 *
 * @param number number for that we should find all divisors.
 */
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


/*
 * checking divisor_list have or no entered divisor
 *
 * @param number entered divisor.
 * @return checking flag.
 */
int divCounter(size_t number, vector<NumberDivisors>& list)
{
	auto lambda = [number](NumberDivisors vector_div) 
	{
		for (size_t i = 0; i < vector_div.getDivisorList().size(); ++i)
			if (vector_div.getDivisorList()[i] == number)
				return true;
		return false;
	};
	int count_of_elems = count_if(list.begin(), list.end(), lambda);
	return count_of_elems;
}


/*
 * getting average value of number divisors
 *
 * @return average value.
 */
double NumberDivisors::averageValue()
{
	size_t sum = std::accumulate(divisor_list.begin(), divisor_list.end(), 0);
	return sum / (double)divisor_list.size();
}


/*
 * object copy
 *
 * @param obj object to be copied.
 */
void NumberDivisors::copy(NumberDivisors& obj)
{
	obj.divisor_list = this->divisor_list;
	obj.number = this->number;
}


/*
 * getting divisor_list
 *
 * @return divisor_list link.
 */
vector<int>& NumberDivisors::getDivisorList()
{
	return divisor_list;
}


/*
 * getting number
 *
 * @return number.
 */
int NumberDivisors::getNumber()
{
	return number;
}


/*
 * the main function - checking all app functions 
 *
 */
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
	}
	size_t counter = 0;
	for (auto value : list_of_obj)
	{

		std::cout << value;
		std::cout << average_list[counter++] << "\n\n";
	}
	std::cout << "count of numbers that have the entered divisor: " << divCounter(n, list_of_obj) << "\n";
	std::cout << "largest common divisor: " << findNOD(list_of_obj[0].getDivisorList(), list_of_obj[1].getDivisorList()) << "\n";
	std::cout << "largest common divisor: " << findNODWithBind(list_of_obj[8].getDivisorList(), list_of_obj[9].getDivisorList()) << "\n";
	return EXIT_SUCCESS;
}