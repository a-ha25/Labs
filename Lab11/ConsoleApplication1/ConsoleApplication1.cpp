#include <iostream>
#include <limits>
#include <conio.h>
using namespace std;

struct stack {
	int inf;
	stack* next;
};

void input(int& a)
{
	while (true)
	{
		cin >> a;
		if (cin.good()) {
			break;
		}
		cout<< "Wrong input" <<endl;
	}
}
stack* addElements(stack* begin)
{
	int inf;
	input(inf);
	stack* t = new stack;
	t->inf = inf;
	t->next = begin;
	return t;
}
void showStack(stack* begin)
{
	cout << "--------------Stack--------------" <<endl;
	stack* p = begin;
	while (p != NULL) {
		cout << "\t\t" << p->inf << endl;
		p = p->next;
	}
	cout << endl;
}
void deleteStack(stack** begin)
{
	while ((*begin) != NULL) {
		stack* t = *begin;
		(*begin) = (*begin)->next;
		delete t;
	}
	cout << "Stack cleared" <<endl;
}


void deleteItems(stack* begin) {
	stack* curr = begin;
	while (curr->next != NULL)
	{
		stack* tmp = curr->next; // удаляемый элемент
		if (tmp->next)
		{
			curr->next = tmp->next;
			delete tmp;

		}
		/* if (tmp->next == NULL)
		{
		curr->next = NULL;
		delete tmp;
		}*/
		curr = curr->next;

	}
}

void deleteEl(stack* begin)
{
	int k = 0;
	stack* i = begin;
	while (i->next != NULL)
	{
		k++;
		if (k % 2 == 0)
		{
			i = i->next;
		}
		else
		{
			stack* dop = i->next;
			i->next = dop->next;
			delete dop;
		}
	}
	cout << "The problem is solved" <<'\n';
}

void Sort_p(stack** begin)
{
	stack* t = NULL, * t1, * temp;
	if ((*begin)->next->next == NULL) return;
	do
	{
		for (t1 = *begin; t1->next->next != t; t1 = t1->next)
			if (t1->next->inf > t1->next->next->inf)
			{
				temp = t1->next->next;
				t1->next->next = temp->next;
				temp->next = t1->next;
				t1->next = temp;
			}
		t = t1->next;
	} while ((*begin)->next->next != t);
}

void Sort_inf(stack* begin)
{
	stack* t = NULL, * t1;
	int temp;
	do {
		for (t1 = begin; t1->next != t; t1 = t1->next)
			if (t1->inf > t1->next->inf) {
				temp = t1->inf;
				t1->inf = t1->next->inf;
				t1->next->inf = temp;
			}
		t = t1;
	} while (begin->next != t);
}

int menu()
{
	cout << "1 - add element" << endl;
	cout << "2 - show stack" << endl;
	cout << "3 - clear stack" << endl;
	cout << "4 - stack sort" <<endl;
	cout <<"0 - exit" << endl;
	int choise;
	input(choise);
	return choise;
}
int main()
{
	int vibor;
	stack* begin = NULL;
	while (true) {
		switch (menu())
		{
		case 1:
			cout << "Enter the element:" << endl;
			begin = addElements(begin);
			cout << "Element added" <<endl;
			break;
		case 2:
			showStack(begin);
			break;
		case 3:
			deleteEl(begin);
			break;
		case 4:
			cout << "Please choose type of sort:" << endl;
			cout << "1 - Pointer sort" << endl;
			cout << "2 - Info swap sort" <<endl;
			cin >> vibor;
			if (vibor == 1)
			{
				Sort_p(&begin);
			}
			if (vibor == 2)
			{
				Sort_inf(begin);
			}
			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Choose 1-4 or 0"<< endl;
			break;
		}
	}
}