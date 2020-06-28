#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iterator>
#include <ctime>
#include <chrono>
#include <map>

using namespace std;



struct Atelier {
	string ProductGroup;
	string ProductBrand;
	string DateOfReceipt;       //KEY
	string OrderCondition;
};


vector<Atelier> Atelier1;


void PrintProductData();
void EditProducts();
void ShowMenu();
void ReadDataFromFile();
void EditProducts();
void RemoveProduct();
void SaveProductsToFile();
void AddProduct();
//void Quick_Sort(int* a, int begin, int end)
//{
//	int left, right, x;
//	left = begin;
//	right = end;
//	x = a[(left + right) / 2];
//	do {
//		while (a[left] < x)  left++;
//		while (x < a[right]) right--;
//		if (left <= right) {
//			x = a[left];
//			a[left] = a[right];
//			a[right] = x;
//			left++;
//			right--;
//		}
//	} while (left <= right);
//	if (begin < right) {
//		Quick_Sort(a, begin, right);
//	}
//	if (left < end) {
//		Quick_Sort(a, left, end);
//	}

int CompareDates(string date1, string date2) {
	char date1_array[100];
	char date2_array[100];

	strcpy_s(date1_array, date1.c_str());
	strcpy_s(date2_array, date2.c_str());

	int year1 = 0, month1 = 0, day1 = 0;
	int year2 = 0, month2 = 0, day2 = 0;

	sscanf_s(date1_array, "%4d.%2d.%2d", &year1, &month1, &day1);
	sscanf_s(date2_array, "%4d.%2d.%2d", &year2, &month2, &day2);

	if (year1 < year2) {

		return -1;
	}
	else if (year1 > year2) {

		return 1;
	}

	if (month1 < month2) {

		return -1;
	}
	else if (month1 > month2) {

		return 1;
	}

	if (day1 < day2) {

		return -1;
	}
	else if (day1 > day2) {

		return 1;
	}

	return 0;
}

void Quick_Sort(vector<Atelier> &a, int begin, int end)
{
	int left, right;
	Atelier x;
	left = begin;
	right = end;
	x = a[(left + right) / 2];
	Atelier temp;
	do {
		while (CompareDates( a[left].DateOfReceipt, x.DateOfReceipt)==-1)  left++;
		while (CompareDates(x.DateOfReceipt , a[right].DateOfReceipt)==-1) right--;
		if (left <= right) {
			 temp= a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) Quick_Sort(a, begin, right);
	if (left < end) Quick_Sort(a, left, end);
}

void PrintProductsByGroup() {

	map<string, vector<Atelier>> group;
	
	for (int i = 0; i < Atelier1.size(); i++) {

		group[Atelier1[i].ProductGroup].push_back(Atelier1[i]);

	}
	map<string, vector<Atelier>>::iterator it = group.begin();

	cout << "\n----------------------- Products by group -----------------------" << endl;
	while (it != group.end())
	{
		
		string groupName = it->first;
		
		vector<Atelier> groupProducts = it->second;

		Quick_Sort(groupProducts, 0, groupProducts.size() - 1);

		
		cout << "\n----------------------- " << groupName<< " -----------------------" << endl;
		for (int i = 0; i < groupProducts.size(); i++)
		{
			cout << i + 1 << endl;
			cout << "ProductBrand:" << groupProducts[i].ProductBrand << endl;
			cout << "DateOfReceipt:" << groupProducts[i].DateOfReceipt << endl;
			cout << "OrderCondition:" << groupProducts[i].OrderCondition << endl;
			cout << "--------------------------------------------------------" << endl;

		}
		it++;
	}

}





void ShowMenu()
{
	while (true)
	{
		cout << "1. Show the list" << endl;
		cout << "2. Edit the list" << endl;
		cout << "3. Sort" << endl;
		cout << "4. Exit" << endl;

		int choice;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			PrintProductData();
			break;
		case 2:
			EditProducts();
			break;
		case 3:
			PrintProductsByGroup();
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void ReadDataFromFile()
{
	ifstream infile("List.txt");
	string line;
	while (getline(infile, line))
	{
		istringstream ss(line);
		string token;
		Atelier product;

		getline(ss, token, ';');
		product.ProductGroup = token;

		getline(ss, token, ';');
		product.ProductBrand = token;

		getline(ss, token, ';');
		product.DateOfReceipt =token;

		getline(ss, token, ';');
		product.OrderCondition = token;

		Atelier1.push_back(product);
	}
}
	void PrintProductData()  {

		cout << "\n----------------------- Products -----------------------" << endl;
		for (int i = 0; i < Atelier1.size(); i++)
		{
			cout << i + 1 << endl;
			cout << "ProductGroup:" << Atelier1[i].ProductGroup << endl;
			cout << "ProductBrand:" << Atelier1[i].ProductBrand << endl;
			cout << "DateOfReceipt:" << Atelier1[i].DateOfReceipt<< endl;
			cout << "OrderCondition:" << Atelier1[i].OrderCondition << endl;
			cout << "--------------------------------------------------------" << endl;

		}

	}

	void EditProducts()
	{
		while (true)
		{
			cout << "1. Add Product" << endl;
			cout << "2. Remove Product" << endl;
			cout << "3. Exit to main menu" << endl;
			int choice;
			cin >> choice;

			system("cls");

			switch (choice)
			{
			case 1:
				AddProduct();
				break;
			case 2:
				RemoveProduct();
				break;
			case 3:
				return;
			default:
				break;
			}
		}
	}
	void RemoveProduct()
	{
		system("cls");

		cout << "--------- Select index of Product To Remove ---------" << endl;
		PrintProductData();

		int i;
		cin >> i;

		Atelier1.erase(Atelier1.begin() + (i - 1));

		/*PrintProductData();*/
		SaveProductsToFile();
	
	}
	void SaveProductsToFile()
	{
		ofstream output_file("List.txt");
		for (int i = 0; i < Atelier1.size(); i++) {

			output_file <<Atelier1[i].ProductGroup << ';';
			output_file <<Atelier1[i].ProductBrand << ';';
			output_file <<Atelier1[i].DateOfReceipt << ';';
			output_file <<Atelier1[i]. OrderCondition<< ';';
			
			if (i != Atelier1.size() - 1) {
				output_file << endl;
			}

		}


	}
	void AddProduct() {
		cout << "Enter product info" << endl;

		Atelier product;
		cout << "ProductGroup:" << endl;

		/*getline(cin >> ws, product.ProductGroup);*/
		cin >> product.ProductGroup;
		cout << "ProductBrand:" << endl;
		cin >> product.ProductBrand;

		cout << "DateOfReceipt:" << endl;
		 cin>>product.DateOfReceipt;


		cout << "OrderCondition:" << endl;
		cin >> product.OrderCondition;


		Atelier1.push_back(product);
		SaveProductsToFile();
		cout << "Product added" << endl;

	}

int main()
{
	ReadDataFromFile();
	ShowMenu();
}
