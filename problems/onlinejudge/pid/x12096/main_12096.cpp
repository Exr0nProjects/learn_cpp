/*
ID: spoytie2
TASK: 12096
LANG: C++14
*/

/*
 * Problem 12096 ([!meta:srcpath!])
 * Create time: Mon 17 Feb 2020 @ 10:02 (PST)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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

void setIO(const std::string &name = "12096");

using namespace std;
const int MX = -1;
int K, N;

typedef int id;
typedef set<id> Set;
vector<Set> db;
map<Set, id> set_id;

int encode(Set s)
{
    if (!set_id.count(s))
    {
        set_id[s] = db.size();
        db.push_back(s);
    }
    return set_id[s];
}

// yoinked from answer
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x,x.end())

int main()
{
    setIO();
    scanf("%d", &K);
    FOR(kase, K)
    {
        stack<int> comp;
        scanf("%d", &N);
        FOR(i, N)
        {
            char cmd;
            scanf("\n%c%*s", &cmd);
            if (cmd == 'P') comp.push(encode(Set{}));
            else if (cmd == 'D') comp.push(comp.top()); // FIX: needs to be else if to propogate the else statement functionality so it doesn't double pop on cmd='P'. found after spending 47 mins debugging vim clipboard integration and 3 minutes in xcode rip
            else
            {
                Set s1 = db[comp.top()];
                comp.pop();
                Set s2 = db[comp.top()];
                comp.pop();
                Set res;
                if (cmd == 'U') set_union(ALL(s1), ALL(s2), INS(res)); // apparently inserter creates an output_iterator
                if (cmd == 'I') set_intersection(ALL(s1), ALL(s2), INS(res));
                if (cmd == 'A') { res = s2; res.insert(encode(s1)); }
                comp.push(encode(res));
            }
            printf("%d\n", db[comp.top()].size());
        }

        printf("***\n");
    }

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
