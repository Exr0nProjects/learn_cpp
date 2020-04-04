#include <utility>
#include <vector>
#include <deque>
#include <cassert>
#include <cmath>

using namespace std;
const int MX = 1000111;

int N;
typedef pair<int, int> Point;
vector<Point> cloud;

bool is_left(Point a, Point b, Point c)
{
    assert(a.first <= b.first); // a is before b
    assert(b.first <= c.first); // b is before c
    double slope_ab = (double)(b.second - a.second) / (b.first - a.first);
    double slope_ac = (double)(c.second - a.second) / (c.first - a.first);
    return slope_ab < slope_ac;
}

void build_hull(const vector<Point> &cloud, deque<int> &hull)
{ // ! Need to sort `cloud` before calling
    hull.clear();
    hull.push_back(0);
    hull.push_back(1);
    for (int i=2; i<N; ++i)
    {
        if (is_left(cloud[hull[hull.size()-2]], cloud[hull[hull.size()-1]], cloud[i]))
        { // need to turn back
            // binary search
            int l=0, r=hull.size(); // inc l, exc r; remove `r` and onwards--l stays in the hull
            for (int d=0; d<(int)log2(hull.size()) +1; ++d)
            {
                int m = l/2 + r/2 + (l%2&r%2);
                if (m == 0) break; // have to remove all the way up to the first one
                if (is_left(cloud[hull[m-1]], cloud[hull[m]], cloud[i]))
                    r = m;
                else
                    l = m;
            }
            // update hull
            hull.erase(hull.begin()+r, hull.end());
        }
        hull.push_back(i);
    }
}

int main()
{
    // init
    scanf("%d", &N);
    cloud.reserve(MX);
    // input
    for (int i=0; i<N; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        cloud.emplace_back(x, y);
    }
    // algo
    // top half
    sort(cloud.begin(), cloud.end());
    deque<int> hull_top;
    build_hull(cloud, hull_top);

    printf("Top half:\n");
    for (auto i : hull_top)
        printf("Point %d (%d %d)\n", i, cloud[i].first, cloud[i].second);

    // bot half
   // sort(cloud.begin(), cloud.end(), greater<Point>{});
    for (auto &p : cloud) // reflect across x axis; FIX: take `p` as a reference
	p.second *= -1;

    deque<int> hull_bot;
    build_hull(cloud, hull_bot);

    printf("Bot half:\n");
    for (auto it=hull_bot.rbegin(); it!=hull_bot.rend(); ++it)
        printf("Point %d (%d %d)\n", *it, cloud[*it].first, cloud[*it].second);
}

/*
8
0 0
0 2
1 1
2 3
3 1
3 2
4 0
2 -1
*/
