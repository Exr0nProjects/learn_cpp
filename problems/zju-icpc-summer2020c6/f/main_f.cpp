/*
 * Problem f (zju-icpc-summer2020c6/f)
 * Create time: Mon 20 Jul 2020 @ 19:33 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MX = 1e4+100;
const int MXK = 20;

int N, K, gift[MX], fav[MX], val[MXK], dps[MXK][MX];
set<int> favs;
multiset<int> at;

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
        at.clear();
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
            auto it = at.find(rem);
            if (it == at.end()) continue;
            at.erase(it);
            at.insert(rem+1);
            dps[i][j] += delta;
            //printf("=> %+3d:  {", delta); for (auto pos : at) printf("%3d", pos); printf(" }\n\n");
        }
    }

    // don't have to give something to everyone
    for (int j=1; j<=maxfav; ++j)
        for (int i=1; i<=N*K; ++i)
            dps[i][j] = max(dps[i][j], dps[i][j-1]);

    int sum=0;
    //for (auto f : favs)
    for (multiset<int>::iterator f=favs.begin(); f!=favs.end(); ++f)
    {
        //printf("fav %d: %d, %d => %d\n", f, gift[f], fav[f], dps[gift[f]][fav[f]]);
        sum += dps[gift[*f]][fav[*f]];
    }
    printf("%d\n", sum);

	return 0;
}



