/*
Base code taken from tree rotations, #e7e5b6bd095629d6ae075e9f1ff13a0e32707123
 */

#include <bits/stdc++.h>
#define cn const int
using namespace std;
const int MAXSZ = 100;
struct Node
{
    int value = NULL, weight = NULL;
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    operator bool() const {return value || left || right;};
};

Node *go_right(Node *base)
{
    printf("rotating node %d right!\n", base->value);
    Node *ret = base->left;
    ret->parent = base->parent;
    base->parent = ret;
    ret->right->parent = base;
    base->left = (ret->right);
    ret->right = base;

    return ret;
}

Node *go_left(Node *base)
{
    printf("rotating node %d left!\n", base->value);
    Node *ret = base->right;
    ret->parent = base->parent;
    base->parent = ret;
    ret->left->parent = base;
    base->right = (ret->left);
    ret->left = base;

    return ret;
}

void heapify(Node *c)
{
    if (!c->parent) return; // c is root of tree
    if (c->value > c->parent->value)
    {
        if      (c->parent->left == c) c = go_right(c->parent);
        else if (c->parent->right == c) c = go_left(c->parent);
    }
    heapify(c);
}

void insert(Node *root, cn v)
{
    Node *n;
    for (n = root; n;)
    {
        if (n->value == v)
            return; // already exists
        else if (n->value > v)
            n = n->left;
        else if (n->value < v)
            n = n->right;
    }
    n = new Node();
    n->value = v;
    n->weight = rand() % MAXSZ;

    heapify(n);
}

void remove(Node* root, cn v)
{
    Node* d;
    for (d = root; d->value != v;)
    {
        if (d->value == NULL) return;
        else if (d->value > v)
        {
            d = d->left;
        }
        else if (d->value < v)
        {
            d = d->right;
        }
    }
    for (; d->right; d=go_left(d));
    if (d->parent) d->parent->right = NULL;
    delete d;
}

queue<Node *> q;
void add_print_queue()
{
    if (!q.empty())
    {
        Node *c = q.front();
        if (c)
        {
            q.push(c->left);
            q.push(c->right);
            printf("%3d", c->value);
        }
        q.pop();
        add_print_queue();
    }
}
void print_tree(Node *root)
{
    for (; !q.empty(); q.pop())
        ;
    q.push(root);
    add_print_queue();
    printf("\n");
}

int main()
{
    Node *root = new Node();
    Node *cur = root;

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        int a;
        scanf("%d", &a);
        insert(root, a);
    }

    print_tree(root);

    root = go_right(root);
    print_tree(root);

    root = go_left(root);
    print_tree(root);
    root = go_left(root);
    print_tree(root);

    return 0;
}

/*
1 -1 -1

1 2 3 -1 -1 -1 4 -1 -1
*/
