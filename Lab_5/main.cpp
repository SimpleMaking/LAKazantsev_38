#include "main_header.h"

SparePart::SparePart(int flag)
{
	if (flag == Parts::shaft)
	{
		replacement_cost = 100;
		one_time_repair_cost = 100;
		time_for_repair = 1;
		life_time = 5;
		wear_degree = rand() % 2;
		wear_degree_arr[0] = wear_degree;
	}
	else if (flag == Parts::electricEngine)
	{
		replacement_cost = 200;
		one_time_repair_cost = 100;
		time_for_repair = 2;
		life_time = 10;
		wear_degree = 1;
		wear_degree_arr[1] = wear_degree;
	}
	else if (flag == Parts::controlPanel)
	{
		replacement_cost = 100;
		one_time_repair_cost = 200;
		time_for_repair = 3;
		life_time = 7;
		wear_degree = 1 + rand() % 3;
		wear_degree_arr[2] = wear_degree;
	}
	else if(flag == Parts::cuttingHead)
	{
		replacement_cost = 50;
		one_time_repair_cost = 40;
		time_for_repair = 1;
		life_time = 12;
		wear_degree = 1 + rand() % 3;
		wear_degree_arr[3] = wear_degree;
	}
}


bool SparePart::definitionProblem()
{
	if (wear_degree > 4)
		return 1;  // part broken
	else
		return 0;  // part ready to work farther
}


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


int Shaft::definitionProblem()
{
	if (wear_degree > 4)
		return 1;  // part broken
	else if (life_time > 8)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}


void Shaft::working(short intensity_of_use)
{
	int limit_value;
	double difference = 0, end_time, promejyt = 0;

	// working
	if (intensity_of_use == 1)
		limit_value = intensity_of_use + rand() % 7;
	else if (intensity_of_use == 2)
		limit_value = intensity_of_use + rand() % 5;
	else
		limit_value = intensity_of_use + rand() % 3;

	double start_time = clock();
	while (difference <= limit_value)
	{
		promejyt = difference;
		Sleep(1000);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
		if (difference - promejyt >= 1)
			++life_time;
	}
	++wear_degree;
}


int ElectricEngine::definitionProblem()
{
	if (wear_degree > 3)
		return 1;  // part broken
	else if (life_time > 17)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}


void ElectricEngine::working(short intensity_of_use)
{
	int limit_value;
	double difference = 0, end_time, promejyt = 0;

	// working
	if (intensity_of_use == 1)
		limit_value = intensity_of_use + rand() % 4;
	else if (intensity_of_use == 2)
		limit_value = intensity_of_use + rand() % 3;
	else
		limit_value = intensity_of_use + rand() % 2;

	double start_time = clock();
	while (difference <= limit_value)
	{
		promejyt = difference;
		Sleep(1000);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
		if (difference - promejyt >= 1)
			++life_time;
	}
	++wear_degree;
}


int ControlPanel::definitionProblem()
{
	if (wear_degree > 6)
		return 1;  // part broken
	else if (life_time > 13)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}


void ControlPanel::working(short intensity_of_use)
{
	int limit_value;
	double difference = 0, end_time, promejyt = 0;

	// working
	if (intensity_of_use == 1)
		limit_value = intensity_of_use + rand() % 5;
	else if (intensity_of_use == 2)
		limit_value = intensity_of_use + rand() % 4;
	else
		limit_value = intensity_of_use + rand() % 2;

	double start_time = clock();
	while (difference <= limit_value)
	{
		promejyt = difference;
		Sleep(1000);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
		if (difference - promejyt >= 1)
			++life_time;
	}
	++wear_degree;
}


int CuttingHead::definitionProblem()
{
	if (wear_degree > 5)
		return 1;  // part broken
	else if (life_time > 18)
		return 2; //need a replacement
	else
		return 0;  // part ready to work farther
}


void CuttingHead::working(short intensity_of_use)
{
	int limit_value;
	double difference = 0, end_time, promejyt = 0;

	// working
	if (intensity_of_use == 1)
		limit_value = intensity_of_use + rand() % 8;
	else if (intensity_of_use == 2)
		limit_value = intensity_of_use + rand() % 6;
	else
		limit_value = intensity_of_use + rand() % 4;

	double start_time = clock();
	while (difference <= limit_value)
	{
		promejyt = difference;
		Sleep(1000);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
		if (difference - promejyt >= 1)
			++life_time;
	}
	++wear_degree;
}


Machine::Machine()
{
	shaft_value = Shaft(0);
	engine_value = ElectricEngine(1);
	control_panel_value = ControlPanel(2);
	cutting_head_value = CuttingHead(3);
}


void Machine::machineWorking(short working_time, short intensity_of_use)
{	
	double start_time, end_time, difference = 0;
	int value;
	std::cout << "Machine is working /////...............\n";
	start_time = clock();
	while (difference <= working_time)
	{
		cutting_head_value.working(intensity_of_use);
		if (value = shaft_value.definitionProblem())
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... shaft  ";
				std::cout << "time of repair: " << shaft_value.time_for_repair << "\n";
				shaft_value.wear_degree = wear_degree_arr[0];
				Sleep(shaft_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... shaft  ";
				std::cout << "time of replace: " << 4 << "\n";
				shaft_value.life_time =life_time_arr[0];
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			
			//start_time += shaft_value->time_for_repair * 1000;
		}
		if (value = engine_value.definitionProblem())
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... electric engine  ";
				std::cout << "time of repair: " << engine_value.time_for_repair << "\n";
				engine_value.wear_degree = wear_degree_arr[1];
				Sleep(engine_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... electric engine  ";
				std::cout << "time of replace: " << 4 << "\n";
				engine_value.life_time = life_time_arr[1];
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += engine_value->time_for_repair * 1000;
		}
		control_panel_value.working(intensity_of_use);
		if (value = control_panel_value.definitionProblem())
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... control panel  ";
				std::cout << "time of repair: " << control_panel_value.time_for_repair << "\n";
				control_panel_value.wear_degree = wear_degree_arr[2];
				Sleep(control_panel_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... control panel  ";
				std::cout << "time of replace: " << 4 << "\n";
				control_panel_value.life_time = life_time_arr[2];
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += control_panel_value->time_for_repair * 1000;
		}
		engine_value.working(intensity_of_use);
		if (value = cutting_head_value.definitionProblem())
		{
			if (value == 1)
			{
				std::cout << "part being repaired /////..................... cutting head  ";
				std::cout << "time of repair: " << cutting_head_value.time_for_repair << "\n";
				cutting_head_value.wear_degree = wear_degree_arr[3];
				Sleep(cutting_head_value.time_for_repair * 1000);
				std::cout << "Machine is working again/////...............\n";
			}
			else if (value == 2)
			{
				std::cout << "part is replacing /////..................... cutting head  ";
				std::cout << "time of replace: " << 4 << "\n";
				cutting_head_value.life_time = life_time_arr[3];
				Sleep(4000);
				std::cout << "Machine is working again/////...............\n";
			}
			//start_time += cutting_head_value->time_for_repair * 1000;
		}
		shaft_value.working(intensity_of_use);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
}


void Machine::workSimulation(short working_time, short intensity_of_use, int* statistic_arr)
{
	double start_time, end_time, difference = 0;
	int value;
	//std::cout << "Machine is working /////...............\n";
	start_time = clock();
	while (difference <= working_time)
	{
		cutting_head_value.working(intensity_of_use);
		if (value = shaft_value.definitionProblem())
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				shaft_value.wear_degree = wear_degree_arr[0];
				statistic_arr[0] += shaft_value.one_time_repair_cost;
				statistic_arr[3] += shaft_value.time_for_repair;
				Sleep(shaft_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				shaft_value.life_time = life_time_arr[0];
				statistic_arr[0] += shaft_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				Sleep(4000);
			}

			//start_time += shaft_value->time_for_repair * 1000;
		}
		if (value = engine_value.definitionProblem())
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				
				engine_value.wear_degree = wear_degree_arr[1];
				statistic_arr[0] += engine_value.one_time_repair_cost;
				statistic_arr[3] += engine_value.time_for_repair;
				Sleep(engine_value.time_for_repair * 1000);
			
			}
			else if (value == 2)
			{
				engine_value.life_time = life_time_arr[1];
				statistic_arr[0] += engine_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				Sleep(4000);
			}
			//start_time += engine_value->time_for_repair * 1000;
		}
		control_panel_value.working(intensity_of_use);
		if (value = control_panel_value.definitionProblem())
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				control_panel_value.wear_degree = wear_degree_arr[2];
				statistic_arr[0] += control_panel_value.one_time_repair_cost;
				statistic_arr[3] += control_panel_value.time_for_repair;
				Sleep(control_panel_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				control_panel_value.life_time = life_time_arr[2];
				statistic_arr[0] += control_panel_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				Sleep(4000);
			}
			//start_time += control_panel_value->time_for_repair * 1000;
		}
		engine_value.working(intensity_of_use);
		if (value = cutting_head_value.definitionProblem())
		{
			statistic_arr[2] += 1;
			if (value == 1)
			{
				cutting_head_value.wear_degree = wear_degree_arr[3];
				statistic_arr[0] += cutting_head_value.one_time_repair_cost;
				statistic_arr[3] += cutting_head_value.time_for_repair;
				Sleep(cutting_head_value.time_for_repair * 1000);
			}
			else if (value == 2)
			{
				cutting_head_value.life_time = life_time_arr[3];
				statistic_arr[0] += cutting_head_value.replacement_cost;
				statistic_arr[1] += 1;
				statistic_arr[3] += 4;
				Sleep(4000);
			}
			//start_time += cutting_head_value->time_for_repair * 1000;
		}
		shaft_value.working(intensity_of_use);
		end_time = clock();
		difference = (end_time - start_time) / CLOCKS_PER_SEC;
	}
}


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
	std::cout << "max downtime of all machines: " << max << "h." << std::endl << std::endl;

	//machine.machineWorking(3, 3);
	for (size_t i = 0; i < COUNT_OF_MACHINES; ++i)
		delete[]statistics[i];
	delete[]statistics;

	return 0;
}