// 13 July 2020
// don't allow concurrent lines or vertical lines
// optimiztion: use next/prev pointers instead of bound function to check neighbors in constant time

#include <queue>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>
#define x first
#define y second
#define id1 y.x
#define id2 y.y
#define mp make_pair
#define dl double
using namespace std;

typedef pair<pair<dl, dl>, pair<dl, dl> > Seg;
typedef pair<pair<dl, int>, pair<int, int> > Event; // x-pos, type{0: new, 1: cross, 2: remove}, {id, 0 for event 0,2; id, id}
const int MX = 1000111;
int N;
Seg segs[MX];
dl slopes[MX];
dl sweep = 0;   // x pos of the sweep line
priority_queue<Event, deque<Event>, greater<Event> > events;

bool cmp(int lhs, int rhs)
{
    return slopes[lhs]*(sweep-segs[lhs].x.x)+segs[lhs].x.y
         < slopes[rhs]*(sweep-segs[rhs].x.x)+segs[rhs].x.y;
}

pair<bool, pair<dl, dl> > intersect(int a, int b)
{
    // TODO: find intersection of ids a and b
}

struct Node
{
    int id, w, s;
    Node *c[2] = {};
    Node (int d): id(d), w(rand() % 10000), s(1) {};
} *root = nullptr;

#define RESET "\033[0m"
#define BLACK "\x1b[38;5;239m"
void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
	//if (lay == 1) printf("dump:\n");
	if (!cur) return;
	dump(cur->c[1], lay+1);
	for (int i=0; i<lay; ++i)
		printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
	printf("%d %s(%4d @ %x)%s\n", cur->id, BLACK, cur->w, cur, RESET);
	dump(cur->c[0], lay+1);
}

void setSize(Node *cur)
{
    cur->s = 1;
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
Node *bound(Node *cur, int id, bool dir, bool take, int lay=1) // take = whether or not to count an exact match
{
    if (!cur || cur->id == id) return take ? cur : nullptr;
    for (int i=0; i<lay; ++i) printf("|   "); printf("bound at %x for %d , %d\n", cur, id, dir);
    Node *got = bound(cur->c[cmp(cur->id, id)], id, dir, take, lay+1);
    for (int i=0; i<lay; ++i) printf("|   "); printf("went %d got %x\n", cmp(cur->id, id), got);
    if (got) return got;
    return cmp(cur->id, id) != dir ? cur : 0;
}
Node *insert(Node *&cur, int id)
{
    if (!cur) return cur = new Node(id);
    if (cur->id == id) return cur;
    const bool dir = cmp(cur->id, id);
    Node *&stp = cur->c[dir];
    Node *ins = insert(stp, id);
    if (cur->w < stp->w)
        rotate(cur, dir);
    setSize(cur);
    return ins;
}
void remove(Node *&cur, int id)
{
    if (!cur) return;
    if (cur->id == id)
    {
        if (cur->c[0] && cur->c[1])
        {
            bool dir = cur->c[0]->w < cur->c[1]->w;
            rotate(cur, dir);
            remove(cur->c[!dir], id);
        }
        else
        {
            Node *thn = cur;
            cur = cur->c[0] ? cur->c[0] : cur->c[1];
            delete thn;
        }
    }
    else
    {
        remove(cur->c[cmp(cur->id, id)], id);
        setSize(cur);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
        scanf("%lf%lf%lf%lf", &segs[i].x.x, &segs[i].x.y, &segs[i].y.x, &segs[i].y.y);
        if (segs[i].y < segs[i].x) swap(segs[i].x, segs[i].y);
    }
    sort(segs, segs+N);
    for (int i=0; i<N; ++i)
    {
        slopes[i] = (segs[i].x.y-segs[i].y.y)/(segs[i].x.x-segs[i].y.x);
        printf("line %d: %lf,%lf .. %lf,%lf with slope %lf\n", i, segs[i].x.x, segs[i].x.y, segs[i].y.x, segs[i].y.y, slopes[i]);
        events.push(mp(mp(segs[i].x.x, 0), mp(i, i)));  // push insertion event
        events.push(mp(mp(segs[i].y.x, 2), mp(i, i)));  // push deletion event
    }
    // TODO: automate crossing checks!
    events.push(mp(mp(5, 1), mp(0, 1)));
    events.push(mp(mp(6.2, 1), mp(1, 2)));
    while (!events.empty())
    {
        Event cur = events.top(); events.pop();
        sweep = cur.x.x - 0.0000001; // FIX: do crossing math right before crossing so order is preserved before swap
        if (cur.x.y == 0)
        {
            printf("sweep %lf: inserting line %d\n", sweep, cur.id1);
            insert(root, cur.id1);
            printf("    would check %dx%x, %dx%x\n", cur.id1, bound(root, cur.id1, 0, 0), cur.id1, bound(root, cur.id1, 1, 0));
            // TODO: check neighbors
        }
        if (cur.x.y == 1)
        {
            printf("sweep %lf: crossing between lines %d and %d\n", sweep, cur.id1, cur.id2);
            Node *lo = bound(root, cur.id1, 0, 1);
            Node *hi = bound(root, cur.id2, 0, 1);
            //printf("got %x and %x\n", lo, hi);
            if (lo && hi) swap(lo->id, hi->id);
            sweep += 0.0000002;
            printf("    would check %dx%x, %dx%x\n", cur.id1, bound(root, cur.id1, 1, 0), cur.id2, bound(root, cur.id2, 0, 0));
            // TODO: check neighbors
        }
        if (cur.x.y == 2)
        {
            printf("sweep %lf: deleting line %d\n", sweep, cur.id1);
            remove(root, cur.id1);
            printf("    would check %dx%x, %dx%x\n", cur.id1, bound(root, cur.id1, 0, 0), cur.id1, bound(root, cur.id1, 1, 0));
            // TODO: check neighbors
        }
        dump(root); printf("\n");
    }
}

