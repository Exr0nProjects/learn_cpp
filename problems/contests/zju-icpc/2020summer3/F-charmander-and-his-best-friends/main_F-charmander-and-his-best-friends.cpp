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
int N, arr[MX], aux[MX];

// do weird dnq where you skip progressive powers of two, taking every other and compressing into the first half
void swippity_swaap(int k=1)
{
    //printf("k = %d:    ", k); for (int i=1; i<=N; ++i) printf("%3d", arr[i]); printf("\n");
    if (1<<k > N) return;
    for (int s=0; s<1<<k-1; ++s)
    {
        int cnt = s+1;
        for (int i=1; i+s<=N; i+=1<<k)
        {
            //printf("%3d <- %-2d", cnt, i+s);
            aux[cnt] = arr[i+s];
            cnt += 1<<(k-1);
        }
        //printf("  |  ");
        //printf("start at %d  ", 1<<(k-1));
        for (int i=1+(1<<k-1); i+s<=N; i+=1<<k)
        {
            //printf("%3d <- %-2d", cnt, i+s);
            aux[cnt] = arr[i+s];
            cnt += 1<<k-1;
        }
        //printf("\n");
    }
    swap(arr, aux);
    swippity_swaap(k+1);
}

int main()
{
    scanf("%d", &N);
    iota(arr, arr+N+1, 0);
    swippity_swaap();
    for (int i=1; i<=N; ++i) printf("%d ", arr[i]);
    printf("\n");

	return 0;
}

