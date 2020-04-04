#include <set>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

const int MX = 100111;
int N;
typedef pair<pair<int, int>, pair<int, int> > Event; // < <sort x, operation type (1 = add, 0 = count, -1 = remove)>, <low, high>(x for op type -1, 1; y for op type 0) >
vector<Event> events;
multiset<int> active_y;

int main()
{
    events.reserve(MX);
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) // vertical
        {
            if (y1 > y2) swap(y1, y2);
            events.emplace_back(make_pair(x1, 0), make_pair(y1, y2));
        }
        else if (y1 == y2) // horizontal
        {
            if (x1 > x2) swap(x1, x2);
            events.emplace_back(make_pair(x1,  1), make_pair(y1, 0)); // second.second not used
            events.emplace_back(make_pair(x2, -1), make_pair(y1, 0));
        }
        else
        {
            return -1; // illegal line!
        }
    }
    sort(events.begin(), events.end());
    int ret=0;
    for (auto ev : events)
    {
        if (ev.first.second == 1)
        {
            active_y.insert(ev.second.first);
        }
        else if (ev.first.second == 0)
        {
            auto lo = active_y.lower_bound(ev.second.first);
            auto hi = active_y.upper_bound(ev.second.second);
            ret += distance(lo, hi);
        }
        else if (ev.first.second == -1)
        {
            // erase through iterator to remove just one element -- TODO: prone to error, if ev.second.first doesn't exist in active_y
            active_y.erase(active_y.find(ev.second.first));
        }
    }
    printf("%d\n", ret);
}
