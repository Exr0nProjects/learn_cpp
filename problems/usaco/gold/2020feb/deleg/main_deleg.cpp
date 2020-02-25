/*
ID: spoytie2
TASK: deleg
LANG: C++14
*/

/*
 * Problem deleg ([!meta:srcpath!])
 * Create time: Mon 24 Feb 2020 @ 16:30 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <list>
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
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

#define FOR_(i, b, e) for (int i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (int i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define SORT(a, n) std::sort((a), (a) + (n))
#define TRAV(a, x) for (auto &a : x)
#define TRAVE(e, s) for (int e = head[s]; e; e = edges[e].n)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name = "deleg");

using namespace std;
const int MX = 100010;
int N;
list<int> head[MX];

bool dont_try[MX], impossible=0;

int dfs(int curr, int len, int prev=0, int layer=0)
{
    FOR(i, layer) printf("|   "); printf("%d -> %d\n", prev, curr);
    int shift=0, badcount=0;
    TRAV(next, head[curr])
    {
        if (next == prev) continue;
        int from = dfs(next, len, curr, layer+1);
        if (from) ++ badcount;
        shift = (shift + from) % len;
        if (shift == 0) badcount=0; // two subtrees canceled out

        FOR(i, layer) printf("|   "); printf("shift= %d\n", shift);

        if (badcount >= 2)
        //if (shift-from && from) // two children need to pass by this and can't complete eachother
        {
            FOR(i, layer) printf("|   "); printf("Impossible! (badcount %d)\n", badcount);
            impossible = 1;
        }



        if (impossible) return 0;
    }
    FOR(i, layer) printf("|   "); printf("=> %d\n", shift+1);
    return (shift+1) % len;
}

int main()
{
    setIO();
    scanf("%d", &N);
    int leaf;
    FOR(i, N-1)
    {
    //printf("inpud i=%d\n", i);
        int a, b;
        scanf("%d%d", &a, &b);
        head[a].push_back(b);
        head[b].push_back(a);
    }

    // find a leaf node
    FOR_(i, 0, N) if (head[i].size() == 1) { leaf=i; break; }

    printf("1"); // one always works
    FOR_(i, 2, N)
    {
        if (dont_try[i] || (N-1) %i)
        {
            printf("0");
            continue;
        }
        impossible = 0;
        printf("\n=====================\nchecking %d\n", i);
        if (dfs(leaf, i) == 1 && !impossible) printf("1");
        else
        {
            printf("0");
            for (int j=i; j<N; j+=i)
                dont_try[j] = 1; // don't try multiples of something that doesn't work
        }
    }
    printf("\n");

    return 0;
}

/*
3
1 2
2 3
=> 11

4
1 2
2 3
3 4
=> 101

5
1 2
2 3
2 4
4 5
=> 1100

// binary tree
15
1 2
2 4
4 8
4 9
2 5
5 10
5 11
1 3
3 6
6 12
6 13
3 7
7 14
7 15
=> 11000000000000

9
1 2
2 3
3 4
4 5
2 6
6 7
7 8
8 9
=> 11010000

31
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
=> 1110110001000010000000000000001
*/

void setIO(const string &name)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); // fast cin/cout
    if (fopen((name + ".in").c_str(), "r") != nullptr)
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w+", stdout);
    }
}
