#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int main()
{
	setlocale(0, "Rus");
	srand(time(NULL));

	int menu, realsize, i, iMax = 0;
	int const maxsize = 1000;
	int mas[maxsize] = {};
	bool alreadythere;

	cout << "Введите количество элементов массива (от 1 до 1000): ";
	cin>> realsize;

	cout << "Вы хотите ввести количество элементов массива с клавиатуры или использовать генератор случайных чисел? =)" << endl <<
		"1. Довериться судьбе" << endl <<
		"2. Ввести самому" << endl;
	cin >> menu;

	switch (menu) {

	case 1:

		cout << "Ваш массив сгенерирован: ";

		for (i = 0; i < realsize; i++) {
			alreadythere = false;
			int newrand = rand() % maxsize + 1;

			for (int j = 0; j < i; j++) {

				if (mas[j] == newrand) {
					alreadythere = true;
					break;
				}
			}

			if (alreadythere) {
				--i;
				continue;
			}

			mas[i] = newrand;
			cout <<mas[i] << " ";

		}

		{
			int maxEl = mas[0];

			cout << endl;

			for (i = 1; i < realsize; i++) {
				if (mas[i] > maxEl) {
					maxEl = mas[i];
					iMax = i;
				}
			}

			cout << "Наибольший элемент в массиве = " << maxEl << endl;

			int sum = 0;
			for (i = 0; i < iMax; i++) {
				sum += mas[i];
			}

			cout<< "Сумма элементов массива, расположенных до максимального элемента = " << sum;
		}

		break;

	case 2:

		cout << "Введите " << realsize << " различных элементов в свой массив: ";
		for (i = 0; i < realsize; i++) {
			cin>> mas[i];
			
		}

		{
			int maxEl = mas[0];

			cout << endl;

			for (i = 1; i < realsize; i++) {
				if (mas[i] > maxEl) {
					maxEl = mas[i];
					iMax = i;
				}
			}

			cout<< "Наибольший элемент в массиве = " << maxEl<< endl;

			int sum = 0;
			for (i = 0; i < iMax; i++) {
				sum += mas[i];
			}

			cout<< "Сумма элементов массива, расположенных до максимального элемента = " << sum;
		}

		break;

	default:

		cout<< "Такого значения нет! Попробуйте еще раз..." << endl;

		break;
	}
}

