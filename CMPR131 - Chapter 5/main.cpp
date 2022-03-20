// date: 03/19/2022
// description: Chapter 5 - Assignment

#include <iostream>
#include <list>
#include "Vectors.h"
#include "Lists.h"
#include "Application.h"

using namespace std;

// Prototype
int menuOption();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1:
        {
            Vectors vec;
            vec.mainMenu();
        } break;
        case 2:
        {
            Lists list;
            list.mainMenu();
        } break;
        case 3:
        {
            Application app;
            app.mainMenu();

        } break;
        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
        /*cout << "\n";
        system("pause");*/
    } while (true);

    return EXIT_SUCCESS;
}

// return a valid option (0...n)
int menuOption()
{
    cout << "\n\t=========================================================================";
    cout << "\n\tCMPR131 Chapter 4 - Complex Numbers, Rational Numbers, Polynomials by:";
    cout << "\n\tAlavi, Eduardo";
    cout << "\n\t=========================================================================";
    cout << "\n\t\t1> Vector container";
    cout << "\n\t\t2> List container";
    cout << "\n\t\t3> Application using Vector and/or List container";
    cout << "\n\t-------------------------------------------------------------------------";
    cout << "\n\t\t0> Exit";
    cout << "\n\t=========================================================================\n";

    int option = inputInteger("\tOption: ", 0, 3);
    system("cls");

    cout << "\n";
    return option;
}