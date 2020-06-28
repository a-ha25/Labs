// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int choice;

	cout << "1. Enter manually\n2. Generate random\n";
	cin >> choice;

	int arraySize;
	int maxArrayElement = 1000;


	
	if (choice == 1) {
		cout << "Enter array size\n";
		cin >> arraySize;
	}
	else {
		arraySize = rand() % 10 + 1;
	}

	int* numbers = new int[arraySize];

	if (choice == 1) {
		cout << "\nEnter numbers:\n";
		for (int i = 0; i < arraySize; i++) {
			cin >> numbers[i];
		}
	}
	else {
		cout << "Generating random numbers...\n";

		for (int i = 0; i < arraySize; i++) {
			numbers[i] = rand() % maxArrayElement + 1;
		}
	}

	

	int maxElement = numbers[0];

	for (int i = 1; i < arraySize; i++) {
		if (numbers[i] > maxElement) {
			maxElement = numbers[i];
		}
	}

	cout << "Array:\n";
	for (int i = 0; i < arraySize; i++) {
		cout << numbers[i] << " ";
	}
	cout << "\nMax element is: " << maxElement;

	
	int sum = 0;
	for (int i = 0; i < arraySize; i++) {

		if (numbers[i] < 0) {
			continue;
		}

		if (numbers[i] == maxElement) {
			break;
		}

		sum += numbers[i];
	}

	cout << "\nSum of positive integers less than " << maxElement<< " is: " << sum;
}
