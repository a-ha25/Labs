#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

int quantity_of_nodes = 0;
struct Tree {
	int key;
	string name;
	Tree* right, * left;
}*root;
Tree* Create_list(int key) {
	Tree* p = new Tree;
	p->key = key;
	cout << "Enter the name: ";
	cin.ignore();
	getline(cin, p->name);
	p->right = p->left = NULL;
	return p;
}
void Create_node(Tree* root, int key) {
	Tree* prev = NULL, * p;
	p = root;
	bool find = true;
	while (p && find) {
		prev = p;
		if (p->key == key) {
			find = false;
		}
		else {
			if (key < p->key)
				p = p->left;
			else p = p->right;
		}
	}
	if (find) {
		p = Create_list(key);
		if (key < prev->key)
			prev->left = p;
		else prev->right = p;
	}
}
void View_tree(Tree* p, int level) {
	if (p) {
		View_tree(p->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "       ";
		cout << p->key << "-" << p->name << endl << endl;
		View_tree(p->left, level + 1);
	}
}
void View_list(Tree* p) {
	if (p) {
		View_list(p->left);
		cout << p->key << "-" << p->name << endl;
		View_list(p->right);
	}
}
void Tree_to_arr(Tree* p, Tree* t) {
	if (p) {
		Tree_to_arr(p->left, t);
		t[quantity_of_nodes].key = p->key;
		t[quantity_of_nodes].name = p->name;
		quantity_of_nodes++;
		Tree_to_arr(p->right, t);
	}
}
void Delete_tree(Tree* p) {
	if (p != NULL) {
		Delete_tree(p->right);
		Delete_tree(p->left);
		delete p;
	}
}
void Balance_tree(Tree** p, int n, int k, Tree* new_tree) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->key = new_tree[m].key;
		(*p)->name = new_tree[m].name;
		Balance_tree(&(*p)->left, n, m, new_tree);
		Balance_tree(&(*p)->right, m + 1, k, new_tree);
	}
}
void Balance() {
	Tree* new_tree = new Tree[100];
	Tree_to_arr(root, new_tree);
	Delete_tree(root);
	Balance_tree(&root, 0, quantity_of_nodes, new_tree);
	quantity_of_nodes = 0;
}
void Find(Tree* p, int key) {
	while (p != NULL && p->key != key) {
		if (key > p->key)p = p->right;
		else p = p->left;
	}
	if (p == NULL) {
		puts("Node not found!");
		return;
	}
	cout << "Desired name : " << p->name;
}
Tree* Delete_node(Tree* root, int key) {
	Tree* del, * prev_del = NULL, * r, * prev_r;
	del = root;
	while (del != NULL && del->key != key) {
		prev_del = del;
		if (key > del->key)del = del->right;
		else del = del->left;
	}
	if (del == NULL) {
		puts("Node not found!");
		return root;
	}
	if (del->right == NULL)r = del->left;
	else
		if (del->left == NULL)r = del->right;
		else {
			prev_r = del;
			r = del->left;
			while (r->right != NULL) {
				prev_r = r;
				r = r->right;
			}
			if (prev_r == del)r->right = del->right;
			else {
				r->right = del->right;
				prev_r->right = r->left;
				r->left = prev_r;
			}
		}
	if (del == root)root = r;
	else
		if (del->key > prev_del->key)prev_del->right = r;
		else prev_del->left = r;
	delete del;
	return root;
}

int Node_count(const Tree* p) {

	if (p == NULL)
		return 0;
	int n = 1;
	if (p->left != NULL)
		n += Node_count(p->left);
	if (p->right != NULL)
		n += Node_count(p->right);
	return n;
}


int main() {
	int key;
	int menu = 0;
	while (menu != 7) {
		puts("\tMenu:");
		puts("1.Add the node");
		puts("2.View the tree");
		puts("3.Balance the tree");
		puts("4.View the node");
		puts("5.Delete the node ");
		puts("6.Solving the task");
		puts("7.Exit ");
		
		cin >> menu;
		switch (menu) {
		case 1: {
			puts("Enter the key : ");
			cin >> key;
			if (root == NULL) {
				root = Create_list(key);
			}

			else {
				Create_node(root, key);
				break;
			}

		}
		case 2: {
			int view;
			puts("1.View by tree\n2.View by list");
			cin >> view;
			if (view == 1) {
				View_tree(root, 0);
			}
			if (view == 2) {
				View_list(root);
			}
			break;
		}
		case 3: {
			Balance();
			break;
		}
		case 4: {
			puts("Enter the key: ");
			cin >> key;
			Find(root, key);
			break;
		}
		case 5: {
			puts("Enter the key : ");
			cin >> key;
			root = Delete_node(root, key);
			break;
		}
		case 6: {
			int result = Node_count(root->right);
			cout << "Number of nodes in the right tree: " << result << endl;
			break;
		}
		case 7: {
			exit(0);
		}

		default: {
			puts("\tYou should pick from the list!\n");
			break;
		}
		}
	}
}