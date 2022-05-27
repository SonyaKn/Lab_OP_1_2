#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

struct tree {
	char info;
	tree* l,*r;
	tree(char key) 
	{
		info = key;
		l = nullptr;
		r = nullptr;
	}
};

void addElement( tree*&,char);
void printTree(tree*,int);
int getMaxDepth(tree*);
bool exists(tree*, char);