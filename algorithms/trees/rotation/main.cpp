/*
 * Tree rotations (first try) in binary trees
 * 19 July 2019
 *
 */

#include <bits/stdc++.h>

using namespace std;
const int MAXSZ = 100;
struct Node
{
  int value = NULL;
  Node* left = NULL;
  Node* right = NULL;
};

Node& go_left (Node& base);

Node& go_right (Node& base)
{
  Node* ret = base.left;
  base.left = (ret->right);
  ret->right = &base;

  return *ret;
}

Node& go_left (Node& base)
{

  Node* ret = base.right;
  base.right = (ret->left);
  ret->left = &base;

  return *ret;
}

void input (Node* cur)
{
  if (cur->value < 0) return;
  int a, b;
  scanf("%d%d", &a, &b);
  cur->left = new Node();
  cur->left->value = a;
  cur->left->value = b;
  input(cur->left);
  input(cur->right);
}

queue<Node *> q;
void add_print_queue ()
{
  if (! q.empty())
  {
    Node* c = q.front();
    if (c)
    {
      q.push(c->left);
      q.push(c->right);
    }
    printf("%3d", c->value);
    q.pop();
    add_print_queue();
  }
}
void print_tree(Node* root)
{
  for (; !q.empty(); q.pop());
  q.push(root);
  add_print_queue();
}

int main ()
{
  int n;
  scanf("%d", &n);

  Node* root = new Node();
  Node* cur = root;

  input(root);
  


  return 0;
}
