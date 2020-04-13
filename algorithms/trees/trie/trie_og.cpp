// trie with pointer array, 9 Nov 2019

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define cn const int
#define ca const auto &
#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;
// auto fin = fopen("[!meta:pid!].in", "r");
// auto fout = fopen("[!meta:pid!].out", "w+");

const int MAXSZ = 1; // todo
struct TrieNode
{
    bool leaf = false;
    TrieNode *c[30] = {};
    TrieNode(){};
} root;
int n;

void insert(string s)
{
    TrieNode *c = &root;
    for (int i = 0; i < s.length(); ++i)
    {
        if (!c->c[s[i] - 'A'])
        {
            c->c[s[i] - 'A'] = new TrieNode();
        }
        c = c->c[s[i] - 'A'];
        if (!s[i + 1])
            c->leaf = true;
    }
}

bool search(string s)
{
    TrieNode *c = &root;
    for (const char &n : s)
    {
        if (!c->c[n - 'A'])
            return false;
        c = c->c[n - 'A'];
    }
    return c->leaf;
}

int main()
{
    printf("%d\n", search("COW"));
    insert("COW");
    printf("%d\n", search("COW"));

    return 0;
}
