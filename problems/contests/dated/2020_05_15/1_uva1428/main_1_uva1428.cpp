/*
TASK: 1_uva1428
LANG: C++14
*/

/*
 * Problem 1_uva1428 (contests/dated/2020_05_15/1_uva1428)
 * Create time: Sun 24 May 2020 @ 11:32 (PDT)
 * Accept time: [!meta:end!]
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=4174
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "1_uva1428");

using namespace std;
const int MX = 20111;
int N, skill[MX], lhsl[MX], lhsg[MX], rhsl[MX], rhsg[MX];	// lhs less, lhs greater, rhs less, rhs greater
struct Node
{
	int d, w, x=1, s=1;
	Node *c[2] = {};
	Node(int d): d(d), w(rand()) {}
} *root = nullptr;
void setSize(Node *cur)
{
	cur->s = cur->x;
	if (cur->c[0]) cur->s += cur->c[0]->s;
	if (cur->c[1]) cur->s += cur->c[1]->s;
}
void rotate(Node *&cur, bool dir)
{
	if (!cur || !cur->c[dir]) return;
	Node *thn = cur->c[dir];
	cur->c[dir] = thn->c[!dir];
	setSize(cur);
	thn->c[!dir] = cur;
	setSize(thn);
	cur = thn;
}
Node *insert(Node *&cur, int d)
{
	if (!cur) return cur = new Node(d);
	if (cur->d == d) { ++cur->x; ++cur->s; return cur; }
	Node *&stp = cur->c[cur->d < d];
	Node *ins = insert(stp, d);
	if (cur->w < stp->w) rotate(cur, cur->d < d);
	setSize(cur);
	return ins;
}
Node *locate(Node *&cur, int d)
{
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d<d], d);
}
ll getRank(Node *cur, int d)
{
	if (!cur) return 0;
	const int lsz = cur->c[0] ? cur->c[0]->s : 0;
	if (d < cur->d) return getRank(cur->c[0], d); 
	if (cur->d == d) return lsz;
	return lsz + cur->x + getRank(cur->c[1], d); // FIX: cur->x not cur->s
}
void dump(Node *cur, int lay=1)
{
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i) printf("    ");
	printf("%d x%d w%d s%d\n", cur->d, cur->x, cur->w, cur->s);
	dump(cur->c[0], lay+1);
}

ll solve()
{
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		scanf("%d", &skill[i]);
	
	Node *lsweep = nullptr;
	for (int i=0; i<N; ++i)
	{
		Node *ins = insert(lsweep, skill[i]);
		lhsl[i] = getRank(lsweep, skill[i]);// + ins->x -1;
		lhsg[i] = lsweep->s - lhsl[i]-1;
		lhsl[i] += ins->x -1;
		printf("left:  %d (%d): less%3d greater%3d\n", i, skill[i], lhsl[i], lhsg[i]);
	}

	Node *rsweep = nullptr;
	for (int i=N-1; i>=0; --i)
	{
		Node *ins = insert(rsweep, skill[i]);
		rhsl[i] = getRank(rsweep, skill[i]) + ins->x -1;
		rhsg[i] = rsweep->s - rhsl[i]-1;
		//rhsl[i] += ins->x -1;
		printf("right: %d (%d): less%3d greater%3d\n", i, skill[i], rhsl[i], rhsg[i]);
	}
	
	ll tot = 0;

	for (int i=0; i<N; ++i)
	{
		printf("%d: += %d\n", i, lhsl[i] * rhsg[i] + lhsg[i] * rhsl[i]);
		tot += lhsl[i] * rhsg[i] + lhsg[i] * rhsl[i];
	}

	printf("%lld\n", tot);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=0; i<T; ++i) solve();

    return 0;
}

