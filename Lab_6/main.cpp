#include "Main_Header.h"

void Pistol::weaponShowProp()
{
	StreamTable table(std::cout, '-', '|');
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(25);
	std::cout << "Pistol\n";
	table << "ammo storage" << "reloading time" << "caliber" << "weight" << "aiming range" << "count of shooting modes";
	table << ammo_storage << reload_time << calibr << weight << aiming_range << count_of_shooting_modes;
	std::cout << std::endl;
}


void Shotgun::weaponShowProp()
{
	StreamTable table(std::cout, '-', '|');
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(25);
	std::cout << "Shotgun\n";
	table << "ammo storage" << "reloading time" << "caliber" << "weight" << "aiming range" << "count of shooting modes";
	table << ammo_storage << reload_time << calibr << weight << aiming_range << count_of_shooting_modes;
	std::cout << std::endl;
}


void AssaultRifle::weaponShowProp()
{
	StreamTable table(std::cout, '-', '|');
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(25);
	std::cout << "Assault rifle\n";
	table << "ammo storage" << "reloading time" << "caliber" << "weight" << "aiming range" << "count of shooting modes";
	table << ammo_storage << reload_time << calibr << weight << aiming_range << count_of_shooting_modes;
	std::cout << std::endl;
}


void SniperRifle::weaponShowProp()
{
	StreamTable table(std::cout, '-', '|');
	for (size_t i = 0; i < COUNT_OF_COLUMNS; ++i)
		table.AddCol(25);
	std::cout << "Sniper rifle\n";
	table << "ammo storage" << "reloading time" << "caliber" << "weight" << "aiming range" << "count of shooting modes";
	table << ammo_storage << reload_time << calibr << weight << aiming_range << count_of_shooting_modes;
	std::cout << std::endl;
}


int Pistol::weaponReload(int ammo_count)
{
	if (ammo_count <= ammo_storage && ammo_count > 0)
	{
		ammo_storage = ammo_count;
		Sleep(reload_time * 1000);
		
	}
	return 0;
}


int Shotgun::weaponReload(int ammo_count)
{
	if (ammo_count <= ammo_storage && ammo_count > 0)
	{
		ammo_storage = ammo_count;
		Sleep(reload_time * 1000);
	}
	return 0;
}


int AssaultRifle::weaponReload(int ammo_count)
{
	if (ammo_count <= ammo_storage && ammo_count > 0)
	{
		ammo_storage = ammo_count;
		Sleep(reload_time * 1000);
	}
	return 0;
}


int SniperRifle::weaponReload(int ammo_count)
{
	if (ammo_count <= ammo_storage && ammo_count > 0)
	{
		ammo_storage = ammo_count;
		Sleep(reload_time * 1000);
	}
	return 0;
}


int Pistol::shooting(double target)
{
	std::cout << "shooting on " << target << " m.\n\n";
	double chance = 1 / pow(exp(target / 1000), 2) + 0.15;
	size_t goal_count = 0;
	char symb;
	std::cout << "making shooting: pistol......\n";
	do
	{
		for (size_t i = 0; i < ammo_storage; ++i)
		{
			if (chance >= 1)
				goal_count += 1;

			else if (chance >= 0.8 && chance < 1)
			{
				int value = rand() % 10;
				if (value <= 7)
					goal_count += 1;
			}
			else if (chance >= 0.6 && chance < 0.8)
			{
				int value = rand() % 10;
				if (value <= 5)
					goal_count += 1;
			}
			else if (chance >= 0.4 && chance < 0.6)
			{
				int value = rand() % 10;
				if (value <= 3)
					goal_count += 1;
			}
			else if (chance >= 0.2 && chance < 0.4)
			{
				int value = rand() % 10;
				if (value <= 1)
					goal_count += 1;
			}
			else
			{
				int value = rand() % 10;
				if (value == 0)
					goal_count += 1;
			}
		}
		std::cout << "hits on target: " << goal_count << "  ammo: " << ammo_storage << std::endl;
		std::cout << "do you want to reload your weapon? y/n\n";
		std::cin >> symb;

		if (symb == "y"[0])
		{
			weaponReload(1 + rand() % MAX_AMMO_STORAGE_PISTOL);
			goal_count = 0;
		}
		else if (symb == "n"[0])
			break;
		else
		{
			goal_count = 0;
			std::cout << "repeat input y or n!\n";
			std::cin >> symb;
			do
			{
				if (symb == "y"[0])
					break;
				else if (symb == "n"[0])
					return goal_count;
				else
				{
					std::cout << "repeat input y or n!\n";
					std::cin >> symb;
				}
			} while (true);
		}

	} while (true);
	std::cout << "\n\n";
	return goal_count;
}


int Shotgun::shooting(double target)
{
	std::cout << "shooting on " << target << " m.\n\n";
	double chance = 1 / pow(exp(target / 1000), 2) + 0.07;
	size_t goal_count = 0;
	char symb;
	std::cout << "making shooting: shotgun......\n";
	do
	{
		for (size_t i = 0; i < ammo_storage; ++i)
		{
			if (chance >= 1)
				goal_count += 1;

			else if (chance >= 0.8 && chance < 1)
			{
				int value = rand() % 10;
				if (value <= 7)
					goal_count += 1;
			}
			else if (chance >= 0.6 && chance < 0.8)
			{
				int value = rand() % 10;
				if (value <= 5)
					goal_count += 1;
			}
			else if (chance >= 0.4 && chance < 0.6)
			{
				int value = rand() % 10;
				if (value <= 3)
					goal_count += 1;
			}
			else if (chance >= 0.2 && chance < 0.4)
			{
				int value = rand() % 10;
				if (value <= 1)
					goal_count += 1;
			}
			else
			{
				int value = rand() % 10;
				if (value == 0)
					goal_count += 1;
			}
		}
		std::cout << "hits on target: " << goal_count << "  ammo: " << ammo_storage << std::endl;
		std::cout << "do you want to reload your weapon? y/n\n";
		std::cin >> symb;

		if (symb == "y"[0])
		{
			weaponReload(1 + rand() % MAX_AMMO_STORAGE_SHOTGUN);
			goal_count = 0;
		}
		else if (symb == "n"[0])
			break;
		else
		{
			goal_count = 0;
			std::cout << "repeat input y or n!\n";
			std::cin >> symb;
			do
			{
				if (symb == "y"[0])
					break;
				else if (symb == "n"[0])
					return goal_count;
				else
				{
					std::cout << "repeat input y or n!\n";
					std::cin >> symb;
				}
			} while (true);
		}

	} while (true);
	std::cout << "\n\n";
	return goal_count;
}


int AssaultRifle::shooting(double target)
{
	std::cout << "shooting on " << target << " m.\n\n";
	double chance = 1 / pow(exp(target / 1000), 2) + 0.45, k = 0;
	size_t goal_count = 0;
	char symb;
	std::cout << "making shooting: assault rifle......\n";
	std::cout << "choose firing mode: b(burst shooting)/s(single shooting)\n";
	std::cin >> symb;
	if (symb == "b"[0])
		k = 0.01;
	else if (symb == "s"[0])
		k = 0;
	else
	{
		std::cout << "repeat input b or s!\n";
		std::cin >> symb;
		do
		{
			if (symb == "b"[0])
			{
				k = 0.01;
				break;
			}
			else if (symb == "s"[0])
			{
				k = 0;
				break;
			}
			else
			{
				std::cout << "repeat input b or s!\n";
				std::cin >> symb;
			}
		} while (true);
	}
	do
	{
		for (size_t i = 0; i < ammo_storage; ++i)
		{
			chance -= k;
			if (chance >= 1)
				goal_count += 1;

			else if (chance >= 0.8 && chance < 1)
			{
				int value = rand() % 10;
				if (value <= 7)
					goal_count += 1;
			}
			else if (chance >= 0.6 && chance < 0.8)
			{
				int value = rand() % 10;
				if (value <= 5)
					goal_count += 1;
			}
			else if (chance >= 0.4 && chance < 0.6)
			{
				int value = rand() % 10;
				if (value <= 3)
					goal_count += 1;
			}
			else if (chance >= 0.2 && chance < 0.4)
			{
				int value = rand() % 10;
				if (value <= 1)
					goal_count += 1;
			}
			else
			{
				int value = rand() % 10;
				if (value == 0)
					goal_count += 1;
			}
			if (symb == "b"[0])
				k += 0.001;
		}
		std::cout << "hits on target: " << goal_count << "  ammo: " << ammo_storage << std::endl;
		std::cout << "do you want to reload your weapon? y/n\n";
		std::cin >> symb;

		if (symb == "y"[0])
		{
			weaponReload(1 + rand() % MAX_AMMO_STORAGE_ASSAULT_RIFLE);
			goal_count = 0;
		}
		else if (symb == "n"[0])
			break;
		else
		{
			goal_count = 0;
			std::cout << "repeat input y or n!\n";
			std::cin >> symb;
			do
			{
				if (symb == "y"[0])
					break;
				else if (symb == "n"[0])
					return goal_count;
				else
				{
					std::cout << "repeat input y or n!\n";
					std::cin >> symb;
				}
			} while (true);
		}

	} while (true);
	std::cout << "\n\n";
	return goal_count;
}


int SniperRifle::shooting(double target)
{
	std::cout << "shooting on " << target << " m.\n\n";
	double chance = 1 / pow(exp(target / 1000), 2) + 0.8;
	size_t goal_count = 0;
	char symb;
	std::cout << "making shooting: sniper rifle......\n";
	do
	{
		for (size_t i = 0; i < ammo_storage; ++i)
		{
			if (chance >= 1)
				goal_count += 1;

			else if (chance >= 0.8 && chance < 1)
			{
				int value = rand() % 10;
				if (value <= 7)
					goal_count += 1;
			}
			else if (chance >= 0.6 && chance < 0.8)
			{
				int value = rand() % 10;
				if (value <= 5)
					goal_count += 1;
			}
			else if (chance >= 0.4 && chance < 0.6)
			{
				int value = rand() % 10;
				if (value <= 3)
					goal_count += 1;
			}
			else if (chance >= 0.2 && chance < 0.4)
			{
				int value = rand() % 10;
				if (value <= 1)
					goal_count += 1;
			}
			else
			{
				int value = rand() % 10;
				if (value == 0)
					goal_count += 1;
			}
		}
		std::cout << "hits on target: " << goal_count << "  ammo: " << ammo_storage << std::endl;
		std::cout << "do you want to reload your weapon? y/n\n";
		std::cin >> symb;

		if (symb == "y"[0])
		{
			weaponReload(1 + rand() % MAX_AMMO_STORAGE_SNIPER_RIFLE);
			goal_count = 0;
		}
		else if (symb == "n"[0])
			break;
		else
		{ 
			goal_count = 0;
			std::cout << "repeat input y or n!\n";
			std::cin >> symb;
			do
			{
				if (symb == "y"[0])
					break;
				else if (symb == "n"[0])
					return goal_count;
				else
				{
					std::cout << "repeat input y or n!\n";
					std::cin >> symb;
				}
			} while (true);
		}

	} while (true);
	std::cout << "\n\n";
	return goal_count;
}


void ShootingRange::shooting()
{
	Pistol pistol; Shotgun shotgun; AssaultRifle assault_rifle; SniperRifle sniper_rifle;
	std::cout << "weapons\n\n";
	pistol.weaponShowProp(); shotgun.weaponShowProp(); assault_rifle.weaponShowProp(); sniper_rifle.weaponShowProp();
	for (size_t i = 0; i < TARGET_COUNT; ++i)
	{
		pistol.shooting(TARGETS[i]);
		shotgun.shooting(TARGETS[i]);
		assault_rifle.shooting(TARGETS[i]);
		sniper_rifle.shooting(TARGETS[i]);
	}
}


int main(void)
{
	srand(time(0));
	ShootingRange shooting_range;
	shooting_range.shooting();
	return 0;
}