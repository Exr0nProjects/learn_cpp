#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

#define mp make_pair
#define dl double

using namespace std;
const dl TOLERANCE = 0.0000000001;
int N;
typedef pair<dl, dl> Point;
typedef pair<Point, Point> Seg;
vector<Seg> segs;

pair<bool, Point> verticalIntersect(Seg s, dl x, dl bot=pow(-2, 99), dl top=pow(2, 99))
{
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
pair<bool, Point> intersect(Seg s1, Seg s2)
{
    // https://www.desmos.com/calculator/8lfyuyytll

    // segments have left point first
    if (s1.first > s1.second) swap(s1.first, s1.second);
    if (s2.first > s2.second) swap(s2.first, s2.second);

    if (s1.first.first == s1.second.first) 		// first line vertical
        return verticalIntersect(s2, s1.first.first, s1.first.second, s1.second.second);
    else if (s2.first.first == s2.second.first)		// second line vertical
        return verticalIntersect(s1, s2.first.first, s2.first.second, s2.second.second);

    dl m1 = (s1.first.second - s1.second.second) / (s1.first.first - s1.second.first);
    dl m2 = (s2.first.second - s2.second.second) / (s2.first.first - s2.second.first);

    //assert(abs(m1-m2) > TOLERANCE); // disallow parallel lines: slope difference > one billionth
    if (abs(m1-m2) < TOLERANCE) return make_pair(0, make_pair(0, 0));

    dl intersect_x = (s2.first.second - s1.first.second + m1 * s1.first.first - m2 * s2.first.first) / (m1 - m2);
    dl intersect_y = m1*(intersect_x - s1.first.first) + s1.first.second;

    if (s1.first.first <= intersect_x && intersect_x <= s1.second.first
            && s2.first.first <= intersect_x && intersect_x <= s2.second.first)
        return mp(1, mp(intersect_x, intersect_y));
    else // intersect out of range
        return mp(0, mp(intersect_x, intersect_y));
}

int main()
{
    scanf("%d", &N);
    segs.reserve(N);
    for (int i=0; i<N; ++i)
    {
        float a, b, c, d;
        scanf("%f%f%f%f", &a, &b, &c, &d);
        segs.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
    }

    for (int i=0; i<N; ++i)
        for (int j=i+1; j<N; ++j)
        {
            auto inter = intersect(segs[i], segs[j]);
            if (inter.first)
                printf("%lf %lf\n", inter.second.first, inter.second.second);
        }
}
