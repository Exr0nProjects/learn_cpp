// TODO: doesn't deal with intersections between horzhorz or vertvert
#include <cstdio>
#include <queue>
#define mp make_pair
#define f first
#define s second

using namespace std;
const int MX = 1e6;
const int MXS = 1e6;    // max coordinate

int N, top[MX], bot[MX], bit[MX]; // for vertical lines

void bu(int x, int v)
{
    for (; x<=MXS; x+=x&-x) bit[x] += v;
}
int bq(int x)
{
    int ans=0;
    for (; x; x-=x&-x) ans += bit[x];
    return ans;
}

// 0, 0, 0, 0, 0, 0

int main()
{
    scanf("%d", &N);
    int vcnt=0;
    typedef pair<int, pair<int, int> > Event; // <x, <0=vertical, -1=begin, 1=end; y/id>
    // states are that because for each x, we want to process all begin, then count intersections, then process end
    priority_queue<Event, deque<Event>, greater<Event> > pq;
    for (int i=1; i<=N; ++i)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        ++x1, ++y1, ++x2, ++y2; // FIX: zero ruins BIT
        if (x1 == x2)   // vertical
            top[vcnt] = max(y1, y2), bot[vcnt] = min(y1, y2), pq.push(mp(x1, mp(0, vcnt))), ++vcnt;
        else            // horizontal
            pq.push(mp(x1, mp(-1, y1))), pq.push(mp(x2, mp(1, y2)));
    }
    int ans=0;
    while (!pq.empty())
    {
        Event cur = pq.top(); pq.pop();
        //printf("cur = %d < %d %d >\n", cur.f, cur.s.f, cur.s.s);
        if (!cur.s.f) ans += bq(top[cur.s.s]) - bq(bot[cur.s.s]-1); // vertical
        else bu(cur.s.s, -cur.s.f);   // horizontal
    }
    printf("%d\n", ans);
}

