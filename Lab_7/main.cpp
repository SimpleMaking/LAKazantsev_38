#include "main_header.h"



Dragon::Dragon(int survivability) : survivability(survivability)
{
	heads[0] = 0; heads[1] = 0; heads[2] = 0;
}


Fortress::Fortress()
{
	for (size_t i = 0; i < COUNT_OF_TOWERS; ++i)
		fortress_towers.push_back(Tower());
}


void Tower::getDamage(int damage)
{
	strength -= damage;
}


bool Tower::checkDestruction()
{
	if (strength <= 0)
		return 1;
	else
		return 0;
}


bool Dragon::attack(Fortress& fortress, int tower_for_atack, int* tower_integrity)
{
		if (tower_for_atack == 0)
		{
			if (fortress.fortress_towers[COUNT_OF_TOWERS - 1].checkDestruction() || fortress.fortress_towers[0].checkDestruction() || fortress.fortress_towers[1].checkDestruction())
				return 1;

			heads[0] = 20 + rand() % 31;
			heads[1] = 20 + rand() % 31;
			heads[2] = 20 + rand() % 31;
			fortress.fortress_towers[COUNT_OF_TOWERS - 1].getDamage(heads[0]);
			fortress.fortress_towers[0].getDamage(heads[1]);
			fortress.fortress_towers[1].getDamage(heads[2]);
			tower_integrity[0] = fortress.fortress_towers[COUNT_OF_TOWERS - 1].strength;
			tower_integrity[1] = fortress.fortress_towers[0].strength;
			tower_integrity[2] = fortress.fortress_towers[1].strength;
		}
		else if (tower_for_atack == COUNT_OF_TOWERS - 1)
		{
			if (fortress.fortress_towers[COUNT_OF_TOWERS - 2].checkDestruction() || fortress.fortress_towers[COUNT_OF_TOWERS - 1].checkDestruction() || fortress.fortress_towers[0].checkDestruction())
				return 1;

			heads[0] = 20 + rand() % 31;
			heads[1] = 20 + rand() % 31;
			heads[2] = 20 + rand() % 31;
			fortress.fortress_towers[COUNT_OF_TOWERS - 2].getDamage(heads[0]);
			fortress.fortress_towers[COUNT_OF_TOWERS - 1].getDamage(heads[1]);
			fortress.fortress_towers[0].getDamage(heads[2]);
			tower_integrity[0] = fortress.fortress_towers[COUNT_OF_TOWERS - 2].strength;
			tower_integrity[1] = fortress.fortress_towers[COUNT_OF_TOWERS - 1].strength;
			tower_integrity[2] = fortress.fortress_towers[0].strength;
		}
		else
		{
			if (fortress.fortress_towers[tower_for_atack - 1].checkDestruction() || fortress.fortress_towers[tower_for_atack].checkDestruction() || fortress.fortress_towers[tower_for_atack + 1].checkDestruction())
				return 1;

			heads[0] = 20 + rand() % 31;
			heads[1] = 20 + rand() % 31;
			heads[2] = 20 + rand() % 31;
			fortress.fortress_towers[tower_for_atack - 1].getDamage(heads[0]);
			fortress.fortress_towers[tower_for_atack].getDamage(heads[1]);
			fortress.fortress_towers[tower_for_atack + 1].getDamage(heads[2]);
			tower_integrity[0] = fortress.fortress_towers[tower_for_atack - 1].strength;
			tower_integrity[1] = fortress.fortress_towers[tower_for_atack].strength;
			tower_integrity[2] = fortress.fortress_towers[tower_for_atack + 1].strength;
		}
		return 0;
}


bool Dragon::checkDeath()
{
	if (survivability <= 0)
		return 1;
	else
		return 0;
}


void Dragon::getDamage(int damage)
{
	survivability -= damage;
}


values Fortress::attack(Dragon& dragon, int tower_for_atack, int damage_for_dragon)
{

	if (tower_for_atack == 0)
	{
		if (dragon.checkDeath())
			return { 1, damage_for_dragon };

		fortress_towers[COUNT_OF_TOWERS - 1].attack = 20 + rand() % 31;
		fortress_towers[1].attack = 20 + rand() % 31;
	
		dragon.getDamage(fortress_towers[COUNT_OF_TOWERS - 1].attack);
		dragon.getDamage(fortress_towers[1].attack);
		damage_for_dragon += fortress_towers[COUNT_OF_TOWERS - 1].attack;
		damage_for_dragon += fortress_towers[1].attack;
	}
	else if (tower_for_atack == COUNT_OF_TOWERS - 1)
	{
		if (dragon.checkDeath())
			return { 1, damage_for_dragon };

		fortress_towers[COUNT_OF_TOWERS - 2].attack = 20 + rand() % 31;
		fortress_towers[0].attack = 20 + rand() % 31;

		dragon.getDamage(fortress_towers[COUNT_OF_TOWERS - 2].attack);
		dragon.getDamage(fortress_towers[0].attack);
		damage_for_dragon += fortress_towers[COUNT_OF_TOWERS - 2].attack;
		damage_for_dragon += fortress_towers[0].attack;
	}
	else
	{
		if (dragon.checkDeath())
			return { 1, damage_for_dragon };

		fortress_towers[tower_for_atack - 1].attack = 20 + rand() % 31;
		fortress_towers[tower_for_atack + 1].attack = 20 + rand() % 31;

		dragon.getDamage(fortress_towers[tower_for_atack - 1].attack);
		dragon.getDamage(fortress_towers[tower_for_atack + 1].attack);
		damage_for_dragon += fortress_towers[tower_for_atack - 1].attack;
		damage_for_dragon += fortress_towers[tower_for_atack + 1].attack;
	}
	return { 0, damage_for_dragon };
}


void Fortress::clear()
{
	fortress_towers.clear();
}


int main(void)
{
	srand(time(0));
	StreamTable table(std::cout, '-', '|');
	int tower_for_atack = rand() % COUNT_OF_TOWERS;
	bool dragon_flag = 0;
	int damage_for_dragon = 0; 
	int tower_integrity[3] = { 0 };
	std::pair<bool, int> p = { 0, 0 };
	Dragon dragon; Fortress fortress;
	while (!dragon_flag && !p.first)
	{
		std::cout << "dragon attack our fortress!!!.........../\n";
		dragon_flag = dragon.attack(fortress, tower_for_atack, tower_integrity);
		std::cout << "our fortress repulsed the attack...../\n";
		p = fortress.attack(dragon, tower_for_atack, damage_for_dragon);
	}
	fortress.clear();
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(23);

	std::cout << "Battle stats\n";
	table << "dragon damage" << "1 tower survivability" << "2 tower survivability" << "3 tower survivability";
	table << p.second << tower_integrity[0] << tower_integrity[1] << tower_integrity[2];
	return 0;
}