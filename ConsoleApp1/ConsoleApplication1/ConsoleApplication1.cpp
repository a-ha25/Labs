

#include <iostream>

int main()
{
    
}

struct SegmentTree
{
	int summa, min, max, LeftPos, RightPos;
	struct SegmentTree* Left, * Right;
};

SegmentTree* build(vector<int>& a, int L, int R)
{
	if (L == R)
	{
		// Строим дерево из одной вершины
		SegmentTree* New = new SegmentTree;
		New->summa = New->min = New->max = a[L]; New->Left = New->Right = NULL;
		New->LeftPos = New->RightPos = L;
		return New;
	}
	int m = (L + R) / 2;
	// строим левое и правое поддерево
	SegmentTree* Left = build(a, L, m);
	SegmentTree* Right = build(a, m + 1, R);
	// создаем результирующее дерево Tree с левым поддеревом Left и правым Right
	SegmentTree* Tree = new SegmentTree;
	Tree->Left = Left; Tree->Right = Right;
	// пересчитываем функции в корне дерева через корни поддеревьев
	Tree->summa = Left->summa + Right->summa;
	Tree->min = min(Left->min, Right->min);
	Tree->max = max(Left->max, Right->max);
	Tree->LeftPos = Left->LeftPos;
	Tree->RightPos = Right->RightPos;
	return Tree;
}
int sum(SegmentTree* tree, int L, int R)
{
	if (L < tree->LeftPos) L = tree->LeftPos;
	if (R > tree->RightPos) R = tree->RightPos;
	if (L > R) return 0;
	// если корень дерева tree соответствует отрезку [L..R],
	// то возвращаем значение суммы, хранящейся в этом корне
	if ((tree->LeftPos == L) && (tree->RightPos == R)) return tree->summa;
	int LeftSum = sum(tree->Left, L, R);
	int RightSum = sum(tree->Right, L, R);
	return LeftSum + RightSum;
}
