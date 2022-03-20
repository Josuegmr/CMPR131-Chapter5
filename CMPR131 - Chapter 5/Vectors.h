#pragma once
#ifndef VECTORS_H
#define VECTORS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include "input.h" // use for validate input
#include "Student.h"

class Vectors
{
private:
	string fileName;
	vector<student> vec;

	// Display if the vector is empty
	void emptyVec()
	{
		cout << "\n\tThe vector is empty.";
	}
public:
	// Default Constructor
	Vectors() : fileName("input.dat") {};

	// Main menu
	void mainMenu()
	{
		cout << "\tVectors are sequence containers representing arrays that can change in size.\n";
		do
		{
			cout << "\n\t1> Vector's member functions";
			cout << "\n\t==========================================================================================================";
			cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
			cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
			cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
			cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
			cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
			cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
			cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
			cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
			cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
			cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector";
			cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
			cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
			cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
			cout << "\n\t\t\telement in the vector";
			cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
			cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
			cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
			cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
			cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
			cout << "\n\t\tS> Sort - Sorts the vector.";
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
				if (vec.size() != 0)
				{
					vec.clear();
					cout << "\n\tThe vector has been cleared.";
				}
				else
					emptyVec();
			} break;
			case 'B':
			{
				vec.reserve(inputInteger("\n\tEnter the capacity (1..100): ", 1, 100));
				cout << "\n\tThe vector has been reserved " << vec.capacity() << " elements.";
			} break;
			case 'C':
			{
				vec.resize(inputInteger("\n\tEnter the new size (1..100): ", 1, 100));
				cout << "\n\tThe vector has been resized to " << vec.size() << " elements.";
			} break;
			case 'D': addFileElements(); break;
			case 'E':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tElement, [" << (vec.size() - 1) << "]: " << vec[vec.size() - 1] << ", has been removed from the vector.\n";
					vec.pop_back();
					cout << "\n\tThe vector now has " << vec.size() << " elements.\n";
					printVector(vec);
				}
				else
					emptyVec();
			} break;
			case 'F':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tThe element from the front of the vector: ";
					cout << "[0] " << vec.front();
				}
				else
					emptyVec();
			} break;
			case 'G':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tThe element from the back of the vector: ";
					cout << "[" << vec.size() - 1 << "] " << vec.back();
				}
				else
					emptyVec();
			} break;
			case 'H': 
			{
				if (vec.size() != 0)
				{
					int index = inputInteger("\n\tEnter the index (0.." + to_string(vec.size() - 1) + "): ", 0, (int)vec.size() - 1);

					cout << "\n\t\tvector.at(" << index << "): " << vec.at(index) << '\n';
					cout << "\t\tvector[" << index << "]: " << vec[index];
				}
				else
					emptyVec();
			} break;
			case 'I':
			{
				if (vec.size() != 0)
					cout << "\n\tThe iterator referring the first element: " << &(*vec.begin()) << " (" << *vec.begin() << ")";
				else
					emptyVec();
			} break;
			case 'J':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tThe iterator referring to the past-the-end element: " << &(*(vec.end() - 1)) << " (" << *(vec.end() - 1)<< ")";
				}
				else
					emptyVec();
			} break;
			case 'K':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tUsing begin() and end(), the vector contains: ";
					for (auto n = vec.begin(); n != vec.end(); ++n)
						cout << "\n\t\t" << &(*n) << " (" << *n << ")";
				}
				else
					emptyVec();
			} break;
			case 'L':
			{
				if (vec.size() != 0)
					cout << "\n\tThe iterator referring the reverse first element: " << &(*vec.rbegin()) << " (" << *vec.rbegin() << ")";
				else
					emptyVec();
			} break; 
			case 'M':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tThe reverse iterator pointing to the theoretical element ";
					cout << "\n\tpreceding the first element in the vector: " << &(*(vec.rend() - 1)) << " (" << *(vec.rend() - 1) << ")";
				}
				else
					emptyVec();
			} break;
			case 'N':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tUsing rbegin() and rend(), the vector contains reversed elments:";
					for (auto n = vec.rbegin(); n != vec.rend(); ++n)
						cout << "\n\t\t" << &(*n) << " (" << *n << ")";
				}
				else
					emptyVec();
			} break;
			case 'O':
			{
				if (vec.size() != 0)
				{
					vec.erase(vec.begin() + 1);
					cout << "\n\tAn element after the begin iterator " << &(*vec.begin()) << " has been removed.";
				}
				else
					emptyVec();
			} break;
			case 'P':
			{
				if (vec.size() != 0)
				{
					cout << "\n\tAll elements starting at begin iterator " << &(*vec.begin()) << " has been removed.";
					cout << "\n\tand going up to end iterator " << &(*(vec.end() - 1)) << " have been removed.";
					vec.erase(vec.begin(), vec.end());
				}
				else
					emptyVec();
			} break;
			case 'Q': addElement(); break;
			case 'R':
			{
				if (vec.size() != 0)
				{
					vector<student> vec2;
					if (vec2.size() == 0)
						cout << "\n\tvector (v2) is initially empty.\n";

					vec.swap(vec2);
					if (vec.size() == 0)
						cout << "\n\tvector (v1) is empty after swapped with vector (v2).\n";
					
					cout << "\n\tvector (v2) after swapped with vector (v1).";
					printVector(vec2);
				}
				else
					emptyVec();
			} break; 
			case 'S':
			{
				if (vec.size() != 0)
				{
					sort(vec.begin(), vec.end());
					cout << "\n\tVector sorted. \n";
					printVector(vec);
				}
				else
					emptyVec();
			} break;
			default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
			}
			cout << '\n';
		} while (true);
	}

	// Precondition: std (vector)
	// Postcondition: Display all elements of the specified vector
	void printVector(vector<student> std)
	{
		for (int i = 0; i < std.size(); i++)
			cout << "\n\t\t[" << i << "]: " << std[i];
	}

	// Precondition:
	// Postcondition: Push back the elements of a file into the vector and display them
	void addFileElements()
	{
		fstream inFile (fileName, ios::in);
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
				vec.push_back(stud);
			}
		}
		inFile.close();

		cout << "\n\tThe vector has now " << vec.size() << " elements.\n";
		printVector(vec);
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

		vec.size() != 0 ? vec.insert(vec.begin() + 1, temp) : vec.insert(vec.begin(), temp);

		cout << "\n\tThe new element has been inserted " << (vec.size() > 1 ? "after" : "at") << " the begin iterator.\n";
		printVector(vec);
	}

};
#endif // !VECTORS_H


