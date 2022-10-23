#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <Windows.h>
constexpr short COUNT_OF_PARTS = 4;
constexpr short COUNT_OF_MACHINES = 8;
constexpr short YEAR_CYCLE = 1;
constexpr short WORKING_DAY = 12;
int wear_degree_arr[COUNT_OF_PARTS];
int life_time_arr[COUNT_OF_PARTS] = {5, 10, 7, 12};


enum Parts
{
	shaft,
	electricEngine,
	controlPanel,
	cuttingHead
};


class SparePart
{
public:
	double replacement_cost;
	double one_time_repair_cost;
	int life_time;   // in hours
	int time_for_repair;    // in hours
	double wear_degree;   
	SparePart(double a = 0, double b = 0, int c = 0, int d = 0, short e = 0) : replacement_cost(a), one_time_repair_cost(b), time_for_repair(c), life_time(d), wear_degree(e) {}
	SparePart(int flag);
	bool definitionProblem();
	void working(short intensity_of_use);

};


class Shaft : public SparePart
{
public:
	Shaft() {}
	Shaft(int flag) : SparePart(flag) {}
	int definitionProblem(int counter);
	int working(short intensity_of_use, int counter);
};


class ElectricEngine : public SparePart
{
public:
	ElectricEngine() {}
	ElectricEngine(int flag) : SparePart(flag) {}
	int definitionProblem(int counter);
	int working(short intensity_of_use, int counter);
};


class ControlPanel : public SparePart
{
public:
	ControlPanel() {}
	ControlPanel(int flag) : SparePart(flag) {}
	int definitionProblem(int counter);
	int working(short intensity_of_use, int counter);
};


class CuttingHead : public SparePart
{
public:
	CuttingHead() {}
	CuttingHead(int flag) : SparePart(flag) {}
	int definitionProblem(int counter);
	int working(short intensity_of_use, int counter);
};


class Machine //: public Shaft, public ElectricEngine, public ControlPanel, public CuttingHead
{
private:
	Shaft shaft_value;
	ElectricEngine engine_value;
	ControlPanel control_panel_value;
	CuttingHead cutting_head_value;
public:
	Machine();
	void machineWorking(short working_time, short intensity_of_use);
	void workSimulation(short working_time, short intensity_of_use, int* statistic_arr);
};