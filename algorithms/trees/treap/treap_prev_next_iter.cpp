// 13 May 2020
// TODO: untested

#include <iostream>
#include <utility>

using namespace std;

struct Node
{
	int d, w;
	Node* c[2] = {};
	Node(int d): d(d), w(rand() % 10000), size(1) {}
} *root;

void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
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

Node* get_prev(int data)
{
	if (!root) return;
	Node *cur = root, ret = nullptr;
	while (cur) // invariant: ret is most recent locked-in pre
	{
		if (cur->d == data)
		{
			if (cur->c[0])
				for (cur=cur->c[0]; cur->c[1]; cur=cur->c[1])
					ret = cur;
			break;
		}
		if (cur->d < data)
			ret = cur;
		cur = cur->c[cur->d < data];
	}
	return ret;
}

Node* get_next(int data)
{
	if (!root) return;
	Node *cur = root, ret = nullptr;
	while (cur)
	{
		if (cur->d == data)
		{
			if (cur->c[1])
				for (cur=cur->c[1]; cur->c[0]; cur=cur->c[0])
					ret = cur;
			break;
		}
		if (!cur->d < data)
			ret = cur;
		cur = cur->c[cur->d < data];
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
		// TODO: test get_prev and get_next
	}
}

