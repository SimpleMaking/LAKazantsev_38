#include "main_header.h"

/*
 * constructor of class SparePart
 *
 * @param flag marker for different details.
 */
SparePart::SparePart(int flag)
{
	if (flag == Parts::shaft)
	{
		replacement_cost = 100;
		one_time_repair_cost = 90;
		time_for_repair = 1;
		life_time = 3 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		time_counter = 0;
		type = 0;

		wear_degree_arr[0] = wear_degree;
	}
	else if (flag == Parts::electricEngine)
	{
		replacement_cost = 215;
		one_time_repair_cost = 105;
		time_for_repair = 2;
		life_time = 8 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		time_counter = 0;
		type = 1;
		wear_degree_arr[1] = wear_degree;
	}
	else if (flag == Parts::controlPanel)
	{
		replacement_cost = 305;
		one_time_repair_cost = 94;
		time_for_repair = 3;
		life_time = 5 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		time_counter = 0;
		type = 2;
		wear_degree_arr[2] = wear_degree;
	}
	else if(flag == Parts::cuttingHead)
	{
		replacement_cost = 50;
		one_time_repair_cost = 40;
		time_for_repair = 1;
		life_time = 10 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		time_counter = 0;
		type = 3;
		wear_degree_arr[3] = wear_degree;
	}
}

/*
 * implementation of the problem definition 
 * 
 * return 1 - part broken, 0 - part is ready to work farther
 */
bool SparePart::definitionProblem()
{
	if (wear_degree > 4)
		return 1;  // part broken
	else
		return 0;  // part ready to work farther
}

/*
 * redefinition: work simulation
 *
 * @param intensity_of_use intensity of using different parts
 */
void SparePart::working(short intensity_of_use) // 1 2 or 3 can take value
{
	int limit_value;
	double difference = 0, end_time;

	// working
	if (intensity_of_use == 1)
		limit_value = intensity_of_use + rand() % 6;
	else if (intensity_of_use == 2)
		limit_value = intensity_of_use + rand() % 4;
	else
		limit_value = intensity_of_use + rand() % 2;

	double start_time = clock();
	while (difference <= limit_value)
	{
		Sleep(1000);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
	++wear_degree;
}

/*
 * redefinition: implementation of the problem definition
 *
 * @param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int Shaft::definitionProblem()
{
	if (wear_degree > 6.4)
		return 1;  // part broken
	else if (time_counter > life_time)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}

/*
 * redefinition: work simulation
 *
 * @param intensity_of_use intensity of using different parts
 * @param counter counter of life time
 * return counter of life time
 */
void Shaft::working(short intensity_of_use)
{
	if (intensity_of_use == 1)
	{
		time_counter += 3;
		wear_degree = rand() % 6;
	}
	else if (intensity_of_use == 2)
	{
		time_counter += 4;
		wear_degree = rand() % 7;
	}
	else
	{
		time_counter += 5;
		wear_degree = rand() % 8;
	}
}

/*
 * redefinition: implementation of the problem definition
 *
 * @param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int ElectricEngine::definitionProblem()
{
	if (wear_degree > 7.1)
		return 1;  // part broken
	else if (time_counter > life_time)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}

/*
 * redefinition: work simulation
 *
 * @param intensity_of_use intensity of using different parts
 * @param counter counter of life time
 * return counter of life time
 */
void ElectricEngine::working(short intensity_of_use)
{
	if (intensity_of_use == 1)
	{
		time_counter += 3;
		wear_degree = rand() % 9;
	}
	else if (intensity_of_use == 2)
	{
		time_counter += 4;
		wear_degree = rand() % 10;
	}
	else
	{
		time_counter += 5;
		wear_degree = rand() % 11;
	}
}

/*
 * redefinition: implementation of the problem definition
 *
 * @param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int ControlPanel::definitionProblem()
{
	if (wear_degree > 6.3)
		return 1;  // part broken
	else if (time_counter > life_time)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}

/*
 * redefinition: work simulation
 *
 * @param intensity_of_use intensity of using different parts
 * @param counter counter of life time
 * return counter of life time
 */
void ControlPanel::working(short intensity_of_use)
{
	if (intensity_of_use == 1)
	{
		time_counter += 3;
		wear_degree = rand() % 7;
	}
	else if (intensity_of_use == 2)
	{
		time_counter += 4;
		wear_degree = rand() % 8;
	}
	else
	{
		time_counter += 5;
		wear_degree += rand() % 9;
	}
}

/*
 * redefinition: implementation of the problem definition
 * 
 *@param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int CuttingHead::definitionProblem()
{
	if (wear_degree > 7.4)
		return 1;  // part broken
	else if (time_counter > life_time)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}

/*
 * redefinition: work simulation
 *
 * @param intensity_of_use intensity of using different parts
 * @param counter counter of life time
 * return counter of life time 
 */
void CuttingHead::working(short intensity_of_use)
{
	if (intensity_of_use == 1)
	{
		time_counter += 3;
		wear_degree = rand() % 8;
	}
	else if (intensity_of_use == 2)
	{
		time_counter += 4;
		wear_degree += rand() % 9;
	}
	else
	{
		time_counter += 5;
		wear_degree = rand() % 10;
	}
}

/*
 * constructor of class Machine
 *
 */
Machine::Machine()
{
	int rand_value;
	for (size_t i = 0; i < COUNT_OF_PARTS; ++i)
	{
		rand_value = rand() % COUNT_OF_TYPES;
		switch (rand_value)
		{
		case Parts::shaft:
		{
			part_set.push_back(Shaft(0));
			break;
		}
		case Parts::electricEngine:
		{
			part_set.push_back(ElectricEngine(1));
			break;
		}
		case Parts::controlPanel:
		{
			part_set.push_back(ControlPanel(2));
			break;
		}
		case Parts::cuttingHead:
		{
			part_set.push_back(CuttingHead(3));
			break;
		}
		}
	}
}

/*
 * machine work simulation
 *
 * @param working_time machine work time
 * @param intensity_of_use intensity of using different parts
 */
void Machine::machineWorking(short working_time, short intensity_of_use)
{	
	double start_time = clock();
	double end_time, difference = 0;
	int value;
	std::cout << "Machine is working /////...............\n";
	while (difference <= working_time)
	{
		for (size_t i = 0; i < COUNT_OF_PARTS; ++i)
		{
			part_set[i].working(intensity_of_use);
			if (value = part_set[i].definitionProblem())
			{
				if (value == 1)
				{
					if (part_set[i].type == 0)
						std::cout << "part being repaired /////..................... shaft  ";
					else if (part_set[i].type == 1)
						std::cout << "part being repaired /////..................... electric engine  ";
					else if (part_set[i].type == 2)
						std::cout << "part being repaired /////..................... control panel  ";
					else
						std::cout << "part being repaired /////..................... cutting head  ";

					std::cout << "time of repair: " << part_set[i].time_for_repair << "\n";
					part_set[i].wear_degree = wear_degree_arr[0];
					working_time -= part_set[i].time_for_repair;
					Sleep(part_set[i].time_for_repair * 1000);
					std::cout << "Machine is working again/////...............\n";
				}
				else if (value == 2)
				{
					if (part_set[i].type == 0)
						std::cout << "part is replacing /////..................... shaft  ";
					else if (part_set[i].type == 1)
						std::cout << "part is replacing /////..................... electric engine  ";
					else if (part_set[i].type == 2)
						std::cout << "part is replacing /////..................... control panel  ";
					else
						std::cout << "part is replacing /////..................... cutting head  ";

					std::cout << "time of replace: " << 4 << "\n";
					part_set[i].life_time = life_time_arr[0];
					working_time -= 4;
					part_set[i].time_counter = 0;
					part_set.erase((part_set.end() - 1) - (part_set.size() - 1 - i));
					switch (part_set[i].type)
					{
					case Parts::shaft:
					{
						part_set.push_back(Shaft(0));
						break;
					}
					case Parts::electricEngine:
					{
						part_set.push_back(ElectricEngine(1));
						break;
					}
					case Parts::controlPanel:
					{
						part_set.push_back(ControlPanel(2));
						break;
					}
					case Parts::cuttingHead:
					{
						part_set.push_back(CuttingHead(3));
						break;
					}
					}
					Sleep(4000);
					std::cout << "Machine is working again/////...............\n";
				}
			}
		}
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
		
	part_set.clear();
}

/*
 * yearly machine work simulation
 *
 * @param working_time machine work time
 * @param intensity_of_use intensity of using different parts
 * @param statistic_arr array for getting statistics 
 */
void Machine::workSimulation(short working_time, short intensity_of_use, int* statistic_arr)
{

	double start_time = clock();
	double end_time, difference = 0;
	int value;
	while (difference <= working_time)
	{
		for (size_t i = 0; i < COUNT_OF_PARTS; ++i)
		{
			part_set[i].working(intensity_of_use);
			if (value = part_set[i].definitionProblem())
			{
				statistic_arr[2] += 1;
				if (value == 1)
				{
					part_set[i].wear_degree = wear_degree_arr[0];
					statistic_arr[0] += part_set[i].one_time_repair_cost;
					statistic_arr[3] += part_set[i].time_for_repair;
					working_time -= part_set[i].time_for_repair;
					Sleep(part_set[i].time_for_repair * 1000);
				}
				else if (value == 2)
				{
					part_set[i].life_time = life_time_arr[0];
					statistic_arr[0] += part_set[i].replacement_cost;
					statistic_arr[1] += 1;
					statistic_arr[3] += 4;
					working_time -= 4;
					part_set[i].time_counter = 0;
					part_set.erase((part_set.end() - 1) - (part_set.size() - 1 - i));
					switch (part_set[i].type)
					{
					case Parts::shaft:
					{
						part_set.push_back(Shaft(0));
						break;
					}
					case Parts::electricEngine:
					{
						part_set.push_back(ElectricEngine(1));
						break;
					}
					case Parts::controlPanel:
					{
						part_set.push_back(ControlPanel(2));
						break;
					}
					case Parts::cuttingHead:
					{
						part_set.push_back(CuttingHead(3));
						break;
					}
					}
					Sleep(4000);
				}
			}
		}
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}

	//part_set.clear();
}

/*
 * the main function - get some yearly statistics for all defined machines
 *
 */
int main()
{
	srand(time(0));

	//Machine machine;
	Machine* machine_arr = new Machine[COUNT_OF_MACHINES];
	int** statistics = new int* [COUNT_OF_MACHINES];
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		statistics[i] = new int[4];

	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		for (size_t j = 0; j < 4; ++j)
			statistics[i][j] = 0;
	std::cout << "simulation in progress...\n\n";
	short counter = 0, intensity_of_use = 1 + rand() % 3;
	for (size_t i = 1; i <= YEAR_CYCLE; ++i)
	{
		for (size_t j = 0; j < COUNT_OF_MACHINES; ++j)
		{
			machine_arr[j].workSimulation(WORKING_DAY, intensity_of_use, statistics[j]);
		}
		++counter;
		if (counter % 30 == 0)
			intensity_of_use = 1 + rand() % 3;
	}

	//output
	counter = 1;
	std::cout << "WORKSHOP STATISTICS\n\n";
	std::cout << "repair cost per machine\n";
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
	{
		std::cout << "Machine " << counter << ": " << statistics[i][0] << "$" << std::endl;
		++counter;
	}
	std::cout << std::endl;
	counter = 1;
	std::cout << "count of replaced parts of each machine\n";
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
	{
	std::cout << "Machine " << counter << ": " << statistics[i][1] << "pc." << std::endl;
	++counter;
	}
	std::cout << std::endl;
	counter = 1;
	std::cout << "count of breakdowns of each machine\n";
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
	{
		std::cout << "Machine " << counter << ": " << statistics[i][2] << "pc." << std::endl;
		++counter;
	}
	std::cout << std::endl;

	int total = 0;
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		total += statistics[i][2];
	std::cout << "total: " << total << "pc." << std::endl << std::endl;

	total = 0;
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		total += statistics[i][3];
	std::cout << "total downtime of all machines: " << total << "h." << std::endl << std::endl;

	int max = statistics[0][3];
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		if (statistics[i][3] > max)
			max = statistics[i][3];
	std::cout << "max downtime from all machines: " << max << "h." << std::endl << std::endl;

	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		delete[]statistics[i];
	delete[]statistics;
	//machine.machineWorking(24, 3);
	return 0;
}