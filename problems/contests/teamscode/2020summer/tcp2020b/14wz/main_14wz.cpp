/*
 * Problem 14wz (tcp2020b/14wz)
 * Create time: Thu 23 Jul 2020 @ 15:20 (PDT)
 * Accept time: [!meta:end!]
 *  waymo's algo, basically count inversions in the removed nodes
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
const ll MX = 1e5+100;

int N, M, arr[MX], og_invs[MX];
pair<int, int> flip[MX];

int bit[MX];
void update(int x)
{
    for (; x<=MX; x+=x&-x)
        ++bit[x];
}
int query(int x)
{
    int sum=0;
    for (; x; x-=x&-x)
        sum += bit[x];
    return sum;
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; ++i)
    {
        scanf("%d", &arr[i]);
        flip[i] = {arr[i], i};
    }
    sort(arr, arr+N);

    for (int i=N-1; i>=0; --i)
    {
        og_invs[i] += query(arr[i]);
        update(arr[i]);
    }

	return 0;
}

