#include <limits>
#include <conio.h>
#include <iostream>
using namespace std;

struct Stack {
	int info;	     
	Stack* next;     
} *stackBegin;


Stack* Push(Stack* p, int in) {
	Stack* t = new Stack;			
	t->info = in;			
	t->next = p;		
	return t;
}

void View(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

Stack* Pop(Stack* p, int* out) {
	Stack* t = p;			
	*out = p->info;
	p = p->next; 		
	delete t; 			
	return p; 			
}

//Stack* Peek(Stack* p, int* out) {
//	Stack* t = p;			// Устанавливаем указатель t на вершину p
//	*out = p->info;
//	return p; 			// Возвращаем старую вершину p
//}

void input(int& a)
{
	while (true)
	{
		cin >> a;
		if (cin.good()) {
			break;
		}
		cout << "Wrong input" << endl;
	}
}
Stack* addElements(Stack* begin)
{
	int inf;
	input(inf);
	Stack* t = new Stack;
	t->info = inf;
	t->next = begin;
	return t;
}

void Sort_pointer(Stack** p) {
	Stack* t = NULL, * t1, * temp;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				temp = t1->next->next;
				t1->next->next = temp->next;
				temp->next = t1->next;
				t1->next = temp;
			}
		t = t1->next;
	} while ((*p)->next->next != t);

	
}
void Sort_inf(Stack* p)
{
	Stack* t = NULL, * t1;
	int temp;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				temp = t1->info;
				t1->info = t1->next->info;
				t1->next->info = temp;
			}
		t = t1;
	} while (p->next != t);
}
void Del_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Remove_odd(Stack** p)
{
	Stack* current = *p, * lastEven;


	while (current != NULL && current->info % 2 != 0)                                
	{
		current = current->next;
	}
	*p = current;                                                

	if (current == NULL) {                                      
		return;
	}

	lastEven = current;                                           

	current = current->next;                                            

	while (current != NULL)                                                  
	{
		
		if (current->info % 2 == 0) {

			lastEven->next = current;                                                                 
			lastEven = current;                                                            
		}
		current = current->next;
	}
	lastEven->next = NULL;                                                                  
}


int main()
{
	int numberOfElements;
	cout << "Enter number of elements\n";
	cin >> numberOfElements;

	cout << "\nEnter numbers:\n";
	for (int i = 0; i < numberOfElements; i++) {
		int element;
		cin >> element;
		stackBegin = Push(stackBegin, element);
	}
	while (true) {
		cout << "1. Sort by pointer" << endl;
		cout << "2. Sort by info" << endl;
		cout << "3. Remove odd numbers" << endl;
		cout << "4. Add elements" << endl;

		int choice;
		cin >> choice;



		switch (choice)
		{




		case 1:
		{
			int el = 100;
			stackBegin = Push(stackBegin, 100);
			Sort_pointer(&stackBegin);
			stackBegin = Pop(stackBegin, &el);
			View(stackBegin);
		}
		break;


		case 2:
		{
			Sort_inf(stackBegin);
			View(stackBegin);
		}
		break;

		case 3:
		{
			
			Remove_odd(&stackBegin);
			View(stackBegin);
		}
		break;
		case 4:
		{
			cout << "Enter the element:" << endl;
			stackBegin = addElements(stackBegin);
			cout << "Element added" << endl;
			View(stackBegin);
		}
		break;
		}
	}
}



