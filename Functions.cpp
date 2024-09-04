#include<iostream>
#include<vector>
#include<fstream>
#include"Header.h"
using namespace std;

void printMenu(int aS, int a[]) {
	string in;
	cout << "Please enter the letter of the function you wish to operate." << endl;
	cout << "a: Find the value at a certain index." << endl;
	cout << "b: Change the number at a given value." << endl;
	cout << "c: Add an integer to the end of the array." << endl;
	cout << "d: Remove a number given the index." << endl;
	cout << "p: Print Array." << endl;
	cout << "q: Quit." << endl;
	cin >> in;
	cout << endl;
	if (in == "a") {
		numIndex(aS, a);
		cout << endl;
		printMenu(aS, a);
	}
	else if (in == "b") {
		changeIndex(aS, a);
		cout << endl;
		printMenu(aS, a);
	}
	else if (in == "c") {
		addInt(aS, a);
		cout << endl;
		printMenu(aS, a);
	}
	else if (in == "d") {
		removeNum(aS, a);
		cout << endl;
		printMenu(aS, a);
	}
	else if (in == "q") {
		cout << "Ending program" << endl;
		return;
	}
	else if (in == "p") {
		printArray(aS, a);
		cout << endl;
		printMenu(aS, a);
	}
	else {
		cout << endl;
		printMenu(aS, a);
	}
}

void numIndex(int aS, int a[]) {
	int n;
	cout << "Enter number to find: ";
	cin >> n;
	if (n > 0 && n < aS) {
		cout << a[n];
	}
	else {
		cout << "Index is not in range" << endl;
		return;
	}
}

void changeIndex(int aS, int *a) {
	try {
		int n, old;
		cout << "Enter index of number to change: ";
		cin >> old;
		cout << endl << "The number at index " << old << " is: " << a[old] << endl;
		cout << "Enter new number: ";
		cin >> n;
		if (old < 0 || old > aS) {
			throw out_of_range("Please enter a valid number\n");
		}
		for (int i = 0; i < aS; ++i) {
			if (i == old) {
				a[old] = n;
				cout << "The old index value is: " << old << endl;
				cout << "The new number is: " << n << endl;
				break;
			}
		}
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}
}

void addInt(int aS, int*& a) {
	int n;
	while (true) {
		cin.clear();
		try {
			cout << "Enter the numebr to add to the end of the array: ";
			cin >> n;
			if (!isdigit(n)) {
				throw invalid_argument("Please enter a valid number\n");
			}
			int* nA = new int[aS + 1];
			for (int i = 0; i < aS; ++i) {
				nA[i] = a[i];
			}
			delete[] a;
			a = nA;
			aS += 1;
			break;
		}
		catch (const invalid_argument& error){
			cout << error.what() << endl;
			break;
		}
		catch (...) {
			cout << "Please try again." << endl;
			break;
		}
	}
}

void removeNum(int aS, int*& a) {
	int in;
	cout << "Enter the index of the number you would like to remove: ";
	cin >> in;
	if (in < 0 || in > aS) {
		return;
	}
	for (int i = in; i < aS; ++i) {
		a[i] = a[i + 1];
	}
	a[aS - 1] = 0;
}

void printArray(int aS, int a[]) {
	for (int i = 0; i < aS; ++i) {
		cout << a[i] << " " << endl;
	}
}