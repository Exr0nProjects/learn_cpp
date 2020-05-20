// 10 May 2020

#include <iostream>
#include <utility>

using namespace std;

struct Node
{
	int d, w, size;
	Node* c[2] = {};
	Node(int d): d(d), w(rand() % 10000), size(1) {}
} *root;

inline int size(Node *cur)
{
	return (cur->c[0] ? cur->c[0]->size : 0)
		+  (cur->c[1] ? cur->c[1]->size : 0);
}

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];

	cur->c[dir] = thn->c[1-dir];
	cur->size = size(cur);

	thn->c[1-dir] = cur;
	thn->size = size(thn);

	cur = thn;
}

int getRank(Node* cur, int data)
{
	// TODO: untested
	if (!cur) return 0;
	if (cur->d < data)
		return getRank(cur->c[0], data);
	int left = cur->c[0] ? cur->c[0]->size : 0;
	if (cur->d == data)
		return left;
	return getRank(cur->c[1], data) + left + 1;
}

Node *& insert(Node *&cur, int data)
{
	if (!cur) return cur = new Node(data);
	if (cur->d == data) return cur;
	
	Node *&stp = cur->c[cur->d < data];
	Node *&ins = insert(stp, data);
	if (cur->w < stp->w)
		rotate(cur, cur->d < data);
	return ins;
}

Node *& locate(Node *&cur, int data)
{
	if (!cur || cur->d == data) return cur;
	return locate(cur->c[cur->d < data], data);
}

void remove(Node *&cur)
{
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]);
	}
	else
	{
		Node *thn = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1];
		delete thn;
	}
}

int main()
{
	while (true)
	{
		char c=0;
		while (c < 'a' || c > 'z') scanf("%c", &c);
		if (c == 'x') break;
		if (c == 't')
		{
			pair<Node*, Node*> bounds = flatten(root);
			printf("got bounds %d thru %d\n", bounds.first->d, bounds.second->d);
			for (Node* it = bounds.first; it!=bounds.second; it = it->next)
				printf("%d ", it->d);
			if (bounds.second)
				printf("%d\n", bounds.second->d);
			continue;
		}

		int d;
		scanf("%d", &d);
		if (c == 'i')
		{
			if (!root) root = new Node(d);
			else insert(root, d);
		}
		else if (c == 'r')
		{
			if (!root) continue;
			else remove(locate(root, d));
		}
		else if (c == 'q')
		{
			printf("%d (rank %d)\n", (bool)locate(root, d), getRank(root, d));
		}
		else if (c == 'd')
		{
			// TODO: untested
			int o; scanf("%d", &o);
			if (root && locate(root, d) && locate(root, o))
				printf("%d\n", getRank(node, o) - getRank(node, d));
		}
	}
}

