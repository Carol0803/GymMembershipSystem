#include <iostream>
#include <string>

using namespace std;

void displayMainMenu();

int main()
{
    cout << "Gym Membership System\n";

    int selectMenu;

    do {
        displayMainMenu();
        cin >> selectMenu;
        if (selectMenu < 0 || selectMenu > 4) {
            cout << "\nNo operation selected. Try again.\n";
        }
        if (selectMenu == 0) {
            cout << "\nExiting Program....\n";
            break;
        }
    } while (selectMenu > -1 || selectMenu < 5);

}

void displayMainMenu() {
    cout << "\nEnter 1-4 to select menu, 0 to exit program\n";
    cout << "\n1.\tAdd new member registration\n";
    cout << "2.\tRenew subscription\n";
    cout << "3.\tView Member namelist\n";
    cout << "4.\tView expired member namelist\n";
    cout << "0.\tExit program.\n";

    cout << "\nYour selection: ";
}

//testing testing