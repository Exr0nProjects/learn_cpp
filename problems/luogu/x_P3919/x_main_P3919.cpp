/*
 * Problem P3919 (luogu/P3919)
 * Create time: Mon 22 Jun 2020 @ 11:22 (PDT)
 * Accept time: Mon 22 Jun 2020 @ 12:44 (PDT)
 *
 */

#include <cstdio>
using namespace std;
const int MX = 1000111;
int N, D, Q, val[MX<<5];
int alc=1, lc[MX<<5], rc[MX<<5], rt[MX];

void update(int q, int setv, int &k, int tl=1, int tr=N)
{
	lc[alc] = lc[k];
	rc[alc] = rc[k];
	k = alc++;
	if (tl == tr) { val[k] = setv; return; }

	int mid = tl + (tr-tl>>1);
	if (q <= mid) update(q, setv, lc[k], tl, mid);
	else update(q, setv, rc[k], mid+1, tr);
}

int query_iter(int q, int k, int tl=1, int tr=N)
{
	while (tl < tr)
	{
		const int mid = tl + (tr-tl>>1);
		if (q <= mid) k = lc[k], tr=mid;
		else k = rc[k], tl=mid+1;
	}
	return val[k];
}

int main()
{
	scanf("%d%d", &N, &Q);
	D = 64-__builtin_clz(N);
	rt[0] = alc++;
	for (int i=1; i<1<<D; ++i)
	{
		lc[i] = alc++;
		rc[i] = alc++;
	}

	for (int i=0; i<N; ++i)
	{
		scanf("%d", &val[i+(1<<D)]);
	}
	N = 1<<D;

	for (int q=1; q<=Q; ++q)
	{
		int t, c, p, d; scanf("%d%d%d", &t, &c, &p);
		rt[q] = rt[t];
		if (c == 2) printf("%d\n", query_iter(p, rt[q]));
		else
		{
			scanf("%d", &d);
			update(p, d, rt[q]);
		}
	}

	return 0;
}

