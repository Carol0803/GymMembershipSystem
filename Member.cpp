#include <iostream>
#include <ctime>
#include<iomanip>
#include "Member.h"
using namespace std;

Member::Member() {
	front = NULL;
	rear = NULL;
	count = 0;

	size = 0;
}

Member::~Member() {}

void Member::enqueueMember() {
	cout << "\n\tNew member registration\n";

	Node* N = new Node;

	cin.ignore();
	cout << "Enter name: ";
	getline(cin, N->data.name);
	
	cout << "Enter IC Number: ";
	//for (int i = 0; i < 12; i++)
	cin >> N->data.ic;

	//generate age
	int year;
	year = ((N->data.ic[0] - '0') * 10) + (N->data.ic[1] - '0');
	if (year <= 21)
		year += 2000;
	else
		year += 1900;
	N->data.age = 2021 - year;

	cout << "Enter gender (M-Male / F-Female): ";
	cin >> N->data.gender;

	cout << "Choose subscription type (M-Monthly / A-Annually): ";
	cin >> N->data.type;
	char subsType = N->data.type;
	N->data.expDate = getExpiryDate(subsType);

	//cout << N->data.expDate << endl; // uncomment this if u want to see the output

	cout << "Enter height(in metre): ";
	cin >> N->data.height;

	cout << "Enter weight(in kg): ";
	cin >> N->data.weight;

	N->data.bmi = ("%.2f", (N->data.weight / pow(N->data.height, 2)));
	cout << (float) N->data.bmi;

	//generate member ID 
	//memID++;
<<<<<<< Updated upstream
	//N->data.memberID = ++memID;
=======
	N->data.memberID = ++memID;
	cout << N->data.memberID << endl;
>>>>>>> Stashed changes

	N->next = NULL;

	if (!Empty())
		rear->next = N;
	else
		front = N;

	count++;
	rear = N;
	size++;
}

string Member::getCurrentDate() {
	#pragma warning(disable : 4996)
	time_t currenttime = time(0);
	tm* now = localtime(&currenttime);

	int Cyear, Cmonth, Cday;
	string day, month, year;
	Cyear = 1900 + now->tm_year;
	Cmonth = 1 + now->tm_mon;
	Cday = now->tm_mday;

	day = (Cday < 10) ? "0" + to_string(Cday) : to_string(Cday);
	month = (Cmonth < 10) ? "0" + to_string(Cmonth) : to_string(Cmonth);
	year = to_string(Cyear);

	return day + month + year;
}

string Member::getExpiryDate(char subsType) {
	#pragma warning(disable : 4996)
	time_t currenttime = time(0);
	tm* now = localtime(&currenttime);

	int Cyear, Cmonth, Cday;
	string day, month, year;
	Cyear = 1900 + now->tm_year;
	Cmonth = 1 + now->tm_mon;
	Cday = now->tm_mday;

	int daysOfMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int addDays = 0;

	if (subsType == 'M' || subsType == 'm')
		addDays = 30;
	else if (subsType == 'A' || subsType == 'a')
		addDays = 365;

	for (int i = 0; i < addDays; i++) {
		if (Cday < daysOfMonth[Cmonth-1])
			Cday++;
		else if (Cday == daysOfMonth[Cmonth - 1] && Cmonth < 12) {
			Cday = 1;
			Cmonth++;
		}
		else if (Cday == daysOfMonth[Cmonth - 1] && Cmonth == 12) {
			Cday = 1;
			Cmonth = 1;
			Cyear++;
		}
	}

	day = (Cday < 10) ? "0" + to_string(Cday) : to_string(Cday);
	month = (Cmonth < 10) ? "0" + to_string(Cmonth) : to_string(Cmonth);
	year = to_string(Cyear);

//	cout << day << "/" << month << "/" << year << endl; //uncomment to see the difference
//	cout << Cday << "/" << Cmonth << "/" << Cyear << endl;

	//char expDate = Cday + Cmonth + Cyear;
	//cout << expDate;
	//string expDate2 = to_string(Cday);

	return day + month + year;
}

void Member::dequeueMember() {
	if (count == 0)
		cout << "Underflow!";
	else {
		Node* temp = front;
		if (count == 1)
			rear = front = NULL;
		else
			front = front->next;
		count--;
		delete temp;
	}
}

bool Member::Empty() {
	return(count == 0);
}
void Member::simpleSort() {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			int a = 0;
			while (memberList[j].name[a] == memberList[min].name[a]) {
				a++;
				if (memberList[j].name[a] != memberList[min].name[a])
					break;
			}
			if (memberList[j].name[a] < memberList[min].name[a])
				min = j;
		}

		Details temp;
		temp = memberList[min];
		memberList[min] = memberList[i];
		memberList[i] = temp;
	}
}

void Member::displaySortedList() {
	cout << setw(10) << "\n\tMember's Namelist\n" << setw(10) << endl;

	cout << left << setw(4) << "NO." << setw(25) << "NAME" << setw(17) << "IC NO." << setw(8) << "AGE" << setw(12) << "GENDER"
		<< setw(12) << "HEIGHT" << setw(12) << "WEIGHT" << setw(20) << "SUBSCRIPTION TYPE" << setw(15) << "MEMBER ID"
		<< setw(15) << "EXPIRY DATE" << endl;
	for (int i = 0; i < size; i++) {
		cout << left << setw(4) << i + 1 << setw(25) << memberList[i].name << setw(17) << memberList[i].ic << setw(8)
			<< memberList[i].age << setw(12) << memberList[i].gender << setw(12) << memberList[i].height << setw(12)
			<< memberList[i].weight << setw(20) << memberList[i].type << setw(15) << memberList[i].memberID
			<< setw(15) << memberList[i].expDate << endl;
	}
}

void Member::renewSubs() {
	simpleSort();
	displaySortedList();

	string numIC;
	char type;
	cout << "Enter IC number: ";
	cin >> numIC;
	cout << "Choose subscription type (M-Monthly / A-Annually): ";
	cin >> type;

	for (int i = 0; i < size; i++) {
		if (numIC == memberList[i].ic) {
			memberList[i].type = type;
			memberList[i].expDate = getExpiryDate(type);
		}
	}

	cout << "Process succeed!" << endl;
}
void Member::displayExpired() {
	simpleSort();

	cout << setw(10) << "\nExpired Membership Namelist\n" << setw(10) << endl;

	cout << left << setw(25) << "NAME" << setw(17) << "IC NO." << setw(8) << "AGE" << setw(12) << "GENDER"
		<< setw(12) << "HEIGHT" << setw(12) << "WEIGHT" << setw(20) << "SUBSCRIPTION TYPE" << setw(15) << "MEMBER ID"
		<< setw(15) << "EXPIRY DATE" << endl;
	for (int i = 0; i < size; i++) {
		//if (stoi(memberList[i].expDate) > cDate) {
		if (memberList[i].expDate < getCurrentDate()) {
		cout << left << setw(25) << memberList[i].name << setw(17) << memberList[i].ic << setw(8)
			<< memberList[i].age << setw(12) << memberList[i].gender << setw(12) << memberList[i].height << setw(12)
			<< memberList[i].weight << setw(20) << memberList[i].type << setw(15) << memberList[i].memberID
			<< setw(15) << memberList[i].expDate << endl;
		}
	}
}

void Member::addItem() {
	if(size == maxSize)
	{
		cout << "Max number of members reached.";
		return;
	}
<<<<<<< Updated upstream

	for (int i = 0; size < maxSize - 1; i++) {
=======
	int k = 0;
	ofstream writeFile("temp.txt", ios::out | ios::app);
	writeFile << size << endl;

	for (int i = 0; i < size - count; i++) {
		writeFile
			<< memberList[i].name << endl
			<< memberList[i].ic << endl
			<< memberList[i].memberID << endl
			<< memberList[i].gender << endl
			<< memberList[i].age << endl
			<< memberList[i].type << endl
			<< memberList[i].expDate << endl
			<< memberList[i].height << endl
			<< memberList[i].weight << endl
			<< memberList[i].bmi << endl;
		k++;
	}
>>>>>>> Stashed changes

	for (int i = k; i <= size; i++) {
		if (Empty())
			break;
<<<<<<< Updated upstream
		if (size == maxSize){
			cout << "Max number of members reached.";
			return;
		}
		
=======
>>>>>>> Stashed changes
		memberList[i].name = front->data.name;
		memberList[i].memberID = front->data.memberID;
		memberList[i].gender = front->data.gender;
		memberList[i].ic = front->data.ic;
		memberList[i].age = front->data.age;
		memberList[i].type = front->data.type;
		memberList[i].expDate = front->data.expDate;
		memberList[i].height = front->data.height;
		memberList[i].weight = front->data.weight;
		memberList[i].bmi = front->data.bmi;

		dequeueMember();
		writeFile
			<< memberList[i].name << endl
			<< memberList[i].ic << endl
			<< memberList[i].memberID << endl
			<< memberList[i].gender << endl
			<< memberList[i].age << endl
			<< memberList[i].type << endl
			<< memberList[i].expDate << endl
			<< memberList[i].height << endl
			<< memberList[i].weight << endl
			<< memberList[i].bmi << endl;
	}
	writeFile.close();
	remove("data.txt");
	rename("temp.txt", "data.txt");
}


void Member::simpleSort() {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			int a = 0;
			while (memberList[j].name[a] == memberList[min].name[a]) {
				a++;
				if (memberList[j].name[a] != memberList[min].name[a])
					break;
			}
			if (memberList[j].name[a] < memberList[min].name[a])
				min = j;
		}
	
		Details temp;
		temp = memberList[min];
		memberList[min] = memberList[i];
		memberList[i] = temp;
	}
}

void Member::displaySortedList () {
	cout << setw(10) << "\n\tMember's Namelist\n" << setw(10) << endl;

	cout <<left << setw(4) << "NO." << setw(25) << "NAME" << setw(17) << "IC NO." << setw(8) << "AGE" << setw(12) << "GENDER"
		<< setw(12) << "HEIGHT" << setw(12) << "WEIGHT" << setw(20) << "SUBSCRIPTION TYPE" << setw(15) << "MEMBER ID"
		<< setw(15) << "EXPIRY DATE" << endl;
	for (int i = 0; i < size; i++) {
		cout << left<< setw(4) << i + 1 << setw(25) << memberList[i].name << setw(17) << memberList[i].ic << setw(8)
			<< memberList[i].age << setw(12) << memberList[i].gender << setw(12) << memberList[i].height << setw(12)
			<< memberList[i].weight << setw(20) << memberList[i].type << setw(15) << memberList[i].memberID
			<< setw(15) << memberList[i].expDate << endl;
	}
}

void Member::loadData() {

	ifstream readFile("data.txt", ios::in);

	while (readFile.is_open()) {
		readFile >> size;
		for (int i = 0; i < size; i++) {
			readFile.get();
			getline(readFile, memberList[i].name); 
			getline(readFile, memberList[i].ic);
			readFile
				>> memberList[i].memberID
				>> memberList[i].gender
				>> memberList[i].age
				>> memberList[i].type
				>> memberList[i].expDate
				>> memberList[i].height
				>> memberList[i].weight
				>> memberList[i].bmi;
			memID = memberList[i].memberID; // get latest value of memberID to generate new memberID for new registration
		}
<<<<<<< Updated upstream
}

=======
	cout << "File Loaded Successfully" << endl;
	readFile.close();
	}
}
>>>>>>> Stashed changes
