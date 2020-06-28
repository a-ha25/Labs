
#include <iostream>
using std::cout;
using std::cin;

struct Queue {
	int info;
	Queue* next, * prev;
} *begin, * end;

void CreateQueue(int in)
{
	Queue* t = new Queue;
	t->info = in;
	t->next = t->prev = NULL;
	begin = end = t;
}
void PushBack(int in)
{
	Queue* t = new Queue;
	t->info = in;
	t->next = NULL;
	t->prev = end;
	end->next = t;
	end = t;
}
void PushFront(int in)
{
	Queue* t = new Queue;
	t->info = in;
	t->prev = NULL;
	t->next = begin;
	begin->prev = t;
	begin = t;
}
void ViewBegin(Queue* t)
{
	for (Queue* i = t; i != NULL; i = i->next)
		cout << i->info << '\n';
}

void ViewEnd(Queue* t)
{
	for (Queue* i = t; i != NULL; i = i->prev)
		cout << i->info << "\n";
}
void Remove_odd()
{
	/*Queue* r=NULL;*/
	auto i = begin;
	/*auto memory = i;*/
	while (i != NULL)
	{
		if (i->info % 2 == 1) {

			auto left = i->prev;
			auto right = i->next;

			if (left != NULL) {
				left->next = right;
			}

			if (right != NULL) {
				right->prev = left;
			}

			if (i == begin) {
				begin = i->next;
			}

			if (i->next == NULL) {
				end = i->prev;
				end->next = NULL;
			}
			
			auto memory = i;
			i = i->next;
			delete memory;
			
			
		}
		else
			i = i->next;
	}
	/*end = memory;*/

}

int main()
{
	int n;
	cout << "Enter number of elements\n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Enter the element: ";
		cin >> x;
		if (i == 0) {
			CreateQueue(x);
		}

		else {
			PushBack(x);
		}

	}
	while (true)
	{
		cout << "1. Add to begin\n";
		cout << "2. Add to end\n";
		cout << "3. View from begin\n";
		cout << "4. View from end\n";
		cout << "5.Remove odd numbers\n";
		int choice;

		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			cout << "Enter the element: ";
			int x;
			cin >> x;
			PushFront(x);
			break;
		case 2:
			cout << "Enter the element: ";
			int y;
			cin >> y;
			PushBack(y);
			break;
		case 3:
			ViewBegin(begin);
			break;
		case 4:
			ViewEnd(end);
			break;
		case 5:
			Remove_odd();
			ViewBegin(begin);
			break;
		default:
			break;
		}
	}


}



