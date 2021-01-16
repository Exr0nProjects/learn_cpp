#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX = 2e5+10;
ll N, M, arr[MX];
ll bit[MX];
map<ll, ll> desc;
ll bq(ll x)
{
    ll ans = 0;
    for (; x; x-=x&-x) ans += bit[x];
    return ans;
}
void bu(ll x, ll v)
{
    for (; x<=N; x+=x&-x) bit[x] += v;
}
int main()
{
    scanf("%lld%lld", &N, &M);
    for (int i=1; i<=N; ++i) scanf("%lld", &arr[i]);
    for (int i=1; i<=N; ++i) desc[arr[i]] = 0;
    int cnt=0; for (auto &p : desc) p.second = ++cnt;
    for (int i=1; i<=N; ++i) arr[i] = desc[arr[i]];
    printf("descretized: "); for (int i=1; i<=N; ++i) printf("%3lld", arr[i]); printf("\n");
    for (int i=1; i<=M; ++i)
    {
        memset(bit, 0, sizeof bit);
        ll a, b; scanf("%lld%lld", &a, &b);
        swap(arr[a], arr[b]);
        // for (int i=1; i<=N; ++i) printf("%3d", arr[i]); printf("\n");
//eeee
	ll invs = 0;
	for (int k=N; k; --k) {
		invs += bq(arr[k]-1);
		bu(arr[k], 1);
	}
        swap(arr[a], arr[b]);
        printf("%lld\n", invs);
    }
}
