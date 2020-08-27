/*
 * Problem 2 (contests/standard-xjoi/1613/2)
 * Create time: Tue 25 Aug 2020 @ 17:19 (PDT)
 * Accept time: [!meta:end!]
 * if cycles lengths have gcd = 1, this just breaks... need to rethink method
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
const ll MX = 3e5;

int N, M, a[MX<<1], djf[MX<<1];
bool self[MX<<1];
int has[MX<<1];

//int find(int n)
//{
//    while (djf[n] != n)
//        //printf("%d %d\n", djf[n], n),
//        n = djf[n];
//    return n;
//}
int find(int n)
{
    //printf("        %d\n", n);
    if (djf[n] != n) n = find(djf[n]);
    return n;
}


//void merge(int a, int b)
//{
//    //printf("merge %6d and %6d", a, b);
//    int _a = find(a);
//    b = find(b);
//    //if (!_a || !b || !(_a-MX) || !(b-MX)) { printf(" is redundant!\n", a, b, a, has[b]); return; }
//    //if (_a == b) { printf(" is redundant!\n", a, b, a, has[b]); return; }
//    if (!_a || !b || !(_a-MX) || !(b-MX) || _a == b) return;
//    //if (djs[a] < djs[b]) swap(a, b);
//    //djs[a] += djs[b];
//    djf[_a] = b;
//    //printf(" aka %6d and %6d, now merging %d* and %d*\n", _a, b, a, has[b]);
//    //if (a < MX) {
//    //    merge(a+MX, has[b]+MX);
//    //    if (b > MX) has[b] = a;
//    //    printf("      has %d = %d\n", b, a);
//    //} else
//    merge(has[_a]+MX, has[b]+MX);
//    //if (a < MX && b > MX) has[b] = a;
//}
void merge(int a, int b)
{
    //printf("WHAAAK\n");
    //printf("merge %2d%c <- %2d%c   ", a%MX, a>MX?'*':' ', b%MX, b>MX?'*':' ');
    //printf("what %d %d\n", a, b);
    a = find(a);
    b = find(b);
    //printf("aka %2d%c <- %2d%c  ", a%MX, a>MX?'*':' ', b%MX, b>MX?'*':' ');
    if (!(a%MX) || !(b%MX) || a == b) { /* printf("\n"); */return; }
    if (self[a] || self[b])
    {   // FIX: special logic to do handle self loops
        self[a] = self[b] = 1;
        merge(a%MX, a%MX + MX);
        merge(b%MX, b%MX + MX);
    }
    //printf("success\n");
    djf[b] = a;
    //printf("a %d b %d djf[b] %d\n", a, b, djf[b]);
    merge(has[a]+MX, has[b]+MX);
}

int main()
{
    //freopen("fcolor.in", "r", stdin);
    //freopen("fcolor.out", "w+", stdout);
    for (int i=1; i<MX<<1; ++i)
        //djs[i] = 1,
        djf[i] = i;
    for (int i=1; i<MX; ++i)
        has[i] = i;

    scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u == v) self[u] = self[u+MX] = 1;
        merge(u+MX, v); // merge `v` with the group that admires `u`
        if (!has[u+MX]) has[u+MX] = v;
        //printf("\n");
    }

    //for (int i=1; i<=N; ++i) printf("%3d: %3d\n%3d* %3d\n", i, find(i), i+MX, find(i+MX));

    int cnt=0;
    for (int i=1; i<=N; ++i)
    {
        if (!a[find(i)]) a[find(i)] = ++cnt;
        printf("%d\n", a[find(i)]);
    }

	return 0;
}

