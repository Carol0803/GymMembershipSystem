#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;
#pragma once

struct Details {
	string name;
	int memberID;
	char gender; // M-Male , F-Female
	char ic[12];
	int age;
	char type; // M-Monthly , A-Annually
	char expDate;
	double height, weight;
};

struct Node {
	Details data;
	Node* next;
};

const int maxSize = 500;

class Member {
private:
	int count; //page 123
	Node* front;
	Node* rear;

	int size;
	Details memberList[maxSize];

	Details sortedList[maxSize];

public:
	Member();
	~Member();
	void enqueueMember();	//new registration
	char getExpiryDate(char);
	void dequeueMember();
	bool Empty();
	
	void addItem();	//process registration

	void simpleSort();	//display item
	void displaySortedList();
};

#endif // !MEMBER_H


