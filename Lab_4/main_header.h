#include "simple_table.h"

constexpr size_t WARRIOR_TYPE_COUNT = 3;
constexpr size_t COUNT = 11;
constexpr size_t COUNT_OF_COLUMNS = 6;
using namespace std;

enum Warriors
{
	SWORDSMAN,
	ARCHER,
	WIZARD
};


class Swordsman
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;
public:
	Swordsman(double pwr, double st, double dist, double pr, string tp);
	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class Archer
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;
public:
	Archer(double pwr, double st, double dist, double pr, string tp);
	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class Wizard
{
private:
	double power;
	double stamina;
	double distance;
	double price;
	string type;
public:
	Wizard(double pwr, double st, double dist, double pr, string tp);
	void genRandomValues(bool flag);
	void output(StreamTable& table);
};


class Mercenary
{
public:
	void* warrior;
	string type;
};


using values = std::pair<Mercenary*, size_t*>;


class Guild
{
private:
	Mercenary* mercenaries;
public:
	size_t* countAllWarriorsTypes(size_t* arr_of_types, size_t* arr_for_warriors_types, size_t count);
    values getMercenaries(StreamTable& table);
};

