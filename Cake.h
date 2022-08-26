#pragma once
#include<iostream>

using namespace std;

class Cake
{
private:
	string name;
public:
	Cake() {}
	Cake(string name)
	{
		this->name = name;
	}
	string getName()
	{
		return name;
	}
	void setName(string name)
	{
		this->name = name;
	}
};