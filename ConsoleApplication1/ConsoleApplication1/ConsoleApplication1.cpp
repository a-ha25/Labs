// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int M;	int N;
	int i, j;
	int** matrix;
	cout << "enter M" << endl;
	cin >> M;
	cout << "enter N" << endl;
	cin >> N;

	matrix = new int* [M];
	for (i = 0; i < M; i++) {
		matrix[i] = new int[N];
	}


	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
		{
			cout << "Enter element " << "[" << i << "][" << j << "]  ";
			cin >> matrix[i][j];
		}
	}


	
	cout << endl;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;


	
	int maxValue, targetI, targetJ;

	maxValue = -1;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
		{
			if (fabs(matrix[i][j]) > maxValue) {
				maxValue = fabs(matrix[i][j]);
				targetI = i;
				targetJ = j;
			}
		}
	}


	cout << "Maximum value: " << maxValue << endl;
	cout << "i " << targetI << endl;
	cout << "j " << targetJ << endl;


	int** matrix2;

	matrix2 = new int* [M - 1];
	for (i = 0; i < M - 1; i++) {
		matrix2[i] = new int[N - 1];
	}

	int i2, j2;

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++)
		{
			if (i == targetI || j == targetJ) {
				continue;
			}

			i2 = i;
			j2 = j;

			if (i > targetI) {
				i2 -= 1;
			}

			if (j > targetJ) {
				j2 -= 1;
			}

			matrix2[i2][j2] = matrix[i][j];
		}
	}


	//вывод матрицы
	cout << endl;
	for (i = 0; i < M - 1; i++) {
		for (j = 0; j < N - 1; j++)
		{
			cout << matrix2[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;


	delete[]matrix;
	delete[]matrix2;
}


