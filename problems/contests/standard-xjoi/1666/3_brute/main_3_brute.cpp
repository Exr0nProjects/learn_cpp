/*
 * Problem 3_brute (contests/standard-xjoi/1666/3_brute)
 * Create time: Wed 09 Dec 2020 @ 18:31 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>

const int MX = 1e5+11;

#define F(i, n) for (int i=1; i<=n; ++i)
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int L, N, M, arr[MX], tarr[MX];
vector<pair<int, int> > vec;

int main()
{
    scanf("%d%d", &L, &N);
    if (L > 50)
    {
        F(i, N) { int x; scanf("%d", &x); arr[x] = 1; }
        F(i, N) arr[i] += arr[i-1];
        scanf("%d", &M);
        F(i, M)
        {
            int l, r; scanf("%d%d", &l, &r);
            if (arr[r] - arr[l-1] == r-l+1) printf("Yes\n");
            else printf("No\n");
        }
        return 0;
    }
    vec.reserve(N);
    F(i, N)
    {
        int a, b; scanf("%d%d", &a, &b);
        vec.pb(mp(min(a, b), max(a, b)));
        ++arr[a], ++arr[b];
    }
    sort(vec.begin(), vec.end());
    for (auto p : vec) printf("%d %d\n", p.f, p.s);
    scanf("%d", &M); F(i, M)
    {
        int l, r; scanf("%d%d", &l, &r);
        bool bad = 0;
        memcpy(tarr, arr, sizeof arr);
        for (int m=l; m<=r; ++m)
        {
            auto left = vec.upper_bound(mp(l, 0));
            auto right = vec.lower_bound(mp(r, MX));
            if (left->f != m && right->f != m) // none have lower = m
                if (!tarr[m]) { bad = 1; break; } else --tarr[m];
            else if (left->s >= l && right->s <= r) // no non-overlapping ones
        }
    }
}

