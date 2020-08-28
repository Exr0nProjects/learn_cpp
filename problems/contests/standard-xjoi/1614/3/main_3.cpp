/*
 * Problem 3 (contests/standard-xjoi/1614/3)
 * Create time: Thu 27 Aug 2020 @ 16:45 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <list>
#include <map>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+11;

int N;
list<int> h[MX];

int remain(int c, int p, int k, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d from %d k %d\n", c, p, k);
    map<int, int> pos;
    for (int n : h[c]) if (n != p)
        ++pos[remain(n, c, k, lay+1) % k];

    //for (auto p : pos) { for (int i=0; i<lay; ++i) printf("|   "); printf("%d...%d\n", p.f, p.s); }

    int ret=0;
    if (pos.count(-1)) return -1;
    if (~k&1 && pos[k>>1]&1) ret = k>>1;    // if even k, center must match self
    for (auto p : pos)
        if (p.f && p.s && p.s > pos[k-p.f]) // FIX: don't doublecount by p.s > pos[k-p.f] instead of p.s != pos[k-p.f]
        {
            //printf("mismatch! val=%d (%d vs %d) ret=%d\n", p.f, p.s, pos[k-p.f], ret);
            if (ret) ret = -2;
            else ret = p.f;
        }
    ++ret;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", ret%k);
    return ret;
}

int main()
{
    scanf("%d", &N);
    --N;
    for (int i=0; i<N; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        h[u].pb(v); h[v].pb(u);
    }

    //int k; scanf("%d", &k);

    for (int i=1; i<=N; ++i)
        if (N % i == 0 && remain(1, 0, i) == 1)
            printf("1");
        else
            printf("0");
    printf("\n");

	return 0;
}

