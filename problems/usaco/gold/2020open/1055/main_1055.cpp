/*
 * Problem 1055 (usaco/gold/2020open/1055)
 * Create time: Sat 19 Dec 2020 @ 11:37 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MX = 10;
//const ll MX = 210;

ll N, ox[MX], oy[MX], dx[MX], dy[MX];
map<ll, ll> descx[MX], descy[MX];

int main()
{
    scanf("%lld", &N);
    for (int i=1; i<=N; ++i) scanf("%lld%lld", ox+i, oy+i);
    //if (N > 20)
    if (N > 0)
    {
        unordered_set<bitset<MX> > vis;
        ll mxx=ox[1], mxy=oy[1], mnx=ox[1], mny=oy[1];
        for (int i=2; i<=N; ++i)
            mxx = max(mxx, ox[i]),
            mxy = max(mxy, oy[i]),
            mnx = min(mnx, ox[i]),
            mny = min(mny, oy[i]);

        //printf("x %d..%d, y %d..%d\n", mnx, mxx, mny, mxy);

        ll ans = 0;
        for (int x=mnx; x<=mxx; ++x)
            for (int y=mny; y<=mxy; ++y)
                for (int l=0; x+l<=mxx && y+l <= mxy; ++l)
                {
                    bitset<MX> cnt;
                    for (int i=1; i<=N; ++i)
                        if (x <= ox[i] && ox[i] <= x+l
                         && y <= oy[i] && oy[i] <= y+l)
                            cnt.set(i);
                    cerr << x << ".." << x+l << "  " << y << ".." << y+l << " got " << cnt << endl;
                    if (!vis.count(cnt)) ++ans, vis.insert(cnt);
                }
        printf("%lld\n", ans);
    }
    else
    {
        cerr << "TODO\n";
    }
}

