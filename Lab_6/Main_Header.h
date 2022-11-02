#include "SimpleTable.h"
#include <Windows.h>

//constexpr int TARGET_COUNT = 8;
constexpr int COUNT_OF_COLUMNS = 6;
constexpr int MAX_AMMO_STORAGE_PISTOL = 8;
constexpr int MAX_AMMO_STORAGE_SHOTGUN = 15;
constexpr int MAX_AMMO_STORAGE_ASSAULT_RIFLE = 30;
constexpr int MAX_AMMO_STORAGE_SNIPER_RIFLE = 20;
constexpr int TARGET_COUNT = 5;
constexpr double TARGETS[TARGET_COUNT] = { 35.5, 50, 400, 1000, 123.1 };

/*
формулы для расчета: 1/e^(прицельная дальность) + x = 1  найти x в статике!
*/

class Weapon
{
	virtual void weaponShowProp() = 0;
	virtual int weaponReload(int ammo_count) = 0;
	virtual int shooting(double target) = 0;
};


class Pistol : public Weapon
{
private:
	int ammo_storage;
	double reload_time;
	std::string calibr;
	double weight;
	double aiming_range;
	int count_of_shooting_modes;
public:
	Pistol(int ammo_storage = 8, double reload_time = 2.5, std::string calibr = "9mm", double weight = 405, double aiming_range = 80, int count_of_shooting_modes = 1) : ammo_storage(ammo_storage), reload_time(reload_time), calibr(calibr), weight(weight), aiming_range(aiming_range), count_of_shooting_modes(count_of_shooting_modes)
	{}
	void weaponShowProp();
	int weaponReload(int ammo_count);
	int shooting(double target);
};


class Shotgun : public Weapon
{
private:
	int ammo_storage;
	double reload_time;
	std::string calibr;
	double weight;
	double aiming_range;
	int count_of_shooting_modes;
public:
	Shotgun(int ammo_storage = 15, double reload_time = 20, std::string calibr = "20mm", double weight = 2000, double aiming_range = 40, int count_of_shooting_modes = 1) : ammo_storage(ammo_storage), reload_time(reload_time), calibr(calibr), weight(weight), aiming_range(aiming_range), count_of_shooting_modes(count_of_shooting_modes)
	{}
	void weaponShowProp();
	int weaponReload(int ammo_count);
	int shooting(double target);
};


class AssaultRifle : public Weapon
{
private:
	int ammo_storage;
	double reload_time;
	std::string calibr;
	double weight;
	double aiming_range;
	int count_of_shooting_modes;
public:
	AssaultRifle(int ammo_storage = 30, double reload_time = 5, std::string calibr = "7.62mm", double weight = 3000, double aiming_range = 300, int count_of_shooting_modes = 2) : ammo_storage(ammo_storage), reload_time(reload_time), calibr(calibr), weight(weight), aiming_range(aiming_range), count_of_shooting_modes(count_of_shooting_modes)
	{}
	void weaponShowProp();
	int weaponReload(int ammo_count);
	int shooting(double target);
};


class SniperRifle : public Weapon
{
private:
	int ammo_storage;
	double reload_time;
	std::string calibr;
	double weight;
	double aiming_range;
	int count_of_shooting_modes;
public:
	SniperRifle(int ammo_storage = 20, double reload_time = 5, std::string calibr = "7.62mm", double weight = 4000, double aiming_range = 800, int count_of_shooting_modes = 1) : ammo_storage(ammo_storage), reload_time(reload_time), calibr(calibr), weight(weight), aiming_range(aiming_range), count_of_shooting_modes(count_of_shooting_modes)
	{}
	void weaponShowProp();
	int weaponReload(int ammo_count);
	int shooting(double target);
};


class ShootingRange
{
public:
	ShootingRange()
	{}
	void shooting();
};