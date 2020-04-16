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

typedef pair<pair<dl, int>, pair<int, int> > Event; // <<pos x, type {1 = start line, 0 = intersect/swap, -1 = end line}>, <line_id, other_id/unused>>

deque<Seg> lines;
priority_queue<Event, deque<Event>, greater<Event> > events;
dl sweepx;

bool setcmp(int lhs, int rhs);
set<int, function<bool(int, int)> > active(setcmp);

pair<bool, Point> verticalIntersect(Seg s, dl x)
{
    if (x < s.first.first || x > s.second.first)
	return mp(false, mp((dl)0, (dl)0));
    dl m = (s.first.second-s.second.second) / (s.first.first - s.second.first);
    return pair<bool, Point>{true, mp(x, m*(x-s.first.first)+s.first.second)};
}
bool setcmp(int lhs, int rhs)
{
    return verticalIntersect(lines[lhs], sweepx) < verticalIntersect(lines[rhs], sweepx);
}

pair<bool, Point> intersect(Seg s1, Seg s2)
{
    // https://www.desmos.com/calculator/txz1ndtoot
    // segments have left point first
    if (s1.first > s1.second) swap(s1.first, s1.second);
    if (s2.first > s2.second) swap(s2.first, s2.second);

    // tilt vertical lines left slightly; TODO: just find the y on the other line at this x instead of modifying
    if (s1.first.first == s1.second.first) s1.second.first += 0.0000000001;
    if (s2.first.first == s2.second.first) s2.second.first += 0.0000000001;

    dl m1 = (s1.first.second - s1.second.second) / (s1.first.first - s1.second.first);
    dl m2 = (s2.first.second - s2.second.second) / (s2.first.first - s2.second.first);

    assert(abs(m2-m1) > 0.0000000001); // disallow parallel lines: slope difference > one billionth

    dl intersect_x = (s2.first.second - s1.first.second + m1 * s1.first.first + m2 * s2.first.first) / (m1 - m2);
    dl intersect_y = m1*(intersect_x - s1.first.first) + s1.first.second;

    if (s1.first.first <= intersect_x && intersect_x <= s1.second.first
     && s2.first.first <= intersect_x && intersect_x <= s2.second.first)
	return make_pair(1, make_pair(intersect_x, intersect_y));
    else // intersect out of range
	return make_pair(0, make_pair(0, 0));
}

void checkNeighboors(const set<int, function<bool(int, int)> >::iterator &it)
{
    auto intersectPrev = intersect(lines[*it], lines[*prev(it)]);
    // if (intersectPrev.first && intersectPrev.second.first > sweepx)
	// events.push(mp(mp(intersectPrev.second, 0), mp((int)*it, (int)*prev(it))));

    auto intersectNext = intersect(lines[*it], lines[*next(it)]);
    if (intersectNext.first && intersectNext.second.first > sweepx)
	events.push(pair<pair<dl, int>, pair<int, int> >(pair<dl, int>(intersectNext.second.first, 0), pair<int, int>((int)*it, (int)*next(it))));
}


int main()
{
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
	events.emplace(make_pair(x1, 1), mp(i, 0));
	events.emplace(make_pair(x2, -1), mp(i, 0));
	lines.emplace_back(Point(x1, y1), Point(x2, y2));
    }
    
    // # of events = 2*N + # of intersections
    while (!events.empty())
    {
	Event ev = events.top();
	events.pop();

	sweepx = ev.first.first;
	
	if (ev.first.second == 1)	// start of a line
	{
	    auto it = active.insert(ev.second.first).first;
	    checkNeighboors(it);
	}
	else if (ev.first.second == 0)	// intersection
	{
	    set<int, function<bool(int, int)> >::iterator left = active.find(ev.second.first);
	    set<int, function<bool(int, int)> >::iterator right = active.find(ev.second.second);
	    // manual swap
	    auto temp = left;
	    left = right;
	    right = temp;

	    checkNeighboors(left);
	    checkNeighboors(right);
	}
	else if (ev.first.second == 1) // end of line
	{
	    active.erase(ev.second.first);
	}
    }
}
