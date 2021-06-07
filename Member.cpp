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
	cout << "======================================================\n";
	cout << "\t\tNEW MEMBER REGISTRATION" << endl;
	cout << "======================================================\n";

	Node* N = new Node;

	cin.ignore();
	cout << "Enter name: ";
	getline(cin, N->data.name);

	cout << "Enter IC Number: ";
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

	cout << "Enter height(in metre): ";
	cin >> N->data.height;

	cout << "Enter weight(in kg): ";
	cin >> N->data.weight;

	N->data.bmi = ("%.2f", (N->data.weight / pow(N->data.height, 2)));
	cout << N->data.bmi;

	//generate member ID 
	if (memID == 0)
		memID = 1000;
	N->data.memberID = ++memID;

	N->next = NULL;

	if (!Empty())
		rear->next = N;
	else
		front = N;

	count++;
	rear = N;
	size++;
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

	return day + "/" + month + "/" + year;
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

void Member::fetchData() {
	for (int i = 0; i < size; i++) {
		sortedList[i].name = memberList[i].name;
		sortedList[i].ic = memberList[i].ic;
		sortedList[i].memberID = memberList[i].memberID;
		sortedList[i].gender = memberList[i].gender;
		sortedList[i].age = memberList[i].age;
		sortedList[i].type = memberList[i].type;
		sortedList[i].expDate = memberList[i].expDate;
		sortedList[i].height = memberList[i].height;
		sortedList[i].weight = memberList[i].weight;
		sortedList[i].bmi = memberList[i].bmi;
	}
}

void Member::simpleSort() {
	fetchData();

	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			int a = 0;
			while (sortedList[j].name[a] == sortedList[min].name[a]) {
				a++;
				if (sortedList[j].name[a] != sortedList[min].name[a])
					break;
			}
			if (sortedList[j].name < sortedList[min].name)
				min = j;
		}

		Details temp;
		temp = sortedList[min];
		sortedList[min] = sortedList[i];
		sortedList[i] = temp;
	}
}

void Member::displaySortedList() {

	string gender[maxSize], type[maxSize];
	for (int a = 0; a < size; a++) {
		if (sortedList[a].gender == 'M' || sortedList[a].gender == 'm')
			gender[a] = "Male";
		else if (sortedList[a].gender == 'F' || sortedList[a].gender == 'f')
			gender[a] = "Female";

		if (sortedList[a].type == 'M' || sortedList[a].type == 'm')
			type[a] = "Monthly";
		else if (sortedList[a].type == 'A' || sortedList[a].type == 'a')
			type[a] = "Annually";
	}
	cout << "===================================================================================================================================\n";
	cout << right << setw(75) << "MEMBER'S NAMELIST" << endl;
	cout << "===================================================================================================================================\n";

	cout << left << setw(4) << "NO." << setw(20) << "NAME" << setw(17) << "IC NO." << setw(8) << "AGE" << setw(12) << "GENDER"
		<< setw(12) << "HEIGHT(M)" << setw(12) << "WEIGHT(KG)" << setw(20) << "SUBSCRIPTION TYPE" << setw(15) << "MEMBER ID"
		<< setw(15) << "EXPIRY DATE" << endl;
	for (int i = 0; i < size; i++) {
		cout << fixed << left << setw(4) << i + 1 << setw(20) << sortedList[i].name << setw(17) << sortedList[i].ic << setw(8)
			<< sortedList[i].age << setw(12) << gender[i] << setw(12) << setprecision(2) << sortedList[i].height << setw(12)
			<< setprecision(2) << sortedList[i].weight << setw(20) << type[i] << setw(15) << sortedList[i].memberID 			
			<< setw(15) << sortedList[i].expDate << endl;
	}
}


void Member::loadData() {

	ifstream readFile("data.txt", ios::in);

	while (readFile.is_open()) {
		readFile >> size; // get total of data has been stored
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
		cout << "\nFile Loaded Successfully\n";
		readFile.close();
	}
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

	return year + month + day;
}

void Member::displayExpired() {
	fetchData();
	simpleSort();
	string gender[maxSize], type[maxSize];
	for (int a = 0; a < size; a++) {
		if (memberList[a].gender == 'M' || memberList[a].gender == 'm')
			gender[a] = "Male";
		else if (memberList[a].gender == 'F' || memberList[a].gender == 'f')
			gender[a] = "Female";

		if (memberList[a].type == 'M' || memberList[a].type == 'm')
			type[a] = "Monthly";
		else if (memberList[a].type == 'A' || memberList[a].type == 'a')
			type[a] = "Annually";
	}

	cout << "===================================================================================================================================\n";
	cout << right << setw(75) << "EXPIRED MEMBERSHIP NAMELIST" << endl;
	cout << "===================================================================================================================================\n";

	cout << left << setw(20) << "NAME" << setw(17) << "IC NO." << setw(8) << "AGE" << setw(12) << "GENDER"
		<< setw(12) << "HEIGHT(M)" << setw(12) << "WEIGHT(KG)" << setw(20) << "SUBSCRIPTION TYPE" << setw(15) << "MEMBER ID"
		<< setw(15) << "EXPIRY DATE" << endl;

	string cD = getCurrentDate(); // currentDate

	for (int i = 0; i < size; i++) {
		string eD = sortedList[i].expDate; // expiredDate
		string chars = "/";

		for (char c : chars) 
			eD.erase(remove(eD.begin(), eD.end(), c), eD.end());

		string d = string() + eD.substr(4, 7) + eD.substr(2, 2) + eD.substr(0, 2);

		if (cD > d) {
			cout << fixed << left << setw(20) << sortedList[i].name << setw(17) << sortedList[i].ic << setw(8)
				<< sortedList[i].age << setw(12) << gender[i] << setw(12) << setprecision(2) << sortedList[i].height << setw(12)
				<< setprecision(2) << sortedList[i].weight << setw(20) << type[i] << setw(15) << sortedList[i].memberID
				<< setw(15) << sortedList[i].expDate << endl;
		}
	}
}

void Member::addItem() {
	cout << "======================================================\n";
	cout << "\t\tPROCESS REGISTRATION" << endl;
	cout << "======================================================\n";
	cout << "Processing..." << endl;

	if(size == maxSize)
	{
		cout << "Max number of members reached.";
		return;
	}

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
	for (int i = k; i <= size; i++) {
		if (Empty())
			break;

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

	cout << "Succeed!\n";
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
	for (int i = 0; i < size; i++) {
		if (numIC == memberList[i].ic) {
			memberList[i].type = type;
			memberList[i].expDate = getExpiryDate(type);
		}
	}
	cout << "Process succeed!" << endl;
}