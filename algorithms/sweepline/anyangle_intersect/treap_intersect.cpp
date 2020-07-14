// 13 July 2020
// don't allow concurrent lines or vertical lines

#include <set>
#include <queue>
#include <cmath>
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
const dl tiny = 0.0000000001;
const bool DEBUG = 0;
int N;
Seg segs[MX];
dl slopes[MX];
dl sweep = 0;   // x pos of the sweep line
//priority_queue<Event, deque<Event>, greater<Event> > events;
set<Event> events;

bool cmp(int lhs, int rhs)
{
    if (DEBUG) printf("cmd %d (%lf) vs %d (%lf)\n",
            lhs, slopes[lhs]*(sweep-segs[lhs].x.x)+segs[lhs].x.y,
            rhs, slopes[rhs]*(sweep-segs[rhs].x.x)+segs[rhs].x.y);
    return slopes[lhs]*(sweep-segs[lhs].x.x)+segs[lhs].x.y
         < slopes[rhs]*(sweep-segs[rhs].x.x)+segs[rhs].x.y;
}

struct Node
{
    int id, w, s;
    Node *c[2] = {};
    Node *r[2] = {};
    Node (int d): id(d), w(rand() % 10000), s(1) {};
} *root = nullptr;

#define RESET "\033[0m"
#define BLACK "\x1b[38;5;239m"
void dump(Node *cur, int lay=1, long long lbar=0, long long rbar=0)
{
    if (!DEBUG) return;
    //if (lay == 1) printf("dump:\n");
    if (!cur) return;
    dump(cur->c[1], lay+1);
    for (int i=0; i<lay; ++i)
        printf("%c   ", (lbar|rbar)&(1<<i) ? '|' : ' ');
    printf("%d %s%x %x (%4d @ %x)%s\n", cur->id, BLACK, cur->r[0], cur->r[1], cur->w, cur, RESET);
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
Node *locate(Node *cur, int id)
{
    if (DEBUG) printf("        locate %d at %x\n", id, cur);
    if (!cur || cur->id == id) return cur;
    return locate(cur->c[cmp(cur->id, id)], id);
}
Node *insert(Node *&cur, int id)
{
    if (!cur) return cur = new Node(id);
    if (cur->id == id) return cur;
    const bool dir = cmp(cur->id, id);
    Node *&stp = cur->c[dir];
    Node *ins = insert(stp, id);
    if (stp == ins && !ins->r[!dir])
    {
        ins->r[dir] = cur->r[dir];
        ins->r[!dir] = cur;
        cur->r[dir] = ins;
        if (ins->r[dir])
            ins->r[dir]->r[!dir] = ins;
    }
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
            if (cur->r[0]) cur->r[0]->r[1] = cur->r[1];
            if (cur->r[1]) cur->r[1]->r[0] = cur->r[0];
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

void intersect(Node *_a, Node *_b)
{
    if (!_a || !_b) return;
    int a = _a->id, b = _b->id;
    if (fabs(slopes[a]-slopes[b]) < tiny) return; // parallel
    dl x = (slopes[a]*segs[a].x.x - slopes[b]*segs[b].x.x + segs[b].x.y-segs[a].x.y)/(slopes[a]-slopes[b]);
    if (x >= sweep
        && segs[a].x.x <= x && x <= segs[a].y.x
        && segs[b].x.x <= x && x <= segs[b].y.x)
    {
        if (DEBUG) printf("\n\n##################\n\nINTERSECTION BETWEEN %d AND %d AT %lf\n\n##################\n\n", a, b, x);
        events.insert(mp(mp(x, 1), mp(a, b)));
    }
}

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
        scanf("%lf%lf%lf%lf", &segs[i].x.x, &segs[i].x.y, &segs[i].y.x, &segs[i].y.y);
        if (segs[i].y < segs[i].x) swap(segs[i].x, segs[i].y);
        segs[i].y.x += tiny*10; // TODO: hacky way of dealing w/ vertical lines
    }
    sort(segs, segs+N);
    for (int i=0; i<N; ++i)
    {
        slopes[i] = (segs[i].x.y-segs[i].y.y)/(segs[i].x.x-segs[i].y.x);
        //printf("line %d: %lf,%lf .. %lf,%lf with slope %lf\n", i, segs[i].x.x, segs[i].x.y, segs[i].y.x, segs[i].y.y, slopes[i]);
        events.insert(mp(mp(segs[i].x.x, 0), mp(i, i)));  // push insertion event
        events.insert(mp(mp(segs[i].y.x, 2), mp(i, i)));  // push deletion event
    }
    while (!events.empty())
    {
        //Event cur = events.top(); events.pop();
        Event cur = *events.begin(); events.erase(events.begin());
        //sweep = cur.x.x - tiny; // FIX: do crossing math right before crossing so order is preserved before swap
        sweep = max(sweep, cur.x.x - tiny); // FIX: don't step back after a crossing changes tree?
        if (cur.x.y == 0)
        {
            if (DEBUG) printf("sweep %lf: inserting line %d\n", sweep, cur.id1);
            Node *ins = insert(root, cur.id1);
            //printf("    would check %dx%x, %dx%x\n", cur.id1, ins->r[0], cur.id1, ins->r[1]);
            intersect(ins->r[0], ins);  // FIX: order matters on intersect, lowest should be first
            intersect(ins, ins->r[1]);
        }
        if (cur.x.y == 1)
        {
            printf("%lf %lf\n", cur.x.x, slopes[cur.y.x]*(cur.x.x-segs[cur.y.x].x.x)+segs[cur.y.x].x.y);
            if (DEBUG) printf("sweep %lf: crossing between lines %d and %d\n", sweep, cur.id1, cur.id2);
            Node *lo = locate(root, cur.id1);
            Node *hi = locate(root, cur.id2);
            //printf("got %x and %x\n", lo, hi);
            if (lo && hi)
            {
                swap(lo->id, hi->id);
                sweep += tiny*2;
                //printf("    would check %dx%x, %dx%x\n", hi->id, hi->r[1], lo->id, lo->r[0]);
                intersect(lo->r[0], lo);
                intersect(hi, hi->r[1]);
            }
        }
        if (cur.x.y == 2)
        {
            if (DEBUG) printf("sweep %lf: deleting line %d\n", sweep, cur.id1);
            Node *rem = locate(root, cur.id1);
            Node *lo = rem->r[0], *hi = rem->r[1];
            remove(root, cur.id1);
            //printf("deleted, about to intersect %x %x\n", lo, hi); fflush(stdout);
            //printf("    would check %xx%x\n", rem->r[0], rem->r[1]);
            intersect(lo, hi);
            //printf("intersected\n"); fflush(stdout);
        }
        dump(root); if (DEBUG) printf("\n");
    }
}

