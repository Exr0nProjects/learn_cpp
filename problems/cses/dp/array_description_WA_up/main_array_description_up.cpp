/*
 * Problem array_description_up (cses/dp/array_description_up)
 * Create time: Sat 29 Aug 2020 @ 18:46 (PDT)
 * Accept time: [!meta:end!]
 *  TODO: Oh, there can be multiple zeros in a row.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <set>
#include <string>
#include <list>
#include <array>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <chrono>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+11;
const int MOD = 1e9+7;

int N, M, arr[MX], dp=1;

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; ++i)
        scanf("%d", arr+i);

    for (int i=2; i<N; ++i)
        if (!arr[i])
        {
            dp = dp*max(3-abs(arr[i-1]-arr[i+1]), 0) % MOD;
            if (arr[i-1] == M && arr[i+1] == M)
                dp = dp / 3 * 2;
        }
    if (!arr[1]) dp = 3*dp % MOD;
    if (!arr[N]) dp = 3*dp % MOD;
    printf("%d\n", dp);

	return 0;
}

