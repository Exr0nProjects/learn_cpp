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
const double TOLERANCE = 0.0000000001; // one billionth
typedef pair<dl, dl> Point; // <x, y>
typedef pair<Point, Point> Seg; // <p1, p2>; assert(p1 <= p2)
int N;

typedef pair<pair<dl, int>, pair<int, int> > Event; // <<pos x, type {0 = start line, 1 = intersect/swap, 2 = end line}>, <line_id, other_id/unused>>

deque<Seg> lines;
priority_queue<Event, deque<Event>, greater<Event> > events;
dl sweepx;
int intersections = 0;

bool setcmp(int lhs, int rhs);
multiset<int, function<bool(int, int)> > active(setcmp);

pair<bool, Point> verticalIntersect(Seg s, dl x, dl bot=pow(-2, 99), dl top=pow(2, 99))
{
    // TODO: what if both lines are vertical
    if (s.first.first == s.second.first) // both lines vertical
    {
	auto inter = mp(s.first.first, max(min(s.first.second, s.second.second), bot));
	return mp(abs(s.first.first - x) <= TOLERANCE, inter);
    }

    dl m = (s.first.second-s.second.second) / (s.first.first - s.second.first);
    dl int_y = m*(x-s.first.first) + s.first.second;

    if (x < s.first.first || x > s.second.first	// segment surrounds vertical line
	 || int_y < bot || int_y > top)		// intersection isn't on vertical line
	return mp(false, mp(x, int_y));

    return mp(true, mp(x, int_y));
}
bool setcmp(int lhs, int rhs)
{   // TODO: fix this function so it actually works..
    // works when sweepx is zero, not when it gets assigned though
    return verticalIntersect(lines[lhs], sweepx).second.second < verticalIntersect(lines[rhs], sweepx).second.second;
}

pair<bool, Point> intersect(Seg s1, Seg s2)
{
    printf("intersect ((%lf %lf) (%lf %lf)) and ((%lf %lf) (%lf %lf))\n", s1.first.first, s1.first.second, s1.second.first, s1.second.second, s2.first.first, s2.first.second, s2.second.first, s2.second.second);
    // https://www.desmos.com/calculator/txz1ndtoot
    // segments have left point first
    if (s1.first > s1.second) swap(s1.first, s1.second);
    if (s2.first > s2.second) swap(s2.first, s2.second);

    if (s1.first.first == s1.second.first) 		// first line vertical
	return verticalIntersect(s2, s1.first.first);
    else if (s2.first.first == s2.second.first)		// second line vertical
	return verticalIntersect(s1, s2.first.first);

    dl m1 = (s1.first.second - s1.second.second) / (s1.first.first - s1.second.first);
    dl m2 = (s2.first.second - s2.second.second) / (s2.first.first - s2.second.first);

    // printf("m1 %lf, m2 %lf\n", m1, m2);

    assert(abs(m1-m2) > TOLERANCE); // disallow parallel lines: slope difference > one billionth

    dl intersect_x = (s2.first.second - s1.first.second + m1 * s1.first.first - m2 * s2.first.first) / (m1 - m2);
    dl intersect_y = m1*(intersect_x - s1.first.first) + s1.first.second;

    // printf("intersect x %lf y %lf\n", intersect_x, intersect_y);

    if (s1.first.first <= intersect_x && intersect_x <= s1.second.first
     && s2.first.first <= intersect_x && intersect_x <= s2.second.first)
	return mp(1, mp(intersect_x, intersect_y));
    else // intersect out of range
	return mp(0, mp(intersect_x, intersect_y));

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

// vertical lines
0 0 5 0
2 2 2 -2
=> yes (2, 0)

0 0.5 2 0.5
1 0 1 1
=> yes (1, 0.5)

0 0 0 2
1 0 1 2
=> no

0 0 0 2
0 1 0 3
=> yes (0, 1)
*/
}

void checkNeighboor(const multiset<int, function<bool(int, int)> > &container, const multiset<int, function<bool(int, int)> >::iterator &it, int direction)
{
    printf("+dist: %d, -dist: %d\n", distance(it, container.end()), distance(container.begin(), it));
    if (direction > 0 && distance(it, container.end()) <= direction) return; 	// would go past end
    if (direction < 0 && distance(container.begin(), it) < -direction) return; 	// would go past begining

    printf("            checking %+d...\n", direction);

    auto other = it;
    advance(other, direction);
    auto crossing = intersect(lines[*it], lines[*other]);
    if (crossing.first && crossing.second.first >= sweepx) // TODO: second condition needed?
    {
	printf("            intersection!!\n");
	events.push(mp(mp(crossing.second.first, 1), mp(*it, *other)));
	++intersections;
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
	events.emplace(mp(x1, 0), mp(i, 0));
	events.emplace(mp(x2, 2), mp(i, 0));
	lines.emplace_back(Point(x1, y1), Point(x2, y2));
	printf("\nsegment %d: %d %d %d %d", i, x1, y1, x2, y2);
    }
    printf("\n");

    // # of events = 2*N + # of intersections
    while (!events.empty())
    {
        printf("=================================================================\n");
        printEvent(events.top());

        Event ev = events.top();
        events.pop();

        sweepx = ev.first.first;

        if (ev.first.second == 0)	// start of a line
        {
            printf("        pushing %d\n", ev.second.first);
            auto it = active.insert(ev.second.first);
            printf("        *it %d\n", *it);
            printf("\nset contains {"); for (auto n : active) printf("%3d", n); printf(" }\n");
            checkNeighboor(active, it, 1);
	    checkNeighboor(active, it, -1);
        }
        else if (ev.first.second == 1)	// intersection
        {
	    // assert size
	    if (ev.second.first > ev.second.second) swap(ev.second.first, ev.second.second);
	    // find in active set
            multiset<int, function<bool(int, int)> >::iterator left = active.find(ev.second.first);
            multiset<int, function<bool(int, int)> >::iterator right = active.find(ev.second.second);

            swap(left, right);

            checkNeighboor(active, left, -1);
            checkNeighboor(active, right, 1);
        }
        else if (ev.first.second == 2) // end of line
        {
            // active.erase(ev.second.first);   // TODO: causes segfault
        }
    }

    printf("%d\n", intersections);
}
