// rewrite of problem #4, using a weighted treap

#include <bits/stdc++.h>
#define cn const int
using namespace std;
cn MAXSZ = 10010;

struct Node
{
    Node* p=nullptr, *l=nullptr, *r=nullptr;
    int v=-1, w=1, b;
    Node (Node* _p, cn _v) {
        p=_p; v=_v;
        b=rand()%MAXSZ;
    }
} *root;

Node* rright(Node* p)
{
    if (!p->l) return p;
    Node* r = p->l; // 0
    if (p->v > p->p->v) p->p->r = r; // 1
    else p->p->l = r;
    r->p = p->p; // 2
    p->p = r; // 3
    if (r->r)
    {
        p->l = r->r; // 4
        p->l->p = p; // 5
    }
    r->r = p; // 6
    r->w = r->l->w + r->r->w + 1; // w1
    p->w = p->l->w + p->r->w + 1; // w2
    return r;
} // todo: rleft

void heapify(Node* p)
{
    if (p->p == nullptr) return;
    if (p->b > p->p->b)
    {
        Node* r;
        if (p->v > p->p->v)
        {
            r = rleft(p->p);
        }
        else
        {
            r = rright(p->p);
        }
        if (r->l == root || r->r == root) root = r;
    }
}

void insert (cn v);

int main()
{
    root = new Node(); // todo: fill in the constructor args for the new root
}