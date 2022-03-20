#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <list>
#include <iomanip>
#include "input.h" // use for validate input

class Application
{
private:
	int num;
	list<int> myList;

public:
	Application() : num(0) {};

	// Main Menu
	void mainMenu()
	{
		do
		{
			cout << "\t3> Application using Vector and/or List container";
			cout << "\n\t==============================================================";
			cout << "\n\t\tA> Add an integer";
			cout << "\n\t\tB> Delete an integer";
			cout << "\n\t\tC> Display input integers";
			cout << "\n\t\tD> Display frequencies of integers";
			cout << "\n\t--------------------------------------------------------------";
			cout << "\n\t\t0> Return";
			cout << "\n\t==============================================================\n";

			int option = inputChar("\n\tOption: ");
			system("cls");
			if (option == '0') break;

			switch (option)
			{
			case 'A': 
			{
				myList.push_back(inputInteger("\n\tAdd an integer: ", 1, 100));
			} break;
			case 'B':
			{
				myList.remove(inputInteger("\n\tDelete an integer: ", 1, 100));
			} break;
			case 'C':
			{
				cout << "\n\tContainer: ";
				if (myList.size() != 0)
				{
					for (auto it = myList.begin(); it != myList.end(); it++)
						cout << *it << " ";
					cout << '\n';
				}
				else
					cout << "empty.\n";
			} break;
			case 'D':
			{
				if (myList.size() != 0)
					frequecies();
				else
					cout << "\n\tContainer: empty.\n";
			} break;
			default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
			}
			cout << '\n';
		} while (true);
	}

	// Precondition:
	// Postcondition: Display a table with the values and frequency of each value with it %
	void frequecies()
	{
		cout << "\n\t" << setw(7) << left << "Value" << setw(11) << left << "Frequency" << "Frequency %";
		myList.sort();

		int value = *myList.begin();
		for (int k = 0; k < myList.size(); k++)
		{
			list<int>::iterator it = myList.begin();
			advance(it, k);
			int frequency = 0;
			if (value == *it)
				continue;
			value = *it;
			for (int i = 0; i < myList.size(); i++)
			{
				list<int>::iterator it2 = myList.begin();
				advance(it2, i);
				if (*it2 == value)
					frequency++;
			}
			double percentage = ((double)frequency / (double)myList.size()) / 0.01;
			cout << setprecision(2) << fixed;
			cout << "\n\t" << setw(7) << left << value << setw(11) << left << frequency << percentage;
		}
		cout << endl;
	}
};
#endif // !APPLICATION_H


