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
#include <algorithm>
#include <utility>
#include <queue>
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

int N, pos[MX];
list<int> h[MX];
vector<int> q[MX];

int remain(int c, int p, int k, int lay=1)
{
    for (int i=0; i<lay; ++i) printf("|   "); printf("%d from %d k %d\n", c, p, k);
    q[c].clear();
    //memset(pos, 0, sizeof pos);
    for (int i=0; i<MX; ++i) pos[i] = 0;
    printf("pos[1] = %d\n", pos[1]);
    for (int n : h[c]) if (n != p)
    {
        int got = remain(n, c, k, lay+1) % k;
        if (got < 0) return -1;
        if (got > 0) {
            if (!pos[got]) q[c].pb(got);
            ++pos[got];
            for (int i=1; i<=lay; ++i) printf("|   "); printf("INCREMENT %d\n", got);
        }
    }

    //for (auto p : pos) { for (int i=0; i<lay; ++i) printf("|   "); printf("%d...%d\n", p.f, p.s); }
    printf("pos[1] = %d\n", pos[1]);
    for (int i : q[c]) { for (int i=0; i<lay; ++i) printf("|   "); printf("%d...%d\n", i, pos[i]); }
    printf("pos[1] = %d\n", pos[1]);

    int ret=0;
    if (~k&1 && pos[k>>1]&1) ret = k>>1;    // if even k, center must match self
    for (int i=1; i<=lay; ++i) printf("|   "); printf("pos[%d] = %d    ret = %d\n", k>>1, pos[k>>1], ret);

    for (int i : q[c])
        if (pos[i] && pos[i] > pos[k-i]) // FIX: don't doublecount by p.s > pos[k-p.f] instead of p.s != pos[k-p.f]
        {
            printf("mismatch! val=%d (%d vs %d) ret=%d\n", i, pos[i], pos[k-i], ret);
            if (ret) ret = -2;
            else ret = i;
        }
    for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", (ret+1)%k);
    return ret+1;
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

    int i; scanf("%d", &i);

    //for (int i=1; i<=N; ++i)
        if (N % i == 0 && remain(1, 0, i) == 1)
            printf("1");
        else
            printf("0");
    printf("\n");

	return 0;
}

