#include<iostream>
#include "Member.h"
using namespace std;

Member::Member() {
	front = NULL;
	rear = NULL;
	count = 0;
}

Member::~Member() {}

void Member::enqueueMember() {
	cout << "\n\tNew member registration\n";

	Node* N = new Node;

	cout << "Enter name: ";
	cin >> N->data.name;

	cout << "Enter IC Number: ";
	cin >> N->data.ic;

	//generate age

	cout << "Enter gender (M-Male / F-Female): ";
	cin >> N->data.gender;

	cout << "Choose subscription type (M-Monthly / A-Annually): ";
	cin >> N->data.type;
	//get expired date

	cout << "Enter height: ";
	cin >> N->data.height;

	cout << "Enter weight: ";
	cin >> N->data.weight;

	N->next = NULL;

	if (!Empty())
		rear->next = N;
	else
		front = N;

	count++;
	rear = N;
}
