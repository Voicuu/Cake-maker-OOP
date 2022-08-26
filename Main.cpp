#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <iterator>

#include "CommandPanel.h"
#include "Cake.h"
#include "CakeMaker.h"
#include "RecipeCake.h"
#include "CarouselOfCakes.h"
#include "CommandTaker.h"

using namespace std;

int main()
{
	CommandPanel cmd;
	int opt, nr;
	string name;
	do
	{
		cout << "0. Iesire." << endl;
		cout << "1. Afisare prajituri." << endl;
		cout << "2. Comanda prajitura." << endl;
		cout << "3. Comanda prajitura + numarul de prajituri comandate." << endl;
		cout << "4. Afisare prajituri din carusel" << endl;
		cout << "Optiunea dvs. este: ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			cout << endl << "Multumim, la revedere!" << endl;
			exit(0);
			break;
		case 1:
			cout << endl;
			cmd.showProducts();
			cout << endl;
			break;
		case 2:
			cout << endl;
			cout << "Vanzator: Ce prajitura doriti sa cumparati?" << endl;
			cout << "Dumneavoastra: ";
			cin >> name;
			cmd.selectProduct(name);
			cout << endl;
			break;
		case 3:
			cout << "Vanzator: Ce prajitura doriti sa cumparati?" << endl;
			cout << "Dumneavoastra: ";
			cin >> name;
			cout << "Super! Cate doriti?" << endl;
			cout << "Dumneavoastra: ";
			cin >> nr;
			cmd.selectProduct(name, nr);
			break;
		default: 
			cout << "Optiune invalida!" << endl;
			break;
		}
	} while (1);
	return 0;
}