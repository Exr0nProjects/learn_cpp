/*
 * Tree rotations (first try) in binary trees
 * 19 July 2019
 *
 */

#include <cstdio>

using namespace std;
const int MAXSZ = 10010;
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

int main ()
{
  int n;
  scanf("%d", &n);

  Node* root = new Node();

  for (int i=1; i<=n; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    root->left = new Node(); root->right = new Node();
    root->left->value = a;
    root->right->value = b;
  }

  return 0;
}
