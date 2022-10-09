#include "main_header.h"


/*
 * assignment constructor
 */
Swordsman::Swordsman(double pwr = 1000, double st = 350, double dist = 100, double pr = 80, string tp = "") : power(pwr), stamina(st), distance(dist), price(pr), type(tp)
{}


/*
 * ooutput warrior data in the table
 */
void Swordsman::output(StreamTable& table)
{
	table << "swordsman" << power << stamina << distance << price << type;
}


/*
 * generation of random warrior values
 *
 * @param flag flag for identification of warrior type.
 */
void Swordsman::genRandomValues(bool flag)
{
	if (flag)
	{
		power = 1000 + rand() % (1200 - 1000);
		stamina = 600 + rand() % (700 - 600);
		distance = 100 + rand() % (200 - 100);
		price = 100;
		type = "tank";
	}
	else
	{
		power = 1500 + rand() % (2000 - 1500);
		stamina = 350 + rand() % (500 - 350);
		distance = 100 + rand() % (200 - 100);
		price = 90;
		type = "max_damage";
	}
}


/*
 * assignment constructor
 */
Archer::Archer(double pwr = 200, double st = 700, double dist = 1000, double pr = 50, string tp = "") : power(pwr), stamina(st), distance(dist), price(pr), type(tp)
{}


/*
 * ooutput warrior data in the table
 */
void Archer::output(StreamTable& table)
{
	table << "archer" << power << stamina << distance << price << type;
}


/*
 * generation of random warrior values
 *
 * @param flag flag for identification of warrior type.
 */
void Archer::genRandomValues(bool flag)
{
	if (flag)
	{
		power = 180 + rand() % (200 - 180);
		stamina = 700 + rand() % (800 - 700);
		distance = 1000 + rand() % (1200 - 1000);
		price = 50;
		type = "medium_distance";
	}
	else
	{
		power = 180 + rand() % (200 - 180);
		stamina = 700 + rand() % (800 - 700);
		distance = 1500 + rand() % (2000 - 1500);
		price = 60;
		type = "maximum_distance";
	}
}


/*
 * assignment constructor
 */
Wizard::Wizard(double pwr = 700, double st = 200, double dist = 1000, double pr = 50, string tp = "") : power(pwr), stamina(st), distance(dist), price(pr), type(tp)
{}


/*
 * ooutput warrior data in the table
 */
void Wizard::output(StreamTable& table)
{
	table << "wizard" << power << stamina << distance << price << type;
}


/*
 * generation of random warrior values
 *
 * @param flag flag for identification of warrior type.
 */
void Wizard::genRandomValues(bool flag)
{
	if (flag)
	{
		power = 700 + rand() % (800 - 700);
		stamina = 200 + rand() % (300 - 200);
		distance = 1000 + rand() % (1200 - 1000);
		price = 50;
		type = "medium_distance";
	}
	else
	{
		power = 700 + rand() % (800 - 700);
		stamina = 200 + rand() % (300 - 200);
		distance = 1500 + rand() % (2000 - 1500);
		price = 60;
		type = "maximum_distance";
	}
}


/*
 * count of all warrior types
 *
 * @param arr_of_types array of mercenary types.
 * @param arr_for_warriors_types array for counting of all warrior types.
 * @param count count of warriors.
 * @return arr_for_warriors_types.
 */
size_t* Guild::countAllWarriorsTypes(size_t* arr_of_types, size_t* arr_for_warriors_types, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		switch (arr_of_types[i])
		{
		case Warriors::SWORDSMAN:
		{
			arr_for_warriors_types[0] += 1;
			break;
		}
		case Warriors::ARCHER:
		{
			arr_for_warriors_types[1] += 1;
			break;
		}
		case Warriors::WIZARD:
		{
			arr_for_warriors_types[2] += 1;
			break;
		}
		}
	}
	return arr_for_warriors_types;
}


/*
 * data output
 *
 * @param mercenaries array of mercenaries.
 * @param arr_of_types array of mercenary types
 * @param table table for careful output
 */
void outputData(Mercenary* mercenaries, size_t* arr_of_types, StreamTable& table)
{
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(17);

	cout << "GUILD" << "\n";
	table << "name" << "power" << "stamina" << "distance" << "price" << "type";
	for (size_t i = 0; i < COUNT; i++)
	{
		switch (arr_of_types[i])
		{
		case Warriors::SWORDSMAN:
		{
			((Swordsman*)mercenaries[i].warrior)->output(table);
			break;
		}
		case Warriors::ARCHER:
		{
			((Archer*)mercenaries[i].warrior)->output(table);
			break;
		}
		case::Warriors::WIZARD:
		{
			((Wizard*)mercenaries[i].warrior)->output(table);
			break;
		}
		}
	}
	cout << "\n\n";
}


/*
 * getting array of mercenary types
 *
 * @param arr_of_types array of mercenary types.
 * @return array of mercenary types.
 */
size_t* get_warrior_arr(size_t* arr_of_types)
{
	size_t arr_for_check[3] = { 0 };
	do {
		arr_for_check[0] = 0;
		arr_for_check[1] = 0;
		arr_for_check[2] = 0;
		for (size_t i = 0; i < COUNT; ++i)
		{
			arr_of_types[i] = rand() % WARRIOR_TYPE_COUNT;
			if (arr_of_types[i] == 0)
				++arr_for_check[0];
			else if (arr_of_types[i] == 1)
				++arr_for_check[1];
			else
				++arr_for_check[2];
		}
	} while (arr_for_check[0] < 2 || arr_for_check[1] < 2 || arr_for_check[2] < 2);

	return arr_of_types;
}


/*
 * getting guild of mercenaries
 * 
 * @param table table for careful output.
 * @return array of mercenaries and array of them types.
 */
values Guild::getMercenaries(StreamTable& table)
{
	size_t arr_of_types_[COUNT];
	size_t* arr_of_types = get_warrior_arr(arr_of_types_);
	size_t arr_for_warriors_types[WARRIOR_TYPE_COUNT] = { 0 };
	mercenaries = new Mercenary[COUNT];

	size_t* arr_for_warriors_types_ = countAllWarriorsTypes(arr_of_types, arr_for_warriors_types, COUNT);

	Swordsman* swordsman_arr = new Swordsman[arr_for_warriors_types_[0]];
	Archer* archer_arr = new Archer[arr_for_warriors_types_[1]];
	Wizard* wizard_arr = new Wizard[arr_for_warriors_types_[2]];

	bool counter_sw[2] = { 0 };
	bool counter_arch[2] = { 0 };
	bool counter_wzrd[2] = { 0 };


	size_t arr_of_counters[WARRIOR_TYPE_COUNT] = { 0 };
	for (size_t i = 0; i < COUNT; ++i)
	{

		switch (arr_of_types[i])
		{
		case Warriors::SWORDSMAN:
		{
			if (!counter_sw[0])
			{
				swordsman_arr[arr_of_counters[0]].genRandomValues(1);
				counter_sw[0] = true;
			}
			else if (!counter_sw[1])
			{
				swordsman_arr[arr_of_counters[0]].genRandomValues(0);
				counter_sw[1] = true;
			}
			else
			{
				swordsman_arr[arr_of_counters[0]].genRandomValues(rand() % 2);
			}
			mercenaries[i].warrior = &swordsman_arr[arr_of_counters[0]++];
			mercenaries[i].type = "swordsman";
			break;
		}
		case Warriors::ARCHER:
		{
			if (!counter_arch[0])
			{
				archer_arr[arr_of_counters[1]].genRandomValues(1);
				counter_arch[0] = true;
			}
			else if (!counter_arch[1])
			{
				archer_arr[arr_of_counters[1]].genRandomValues(0);
				counter_arch[1] = true;
			}
			else
			{
				archer_arr[arr_of_counters[1]].genRandomValues(rand() % 2);
			}
			mercenaries[i].warrior = &archer_arr[arr_of_counters[1]++];
			mercenaries[i].type = "archer";
			break;
		}
		case Warriors::WIZARD:
		{
			if (!counter_wzrd[0])
			{
				wizard_arr[arr_of_counters[2]].genRandomValues(1);
				counter_wzrd[0] = true;
			}
			else if (!counter_wzrd[1])
			{
				wizard_arr[arr_of_counters[2]].genRandomValues(0);
				counter_wzrd[1] = true;
			}
			else
			{
				wizard_arr[arr_of_counters[2]].genRandomValues(rand() % 2);
			}
			mercenaries[i].warrior = &wizard_arr[arr_of_counters[2]++];
			mercenaries[i].type = "wizard";
			break;
		}
		}
	}
	outputData(mercenaries, arr_of_types, table);
	
	return { mercenaries, arr_of_types };
}


/*
 * The main function. here goes interaction with user
 *
 * @return work flag.
 */
int main(void)
{
	setlocale(LC_ALL, "Russian");
    StreamTable table(cout, '-', '|');
	srand(time(0));
	Guild g;
	vector<Mercenary*> guild_mercenaries;
	values arr = g.getMercenaries(table);
	guild_mercenaries.push_back(arr.first);
	
	char s;
	cout << "it's your first guild, do you add this in the group?  y/n\n";
	do {
		cin >> s;
		if (s == "y"[0])
		{
			guild_mercenaries.push_back(arr.first);
			StreamTable table(cout, '-', '|');
			g.getMercenaries(table);
		}
		else if (s == "n"[0])
		{
			cout << "you have: " << guild_mercenaries.size() << " guilds in your group" << endl;
			break;
		}
	} while (s != "n"[0]);
	
	return 0;
}