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
public:
	mutable vector<int> divisor_list;
	mutable int number;
	NumberDivisors(int number);
	NumberDivisors() : number(0) {}
	bool divCounter(size_t number);
	void copy(NumberDivisors&);
	double averageValue();
	template <typename T>
	friend ostream& operator<<(ostream& out, NumberDivisors const& obj);
	friend int findNOD(vector<int>&, vector<int>&);
	friend int findNODWithBind(vector<int>&, vector<int>&);
};


ostream& operator<<(ostream& out, NumberDivisors const& obj)
{
	out << obj.number << "\n";
	std::copy(obj.divisor_list.begin(), obj.divisor_list.end(),
		std::ostream_iterator<int>(out, " "));
	
	out << "\n";
	return out;
}


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


int findNODWithBind(vector<int>& val1, vector<int>& val2)
{
	auto funcNOD = std::bind(findNOD, val1, val2);
	return funcNOD();
}