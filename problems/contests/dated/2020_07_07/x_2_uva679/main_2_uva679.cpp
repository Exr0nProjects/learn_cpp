/*
 * Problem 2_uva679 (contests/dated/2020_07_07/2_uva679)
 * Create time: Tue 07 Jul 2020 @ 15:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
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
const ll MX = -1;

int main()
{
    int kase; scanf("%d", &kase);
    for (int cs=0; cs<kase; ++cs)
    {
        int n, d, k, ret=0;
        scanf("%d%d", &d, &k);
        --k, --d;
        n = 1<<d;
        for (int i=0; i<d; ++i)
        {
            n>>=1;
            if (k&(1<<i))
                ret += n;
            //printf("i %d n %d ret %d\n", i, n, ret);
        }
        printf("%d\n", (1<<d)+ret);
    }

	return 0;
}

