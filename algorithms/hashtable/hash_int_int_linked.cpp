/*
20 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 108; // should be a prime number + 1
struct Val
{
    int k, v;
    Val *next = nullptr;
} * table[MAXSZ * 2];

inline int gk(const int k)
{
    return k % (MAXSZ - 1);
}

void write(const int k, const int v)
{
    Val *n = new Val;
    n->k = k;
    n->v = v;
    n->next = table[gk(k)];
    table[gk(k)] = n;
}

int read(const int k)
{
    Val *v = table[gk(k)];
    for (; v->k != k; v = v->next)
    {
        if (v == nullptr)
            return NULL;
    }
    return v->v;
}

int key_store[MAXSZ]; // not used for actual hash table, just storing the keys to retrieve

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int k, v;
        scanf("%d%d", &k, &v);
        write(k, v);
        key_store[i] = k;
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d: %d\n", key_store[i], read(key_store[i]));
    }

    return 0;
}
