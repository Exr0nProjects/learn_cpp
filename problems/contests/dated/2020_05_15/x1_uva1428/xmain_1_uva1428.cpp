/*
TASK: 1_uva1428
LANG: C++14
*/

/*
 * Problem 1_uva1428 (contests/dated/2020_05_15/1_uva1428)
 * Create time: Sun 24 May 2020 @ 11:32 (PDT)
 * Accept time: Fri 29 May 2020 @ 15:59 (PDT)
 * https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=4174
 * TODO: write with segtree over counting sort array
 */

#include <iostream>
#define ll long long

using namespace std;
const int MX = 20111;
int N, skill[MX];
int c[MX], d[MX];
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
	//printf("rotate...\n"); fflush(stdout);
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
	//printf("insert... %d at %x\n", d, cur); fflush(stdout);
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
	//printf("locate... %d at %x\n", d, cur); fflush(stdout);
	if (!cur || cur->d == d) return cur;
	return locate(cur->c[cur->d<d], d);
}
ll getRank(Node *cur, int d)
{
	//printf("getRank... %d at %x\n", d, cur); fflush(stdout);
	if (!cur) return 0;
	const int lsz = cur->c[0] ? cur->c[0]->s : 0;
	if (d < cur->d) return getRank(cur->c[0], d); 
	if (cur->d == d) return lsz;
	return lsz + cur->x + getRank(cur->c[1], d); // FIX: cur->x not cur->s
}
void clear(Node *cur)
{
	if (!cur) return;
	clear(cur->c[0]);
	clear(cur->c[1]);
	delete cur;
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
		c[i] = getRank(lsweep, skill[i]);
		//printf("left %d (%d): less %d\n", i, skill[i], c[i]);
	}
	clear(lsweep);

	Node *rsweep = nullptr;
	for (int i=N-1; i>=0; --i)
	{
		Node *ins = insert(rsweep, skill[i]);
		d[i] = getRank(rsweep, skill[i]);
		//printf("right %d (%d): less %d\n", i, skill[i], d[i]);
	}
	clear(rsweep);
	
	ll tot = 0;

	for (int i=0; i<N; ++i)
	{
		tot += c[i]*(N-d[i]-i-1) + (i-c[i])*d[i];
		//printf("%d: %d\n", i, tot);
	}

	printf("%lld\n", tot);
}

int main()
{
	srand(10);
	int T;
	scanf("%d", &T);
	for (int i=0; i<T; ++i) solve();

    return 0;
}

