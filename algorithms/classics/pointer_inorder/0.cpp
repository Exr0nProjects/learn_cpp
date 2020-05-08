// 7 May 2020

#include <iostream>

struct Node
{
	int val;
	Node *c[2];
	Node(int v): val(v) {}
} *root = nullptr;
int N;

void insert(Node *cur, int val)
{
	Node *&stp = cur->c[cur->val<val];
	if (stp == nullptr)
		stp = new Node(val);
	else
		insert(stp, val);
}

void in_order(Node* cur)
{
	if (cur == nullptr) return;
	in_order(cur->c[0]);
	printf("%3d", cur->val);
	in_order(cur->c[1]);
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		int v;
		scanf("%d", &v);
		if (!root) root = new Node(v);
		else insert(root, v);
	}

	in_order(root);
}

