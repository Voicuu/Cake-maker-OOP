#pragma once
#include<iostream>
#include<Windows.h>

#include"RecipeCake.h"
#include"Cake.h"

using namespace std;

class CakeMaker
{
public:
	CakeMaker() {}
	Cake takeCommand(RecipeCake recipe)
	{
		Cake newCake;
		newCake.setName(recipe.getName());
		int time = recipe.getTime();
		Sleep(time * 1000);
		return newCake;
	}
};