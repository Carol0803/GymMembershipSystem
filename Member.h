#ifndef MEMBER_H
#define MEMBER_H
#define MAX_SIZE 38080

#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <algorithm>
using namespace std;
#pragma once

struct Details {
	string name;
	int memberID;
	char gender;
	string ic;
	int age;
	char type;
	string expDate;
	double height, weight, bmi;
};

struct Node {
	Details data;
	Node* next;
};

const int maxSize = 500;

class Member {
private:
	int count = 0;
	Node* front;
	Node* rear;

	int size = 0;
	int memID = 0;
	Details memberList[maxSize];

	Details sortedList[maxSize];
	

public:
	int total = 0;
	Member();
	~Member();
	void enqueueMember();	//new registration
	void dequeueMember();
	string getExpiryDate(char); // get expiry date for membership registration
	string getCurrentDate(); // get current date for comparison
	bool Empty();

	void renewSubs(); // function to renew subscription based on plan
	void displayExpired(); // display namelist of expired membership
	void displaySortedList(); // display namelist in sorted array
	void fetchData(); // fetch data from main array into sub-array
	
	void simpleSort();	// sort array
	void addItem();	// process registration from linked list into array and write the data in a file

	void loadData(); // load existing data from stored file

};

#endif // !MEMBER_H


