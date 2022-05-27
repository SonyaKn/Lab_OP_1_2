#include "tree.h"

bool exists(tree* t, char element)
{
	if (t == nullptr) return false;
	if (t->info == element) return true;
	if (element < t->info) return exists(t->r, element);
	return exists(t->l, element);
}
void addElement(tree*& t, char element) 
{
	if (exists(t, element)) return;

	if (!t) 
	{
		t = new tree(element);
		return;
	}
	if (element > t->info) addElement(t->r, element);
	else addElement(t->l, element);
}

void printTree(tree* t, int tabs) 
{
	if (!t) 
	{
		return;
	}
	printTree(t->r, ++tabs);

	for (int i = 1; i < tabs; i++) 
	{
		cout << "\t";
	}
	cout << t->info << endl;

	printTree(t->l, tabs);
}
int getMaxDepth(tree* t)
{ 
	if (t == nullptr) return 0;
	return max(getMaxDepth(t->r), getMaxDepth(t->l))+1;
}
