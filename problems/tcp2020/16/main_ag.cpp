#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, bit[50000];
pair <ll, ll> discre[50000];
map <ll, ll> m;
ll a[50000];
ll ans[50000];
ll lowbit(ll x) {
    return x & (-x);
}
ll query(ll k) {
    ll ret = 0;
    while (k > 0) {
        ret += bit[k];
        k -= lowbit(k);
    }
    return ret;
}
void update(ll k, ll v) {
    while (k <= n) {
        bit[k] += v;
        k += lowbit(k);
    }
}
int main() {
    scanf("%lld", &n);
    ll y;
    for (ll i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i], &y);
        discre[i] = make_pair(a[i], i);
        m[a[i]] = 0;
    }
    sort(discre, discre+n+1);
    for (ll i = 1; i <= n; i++) {
        if (m[discre[i].first] != 0) continue;
        m[discre[i].first] = i;
    }
    for (ll i = 1; i <= n; i++) {
        ans[query(m[a[i]])]++;
        update(m[a[i]], 1);
    }
    for (ll i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }
}

