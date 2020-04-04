#include <utility>
#include <vector>
#include <multiset>

#define dl double

using namespace std;

const int MX = 1000111;
typedef pair<dl, dl> Point; // <x, y>
typedef pair<Point, Point> Seg; // <p1, p2>; assert(p1 <= p2)

pair<bool, Point> intersect(Seg s1, Seg s2)
{
    // segments have left point first
    if (s1.first > s1.second) swap(s1.first, s1.second);
    if (s2.first > s2.second) swap(s2.first, s2.second);

    // tilt vertical lines left slightly
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
