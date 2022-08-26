#pragma once
#include<iostream>
#include<fstream>
#include<list>
#include<iterator>

#include"Cake.h"

using namespace std;

ifstream g("CarouselOfCakes.txt");

class CarouselOfCakes
{
private:
	list<Cake*>storage;
	const unsigned int maxCapacity = 12;
	const unsigned int lowLimit = 3;
public:
	unsigned CurrentCapacity;
	string name_cake;
	CarouselOfCakes()
	{
		while (!g.eof())
		{
			g >> name_cake;
			auto b = new Cake(name_cake);
			storage.push_back(b);
			CurrentCapacity++;
		}
	}
	bool addCake(Cake cake)
	{
		if (CurrentCapacity < maxCapacity)
		{
			g >> name_cake;
			auto b = new Cake(name_cake);
			storage.push_back(b);
			CurrentCapacity++;
			return true;
		}
		else
			return false;
	}
	Cake getCake(string name)
	{
		Cake getCake;
		int k = 0;
		for (auto a : storage)
		{
			if (a->getName() == name)
			{
				k = 1;
				getCake = *a;
				storage.remove(a);
				break;
			}
		}
		if (k == 1)
		{
			CurrentCapacity--;
		}
		return getCake;
	}
	int getCurrentCapacity()
	{
		return CurrentCapacity;
	}
	void ShowCarousel()
	{
		for (auto a : storage)
		{
			cout << a->getName() << " ";
			cout << endl;
		}
	}
	friend class CommandTaker;
};