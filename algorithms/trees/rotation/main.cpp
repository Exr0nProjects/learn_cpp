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
  Node* ret = &base.left;
  base.left = &(ret->right);
  ret->right = &base;

  return *ret;
}

Node& go_left (Node& base)
{

  Node* ret = &base.right;
  base.right = &(ret->left);
  ret->left = &base;

  return *ret;
}

int main ()
{
  const int siz = 20;
  Node nodes[20];
  nodes[0].value = 1;


  return 0;
}
