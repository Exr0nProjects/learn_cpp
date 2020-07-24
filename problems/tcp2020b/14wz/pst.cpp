#include <cassert>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
const int MX = 100111;
int N, M, alc=1, invs[MX], occ[MX], arr[MX];
vector<pair<int, int> > arr2(1);   // store the pairs of lines
int ibit[MX];

void update(int b[], int x, int v)
{
    for (; x<=N; x+=x&-x)
        b[x] += v;
}
int query(int b[], int x)
{
    int sum = 0;
    for (; x; x-=x&-x)
        sum += b[x];
    return sum;
}

map<pair<int, int>, int> bit;
void update(int x, int _y, int v)
{
    for (; x<=N; x+=x&-x)
    {
        for (int y=_y; y<=N; y+=y&-y)
        {
            bit[mp(x, y)] += v;
        }
    }
}
int query(int x, int _y)
{
    int sum=0;
    for (; x; x-=x&-x)
    {
        printf("x %d sum %d\n", x, sum);
        for (int y=_y; y; y-=y&-y)
        {
            printf("    sum += %d,%d = %d\n", x, y, bit.count(mp(x, y)) ? bit[mp(x, y)] : 0);
            if (bit.count(mp(x, y)))
                sum += bit[mp(x, y)];
        }
    }
    return sum;
}
int rquery(int x1, int y1, int x2, int y2)
{
    //assert(x1 >= 1 && y1 >= 1);
    --x1, --y1;
    printf("rquery %d..%d, %d..%d\n", x1, x2, y1, y2);
    return query(x1, y1) + query(x2, y2) - query(x1, y2) - query(x2, y1);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i)
    {
        scanf("%d", &arr[i]);
        occ[arr[i]] = i;
    }
    for (int i=1; i<=M; ++i)
    {
        int d; scanf("%d", &d);
        arr2.pb(mp(d, occ[d]));
        assert(d > 0 && occ[d] > 0);
    }
    // count all the inversions
    for (int i=N; i; --i)
    {
        invs[i] = query(ibit, arr[i]);
        update(ibit, arr[i], 1);
    }
    memset(ibit, 0, sizeof ibit);
    printf("inversions:\n"); for (int i=1; i<=N; ++i) printf("%d: %d\n", i, invs[i]);
    int totinvs = 0;
    for (int i=1; i<=N; ++i)
    {
        invs[i] += i-1-query(ibit, arr[i]);
        totinvs += invs[i];
        update(ibit, arr[i], 1);
    }
    printf("inversions:\n"); for (int i=1; i<=N; ++i) printf("%d: %d\n", i, invs[i]);
    //printf("inversions:\n"); for (int i=0; i<N; ++i) printf("%d: %d\n", i, invs[i]);

    // line intersection
    totinvs/=2;
    printf("m = %d\n", M);
    for (int i=1; i<=M; ++i)
    {
        printf("%d\n", totinvs);
        printf("arr2[%d].f %d: update/querying %d %d; %d - %d + bit stuff\n", i, arr2[i].f, arr2[i].f, arr2[i].s, totinvs, invs[i]);
        //totinvs = totinvs - invs[occ[i]] + rquery(arr2[occ[i]].f, N, arr2[occ[i]].s, N) + rquery(1, arr2[occ[i]].f, 1, arr2[occ[i]].s);
        totinvs = totinvs - invs[arr2[i].f] + rquery(arr2[i].f, N, arr2[i].s, N) + rquery(1, arr2[i].f, 1, arr2[i].s);
        update(arr2[i].f, arr2[i].s, 1);
        //printf("inf loop?\n");
    }
}

