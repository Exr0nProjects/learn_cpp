// 7 may 2020
#include <iostream>

int N;
struct Node
{
	int val;
	Node* c[2];
	Node(int v): val(v) {}
} *root;

void insert(Node *cur, int val)
{
	Node*& stp = cur->c[cur->val<val];
	if (!stp) stp = new Node(val);
	else insert(stp, val);
}

void post_order(Node *cur)
{
	if (!cur) return;
	post_order(cur->c[0]);
	post_order(cur->c[1]);
	printf("%3d", cur->val);
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

	post_order(root);
}

