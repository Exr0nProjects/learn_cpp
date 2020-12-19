/*
 * Problem 1055 (usaco/gold/2020open/1055)
 * Create time: Sat 19 Dec 2020 @ 11:37 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
//const ll MX = 10;
const ll MX = 210;

ll N, ox[MX], oy[MX], dx[MX], dy[MX], rx[MX], ry[MX];
//map<ll, ll> descx[MX], descy[MX];
map<ll, ll> descx, descy;
ll psum[MX][MX];

int main()
{
    scanf("%lld", &N);
    for (int i=1; i<=N; ++i) scanf("%lld%lld", ox+i, oy+i);
    //if (N > 20)
    ////if (N > 0)
    //{
    //    unordered_set<bitset<MX> > vis;
    //    ll mxx=ox[1], mxy=oy[1], mnx=ox[1], mny=oy[1];
    //    for (int i=2; i<=N; ++i)
    //        mxx = max(mxx, ox[i]),
    //        mxy = max(mxy, oy[i]),
    //        mnx = min(mnx, ox[i]),
    //        mny = min(mny, oy[i]);
    //
    //    //printf("x %d..%d, y %d..%d\n", mnx, mxx, mny, mxy);
    //
    //    ll ans = 0;
    //    for (int x=mnx; x<=mxx; ++x)
    //        for (int y=mny; y<=mxy; ++y)
    //            for (int l=-max(mxx-mnx, mxy-mny); x+l<=mxx || y+l <= mxy; ++l)
    //            {
    //                bitset<MX> cnt;
    //                for (int i=1; i<=N; ++i)
    //                    if (min(x, x+l) <= ox[i] && ox[i] <= max(x, x+l)
    //                     && min(y, y+l) <= oy[i] && oy[i] <= max(y, y+l))
    //                        cnt.set(i);
    //                //cerr << x << ".." << x+l << "  " << y << ".." << y+l << " got " << cnt << endl;
    //                if (!vis.count(cnt)) ++ans, vis.insert(cnt);
    //            }
    //    printf("%lld\n", ans);
    //}
    //else
    {
        ll ans = 0;
        for (int i=1; i<=N; ++i)
            descx[ox[i]] = 0,
            descy[oy[i]] = 0;
        int cnt=0; for (auto &p : descx) p.second = ++cnt, rx[cnt] = p.first;
            cnt=0; for (auto &p : descy) p.second = ++cnt, ry[cnt] = p.first;
        for (int i=1; i<=N; ++i)
            dx[i] = descx[ox[i]],
            dy[i] = descy[oy[i]],
            psum[dx[i]][dy[i]] = 1;
        for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j)
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];

        for (int bx=1; bx<1<<N; ++bx)
        {
            ll mxx=-10, mxy=-10, mnx=2e9, mny=2e9, popc=0;
            ll omxx=-10, omxy=-10, omnx=2e9, omny=2e9;
            for (int i=1; i<=N; ++i) if (bx>>(i-1)&1)
                db("%3d", i),
                ++popc,
                mxx = max(mxx, dx[i]),
                mxy = max(mxy, dy[i]),
                mnx = min(mnx, dx[i]),
                mny = min(mny, dy[i]),
                omxx = max(omxx, ox[i]),
                omxy = max(omxy, oy[i]),
                omnx = min(omnx, ox[i]),
                omny = min(omny, oy[i]);
                else db("   ");
            db("   :    %d..%d   %d..%d\n", mnx, mxx, mny, mxy);
            if (popc == 1) { ++ans; continue; }
            printf("psum = %d\n", psum[mxx  ][mxy  ] + psum[mnx-1][mny-1] -psum[mxx  ][mny-1] - psum[mnx-1][mxy  ]);
            if (psum[mxx  ][mxy  ] + psum[mnx-1][mny-1]
               -psum[mxx  ][mny-1] - psum[mnx-1][mxy  ] > popc) continue;
            if (omxx-omnx > omxy-omny) // slide on y
            {
                auto lo = descy.lower_bound(omny);
                auto hi = descy.lower_bound(omxy);
                //db("slide on y    %d >= %d\n", next(hi)->first - prev(lo)->first, omxx-omnx);
                if (next(hi) != descy.end() && lo != descy.begin() &&
                    next(hi)->first - prev(lo)->first < omxx-omnx) continue;
                db("worked\n");
                ++ans;
            }
            else
            {
                auto lo = descx.lower_bound(omnx);
                auto hi = descx.lower_bound(omxx);
                //db("slide on x  (%d-%d  %d) >= %d\n", next(hi)->first, prev(lo)->second, next(hi)->first - prev(lo)->first, omxx-omnx);
                if (next(hi) != descx.end() && lo != descx.begin() &&
                    next(hi)->first - prev(lo)->first < omxy-omny) continue;
                db("worked!\n");
                ++ans;
            }
        }
        printf("%lld\n", ans);
        //for (int i=1; i<=N; ++i) db("%d %d\n", dx[i], dy[i]);
    }
}

