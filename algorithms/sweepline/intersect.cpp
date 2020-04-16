#include <functional>
#include <utility>
#include <deque>
#include <queue>
#include <cmath>
#include <set>

#define dl double
#define mp make_pair

using namespace std;

const int MX = 1000111;
typedef pair<dl, dl> Point; // <x, y>
typedef pair<Point, Point> Seg; // <p1, p2>; assert(p1 <= p2)
int N;

typedef pair<pair<dl, int>, pair<int, int> > Event; // <<pos x, type {0 = start line, 1 = intersect/swap, 2 = end line}>, <line_id, other_id/unused>>

deque<Seg> lines;
priority_queue<Event, deque<Event>, greater<Event> > events;
dl sweepx;

bool setcmp(int lhs, int rhs);
multiset<int, function<bool(int, int)> > active(setcmp);

pair<bool, Point> verticalIntersect(Seg s, dl x)
{
    if (x < s.first.first || x > s.second.first)
	return mp(false, mp((dl)0, (dl)0));
    dl m = (s.first.second-s.second.second) / (s.first.first - s.second.first);
    return pair<bool, Point>{true, mp(x, m*(x-s.first.first)+s.first.second)};
}
bool setcmp(int lhs, int rhs)
{   // TODO: fix this function so it actually works..
    // works when sweepx is zero, not when it gets assigned though
    return verticalIntersect(lines[lhs], sweepx).second.second < verticalIntersect(lines[rhs], sweepx).second.second;
}

pair<bool, Point> intersect(Seg s1, Seg s2)
{
    // printf("intersect ((%lf %lf) (%lf %lf)) and ((%lf %lf) (%lf %lf))\n", s1.first.first, s1.first.second, s1.second.first, s1.second.second, s2.first.first, s2.first.second, s2.second.first, s2.second.second);
    // https://www.desmos.com/calculator/txz1ndtoot
    // segments have left point first
    if (s1.first > s1.second) swap(s1.first, s1.second);
    if (s2.first > s2.second) swap(s2.first, s2.second);

    // tilt vertical lines left slightly; TODO: just find the y on the other line at this x instead of modifying
    if (s1.first.first == s1.second.first) s1.second.first += 0.0000000001;	// TODO: use verticalIntersect
    if (s2.first.first == s2.second.first) s2.second.first += 0.0000000001;

    dl m1 = (s1.first.second - s1.second.second) / (s1.first.first - s1.second.first);
    dl m2 = (s2.first.second - s2.second.second) / (s2.first.first - s2.second.first);

    // printf("m1 %lf, m2 %lf\n", m1, m2);

    assert(abs(m2-m1) > 0.0000000001); // disallow parallel lines: slope difference > one billionth

    dl intersect_x = (s2.first.second - s1.first.second + m1 * s1.first.first - m2 * s2.first.first) / (m1 - m2);
    dl intersect_y = m1*(intersect_x - s1.first.first) + s1.first.second;

    // printf("intersect x %lf y %lf\n", intersect_x, intersect_y);

    if (s1.first.first <= intersect_x && intersect_x <= s1.second.first
     && s2.first.first <= intersect_x && intersect_x <= s2.second.first)
	return make_pair(1, make_pair(intersect_x, intersect_y));
    else // intersect out of range
	return make_pair(0, make_pair(intersect_x, intersect_y));

/*
int main()
{
    while (true)
    {
	int a, b, c, d, e, f, g, h;
	scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
	auto loc = intersect(mp(mp(a, b), mp(c, d)), mp(mp(e, f), mp(g, h)));
	printf("%d: (%lf %lf)\n", loc.first, loc.second.first, loc.second.second);
    }
}

0 0 5 0
2 2 2 -2
=> yes (2, 0)

12 3 5 9
2 -4 12 10
=> yes (8.989, 5.658)

-20 -13 33 26
21 -5 -25 20
=> yes (3.671, 4.418)

9 18 25 25
10 10 -10 20
=> no (1, 14.5)

9 19 0 25
30 1 0 20
=> no (150, -75)
*/
}

void checkNeighboors(const multiset<int, function<bool(int, int)> > &container, const multiset<int, function<bool(int, int)> >::iterator &it)
{
    printf("        Checking neighbors of %d\n", *it);
    if (it != container.begin())	// FIX: checks to prevent accessing invalid iter and segfault
    {
	printf("            checking prev...\n");
	auto intersectPrev = intersect(lines[*it], lines[*prev(it)]);
	if (intersectPrev.first && intersectPrev.second.first > sweepx)
	{
	    printf("            intersection!!\n");
	    events.push(mp(mp(intersectPrev.second.first, 1), mp(*it, *prev(it))));
	}
    }

    if (next(it) != container.end())
    {
	printf("            checking next...\n");
	auto intersectNext = intersect(lines[*it], lines[*next(it)]);
	if (intersectNext.first && intersectNext.second.first > sweepx)
	{
	    printf("            intersection!!\n");
	    events.push(mp(mp(intersectNext.second.first, 1), mp(*it, *next(it))));
	}
    }
}

void printEvent(const Event &ev)
{
    printf("    %d event at %lf, payload %d %d\n", ev.first.second, ev.first.first, ev.second.first, ev.second.second);
}

int main()
{
    /*
     * testing plan:
     * 1. [x] test intersection
     * 2. [ ] test swapping of stuff in the set
2
0 0 5 0
2 2 2 -2
     * 3. [ ] test events---do events show up in the right place?
     */

    printf("Please, no parallel or concurrent lines!\n");
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 > x2)
	{
	    swap(x1, x2);
	    swap(y1, y2);
	}
	events.emplace(make_pair(x1, 0), mp(i, 0));
	events.emplace(make_pair(x2, 2), mp(i, 0));
	lines.emplace_back(Point(x1, y1), Point(x2, y2));
	printf("\nsegment %d: %d %d %d %d", i, x1, y1, x2, y2);
    }
    printf("\n");

    // # of events = 2*N + # of intersections
    while (!events.empty())
    {
        printf("=================================================================\n");
        printEvent(events.top());   // TODO: why does the destruction event of 1 come before the crossing?

        Event ev = events.top();
        events.pop();

        sweepx = ev.first.first;

        if (ev.first.second == 0)	// start of a line
        {
            printf("        pushing %d\n", ev.second.first);
            auto it = active.insert(ev.second.first);
            printf("        *it %d\n", *it);
            printf("\nset contains {"); for (auto n : active) printf("%3d", n); printf(" }\n");
            checkNeighboors(active, it);
        }
        else if (ev.first.second == 1)	// intersection
        {
            set<int, function<bool(int, int)> >::iterator left = active.find(ev.second.first);
            set<int, function<bool(int, int)> >::iterator right = active.find(ev.second.second);

            swap(left, right);

            checkNeighboors(active, left);
            checkNeighboors(active, right);
        }
        else if (ev.first.second == 2) // end of line
        {
            // active.erase(ev.second.first);   // TODO: causes segfault
        }
    }
}
