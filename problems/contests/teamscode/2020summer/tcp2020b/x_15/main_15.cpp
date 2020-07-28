/*
 * Problem 15 (tcp2020b/15)
 * Create time: Wed 22 Jul 2020 @ 20:18 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>

using namespace std;
const int MX = 20111;

int bit[MX], alc;

void update(int n)
{
    int v = n;
    for (; n<=MX; n+=n&-n)
        bit[n] ^= v;
}
int query(int l, int r)
{
    if (l > r) return 0;
    int tot=0; --l;
    for (; r>l; r-=r&-r)
        tot ^= bit[r];
    for (; l>r; l-=l&-l)
        tot ^= bit[l];
    return tot;
}

int main()
{
    string s; int d;
    while (cin >> s)
    {
        if (s[0] == 'A' || s[0] == 'R')
        {
            cin >> d;
            if (d) update(d);
        }
        else
        {
            cin >> s >> d >> s;
            int r; cin >> r;
            printf("%d\n", query(d, r));
        }
    }

	return 0;
}

