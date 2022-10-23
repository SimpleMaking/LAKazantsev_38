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
		wear_degree_arr[0] = wear_degree;
	}
	else if (flag == Parts::electricEngine)
	{
		replacement_cost = 215;
		one_time_repair_cost = 105;
		time_for_repair = 2;
		life_time = 8 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		wear_degree_arr[1] = wear_degree;
	}
	else if (flag == Parts::controlPanel)
	{
		replacement_cost = 305;
		one_time_repair_cost = 94;
		time_for_repair = 3;
		life_time = 5 + rand() % 3;
		wear_degree = 1 + rand() % 4;
		wear_degree_arr[2] = wear_degree;
	}
	else if(flag == Parts::cuttingHead)
	{
		replacement_cost = 50;
		one_time_repair_cost = 40;
		time_for_repair = 1;
		life_time = 10 + rand() % 3;
		wear_degree = 1 + rand() % 4;
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
int Shaft::definitionProblem(int counter)
{
	if (wear_degree > 6.4)
		return 1;  // part broken
	else if (counter > life_time)
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
int Shaft::working(short intensity_of_use, int counter)
{
	if (intensity_of_use == 1)
	{
		counter += 1;
		wear_degree = rand() % 8;
	}
	else if (intensity_of_use == 2)
	{
		counter += 2;
		wear_degree = rand() % 9;
	}
	else
	{
		counter += 3;
		wear_degree = rand() % 10;
	}
	return counter;
}

/*
 * redefinition: implementation of the problem definition
 *
 * @param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int ElectricEngine::definitionProblem(int counter)
{
	if (wear_degree > 7.1)
		return 1;  // part broken
	else if (counter > life_time)
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
int ElectricEngine::working(short intensity_of_use, int counter)
{
	if (intensity_of_use == 1)
	{
		counter += 1;
		wear_degree = rand() % 11;
	}
	else if (intensity_of_use == 2)
	{
		counter += 2;
		wear_degree = rand() % 12;
	}
	else
	{
		counter += 3;
		wear_degree = rand() % 13;
	}
	return counter;
}

/*
 * redefinition: implementation of the problem definition
 *
 * @param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int ControlPanel::definitionProblem(int counter)
{
	if (wear_degree > 6.3)
		return 1;  // part broken
	else if (counter > life_time)
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
int ControlPanel::working(short intensity_of_use, int counter)
{
	if (intensity_of_use == 1)
	{
		counter += 1;
		wear_degree = rand() % 9;
	}
	else if (intensity_of_use == 2)
	{
		counter += 2;
		wear_degree = rand() % 10;
	}
	else
	{
		counter += 3;
		wear_degree += rand() % 11;
	}
	return counter;
}

/*
 * redefinition: implementation of the problem definition
 * 
 *@param counter counter of life time
 * return 1 - part broken, 2 - part need a replacement, 0 - part is ready to work farther
 */
int CuttingHead::definitionProblem(int counter)
{
	if (wear_degree > 7.4)
		return 1;  // part broken
	else if (counter > life_time)
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
int CuttingHead::working(short intensity_of_use, int counter)
{
	if (intensity_of_use == 1)
	{
		counter += 1;
		wear_degree = rand() % 10;
	}
	else if (intensity_of_use == 2)
	{
		counter += 2;
		wear_degree += rand() % 11;
	}
	else
	{
		counter += 3;
		wear_degree = rand() % 12;
	}
	return counter;
}

/*
 * constructor of class Machine
 *
 */
Machine::Machine()
{
	shaft_value = Shaft(0);
	engine_value = ElectricEngine(1);
	control_panel_value = ControlPanel(2);
	cutting_head_value = CuttingHead(3);
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
	int counter_arr[COUNT_OF_PARTS] = { 0 };
	double end_time, difference = 0;
	int value;
	std::cout << "Machine is working /////...............\n";
	while (difference <= working_time)
	{
		counter_arr[3] = cutting_head_value.working(intensity_of_use, counter_arr[3]);
		if (value = shaft_value.definitionProblem(counter_arr[0]))
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... shaft  ";
				std::cout << "time of repair: " << shaft_value.time_for_repair << "\n";
				shaft_value.wear_degree = wear_degree_arr[0];
				working_time -= shaft_value.time_for_repair;
				Sleep(shaft_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... shaft  ";
				std::cout << "time of replace: " << 4 << "\n";
				shaft_value.life_time =life_time_arr[0];
				working_time -= 4;
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			
			//start_time += shaft_value->time_for_repair * 1000;
		}
		if (value = engine_value.definitionProblem(counter_arr[1]))
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... electric engine  ";
				std::cout << "time of repair: " << engine_value.time_for_repair << "\n";
				engine_value.wear_degree = wear_degree_arr[1];
				working_time -= engine_value.time_for_repair;
				Sleep(engine_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... electric engine  ";
				std::cout << "time of replace: " << 4 << "\n";
				engine_value.life_time = life_time_arr[1];
				working_time -= 4;
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += engine_value->time_for_repair * 1000;
		}
		counter_arr[2] = control_panel_value.working(intensity_of_use, counter_arr[2]);
		if (value = control_panel_value.definitionProblem(counter_arr[2]))
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... control panel  ";
				std::cout << "time of repair: " << control_panel_value.time_for_repair << "\n";
				control_panel_value.wear_degree = wear_degree_arr[2];
				working_time -= control_panel_value.time_for_repair;
				Sleep(control_panel_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... control panel  ";
				std::cout << "time of replace: " << 4 << "\n";
				control_panel_value.life_time = life_time_arr[2];
				working_time -= 4;
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += control_panel_value->time_for_repair * 1000;
		}
		counter_arr[1] = engine_value.working(intensity_of_use, counter_arr[1]);
		if (value = cutting_head_value.definitionProblem(counter_arr[3]))
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... cutting head  ";
				std::cout << "time of repair: " << cutting_head_value.time_for_repair << "\n";
				cutting_head_value.wear_degree = wear_degree_arr[3];
				working_time -= cutting_head_value.time_for_repair;
				Sleep(cutting_head_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... cutting head  ";
				std::cout << "time of replace: " << 4 << "\n";
				cutting_head_value.life_time = life_time_arr[3];
				working_time -= 4;
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += cutting_head_value->time_for_repair * 1000;
		}
		counter_arr[0] = shaft_value.working(intensity_of_use, counter_arr[0]);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
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
	int counter_arr[COUNT_OF_PARTS] = { 0 };
	double end_time, difference = 0;
	int value;
	//std::cout << "Machine is working /////...............\n";
	while (difference <= working_time)
	{
		counter_arr[3] = cutting_head_value.working(intensity_of_use, counter_arr[3]);
		if (value = shaft_value.definitionProblem(counter_arr[0]))
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				shaft_value.wear_degree = wear_degree_arr[0];
				statistic_arr[0] += shaft_value.one_time_repair_cost;
				statistic_arr[3] += shaft_value.time_for_repair;
				working_time -= shaft_value.time_for_repair;
				Sleep(shaft_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				shaft_value.life_time = life_time_arr[0];
				statistic_arr[0] += shaft_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				working_time -= 4;
				Sleep(4000);
			}

			//start_time += shaft_value->time_for_repair * 1000;
		}
		if (value = engine_value.definitionProblem(counter_arr[1]))
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				
				engine_value.wear_degree = wear_degree_arr[1];
				statistic_arr[0] += engine_value.one_time_repair_cost;
				statistic_arr[3] += engine_value.time_for_repair;
				working_time -= engine_value.time_for_repair;
				Sleep(engine_value.time_for_repair * 1000);
			
			}
			else if (value == 2)
			{
				engine_value.life_time = life_time_arr[1];
				statistic_arr[0] += engine_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				working_time -= 4;
				Sleep(4000);
			}
			//start_time += engine_value->time_for_repair * 1000;
		}
		counter_arr[2] = control_panel_value.working(intensity_of_use, counter_arr[2]);
		if (value = control_panel_value.definitionProblem(counter_arr[2]))
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				control_panel_value.wear_degree = wear_degree_arr[2];
				statistic_arr[0] += control_panel_value.one_time_repair_cost;
				statistic_arr[3] += control_panel_value.time_for_repair;
				working_time -= control_panel_value.time_for_repair;
				Sleep(control_panel_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				control_panel_value.life_time = life_time_arr[2];
				statistic_arr[0] += control_panel_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				working_time -= 4;
				Sleep(4000);
			}
			//start_time += control_panel_value->time_for_repair * 1000;
		}
		counter_arr[1] = engine_value.working(intensity_of_use, counter_arr[1]);
		if (value = cutting_head_value.definitionProblem(counter_arr[3]))
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				cutting_head_value.wear_degree = wear_degree_arr[3];
				statistic_arr[0] += cutting_head_value.one_time_repair_cost;
				statistic_arr[3] += cutting_head_value.time_for_repair;
				working_time -= cutting_head_value.time_for_repair;
				Sleep(cutting_head_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				cutting_head_value.life_time = life_time_arr[3];
				statistic_arr[0] += cutting_head_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				working_time -= 4;
				Sleep(4000);
			}
			//start_time += cutting_head_value->time_for_repair * 1000;
		}
		counter_arr[0] = shaft_value.working(intensity_of_use, counter_arr[0]);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
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

	//machine.machineWorking(3, 3);
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		delete[]statistics[i];
	delete[]statistics;

	return 0;
}