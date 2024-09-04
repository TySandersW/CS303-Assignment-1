#include<iostream>
#include<vector>
#include<fstream>
#include"Header.h"
using namespace std;

int main() {
	int aS = 100;
	int* a = new int[aS];

	ifstream inFS("A1input.txt");
	if (!inFS.is_open()) {
		return 0;
	}

	for (int i = 0; !inFS.eof(); ++i) {
		inFS >> a[i];
	}

	printMenu(aS, a);
	
	return 1;
}
