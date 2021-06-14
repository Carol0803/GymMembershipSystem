/*
Project Title: Gym Membership System
Team members : Wong Kak Lok (B032010436)
               Muhammad Haziq bin Mohd Hapiz (B032010199)
Compiler: Visual Studio 2019

Main Program File (GymMembership.cpp):
The main program involves two functions, displayMainMenu() and main() function.

The displayMainMenu() function lists out the menu of operation and instruction to use the program.
Menu of operation:
1. New member registration
2. Process registration
3. Renew subscription
4. View all member namelist
5. View active/expired member namelist
0. Exit

In main() function, an object called New is declared under class Member.
Then, there is a do-while loop.
In the do-while loop, the displayMainMenu() function is called and users are required to enter their option.
The input of the user will call the respective function to perform the respective operation.
The loop will continue until 0(Exit) is entered.

In this program, when respective function is called,
the new-registered member's data will be inserted into a linked list using queue concept(Menu 1).
The data will be processed into a new array list(Menu 2).
The subscription can be renewed monthly or annually(Menu 3).
The data in array list will be fetch into a sub array list and sort using simple sort technique,
then the sorted member namelist will be displayed(Menu 4).
The active or expired member namelist will be displayed(Menu 5).
Exit program(Menu 0).
*/

#include <iostream>
#include <string>
#include "Member.h"
using namespace std;

void displayMainMenu();

int main()
{
    cout << "======================================================================\n";
    cout << "|                                                                    |\n";
    cout << "|                                                                    |\n";
    cout << "|\t\t\tGYM MEMBERSHIP SYSTEM\t\t\t     |\n";
    cout << "|                                                                    |\n";
    cout << "|                                                                    |\n";
    cout << "======================================================================\n";
    Member New;
    int selectMenu;

    New.loadData();

    do {
        displayMainMenu();
        cin >> selectMenu;
        if (selectMenu < 0 || selectMenu > 5) {
            cout << "\nNo operation selected. Try again.\n";
        }
        else if (selectMenu == 0) {
            cout << "\nExiting Program....\n";
            break;
        }
        else if (selectMenu == 1) { 
            New.enqueueMember();
        }
        else if (selectMenu == 2) {
            New.addItem();
        }
        else if (selectMenu == 3) { 
            New.renewSubs();
        }
        else if (selectMenu == 4) {
            New.displaySortedList();
        }
        else if (selectMenu == 5) { 
            int c;
            do {
                cout << "\nSelect what to display:";
                cout << "\n1.\tView active membership only";
                cout << "\n2.\tView expired membership only";
                cout << "\nYour selection: ";
                cin >> c;
                if (c == 1) {
                    New.displayMember(1);
                }
                if (c == 2) {
                    New.displayMember(0);
                }
            } while (c < 1 || c > 2);
        }
        else {}
    } while (selectMenu != 0);

    return 0;
}

void displayMainMenu() {
    cout << "\nEnter 1-4 to select menu, 0 to exit program\n";
    cout << "\n1.\tNew member registration\n";
    cout << "2.\tProcess registration\n";
    cout << "3.\tRenew subscription\n";
    cout << "4.\tView all member namelist\n";
    cout << "5.\tView active/expired member namelist\n";
    cout << "0.\tExit program.\n";
    cout << "\nYour selection: ";
}