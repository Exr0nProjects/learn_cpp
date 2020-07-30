/*
 * Problem F-charmander-and-his-best-friends (contests/zju-icpc/2020summer3/F-charmander-and-his-best-friends)
 * Create time: Wed 29 Jul 2020 @ 16:37 (PDT)
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
const ll MX = 50111;
//int N, arr[MX], aux[MX];
int N;

// do weird dnq where you skip progressive powers of two, taking every other and compressing into the first half
void swippity_swaap(vector<int> v)
{
    //for (int i=0; i<v.size(); ++i) printf("%3d", v[i]); printf("\n");
    if (v.size() <= 1)
    {
        printf("%d ", v[0]);
        return;
    }
    vector<int> even, odd;
    for (int i=0; i<v.size(); ++i)
        if (i % 2) odd.pb(v[i]);
        else even.pb(v[i]);
    swippity_swaap(odd);
    swippity_swaap(even);
}

int main()
{
    scanf("%d", &N);
    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);
    swippity_swaap(arr);
    //for (int i=1; i<=N; ++i) printf("%d ", arr[i]);
    printf("\n");

	return 0;
}

