#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;
#pragma once

struct Details {
	string name;
	int memberID;
	char gender; // M->Male , F->Female
	int ic;
	int age;
	char type;
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
	

};

#endif // !MEMBER_H


