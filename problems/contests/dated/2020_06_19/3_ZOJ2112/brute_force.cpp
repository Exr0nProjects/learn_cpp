#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const ll MX = 50111;
ll N, M, arr[MX], srt[MX];

int main()
{
    ll kase; scanf("%lld", &kase);
    while (kase--)
    {
        scanf("%lld%lld", &N, &M);
        memset(arr, 0, sizeof arr);
        for (ll i=1; i<=N; ++i)
            scanf("%lld", &arr[i]);
        for (ll i=0; i<M; ++i)
        {
            char c=0; while (c !='Q' && c!='C') scanf("%c", &c);
            ll l, r; scanf("%lld%lld", &l, &r);
            if (c == 'Q')
            {
                ll k; scanf("%lld", &k);
                memcpy(srt, arr+l, (r-l+1)*sizeof(ll));
                sort(srt, srt+r-l+1);
                printf("%lld\n", srt[k-1]);
            }
            else arr[l] = r;
        }
    }
}

