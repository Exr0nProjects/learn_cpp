/*
TASK: 1630down
LANG: C++14
*/

/*
 * Problem 1630down (oj/pid/1630down)
 * Create time: Tue 17 Mar 2020 @ 13:45 (PDT)
 * Accept time: Tue 17 Mar 2020 @ 14:25 (PDT)
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
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

void setIO(const std::string &name = "1630down");

using namespace std;
const int MX = 111;
string s;
map<string, string> mem;

list<int> factors[MX];
void populateFactors()
{
    FOR_(i, 1, MX)
    {
        for (int j=2*i; j<MX; j += i)
        {
            factors[j].push_back(i);
        }
    }

    // FOR(i, MX)
    // {
    //     printf("%d:", i);
    //     TRAV(f, factors[i]) printf(" %d", f);
    //     printf("\n");
    // }
}

string dp(const string &s, int layer = 0)
{
    // FOR(i, layer) printf("|   "); printf("dp(%s)\n", s.c_str());
    if (mem.count(s)) return mem[s];
    string &ret = mem[s];
    if (s.length() <= 4)
    {
        ret = s;
        return ret;
    }
    // FOR(i, layer) printf("|   ");printf("start checking for reps\n");
    TRAV(f, factors[s.length()])
    {
        // FOR(i, layer) printf("|   "); printf("len: %d fac: %d\n", s.length(), f);
        bool legit = 1;
        FOR_(i, f, s.length())
            if (s[i] != s[i%f])
                legit = 0;
        if (legit)
        {
            // int og_len = s.length();
            ret = to_string(s.length()/f) + "(" + dp(s.substr(0, f), layer+1) + ")";
    // FOR(i, layer) printf("|   "); printf("=> %s\n", ret.c_str());
            return ret;
        }
    }

    // FOR(i, layer) printf("|   "); printf("no repetition found\n");

    ret = s; // FIX: initialize ret
    FOR_(i, 1, s.length())
    {
        string l, r;
        l = dp(s.substr(0, i), layer+1);
        r = dp(s.substr(i), layer+1);

    // FOR(i, layer) printf("|   "); printf("%s;%s\n", l.c_str(), r.c_str());
        if (l.length() + r.length() < ret.length())
        {
            ret = l + r;
        }
    }
    // FOR(i, layer) printf("|   "); printf("=> %s\n", ret.c_str());
    mem[s] = ret;
    return ret;
}

int main()
{
    // setIO();
    populateFactors();
    string s;
    while (cin >> s)
    {
        cout << dp(s) << endl;
        s.clear();
    }

    // TRAV(p, mem)
    // {
    //     printf("%s -> %s\n", p.F.c_str(), p.S.c_str());
    // }

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
