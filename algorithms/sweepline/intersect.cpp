#include <utility>
#include <deque>
#include <queue>
#include <cmath>
#include <set>

#define dl double

using namespace std;

const int MX = 1000111;
typedef pair<dl, dl> Point; // <x, y>
typedef pair<Point, Point> Seg; // <p1, p2>; assert(p1 <= p2)
int N;

typedef pair<pair<int, int>, int> Event // <<pos x, type {1 = start line, 0 = intersect/swap, -1 = end line}>, line_id>

deque<Line> lines;
priority_queue<Event, deque<Event>, greater<Event> > events;
dl sweepx;

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
	return make_pair(1, make_pair(intersect_x, intersect_y);
    else // intersect out of range
	return make_pair(0, make_pair(0, 0));
}

int main()
{
    printf("Please, no parallel or concurrent lines!\n");
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", x1, y1, x2, y2);
	events.emplace_back(make_pair(x1, 1), i);
	events.emplace_back(make_pair(x2, -1), i);
	lines.emplace_back(Point(x1, y1), Point(x2, y2));
    }
    
    // # of events = 2*N + # of intersections
    while (!events.empty())
    {
	Event ev = events.top();
	events.pop();

	sweepx = ev.first.first;
	auto l = active.begin(), r = active.end();
	for (int d=0; d<(int)log2(active.size()) +1; ++d)
	{
	    auto mid = (l+r)/2;
	    if (intersect(*mid, // TODO: what here?
	}
	
	if (ev.first.second == 1)
	{ /* TODO */ }
    }
}
