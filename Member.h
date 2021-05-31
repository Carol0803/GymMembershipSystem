#ifndef MEMBER_H
#define MEMBER_H

#include <string>
using namespace std;
#pragma once

template <class MyData>
struct Nod {
	MyData data;
	Nod<MyData> *next;
};

template <class MyData>
class Member {
private:
	int total; //page 123
	string name;
	int memberID;
	char gender; // M->Male ,, F->Female
	int ic;
	int age;
	int type;
	double height, weight;

public:
	Member();
	~Member();
	void addNew();
	

};

#endif // !MEMBER_H


