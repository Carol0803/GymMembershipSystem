/*
Project Title: Gym Membership System
Team members : Wong Kak Lok (B032010436)
               Muhammad Haziq bin Mohd Hapiz (B032010199) 
Compiler: Visual Studio 2019

Main Program File (GymMembership.cpp): 
The main program involve two function, displayMainMenu() and main() function.
The displayMainMenu() function list out the menu of operation could be done by the program and instruction to use the program.
In main() function, an object called New is declared under class Member.
Then, there is a do-while loop.
In the do-while loop, the displayMainMenu() function is called and user require to enter their option.
The input of user will call respective function to undergo the operation.
The loop will continue until 0(Exit) is entered.
*/

#include <iostream>
#include <string>
#include "Member.h"
using namespace std;

void displayMainMenu();
void displayList();

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
        else if (selectMenu == 1) { //
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
        else if (selectMenu == 5) { // view expired namelist
            int c;
            do {
                displayList();
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

void displayList() {
    cout << "\nSelect what to display:";
    cout << "\n1.\tView active membership only";
    cout << "\n2.\tView expired membership only";
    cout << "\nYour selection:";
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