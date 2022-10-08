#include "simple_table.h"

constexpr size_t WARRIOR_TYPE_COUNT = 3;
constexpr size_t COUNT = 11;
constexpr size_t COUNT_OF_COLUMNS = 6;
using namespace std;

enum warriors
{
	SWORDSMAN,
	ARCHER,
	WIZARD
};


class swordsman
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;

public:
	swordsman(double pwr, double st, double dist, double pr, string tp);

	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class archer
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;

public:
	archer(double pwr, double st, double dist, double pr, string tp);

	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class wizard
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;

public:
	wizard(double pwr, double st, double dist, double pr, string tp);

	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class mercenary
{
public:
	void* warrior;
	string type;
};


using values = std::pair<mercenary*, size_t*>;


class guild
{
private:
	mercenary* mercenaries;

public:
	size_t* countAllWarriorsTypes(size_t* arr_of_types, size_t* arr_for_warriors_types, size_t count);


    values getMercenaries(StreamTable& table);
};

