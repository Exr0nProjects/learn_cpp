// 1 jul 2020
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const ll MX = 100111;
ll N, cons[MX];

int main()
{
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w+", stdout);
    scanf("%lld", &N);
    ll ans = 0;
    for (ll i=1; i<N; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        ans = max(ans, max(++cons[u], ++cons[v]));
    }
    printf("%lld\n", ans+1);
}

