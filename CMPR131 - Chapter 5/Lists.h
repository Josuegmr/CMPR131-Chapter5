#pragma once
#ifndef LISTS_H
#define LISTS_H

#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "input.h" // use for validate input
#include "Student.h"

class Lists
{
private:
	string fileName;
	list<student> li;

	// Display if the vector is empty
	void emptyVec()
	{
		cout << "\n\tThe vector is empty.";
	}
public:
	// Default Constructor
	Lists() : fileName("input.dat") {};

	// Main menu
	void mainMenu()
	{
		list<student> li2;

		cout << "\tLists are sequence containers that allow constant time insert and erase operations anywhere within the\n";
		cout << "\tsequence, and iteration in both directions.\n";
		do
		{
			cout << "\n\t2> List container";
			cout << "\n\t==========================================================================================================";
			cout << "\n\t\tA> clear() - Destroys all elements from the list";
			cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
			cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
			cout << "\n\t\tD> pop_front() - Deletes the first element";
			cout << "\n\t\tE> front() - Accesses the first element";
			cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
			cout << "\n\t\tG> pop_back() - Delete the last element";
			cout << "\n\t\tH> back() Accesses the last element";
			cout << "\n\t\tI> begin() - Returns an iterator refereing to the first element in the list";
			cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
			cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
			cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
			cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element";
			cout << "\n\t\t\tin the list";
			cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
			cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
			cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements(using iterators)";
			cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
			cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
			cout << "\n\t\tS> Sort - Sorts the list.";
			cout << "\n\t----------------------------------------------------------------------------------------------------------";
			cout << "\n\t\t0> Return";
			cout << "\n\t==========================================================================================================\n";

			int option = inputChar("\n\tOption: ");
			system("cls");
			if (option == '0') break;

			switch (option)
			{
			case 'A':
			{
				if (li.size() != 0)
				{
					li.clear();
					cout << "\n\tThe list has been cleared.";
				}
				else
					emptyVec();
			} break;
			case 'B':
			{
				li.resize(inputInteger("\n\tEnter the new size (1..100): ", 1, 100));
				cout << "\n\tThe list has been resized to " << li.size() << " elements.";
			} break;
			case 'C': addFileElements(true); break;
			case 'D':
			{
				if (li.size() != 0)
				{
					cout << "\n\tFirst element, (" << *li.begin() << "), has been removed from the list.\n";
					li.pop_front();
					cout << "\n\tThe list now has " << li.size() << " elements.\n";
					printList(li);
				}
				else
					emptyVec();
			} break;
			case 'E':
			{
				if (li.size() != 0)
					cout << "\n\tFirst element from the list is (" << li.front() << ").";
				else
					emptyVec();
			} break; 
			case 'F': addFileElements(false); break;
			case 'G':
			{
				if (li.size() != 0)
				{
					cout << "\n\tLast element, (" << li.back() << "), has been removed from the list.\n";
					li.pop_back();
					cout << "\n\tThe list now has " << li.size() << " elements.\n";
					printList(li);
				}
				else
					emptyVec();
			} break;
			case 'H':
			{
				if (li.size() != 0)
					cout << "\n\tLast element from the list is (" << li.back() << ").";
				else
					emptyVec();
			} break;
			case 'I':
			{
				if (li.size() != 0)
					cout << "\n\tThe iterator referring the first element: " << &(*li.begin()) << " (" << *li.begin() << ")";
				else
					emptyVec();
			} break;
			case 'J':
			{
				if (li.size() != 0)
				{
					cout << "\n\tThe iterator referring to the past-the-end element: " << &(*(--li.end())) << " (" << *--li.end() << ")";
				}
				else
					emptyVec();
			} break;
			case 'K':
			{
				if (li.size() != 0)
				{
					cout << "\n\tUsing begin() and end(), the list contains: ";
					for (auto n = li.begin(); n != li.end(); ++n)
						cout << "\n\t\t" << &(*n) << " (" << *n << ")";
				}
				else
					emptyVec();
			} break;
			case 'L':
			{
				if (li.size() != 0)
					cout << "\n\tThe iterator referring the reverse first element: " << &(*li.rbegin()) << " (" << *li.rbegin() << ")";
				else
					emptyVec();
			} break;
			case 'M':
			{
				if (li.size() != 0)
				{
					cout << "\n\tThe iterator referring to the reverse past-the-end element: " << &(*(--li.rend())) << " (" << *--li.rend() << ")";
				}
				else
					emptyVec();
			} break;
			case 'N':
			{
				if (li.size() != 0)
				{
					cout << "\n\tUsing rbegin() and rend(), the list contains reversed elments:";
					for (auto n = li.rbegin(); n != li.rend(); ++n)
						cout << "\n\t\t" << &(*n) << " (" << *n << ")";
				}
				else
					emptyVec();
			} break;
			case 'O':
			{
				if (li.size() != 0)
				{
					li.erase(li.begin()++);
					cout << "\n\tAn element after the begin iterator " << &(*li.begin()) << " has been removed.";
				}
				else
					emptyVec();
			} break;
			case 'P':
			{
				if (li.size() != 0)
				{
					cout << "\n\tAll elements starting at begin iterator " << &(*li.begin()) << " has been removed.";
					cout << "\n\tand going up to end iterator " << &(*li.end()) << " have been removed.";
					li.erase(li.begin(), li.end());
				}
				else
					emptyVec();
			} break;
			case 'Q': addElement(); break;
			case 'R':
			{
				if (li.size() != 0)
				{
					list<student> li2;
					if (li2.size() == 0)
						cout << "\n\tlist (l2) is initially empty.\n";

					li.swap(li2);
					if (li.size() == 0)
						cout << "\n\tlist (l1) is empty after swapped with list (l2).\n";

					cout << "\n\tlist (l2) after swapped with list (l1).";
					printList(li2);
				}
				else
					emptyVec();
			} break;
			case 'S':
			{
				if (li.size() != 0)
				{
					li.sort();
					cout << "\n\tList sorted. \n";
					printList(li);
				}
				else
					emptyVec();
			} break;
			default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
			}
			cout << '\n';
		} while (true);
	}

	// Precondition: std (list)
	// Postcondition: Display all elements of the specified list
	void printList(list<student> std)
	{
		int count = 0;
		for (auto n = std.begin(); n != std.end(); ++n)
			cout << "\n\t\t[" << count++ << "]: " << *n;
	}

	// Precondition: push (boolean) front or back
	// Postcondition: Push front or back (depend of push) the elements of a file into the list and display them
	void addFileElements(bool push)
	{
		fstream inFile(fileName, ios::in);
		// Filling up the array with the file's data
		while (!inFile.eof())
		{
			string line;
			while (getline(inFile, line)) // grabbing the whole line
			{
				student stud;
				stringstream ss(line);
				string name, level, gpa;

				// Seperating the strings
				getline(ss, name, ',');
				getline(ss, level, ',');
				getline(ss, gpa, ',');

				// Add into the student class
				stud.setName(name);
				stud.setGradeLevel(level);
				stud.setGPA(stod(gpa));

				// Filling the vector
				push == true ? li.push_front(stud) : li.push_back(stud);
			}
		}
		inFile.close();

		cout << "\n\tThe list has now " << li.size() << " elements.\n";
		printList(li);
	}

	// Precondition:
	// Postcondition: Insert the an element after the begin iterator.
	void addElement()
	{
		student temp;
		temp.setName(inputString("\n\tEnter a new student name: ", true));
		int level = inputInteger("\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
		temp.setGradeLevel(level == 1 ? "Freshman" : level == 2 ? "Sophmore" : level == 3 ? "Junior" : level == 4 ? "Senior" : "Unknown");
		temp.setGPA(inputDouble("\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0));

		li.size() != 0 ? li.insert(++li.begin(), temp) : li.insert(li.begin(), temp);

		cout << "\n\tThe new element has been inserted " << (li.size() > 1 ? "after" : "at") << " the begin iterator.\n";
		printList(li);
	}
};
#endif // !LISTS_H


