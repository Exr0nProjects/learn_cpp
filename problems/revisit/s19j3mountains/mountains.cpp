#include <cstdio>
#include <algorithm>

using namespace std;
#define ll long long
#define f first
#define s second
const ll MX = 100111;

//vector<pair<ll, ll> > mountains;
pair<ll, ll> mountains[MX];

ll N, merged=0, djf[MX];
void init()
{
    for (ll i=0; i<MX; ++i)
        djf[i] = i;
}
ll find(ll n)
{
    if (djf[n] != n)
        djf[n] = find(djf[n]);
    return djf[n];
}
void merge(ll a, ll b)
{
    a = find(a);
    if (a == b) return;
    ++merged;
    if (mountains[a].s < mountains[b].s) swap(a, b);
    djf[b] = a;
}

bool isOverlap(ll a, ll b)
{
    ll xdif = abs(mountains[a].f-mountains[b].f);
    ll ydif = abs(mountains[a].s-mountains[b].s);
    return xdif <= ydif;
}

int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w+", stdout);
    scanf("%lld", &N);
    for (ll i=0; i<N; ++i)
        scanf("%lld%lld", &mountains[i].f, &mountains[i].s);
    sort(mountains, mountains+N);
    init(); // FIX: INIT DJS SMAHHHH

    for (ll i=1; i<N; ++i)
    {
        if (isOverlap(i, i-1))
            merge(i-1, i);
    }

    printf("%lld\n", N - merged);
}

