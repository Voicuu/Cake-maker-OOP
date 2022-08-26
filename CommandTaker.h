#pragma once
#include<iostream>
#include<list>
#include<iterator>

#include"CakeMaker.h"
#include"CarouselOfCakes.h"
#include"Cake.h"
#include"RecipeCake.h"

using namespace std;

class CommandTaker
{
private:
	RecipeCake carouselRecipe;
	CakeMaker cakeMaker;
	CarouselOfCakes carousel;
public:
	Cake cake;
	CommandTaker() {}
	Cake takeCommand(RecipeCake recipe)
	{
		Cake a;
		int k = 0;
		for (auto b : carousel.storage)
		{
			if (b->getName() == recipe.getName())
			{
				a = carousel.getCake(recipe.getName());
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			Cake* b;
			cout << "Asteptati..." << endl;
			b = new Cake(cakeMaker.takeCommand(recipe));
			cout << "Bucurati-va de prajitura!" << endl;
			return a;

		}
		refillCarousel();
		cout << "Bucurati-va de prajitura!" << endl;
		return a;
	}
	Cake* takeCommand(RecipeCake recipe, int nrOfCakes)
	{
		Cake* a;
		cout << "Asteptati..." << endl;
		do 
		{
			a = new Cake(cakeMaker.takeCommand(recipe));
			nrOfCakes--;
		} while (nrOfCakes > 0);
		cout << "Bucurati-va de prajitura!" << endl;
		return a;
	}
	Cake takeCommand(string nameOfCake)
	{
		Cake a;
		int k = 0;
		for (auto b : carousel.storage)
		{
			if (b->getName() == nameOfCake)
			{
				a = carousel.getCake(nameOfCake);
				k = 1;
				break;
			}
		}
		if (k == 0)
		{
			cout << "Asteptati..." << endl;
			RecipeCake recipe(nameOfCake, 5);
			a = cakeMaker.takeCommand(recipe);
		}
		refillCarousel();
		cout << "Bucurati-va de prajitura!" << endl;
		return a;
	}
	bool getCakesFromCarousel()
	{
		if (true)
			carousel.ShowCarousel();
		else
			return false;
	}
private:
	bool checkCarouselOfCakes()
	{
		if (carousel.getCurrentCapacity() > carousel.lowLimit)
			return true;
		return false;
	}
	bool refillCarousel()
	{
		if (checkCarouselOfCakes() == false)
		{
			do 
			{
				RecipeCake recipe("Tiramisu", 2);
				cake.setName(recipe.getName());
				carousel.addCake(cake);
			} while (carousel.getCurrentCapacity() < 12);
			return true;
		}
		return false;
	}
	friend class CarouselOfCakes;
};