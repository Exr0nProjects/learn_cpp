/*
Base code taken from tree rotations, #e7e5b6bd095629d6ae075e9f1ff13a0e32707123
 */

#include <bits/stdc++.h>
#define cn const int
using namespace std;
const int MAXSZ = 100;
struct Node
{
    int value = 0, weight = 0;
    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
    operator bool() const { return value || left || right; };
};

void print_tree(Node *root)
{
    printf("root: %d\n", root->value);
    queue<Node *> q;
    for (q.push(root); !q.empty(); q.pop())
    {
        auto c = q.front();
        if (c)
        {
            q.push(c->left);
            q.push(c->right);
            // printf("%3d", c->value);
            printf("node %3d: %3d -> (%4d, %4d) -> %3d, %3d\n", c->value, c->parent ? c->parent->value : 0, c->value, c->weight, c->left ? c->left->value : 0, c->right ? c->right->value : 0);
        }
    }
    printf("\n");
}

Node *go_right(Node *base)
{
    //d*/printf("rotating node %d right!\n", base->value);
    if (!base->left)
        return base;
    Node *ret = base->left;
    ret->parent = base->parent;
    if (ret->parent)
    {
        if (ret->parent->left == base)
            ret->parent->left = ret;
        if (ret->parent->right == base)
            ret->parent->right = ret;
    }
    base->parent = ret;
    base->left = nullptr;
    if (ret->right)
    {
        ret->left->parent = base;
        base->right = (ret->left);
    }
    ret->right = base;

    return ret;
}

Node *go_left(Node *base)
{
    //d*/printf("rotating node %d left!\n", base->value);
    if (!base->right)
        return base;
    Node *ret = base->right;
    ret->parent = base->parent;
    if (ret->parent)
    {
        if (ret->parent->left == base)
            ret->parent->left = ret;
        if (ret->parent->right == base)
            ret->parent->right = ret;
    }
    base->parent = ret;
    base->right = nullptr;
    if (ret->left)
    {
        ret->left->parent = base;
        base->right = (ret->left);
    }
    ret->left = base;

    return ret;
}

Node *heapify(Node *c)
{
    if (!c->parent)
        return c; // c is root of tree
    if (c->weight > c->parent->weight)
    {
        //d*/printf("heapify:  ");
        if (c->value < c->parent->value)
            c = go_right(c->parent);
        else if (c->value > c->parent->value)
            c = go_left(c->parent);
        c = heapify(c);
    }
    //d*/printf("finished heapify, returning %d\n", c->value);
    return c;
}

Node *insert(Node *&root, cn v) // returns pointer to the newly created node
{
    Node *n = root, *p = nullptr;
    for (; n && n->value;)
    {
        if (n->value == v)
            return n; // already exists
        p = n;
        if (n->value > v)
            n = n->left;
        else if (n->value < v)
            n = n->right;
    }
    p = p == n ? nullptr : p;
    n = new Node();
    n->parent = p;
    if (n->parent)
    {
        if (v > n->parent->value)
            n->parent->right = n;
        if (v < n->parent->value)
            n->parent->left = n;
    }
    n->value = v;
    n->weight = (rand() % MAXSZ) + 1;
    //d*/printf("inserting new node %d: w=%d\n", n->value, n->weight);
    //d*/print_tree(root);

    n = heapify(n);
    if (!n->parent)
        root = n;
    return n;
}

Node *remove(Node *&root, cn v)
{
    Node *d;
    for (d = root; d->value != v;)
    {
        if (!d->value)
            return root;
        else if (d->value > v)
        {
            d = d->left;
        }
        else if (d->value < v)
        {
            d = d->right;
        }
    }
    //d*/printf("found: val = %d\n", d->value);
    for (; d->right || d->left;)
    {
        if (d->right)
            go_left(d);
        else if (d->left)
            go_right(d);
        if (!d->parent->parent)
            root = d->parent;
    }
    if (d->value > d->parent->value)
        d->parent->right = nullptr;
    else
        d->parent->left = nullptr;
    delete d;
    return root;
}

int main()
{
    Node *root = new Node();
    printf("0 for default test: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        insert(root, a);
        //d*/print_tree(root);
    }

    if (!n)
    {
        printf("inserting 1-5 inc\n");
        for (int i = 1; i < 5; ++i)
        {
            insert(root, i);
        }
        print_tree(root);

        printf("deleting 1\n");
        remove(root, 1);
        print_tree(root);

        printf("deleting 3\n");
        remove(root, 3); // todo: error: Wrong! this doesn't work
        print_tree(root);
    }

    return 0;
}
