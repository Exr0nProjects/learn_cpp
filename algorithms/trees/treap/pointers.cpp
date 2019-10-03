/*
Base code taken from tree rotations, #e7e5b6bd095629d6ae075e9f1ff13a0e32707123
 */

#include <bits/stdc++.h>
#define cn const int
using namespace std;
const int MAXSZ = 100;
struct Node
{
    int value = NULL;
    Node *left = NULL;
    Node *right = NULL;
    operator bool() const {return value || left || right;};
};

Node *go_right(Node *base)
{
    printf("rotating node %d right!\n", base->value);
    Node *ret = base->left;
    base->left = (ret->right);
    ret->right = base;

    return ret;
}

Node *go_left(Node *base)
{
    printf("rotating node %d right!\n", base->value);
    Node *ret = base->right;
    base->right = (ret->left);
    ret->left = base;

    return ret;
}

void insert(Node *root, cn v)
{
    Node *n;
    for (n = root; n;)
    {
        if (n->value == v) return; // already exists
        else if (n->value > v) n = n->left;
        else if (n->value < v) n = n->right;
    }
    n = new Node();
    n->value = v;
}

void input(Node *cur)
{
    if (cur == NULL || cur->value < 0)
        return;
    int a, b;
    scanf("%d%d", &a, &b);
    cur->left = new Node();
    cur->right = new Node();
    cur->left->value = a;
    cur->right->value = b;
    input(cur->left);
    input(cur->right);
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

    scanf("%d", &cur->value);
    input(root);

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
