/*
TASK: 1_uva1428
LANG: C++14
*/

/*
 * Problem 1_uva1428 (contests/dated/2020_05_15/1_uva1428)
 * Create time: Mon 25 May 2020 @ 09:07 (PDT)
 * Accept time: [!meta:end!]
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=4174
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 20111;
const int TREE = 100111;
int N, D, sadd[2*TREE], sval[2*TREE], skill[MX], lef[MX], rig[MX];
ll query(ll ql, ll qr, ll k=1, ll tl=1, ll tr=1<<D, ll acc=0, int lay=0)
{
	//for (int i=0; i<lay; ++i) printf("    "); printf("query %d %d : %d %d..%d +%d\n", ql, qr, k, tl, tr, acc);
	if (qr < ql) return 0;
	if (qr < tl || tr < ql) return 0;
	acc += sadd[k];
	if (ql <= tl && tr <= qr)
	{
		//printf("direct => %d + %d*%d = %d\n", sval[k], acc, (tr-tl+1), sval[k]+acc*(tr-tl+1));
		return sval[k] + acc*(tr-tl+1);	// FIX: (tr-tl+1) not (tr-tl) cuz its inc inc
	}
	const int mid = tl + (tr - tl)/2;
	ll ret= query(ql, qr, 2*k, tl, mid, acc, lay+1) + query(ql, qr, 2*k+1, mid+1, tr, acc, lay+1);
	//for (int i=0; i<lay; ++i) printf("    "); printf("=> %d\n", ret);
	return ret;
}
ll update(ll ql, ll qr, ll v, ll k=1, ll tl=1, ll tr=1<<D)
{
	//printf("update %d %d +%d: %d %d..%d\n", ql, qr, v, k, tl, tr);
	if (qr < ql) return 0;
	if (qr < tl || tr < ql) return sval[k] + sadd[k]*(tr-tl+1);
	if (ql <= tl && tr <= qr)
	{
		sadd[k] += v;
		return sval[k] + sadd[k]*(tr-tl+1);
	}
	const int mid = tl + (tr-tl)/2;
	sval[k] = update(ql, qr, v, 2*k, tl, mid) + update(ql, qr, v, 2*k+1, mid+1, tr);
	return sval[k] + sadd[k]*(tr-tl+1);
}

ll solve()
{
	memset(sadd, 0, sizeof sadd);
	memset(sval, 0, sizeof sval);
	D = log2(100000) +1;

	memset(lef, 0, sizeof lef);
	memset(rig, 0, sizeof rig);

	vector<pair<int, int> > sorted;

	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		scanf("%d", &skill[i]);
		lef[i] = query(1, skill[i]-1);
		//printf("%d (%d): c%3d\n", i, skill[i], lef[i]);
		update(skill[i], skill[i], 1);	// FIX: don't update range, just update one. segtree takes care of range
		sorted.pb(mp(skill[i], i));
	}
	sort(sorted.begin(), sorted.end());
	for (int i=0; i<sorted.size(); ++i)
	{
		//printf("sorted %d: (%3d #%3d) c%3d d%3d\n", i, sorted[i].f, sorted[i].s, lef[sorted[i].s], i-lef[sorted[i].s]);
		rig[sorted[i].s] = i-lef[sorted[i].s];
	}
	ll tot=0;
	for (int i=0; i<N; ++i)
	{
		//printf("%d (%d): c%3d d%3d\n", i, skill[i], lef[i], rig[i]);
		tot += lef[i]*(N-rig[i]-i-1) + (i-lef[i])*rig[i];
	}
	printf("%lld\n", tot);
}

void dump()
{
	for (int i=1; i<(1<<D+1); ++i)
	{
		if (__builtin_popcount(i) == 1) printf("\n");
		printf("%3d +%3d", sval[i], sadd[i]);
	}
	printf("\n");
}

//ll solve()
//{
//    scanf("%d", &N);
//    for (int i=0; i<N; ++i)
//        scanf("%d", &skill[i]);

//    Node *lsweep = nullptr;
//    for (int i=0; i<N; ++i)
//    {
//        Node *ins = insert(lsweep, skill[i]);
//        c[i] = getRank(lsweep, skill[i]);
//        //printf("left %d (%d): less %d\n", i, skill[i], c[i]);
//    }
//    clear(lsweep);

//    Node *rsweep = nullptr;
//    for (int i=N-1; i>=0; --i)
//    {
//        Node *ins = insert(rsweep, skill[i]);
//        d[i] = getRank(rsweep, skill[i]);
//        //printf("right %d (%d): less %d\n", i, skill[i], d[i]);
//    }
//    clear(rsweep);

//    ll tot = 0;

//    for (int i=0; i<N; ++i)
//    {
//        tot += c[i]*(N-d[i]-i-1) + (i-c[i])*d[i];
//        //printf("%d: %d\n", i, tot);
//    }

//    printf("%lld\n", tot);
//}

int main()
{
	//scanf("%d", &N);
	//D = log2(N) +1;
	//for (int i=0; i<N; ++i)
	//    scanf("%d", &sval[(1<<D)+i]);
	//for (int i=(1<<D)-1; i>0; --i)
	//    sval[i] = sval[2*i] + sval[2*i+1];
	//while (true)
	//{
	//    char c=' '; while(c<'a'||c>'z')scanf("%c",&c);
	//    int l, r; scanf("%d%d", &l, &r);
	//    if (c == 'q')
	//        printf("%d\n", query(l, r));
	//    if (c == 'u')
	//    {
	//        int v; scanf("%d", &v);
	//        printf("%d\n", update(l, r, v));
	//    }
	//    dump();
	//}

	int T;
	scanf("%d", &T);
	for (int i=0; i<T; ++i) solve();

    return 0;
}

