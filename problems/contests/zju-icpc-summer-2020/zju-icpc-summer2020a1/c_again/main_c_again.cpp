/*
 * Problem c_again (zju-icpc-summer2020a1/c_again)
 * Create time: Sun 12 Jul 2020 @ 20:36 (PDT)
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
const ll MX = 10e5+100;
int N, M;
set<int> head[MX];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int op, u, v; scanf("%d%d%d", &op, &u, &v);
        if (op == 1)
        {
            head[u].insert(v);
            head[v].insert(u);
        }
        else
        {
            bool legit = false;
            for (int j : head[u])
                if (

	return 0;
}

