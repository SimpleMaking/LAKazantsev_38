#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>
#include <numeric>
#include <functional>

using namespace std;
constexpr int N = 10;


class NumberDivisors
{
private:
	//NumberDivisors(const NumberDivisors&);
	void operator=(const NumberDivisors&);
	vector<int> divisor_list;
	int number;
public:
	NumberDivisors(int number);
	NumberDivisors() : number(0) {}
	bool divCounter(size_t number);
	vector<int>& getDivisorList();
	int getNumber();
	void copy(NumberDivisors&);
	double averageValue();
	friend ostream& operator<<(ostream& out, NumberDivisors const& obj);
	friend int findNOD(vector<int>&, vector<int>&);
	friend int findNODWithBind(vector<int>&, vector<int>&);
};


/*
 * overload << operator for output via std::copy
 *
 * @param out output object.
 * @param obj obj that will be rendered.
 * @return output object link.
 */
ostream& operator<<(ostream& out, NumberDivisors const& obj)
{
	out << obj.number << "\n";
	std::copy(obj.divisor_list.begin(), obj.divisor_list.end(),
		std::ostream_iterator<int>(out, " "));
	
	out << "\n";
	return out;
}


/*
 * search largest common divisor 
 *
 * @param val1 first values list.
 * @param val2 second values list.
 * @return largest common divisor.
 */
int findNOD(vector<int>& val1, vector<int>& val2)
{
	size_t max = 1;
	for (size_t i = 0; i < val1.size(); ++i)
	{
		auto elem = val1[i];
		auto next_elem = std::find_if(val2.begin(), val2.end(), [elem](int val2_elem) {return elem == val2_elem;});
		if (next_elem != val2.end() && *next_elem > max)
			max = *next_elem;
	}
	return max;
}


/*
 * search largest common divisor via std::bind
 *
 * @param val1 first values list.
 * @param val2 second values list.
 * @return largest common divisor.
 */
int findNODWithBind(vector<int>& val1, vector<int>& val2)
{
	auto funcNOD = std::bind(findNOD, val1, val2);
	return funcNOD();
}