#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <time.h>
using namespace std;
#pragma once

struct Details {
	string name;
	int memberID;
	//char toupper(gender); // M-Male , F-Female
	char gender;
	string ic; // char ic[12]; can convert to char
	int age;
	char type; // M-Monthly , A-Annually
	string expDate; // char expDate
	double height, weight;
	double bmi;
};

struct Node {
	Details data;
	Node* next;
};

const int maxSize = 500;
//int memID = 0;

class Member {
private:
	int count = 0; //page 123
	Node* front;
	Node* rear;

	int size;
	int memID = 0;
	Details memberList[maxSize];

	Details sortedList[maxSize];

public:
	int total = 0;
	Member();
	~Member();
	void enqueueMember();	//new registration
	string getExpiryDate(char);
	void dequeueMember();
	bool Empty();

	string getCurrentDate();
	void renewSubs();
	void displayExpired();
	
	void simpleSort();	//display item
	void displaySortedList();
	void addItem();	//process registration

	void loadData(); // load existing data from stored file

};

#endif // !MEMBER_H


