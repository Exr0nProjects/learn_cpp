/*
 * Problem 1 (contests/standard-xjoi/1613/1)
 * Create time: Tue 25 Aug 2020 @ 19:00 (PDT)
 * Accept time: [!meta:end!]
 *
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
const ll MX = 1e4+10;

int N, M, vec[MX], vis[MX][MX];
unordered_set<int> ddup;

void klcm(int n)
{
    for (int i=0; i<n; ++i) printf("%3d", vec[i]); printf("\n");
}

void gen(int i, int r)
{
    if (vis[i][r]) return;
    vis[i][r] = 1;
    klcm(i);
    for (int d=(i?vec[i-1]:0)+1; d<=r; ++d) {
        vec[i] = d;
        gen(i+1, r-d);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    gen(0, N);
    printf("%d\n", ddup.size());

	return 0;
}

