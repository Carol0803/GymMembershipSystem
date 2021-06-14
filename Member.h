/*
Project Title: Gym Membership System
Team members : Wong Kak Lok (B032010436)
			   Muhammad Haziq bin Mohd Hapiz (B032010199)
Compiler: Visual Studio 2019

Interface Class File （Member.h):
This project involved a class named Member and two structures named Node and Details.
There is also a global declared const int maxSize.

In class Member, variables are private while functions are public.
Below are the operation performed by each function:
Member() - constructor
~Member() - destructor
bool Empty() - check whether the queue is empty and return
void enqueueMember() - insert new-registered member's data into queue
void dequeueMember() - remove new-registered member's data from queue
string getCurrentDate() - get and return current date when program running
string getExpiryDate(char) - get and return expiry date of membership
*void renewSubs() - renew the subscription based on plan
*void displayMember(int) - display namelist of expired membership
*void fetchData() - fetch data from main array list into sub-array list
void simpleSort() - sort array list using simple sort technique
void displaySortedList() - display namelist of sorted array list
*void addItem() - process registration from linked list into array and write the data in a file
*void loadData() - load existing data from stored file

The Node structure stored pointer to apply a linked list queue.

The Details structure stored 10 variables of member's information. It is nested in Node structure.
*/

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
	int count;
	Node* front;
	Node* rear;
	int size;
	int memID;
	Details memberList[maxSize];
	Details sortedList[maxSize];

public:
	Member();
	~Member();
	bool Empty();
	void enqueueMember();	
	void dequeueMember();
	string getCurrentDate();
	string getExpiryDate(char); 
	void renewSubs(); 
	void displayMember(int); 
	void fetchData();
	void simpleSort();
	void displaySortedList();  	
	void addItem();	
	void loadData(); 
};

#endif // !MEMBER_H