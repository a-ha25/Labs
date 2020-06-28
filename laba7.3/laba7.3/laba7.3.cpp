#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
#include<stdio.h>
using namespace std;

int main()
{
	int currentWordSize, minimalWordSize, len, minimalWordPosition, currentWordPosition;
	currentWordSize = 0;
	minimalWordSize = 0;
	minimalWordPosition = 0;
	currentWordPosition = 0;
	char str[100];
	cout << "Enter a string: ";
	gets_s(str);
	cout << "You entered: " << str << endl;
	len = strlen(str);// yui tr


	for (int i = 0; i < len; i++)
	{

		if (str[i] == ' ' || i == (len - 1)) {

			if (i == (len - 1)) {
				currentWordSize++;
			}
			currentWordPosition++;
			if (currentWordSize < minimalWordSize || minimalWordSize == 0) {


				minimalWordPosition = currentWordPosition;
				minimalWordSize = currentWordSize;
			}
			currentWordSize = 0;
		}
		else {

			currentWordSize++;
			

		}
	}
	cout << "Minimal word position: " << minimalWordPosition << endl;
	cout << "Minimal word size: " << minimalWordSize << endl;
	cout << len << endl;
	return 0;

}
