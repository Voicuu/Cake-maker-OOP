#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<iterator>
#include<string>
#include<stdlib.h>
#include<Windows.h>

#include "RecipeCake.h"
#include "CommandTaker.h"
#include "Cake.h"
#include "CarouselOfCakes.h"
#include "CakeMaker.h"

using namespace std;

ifstream f("CakeMaker.txt");

class CommandPanel
{
private:
	list<RecipeCake*> menu;
	CommandTaker commandTaker;
public:
	CarouselOfCakes carousel;
	string name;
	int time;
	CommandPanel() {
		while (!f.eof())
		{
			f >> name;
			f >> time;
			auto a = new RecipeCake(name, time);
			menu.push_back(a);
		}
	}
	void showProducts()
	{
		cout << "\tPrajituri care nu sunt facute:" << endl;
		for (auto a : menu)
		{
			cout << "Prajitura: " << a->getName() << endl;
			cout << "Timpul alocat pregatirii: " << a->getTime() << " secunde" << endl << endl;
		}
		cout << endl << "\tPrajituri pregatite: " << endl;
		commandTaker.getCakesFromCarousel();
		cout << endl;
	}
	void selectProduct(string name)
	{
		int k = 0;
		for (auto a : menu)
		{
			if (a->getName() == name)
			{
				k = 1;
				RecipeCake Reteta(*a);
				commandTaker.takeCommand(a->getName());
				break;
			}
		}
		carousel.getCake(name);
		if (k == 0)
		{
			cout << endl << "Prajitura cautata nu exista!" << endl << endl;
		}
	}
	void selectProduct(string name, int numberOfProducts)
	{
		int k = 0;
		if (numberOfProducts >= 1)
		{
			for (auto a : menu)
			{
				if (a->getName() == name)
				{
					k = 1;
					commandTaker.takeCommand(*a, numberOfProducts)->getName();
					break;
				}
			}
		}
		else
		{
			for (auto a : menu)
			{
				if (a->getName() == name)
				{
					commandTaker.takeCommand(a->getName());
					k = 2;
					break;
				}
			}
		}
		if (k == 0)
		{
			cout << endl << "Prajitura cautata nu exista!" << endl << endl;
		}
	}
	void showProductsInCarousel()
	{
		commandTaker.getCakesFromCarousel();
	}
	friend class CommandTaker;
};