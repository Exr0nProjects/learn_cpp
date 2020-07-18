/*
 * Problem 1626_down (uva/1626_down)
 * Create time: Sat 18 Jul 2020 @ 09:01 (PDT)
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
const ll MX = 111;
string inp;

char ope(char c) // oposite
{
    switch (c)
    {
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '[';
    }
    return 'x';
}

string MIN(const string &lhs, const string &rhs)
{
    return lhs.size() < rhs.size() ? lhs : rhs;
}

map<pair<int, int>, int> dps;
int from[MX][MX];
//map<pair<int, int>, pair<int, int> > from;
int dp(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return 0;
    //if (l == r) return min(string({inp[l], ope(inp[l])}), string({ope(inp[l]), inp[l]}));
    if (l == r) return 2;
    if (dps.count(mp(l, r))) return dps[mp(l, r)];

    int ret = dp(l, l, lay+1) + dp(l+1, r, lay+1);
    int split = 0;
    for (int k=l+2; k<r; ++k)
        if (dp(l, k) + dp(k+1, r) < ret)
            ret = dp(l, k) + dp(k+1, r),
            split = k;
        //ret = min(ret, dp(l, k, lay+1) + dp(k+1, r, lay+1));

    //for (int i=0; i<lay; ++i) printf("|   "); printf("%c == %c ?\n", inp[l], inp[r]);
    //if (ope(s[0]) == *s.rbegin())

    if (inp[l] == ope(inp[r]) && dp(l+1, r-1) +2 < ret) ret = dp(l+1, r-1)+2, split=0;
    //printf("MIN{ %s , %s } = %s\n", ret.c_str(), (string(1, inp[l]) + dp(l+1, r-1, lay+1) + inp[r]).c_str(), min(ret, string(1, inp[l]) + dp(l+1, r-1, lay+1) + inp[r]).c_str());
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %s\n", ret.c_str());
    from[l][r] = split;
    return dps[mp(l, r)] = ret;
}

void print(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return;
    if (l == r) cout << min(string({inp[l], ope(inp[l])}), string({ope(inp[l]), inp[l]}));
    else if (inp[l] == ope(inp[r]))
    {
        printf("%c", inp[l]);
        print(l+1, r-1, lay+1);
        printf("%c", inp[r]);
    }
    else
    {
        //printf("from[%d][%d] = %d\n", l, r, from[l][r]);
        print(l, l+from[l][r], lay+1);
        print(l+from[l][r]+1, r, lay+1);
    }
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        dps.clear();
        memset(from, 0, sizeof from);
        cin >> inp;
        //cout << "min len = " << dp(0, inp.size()-1) << endl;
        print(0, inp.size()-1);
        printf("\n");
        if (cs-1) cout << endl;
    }

	return 0;
}

