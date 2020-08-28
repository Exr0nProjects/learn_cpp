/*
 * Problem 3 (contests/standard-xjoi/1614/3)
 * Create time: Thu 27 Aug 2020 @ 16:45 (PDT)
 * Accept time: Fri 28 Aug 2020 @ 16:04 (PDT)
 *  Basically yoinked the usaco soln because I was close-ish to figuring it out. I guess the takeaway is to use this method of matching instead of counting sort.
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

int N, pos[MX], siz[MX];
list<int> h[MX], around[MX];

void ksub(int c, int p) // get subtree sizes
{
    siz[c] = 1;
    for (int n : h[c]) if (n != p)
    {
        ksub(n, c);
        siz[c] += siz[n];
        around[c].pb(siz[n]);
    }
    around[c].pb(N-siz[c]); // subtree complement
}

int check(int k)
{
    if ((N-1)%k) return 0;
    memset(pos, 0, sizeof pos);
    for (int i=1; i<=N; ++i)    // FIX: precompute then looop to avoid an entire counting sort per stack frame
    {
        int dif=0;
        for (int a : around[i]) if (a %= k)
        {
            if (pos[k-a]) --pos[k-a], --dif;    // FIX: enourmous brain matching sweep
            else          ++pos[a],   ++dif;
        }
        if (dif) return 0;
    }
    return 1;
}

int main()
{
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w+", stdout);
    scanf("%d", &N);
    //--N;
    for (int i=1; i<N; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        h[u].pb(v); h[v].pb(u);
    }

    ksub(1, 0);

    for (int k=1; k<N; ++k)
        printf("%d", check(k));
    printf("\n");

	return 0;
}

