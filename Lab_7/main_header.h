#pragma once
#include "simple_table.h"
constexpr int COUNT_OF_TOWERS = 8;
constexpr int COUNT_OF_COLUMNS = 4;
using values = std::pair<bool, int>;
class Dragon;
class Tower;
class Fortress;


class Dragon
{
private:
	int survivability;
	std::array<size_t, 3> heads;
public:
	void getDamage(int damage);
	bool checkDeath();
	Dragon(int survivability = 1000);
	bool attack(Fortress& fortress, int tower_for_atack, int* tower_integrity);
};


class Tower
{
public:
	int strength;
	int attack;
	void getDamage(int damage);
	bool checkDestruction();
	Tower(int strength = 100, int attack = 0) : strength(strength), attack(attack)
	{}
};


class Fortress
{
public:
	std::vector<Tower> fortress_towers;
	Fortress();
	void clear();
	values attack(Dragon& dragon, int tower_for_atack, int damage_for_dragon);
};
