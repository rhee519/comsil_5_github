#include <stdio.h>
#include "Stack.h"

void prnMenu() {
	cout << "*********************************************" << endl;
	cout << "* 1. insert  2. delete   3. print   4. exit *" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
	cout << "Select Menu : ";
}

int main() {
	int mode, selectNumber, tmpItem;
	LinkedList<int>* p;
	bool flag = false;

	cout << "Select Data Structure (1: Stack, Other: Linked List): ";
	cin >> mode;

	if (mode == 1)
		p = new Stack<int>();    // int stack

	else
		p = new LinkedList<int>();


	do {
		prnMenu();
		cin >> selectNumber;

		switch (selectNumber) {
		case 1:
			cout << "input value : ";
			cin >> tmpItem;    p->Insert(tmpItem);
			cout << tmpItem << " has been inserted." << endl;
			break;

		case 2:
			if (p->Delete(tmpItem) == true)
				cout << tmpItem << " has been deleted." << endl;

			else cout << "delete fail : the list is empty" << endl;
			break;

		case 3:
			cout << "List size : " << p->GetSize() << endl;
			p->Print();
			break;

		case 4:
			flag = true;     break;

		default:
			cout << "error : selected menu is wrong." << endl;
			break;

		}

		if (flag) break;

	} while (1);

	return 0;
}

