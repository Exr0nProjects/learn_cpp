// 10 May 2020

#include <iostream>
#include <utility>

using namespace std;

struct Node
{
	int d, w, size;
	Node* c[2] = {};
	Node *next=nullptr, *prev=nullptr;
	Node(int d): d(d), w(rand() % 10000), size(1) {}
} *root;

inline int size(Node *cur)
{
	return (cur->c[0] ? cur->c[0]->size : 0)
		+  (cur->c[1] ? cur->c[1]->size : 0);
}

// TODO: logn traversal to get next/prev
pair<Node*, Node*> flatten(Node* cur) // pointers to left and right extremes of subtree
{
	if (!cur) return make_pair(nullptr, nullptr);
	pair<Node*, Node*> left, right;
	left  = cur->c[0] ? flatten(cur->c[0]) : pair<Node*, Node*>(cur, nullptr);
	right = cur->c[1] ? flatten(cur->c[1]) : pair<Node*, Node*>(nullptr, cur);

	cur->prev = left.second;
	if (left.second) left.second->next = cur;

	cur->next = right.first;
	if (right.first) right.first->prev = cur;
	
	return make_pair(left.first, right.second);
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

int getRank(Node *cur, int data)
{ // TODO: doesn't work
	if (!cur) return 0;
	if (cur->d == data)
		return cur->c[0] ? cur->c[0]->size : 0;
	if (cur->d < data)
		return getRank(cur->c[0], data);
	return getRank(cur->c[1], data) + cur->c[0]->size;
}

int getRank(Node* cur, int data)
{
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
			int o; scanf("%d", &o);
			if (root && locate(root, d) && locate(root, o))
				printf("%d\n", getRank(node, o) - getRank(node, d));
		}
	}
}

/*
// answer_ad
int get_pre(int x) {
    int ans = 2;
    int p = root;
    while (p) {
        if (v[p] == x) {
            if (c[p][0]) {
                p = c[p][0];
                while (c[p][1]) {
                    p = c[p][1];
                }
                ans = p;
            }
            break;
        }
        if (v[p] > v[ans] && v[p] < x) {
            ans = p;
        }
        if (v[p] < x) p = c[p][1];
        else p = c[p][0];
    }
    return v[ans];
}

int get_pre(int data) {
	int ans = 2; // ????
	int cur = root;
	while (cur)
	{
		if (cur->d == data)
		{
			if (cur->c[0])
			{
				for (cur = cur->c[0]; cur->c[1]; cur=cur->c[1]);
				ans = cur;
			}
			break;
		}
		if (cur->d > ans->d && cur->d < data)
			ans = cur;
		cur = cur->c[cur->d < data];
	}
}
*/

Node* get_pre_iter(int data)
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
		cur = cur-c[cur->d < data];
	}
	return ret;
}

