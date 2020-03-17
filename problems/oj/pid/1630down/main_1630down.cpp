/*
TASK: 1630down
LANG: C++14
*/

/*
 * Problem 1630down (oj/pid/1630down)
 * Create time: Mon 16 Mar 2020 @ 17:00 (PDT)
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
list<char> s;
list<int> factors[MX];

map<list<char>, pair<list<char>, int> > mem;

void populateFactors()
{
    FOR_(i, 2, MX)
        for (int j=2*i; j<MX; j+=i)
            factors[j].push_back(i);
}

int fold(list<char> &src, int size, int layer=0)
{
    if (mem.count(src))
    {
        src = mem[src].F;
        return mem[src].S;
    }
    FOR(i, layer) printf("|   "); printf("size %d\n", size);
    if (size <= 4) return size;
    // try folding
    TRAV(len, factors[size])
    {
        bool legit = 1;
        auto lit = src.begin(), rit = src.begin();
        advance(rit, len);

        while (rit != src.end())
        {
            if (*lit != *rit) legit = 0;
            advance(lit, 1);
            advance(rit, 1);
        }

        if (legit)
        {
            auto &ret = mem[src];
            int pre = size / len;
            src.erase(src.begin(), next(src.begin(), len));
            int post = fold(src, len, layer+1);
            src.push_front('(');
            while (pre)
            {
                src.push_front(pre%10 + '0');
                pre /= 10;
            }
            src.push_back(')');
            ret = {src, post};
            return post;
        }
    }
    // recurse if folding didn't work
    // printf("folding didn't work...\n");
    list<char> ret;
    int div = 0, minn = size;
    auto it = next(src.begin(), 1);
    printf("it nexd...\n");
    for (; it != src.end(); ++it)
    {
        list<char> lef, rig;
        // TODO: copy is slow...
        copy(src.begin(), it, back_inserter(lef));
        copy(it, src.end(), back_inserter(rig));

        int post = fold(lef, div, layer+1) + fold(rig, size-div, layer+1);
        if (post < minn)
        {
            ret.clear();
            ret.splice(ret.end(), lef);
            ret.splice(ret.end(), rig);
            minn = post;
        }
        ++div;
    }
    mem[src] = {ret, minn};
    src = ret;
    return minn;
}

int main()
{
    setIO();
    populateFactors();
    while (true)
    {
        s.clear();
        char c;
        int len=0;
        while (c != '\n')
        {
            scanf("%c", &c);
            s.push_back(c);
            ++len;
        }
        fold(s, len);
        TRAV(c, s)
        {
            printf("%c", c);
        }
        printf("\n");
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
