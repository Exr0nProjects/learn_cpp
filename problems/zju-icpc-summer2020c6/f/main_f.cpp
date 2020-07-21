/*
 * Problem f (zju-icpc-summer2020c6/f)
 * Create time: Mon 20 Jul 2020 @ 19:33 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <iterator>
#include <exception>
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const int MX = 1e5+100;
const int MXK = 20;

int N, K, gift[MX], fav[MX], val[MXK], dps[MXK][MX];
set<int> favs;

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=0; i<N*K; ++i)
    {
        int d; scanf("%d", &d);
        ++gift[d];
    }
    int maxfav = 0;
    for (int i=0; i<N; ++i)
    {
        int d; scanf("%d", &d);
        ++fav[d];
        favs.insert(d);
        maxfav = max(maxfav, fav[d]);
    }
    for (int i=0; i<K; ++i)
        scanf("%d", &val[i]);

    for (int j=1; j<=maxfav; ++j)
    {
        multiset<int> at;
        for (int i=0; i<j; ++i) at.insert(0);
        dps[j][j] = val[0]*j;
        for (int i=j+1; i<=N*K; ++i)
        {
            //printf("i %d j %d: {", i, j); for (auto pos : at) printf("%3d", pos); printf(" }\n");
            dps[i][j] = dps[i-1][j];
            int delta = 0, rem=-1;
            for (auto pos : at)
                if (pos+1 < K && val[pos+1]-val[pos] > delta)
                {
                    delta = val[pos+1]-val[pos];
                    rem = pos;
                }
            if (i > at.size() && j > at.size() && val[0] > delta)
            {   // start giving to a new npc
                at.insert(0);
                dps[i][j] += val[0];
            }
            else
            {   // give another to the most effective
                auto it = at.find(rem);
                if (it == at.end()) continue;
                at.erase(it);
                at.insert(rem+1);
                dps[i][j] += delta;
            }
            //printf("=> %+3d:  {", delta); for (auto pos : at) printf("%3d", pos); printf(" }\n\n");
        }
    }

    // don't have to give something to everyone
    for (int j=1; j<=maxfav; ++j)
        for (int i=1; i<=N*K; ++i)
            dps[i][j] = max(dps[i][j], dps[i][j-1]);

    int sum=0;
    for (auto f : favs)
    {
        //printf("fav %d: %d, %d => %d\n", f, gift[f], fav[f], dps[gift[f]][fav[f]]);
        sum += dps[gift[f]][fav[f]];
    }
    printf("%d\n", sum);

    //for (int i=0; i<20; ++i)
    //{
    //    for (int j=0; j<4; ++j)
    //        printf("%3d", dps[i][j]);
    //    printf("\n");
    //}

	return 0;
}

