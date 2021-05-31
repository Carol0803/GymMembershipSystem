#include "Member.h"

template <class MyData>
Member<MyData>::Member() {
	front = NULL;
	rear = NULL;
	total = 0;
}

template <class MyData>
void Member<MyData>::addNew() {
	cout << "Enter name: ";
	cin >> memberID;
}
