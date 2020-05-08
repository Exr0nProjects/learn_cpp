// 7 May 2020
#include <iostream>

using namespace std;
const int MX = 1111;

int N;
struct Node
{
	int value;
	Node* c[2];
	Node(int val): value(val) {}
} *root;

void insert(Node* cur, int n)
{
	Node *& stp = cur->c[cur->value<n];
	if (stp == nullptr)
		stp = new Node(n);	// mem leak galore
	else
		insert(stp, n);
}

void preorder(Node* cur)
{
	if (cur == nullptr) return; // FIX: base case
	printf("%3d", cur->value);
	preorder(cur->c[0]);
	preorder(cur->c[1]);
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		int t;
		scanf("%d", &t);
		if (root == nullptr) root = new Node(t); // FIX: construct root instead of assigning to nullptr
		else insert(root, t);
	}

	preorder(root);
	printf("\n");
}

