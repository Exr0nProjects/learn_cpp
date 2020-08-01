/*
 * Problem 2_convert-tree-to-binary (contests/standard-xjoi/1543/2_convert-tree-to-binary)
 * Create time: Sat 01 Aug 2020 @ 15:22 (PDT)
 * Accept time: Sat 01 Aug 2020 @ 15:28 (PDT)
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 111;
int N, lc[MX], rc[MX], par[MX];

int main()
{
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
    {
        int d; scanf("%d", &d);
        int pre = i;
        for (int j=0; j<d; ++j)
        {
            int v; scanf("%d", &v);
            if (!j) lc[i] = v;
            else rc[pre] = v;
            pre = v;
        }
    }

    //for (int i=1; i<=N; ++i)
    //    if (lc[par[i]]) rc[par[i]] = i;
    //    else lc[par[i]] = i;

    printf("%d\n", N);
    for (int i=1; i<=N; ++i) printf("%d %d\n", lc[i], rc[i]);

	return 0;
}

