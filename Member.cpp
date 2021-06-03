#include <iostream>
#include <ctime>
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
	N->data.memberID = ++memID;

	N->next = NULL;

	if (!Empty())
		rear->next = N;
	else
		front = N;

	count++;
	rear = N;
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
		if (Cday < daysOfMonth[Cmonth - 1])
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

void Member::addItem() {
	if(size == maxSize)
	{
		cout << "Max number of members reached.";
		return;
	}
	for (int i = 0; size < maxSize - 1; i++) {

		if (Empty())
			break;

		memberList[i].name = front->data.name;
		memberList[i].memberID = front->data.memberID;
		memberList[i].gender = front->data.gender;
		for (int a = 0; a < 12; a++)
			memberList[i].ic[a] = front->data.ic[a];
		memberList[i].age = front->data.age;
		memberList[i].type = front->data.type;
		memberList[i].expDate = front->data.expDate;
		memberList[i].height = front->data.height;
		memberList[i].weight = front->data.weight;
		memberList[i].bmi = front->data.bmi;

		dequeueMember();
		size++;
	}
	//here add write file function to data.txt
}

void Member::loadData() {
	static int n[1000];
	int existingSize = 0;

		ifstream readFile("data.txt", ios::in);

		while (readFile.is_open()) {
			readFile >> existingSize;
			size = existingSize; // get total of data has been stored
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
		cout << "File Loaded Successfully" << endl;
		total = size;
			readFile.close();
		}
}