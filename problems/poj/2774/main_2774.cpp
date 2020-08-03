/*
 * Problem 2774 (poj/2774)
 * Create time: Mon 03 Aug 2020 @ 11:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 4000111;
const int LGMX = 25;
char inp[MX];
//string inp;
int N, sa[MX], rk[MX], tmp[MX], pos[MX];
int lcp[MX];
//int st[MX][LGMX];

void ksa()
{
    int mx = 128;
    for (int i=1; i<=N; ++i)
        rk[i] = inp[i], sa[i] = i;

    for (int i=1; i>>1<N; i<<=1)
    {
        int k = i>>1, p = k;
        // second keyword
        for (int i=1; i<=k; ++i) tmp[i] = N-i +1;
        for (int i=1; i<=N; ++i) if (sa[i] > k) tmp[++p] = sa[i]-k;
        // first keyword
        memset(pos, 0, 1+mx<<2);
        for (int i=1; i<=N; ++i) ++pos[rk[i]];
        for (int i=1; i<=mx; ++i) pos[i] += pos[i-1];    // FIX: mx not MX, altho both work; FIX: <=mx not <mx, causes whack bus error?
        for (int i=N; i; --i) sa[pos[ rk[tmp[i]] ]--] = tmp[i];
        //for (int i=1; i<=N; ++i) printf("%3d", sa[i]); printf("\n");
        // re-rank
        for (int i=1; i<=N; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + (rk[sa[i]] != rk[sa[i-1]] || rk[sa[i]+k] != rk[sa[i-1]+k]);
        memcpy(rk, tmp, 1+N<<2);
        //for (int i=1; i<=N; ++i) printf("%3d", rk[i]); printf("\n");
        // prep
        mx = rk[sa[N]];
        if (mx == N) break;
    }
}

void klcp()
{
    lcp[rk[1]] = 0;
    for (int i=1; i<=N; ++i)    // FIX: iterbounds--<=N not <N
    {
        lcp[rk[i]] = max(lcp[rk[i-1]]-1, 0);    // re 2 lines down: whereas here we actually want the prefix before
        if (rk[i] > 1)
            while (inp[i +lcp[rk[i]]] == inp[sa[rk[i]-1] + lcp[rk[i]]]) // FIX: rk[i]-1 not rk[i-1] cuz we want the rank before, not the prefix before
                ++lcp[rk[i]];
    }
}

//void kst()
//{
//    memcpy(st, lcp, 1+N<<2);
//    for (int i=1; 1<<i <= N; ++i)
//        for (int j=1; j+(1<<i)<=N+1; ++j)   // FIX: fencepost hell because sparsetable is inc exc
//        st[i][j] = min(st[i-1][j], st[i-1][j+(1<<i-1)]);
//    for (int i=0; 1<<i <= N; ++i)
//    {
//        for (int j=1; j+(1<<i)<=N+1; ++j)
//            printf("%3d", st[i][j]);
//        printf("\n");
//    }
//}
//int rmq(int l, int r)   // inc exc
//{
//    if (l > r) swap(l, r);
//    int d;
//    while (1<<d < r-l) ++d;
//    return min(st[d][l], st[d][r-(1<<d)]);
//}

int main()
{
    //int N1;
    //string b;
    //cin >> inp;
    //N1 = inp.size();
    //inp += '#';
    //cin >> b;
    //inp += b;
    //N = inp.size();
    ////cout << inp << " " << N1 << " " << N << endl;


    scanf("%s", inp+1);
    int N1 = strlen(inp+1);
    //N = strlen(inp+1);
    inp[N1+1] = '#';
    scanf("%s", inp+2+N1);          // FIX: rename-- +N1 not +N because N == 0 here!
    //printf("'%s'\n", inp+1);
    N = N1 + strlen(inp+1+N1);
    ksa();
    klcp();

    //for (int i=1; i<=N; ++i) printf("%3d ", lcp[i]); printf("\n");

    //printf("i:          "); for (int i=1; i<=N; ++i) printf("%3d", sa[i]); printf("\n");
    //printf("inp[i]:     "); for (int i=1; i<=N; ++i) printf("%3c", inp[sa[i]]); printf("\n");
    //printf("rk[i]:      "); for (int i=1; i<=N; ++i) printf("%3d", i); printf("\n");
    //printf("lcp[rk[i]]: "); for (int i=1; i<=N; ++i) printf("%3d", lcp[i]); printf("\n");

    //kst();

    //while (true)
    //{
    //    int i, j; scanf("%d%d", &i, &j);
    //    printf("lcp of %d and %d: %d\n", rk[i], rk[j], rmq(rk[i]+1, rk[j]+1));
    //}
    int mx=0;
    for (int i=2; i<=N; ++i)
    {
        int l = sa[i], r = sa[i-1];
        if (l > r) swap(l, r);      // FIX: checking across needs to account for which side is larger
        //printf("%d,   %d and %d: %d        but %d && %d -> %d\n", N1, l, r, lcp[i], l <= N1, r > N1, l <= N1 && r > N1);
        if (l <= N1 && r > N1)      // FIX: only take from across strings
            mx = max(mx, lcp[i]);   // FIX: indexing--lcp[i+1] not lcp[i]
    }
    printf("%d\n", mx);

	return 0;
}

