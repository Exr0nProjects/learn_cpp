/*
ID: spoytie2
TASK: revegetate
LANG: C++14
*/

/*
 * Problem revegetate ([!meta:srcpath!])
 * Create time: Thu 20 Feb 2020 @ 08:42 (PST)
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

void setIO(const std::string &name = "revegetate");

using namespace std;
const int MX = 100010;
int N, M;

int djs_f[MX];
int djs_s[MX];
int find(cn n)
{
    if (djs_f[n] != n)
    {
        djs_f[n] = find(djs_f[n]);
    }
    return djs_f[n];
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a < b) swap(a, b);
    djs_s[a] += djs_s[b];
    djs_f[b] = a;
}

bool color[MX]; // FIX: also need to check if it is even colorable
bool seen[MX]; // have we seen this field before?

int main()
{
    setIO();
    scanf("%d%d", &N, &M);
    // init djs
    iota(djs_f, djs_f+N, 0);
    FOR(i, N) djs_s[i] = 1;
    // build djs
    FOR(i, M)
    {
        char c;
        int a, b;
        scanf("\n%c%d%d", &c, &a, &b);
        merge(a, b);
        // TODO: this logic to check if there is a type conflict overreacts
        //if (seen[a] && seen[b])
        //{
            //if (color[a] == color[b] && c == 'D') // conflict
            //{
                //printf("0\n");
                //return 0;
            //}
        //}
        //else if (seen[a] && !seen[b]) color[b] = (color[a] + (c == 'D'))%2;
        //else if (seen[b] && !seen[a]) color[a] = (color[b] + (c == 'D'))%2;
        //else
        //{
            //color[a] = 0;
            //color[b] = (c == 'D');
        //}
        seen[a] = seen[b] = true;
    }

    set<int> components;
    FOR(i, N)
    {
        components.insert(find(i));
    }

    printf("1");
    FOR(i, components.size()) printf("0"); // string bitshifting
    printf("\n");

    return 0;
}

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
