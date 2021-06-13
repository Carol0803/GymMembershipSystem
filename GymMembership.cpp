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
        else if (selectMenu == 3) { //renew 
            New.renewSubs();
        }
        else if (selectMenu == 4) {
            New.displaySortedList();
        }
        else if (selectMenu == 5) { // view expired namelist
            New.displayExpired();
        }
        else {}
    } while (selectMenu > -1 && selectMenu < 6);

    return 0;
}

void displayMainMenu() {
    cout << "\nEnter 1-4 to select menu, 0 to exit program\n";
    cout << "\n1.\tNew member registration\n";
    cout << "2.\tProcess registration\n";
    cout << "3.\tRenew subscription\n";
    cout << "4.\tView Member namelist\n";
    cout << "5.\tView expired member namelist\n";
    cout << "0.\tExit program.\n";
    cout << "\nYour selection: ";
}