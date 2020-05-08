// 7 May 2020

#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* c[2];
} *root = nullptr;

void insert(Node* node, int value, bool dir)
{
	node->c[dir] = new Node();
	node->c[dir]->value = value;
}

int main()
{
	root = new Node();
	insert(root, 2, 1);
	printf("hello world\n");
}

