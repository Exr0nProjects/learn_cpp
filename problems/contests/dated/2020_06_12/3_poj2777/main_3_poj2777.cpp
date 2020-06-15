/*
 * Problem 3_poj2777 (contests/dated/2020_06_12/3_poj2777)
 * Create time: Mon 15 Jun 2020 @ 11:29 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <numeric>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 300111;
int N, D, segt[MX<<1], sett[MX<<1];	// FIX: bounds--segtee needs 2*MX

inline int popcount(int n)
{
	int tot = 0;
	for (int i=0; i<32; ++i)
		if (n & 1<<i) ++tot;
	return tot;
}
void push_down(int k, int tl, int tr)
{
	if (!sett[k]) return;
	segt[k<<1] = segt[k<<1|1] =
	sett[k<<1] = sett[k<<1|1] = sett[k];
	sett[k] = 0;
}
void consolidate(int k, int tl, int tr)
{
	segt[k] = segt[k<<1] | segt[k<<1|1];
}

int query(int ql, int qr, int k=1, int tl=1, int tr=1<<D)
{
	if (qr < tl || tr < ql) return 0;
	if (ql <= tl && tr <= qr) return segt[k];
	push_down(k, tl, tr);
	int mid = tl + (tr-tl>>1);
	return query(ql, qr, k<<1, tl, mid) | query(ql, qr, k<<1|1, mid+1, tr);
}
void update(int ql, int qr, int v, int k=1, int tl=1, int tr=1<<D)
{
	//printf("update %d..%d with %d @ %d (%d..%d %f)\n", ql, qr, v, k, tl, tr, log2(tr-tl));
	if (qr < tl || tr < ql) return;
	if (ql <= tl && tr <= qr)
	{
		sett[k] = segt[k] = v;
		return;
	}
	push_down(k, tl, tr);
	int mid = tl + (tr-tl>>1);
	update(ql, qr, v, k<<1, tl, mid);
	update(ql, qr, v, k<<1|1, mid+1, tr);
	consolidate(k, tl, tr);
}

//void update(int ql, int qr, int v, int k=1, int tl=1, int tr=1<<D)
//{
//    printf("update %d..%d with %d @ %d (%d..%d)\n", ql, qr, v, k, tl, tr);
//    if (qr < tl || tr < ql) return;
//    if (ql <= tl && tr <= qr)
//    {
//        sett[k] = v;
//        segt[k] = v;
//        return;
//    }
//    push_down(k, tl, tr);
//    int mid = tl + (tr - tl) /2;
//    update(ql, qr, v, k*2, tl, mid);
//    update(ql, qr, v, k*2+1, mid+1, tr);
//    consolidate(k, tl, tr);
//}

void dump()
{
	return;
	int pad = D;
	for (int i=1; i<1<<1+D; ++i)
	{
		if (popcount(i) == 1) { printf("\n"); --pad; }
		printf("%3d%3d, ", segt[i], sett[i]);
		for (int i=1; i<1<<D; ++i) printf("        ");
	}
	printf("\n");
}

int main()
{
	int O;
	scanf("%d%d%d", &N, &O, &O);
	for (; 1<<D<=N; ++D);	// FIX: init segtree
	update(1, N, 1);	// FIX: init the values too
	//printf("D = %d vs %d\n", D, (int)log2(N)+1);

	for (int i=0; i<O; ++i)
	{
		char c; scanf("\n%c", &c);
		//printf("got %c\n", c);
		int l, r; scanf("%d%d", &l, &r);
		if (c == 'C')
		{
			int d; scanf("%d", &d);
			update(l, r, 1<<d-1);
		}
		else if (c == 'P')
			printf("%d\n", popcount(query(l, r)));
		else --i;
		dump();
	}

	return 0;
}

