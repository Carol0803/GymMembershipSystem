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

class Member {
private:
	int count; //page 123
	Node* front;
	Node* rear;

public:
	Member();
	~Member();
	void enqueueMember();
	char getExpiryDate(char);
	void dequeueMember();
	Details queueFront();
	bool Empty();
	

};

#endif // !MEMBER_H


