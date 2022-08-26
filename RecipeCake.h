#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class RecipeCake
{
private:
	string name;
	int time;
public:
	RecipeCake() {}
	RecipeCake(string name, int time)
	{
		this->name = name;
		this->time = time;
	}
	string getName()
	{
		return name;
	}
	int getTime()
	{
		return time;
	}
};