/*
 * Problem 3321 (poj/3321)
 * Create time: Sun 07 Jun 2020 @ 14:16 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <utility>
#include <list>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 100111;
int N, Q;

list<int> head[MX];
int pos[MX], lef[MX], rig[MX];	// how the tree maps to the bit

bool apple[MX];

ll bidx[MX];

int idx=1;
pair<int, int> get_bounds(int cur, int pre=0)
{
	if (pos[cur]) return mp(0, 0); // should never happen
	if (!pre) idx = 1; // simulate static variable
	pos[cur] = idx++;	// FIX: idx++ not cur++

	pair<int, int> ret(0, pos[cur]);	// FIX: pos[cur] not pos[MX]
	if (head[cur].size() == 1)
		ret = mp(pos[cur], pos[cur]);	// no children
	else
	{
		for (list<int>::iterator it=head[cur].begin(); it!=head[cur].end(); ++it)
			if (*it != pre)
				ret.s = get_bounds(*it, cur).s;
		ret.f = pos[cur];				// include self in the range (preorder traversal)
	}

	lef[cur] = ret.f;
	rig[cur] = ret.s;
	return ret;
}

ll query(int l, int r)
{
	--l;
	ll tot = 0;
	for (; r>l; r-=r&-r)
		tot += bidx[r];
	for (; l>r; l-=l&-l)
		tot -= bidx[l];
	return tot;
}
void update(int i, int v)
{
	for (; i<=N; i+=i&-i)
		bidx[i] += v;
}

int main()
{
	scanf("%d", &N);
	for (int i=1; i<N; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		head[u].pb(v);
		head[v].pb(u);
	}

	get_bounds(1);		// figure out how to map the input tree to the bit
	//for (int i=1; i<=N; ++i) printf("fork %3d (%3d): %3d ..%3d\n", i, pos[i], lef[i], rig[i]);

	// init the tree to full
	for (int i=1; i<=N; ++i)
	{
		update(i, 1);
		apple[i] = 1;
	}
	//printf("ready for queries\n");

	scanf("%d", &Q);
	for (int i=0; i<Q; ++i)
	{
		//printf("kk $ ");
		char c=0; while (c != 'Q' && c != 'C') scanf("%c", &c);
		int d; scanf("%d", &d);
		if (c == 'Q') printf("%d\n", query(lef[d], rig[d]));
		if (c == 'C')
		{
			update(pos[d], 1-2*apple[d]);
			apple[d] ^= 1;
		}
	}

	return 0;
}

