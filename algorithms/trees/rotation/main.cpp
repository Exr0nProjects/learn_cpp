/*
 * Tree rotations (first try) in binary trees
 * 19 July 2019
 *
 */

#include <cstdio>

using namespace std;

struct Node
{
  int value = NULL;
  node* left = NULL;
  node* right = NULL;
}

Node& go_left (Node& base);

Node& go_right (Node& base)
{
  while (base.left.right != NULL) go_left(base.left);

  Node* ret;
  ret = &base.left;

  ret->right = &base;
  base.left = NULL;

  return ret;
}

Node& go_left (Node& base)
{
  while (base.right.left != NULL) go_right(base.right);

  Node* ret;
  ret = &base.right;

  ret->left = &base;
  base.right = NULL;

  return ret;
}

int main ()
{
  const int siz = 20;
  Node nodes[20];
  nodes[0].value = 1;
  

  return 0;
}
