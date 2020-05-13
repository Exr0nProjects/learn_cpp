// treap memorization 13 may 2020

struct Node
{
	int d, w;
	Node *c[2] = {};
	Node(int d): d(d), w(rand() % 10000) {}
} *root = nullptr;

void rotate(Node *&cur, bool dir) // 1 = left, 0 = right
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node *&insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) return cur;
	Node *&stp = cur->c[cur->d < d];
	Node *&ins = insert(stp, d);
	if (cur->w < stp->w)
		rotate(cur, cur->d < d);
	return ins;
}

Node *&locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d < d], d);
}

void remove(Node *&cur)
{
	if (!cur) return; // FIX
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

