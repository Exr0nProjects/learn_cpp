// 9 May 2020

#include <iostream>
#include <cassert> // assert
#include <cstdlib> // random

#define RESET "\033[0m"
#define BLACK "\x1b[38;5;239m"

struct Node
{
	int data;
	int w;
	Node* c[2] = {};
	Node(int d): w(rand()%10000), data(d) {}
} *root = nullptr;

void rotate(Node *&cur, bool dir) // dir = which child should be new parent?
{
	//printf("rotating %d %d (%d)\n", cur->data, dir, cur->c[dir]->data);
	if (!cur) return;
	assert(cur->c[dir]);
	Node* thn = cur->c[dir];
	cur->c[dir] = thn->c[1-dir];
	thn->c[1-dir] = cur;
	cur = thn;
}

Node*& insert(Node *&cur, int data)
{
	if (!cur || cur->data == data)
		return cur;
	//printf("inserting %d\n", data);
	const bool dir = cur->data < data;
	Node*& stp = cur->c[dir];
	Node* t; Node*& ins = t; // used to return inserted position
	if (stp)   ins = insert(stp, data);
	else 
		stp = ins = new Node(data);
	if (stp->w > cur->w)
	{
		//printf("    rotating\n");
		rotate(cur, dir);
	}
	return ins;
}

Node *& locate(Node *&cur, int data)
{
	if (!cur || cur->data == data)
		return cur;
	const bool dir = cur->data < data;
	return locate(cur->c[dir], data);
}


void remove(Node *&cur)
{
	//printf("erasing %d (%x)\n", cur->data, cur);
	if (!cur) return;
	if (cur->c[0] && cur->c[1])
	{
		const bool dir = cur->c[0]->w < cur->c[1]->w;
		rotate(cur, dir);
		remove(cur->c[1-dir]);
	}
	else
	{
		Node *tmp = cur;
		cur = cur->c[0] ? cur->c[0] : cur->c[1]; // take whichever one exists, or nullptr if none
		delete tmp;
	}
}

void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
	return;
	if (lay == 1) printf("dump:\n");
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i)
		printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
	printf("%d %s(%4d @ %x)%s\n", cur->data, BLACK, cur->w, cur, RESET);
	dump(cur->c[0], lay+1);
}

int main()
{
	srand(10);
	while (true)
	{
		char t=' ';
		while (t < 'a' || t > 'z') scanf("%c", &t);
		
		if (t == 'x') break;

		if (t == 'd') dump(root);
		else
		{
			int d;
			scanf("%d", &d);
			if (false) {}
			else if (t == 'i')
			{
				if (!root) root = new Node(d);
				//else printf("%x\n", insert(root, d));
				else insert(root, d);
				dump(root);
			}
			else if (t == 'r')
			{
				if (!root) continue;
				else
				{
					//printf("removing..\n");
					Node *& t = locate(root, d);
					remove(t);
				}
				dump(root);
			}
			else if (t == 'q')
			{
				printf("%x\n", (bool)locate(root, d));
			}
		}
		//printf("\n");
	}
}

