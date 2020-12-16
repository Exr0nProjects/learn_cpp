/*
 * Problem ezdijkst_1 (spoj/ezdijkst_1)
 * Create time: Wed 16 Dec 2020 @ 13:32 (PST)
 * Accept time: Wed 16 Dec 2020 @ 13:47 (PST)
 *
 */
#include <queue>
#include <cstring>
#include <cstdio>
#include <utility>
#include <tuple>
#define ll long long
#define mp make_pair
using namespace std;
const ll MX = 1e4+10;

ll T, N, M, A, B, dist[MX];
typedef pair<ll, ll> St;
struct Edge { ll t, w, n; } eg[MX<<2]; ll hd[MX], ecnt=2;
void addEdge()
{
    ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
    eg[ecnt] = { v, w, hd[u] };
    hd[u] = ecnt++;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(dist, 0x3f, sizeof dist);
        memset(eg, 0, sizeof eg);
        memset(hd, 0, sizeof hd);

        scanf("%lld%lld", &N, &M);  // FIX: clang scanf lls with %lld not %d
        for (int i=1; i<=M; ++i) addEdge();
        scanf("%lld%lld", &A, &B);
        //printf("%d -> %d\n", A, B);

        priority_queue<St, deque<St>, greater<St> > pq;
        pq.push(mp(0, A));
        while (pq.size())
        {
            ll d, c; tie(d, c) = pq.top(); pq.pop();
            //printf("at %d after %d\n", c, d);
            if (dist[c] <= d) continue;
            dist[c] = d;
            //printf("continuing %d vs %lld %lld\n", c, B, c == B);

            if (c == B) { B = -1, A = d; break; }   // FIX: typo--c == B not d == B
            for (int e=hd[c]; e; e=eg[e].n)
                pq.push(mp(eg[e].w + d, eg[e].t));
        }
        if (~B) printf("NO\n");
        else printf("%d\n", A);
    }
}

