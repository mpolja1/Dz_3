#include<iostream>
#include<thread>
#include "Tocka.h"

using namespace std;

const int redak = 20;
const int stupac = 40;

int main() {

	Tocka pocetak;
	Tocka kraj;

	cout << "Unesite A-x: ";
	cin >> pocetak.x;
	cout << "Unesite A-y: ";
	cin >> pocetak.y;

	cout << "Unesite B-x: ";
	cin >> kraj.x;
	cout << "Unesite B-y: ";
	cin >> kraj.y;

	
	char gr[redak][stupac];
	for (int i = 0; i < redak; i++)
	{
		for (int j = 0; j < stupac; j++)
		{
			if (pocetak.x - 1 == i && pocetak.y == j)
			{
				gr[i][j] = 'A';
			}
			else if (kraj.x - 1 == i && kraj.y - 1 == j)
			{
				gr[i][j] = 'B';
			}
			else
			{
				gr[i][j] = '-';
			}
		}
	}
	
	while (pocetak.x != kraj.x || pocetak.y != kraj.y)
	{
		this_thread::sleep_for(chrono::milliseconds(200));
		system("cls");
		for (size_t i = 0; i < redak; i++)
		{
			for (size_t j = 0; j < stupac; j++)
			{
				if (pocetak.x-1 == i && pocetak.y == j)
				{
					cout << 'x';
				}
				else
				{
					cout<<gr[i][j];
				}
			}
			cout << endl;
		}
		if (pocetak.x != kraj.x)
		{
			if (pocetak.x <= kraj.x)
			{
				pocetak.desno();
			}
			else if (pocetak.x >= kraj.x)
			{
				pocetak.lijevo();
			}
		}
		else if (pocetak.y != kraj.y)
		{
			if (pocetak.y <= kraj.y)
			{
				pocetak.gore();
			}
			else if (pocetak.y >= kraj.y)
			{
				pocetak.dolje();
			}
		}
	}
	return 0;
}