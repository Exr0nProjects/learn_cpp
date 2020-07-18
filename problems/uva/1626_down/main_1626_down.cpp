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
const ll MX = -1;

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

map<string, string> dps;
string dp(string s, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%s\n", s.c_str());
    if (s.size() == 0) return s;
    if (s.size() == 1) return s[0] == '(' || s[0] == '[' ? s + ope(s[0]) : string(1, ope(s[0])) + s;
    if (dps.count(s)) return dps[s];
    dps[s] = dp(s.substr(0, 1), lay+1) + dp(s.substr(1), lay+1);
    for (int k=2; k<s.size(); ++k)
        dps[s] = min(dps[s], dp(s.substr(0, k), lay+1) + dp(s.substr(k), lay+1));
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%c == %c ?\n", s[0], *s.rbegin());
    if (ope(s[0]) == *s.rbegin()) dps[s] = min(dps[s],
            string(1, s[0]) + dp(s.substr(1, s.size()-2), lay+1) + string(1, ope(s[0])));
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %s\n", dps[s].c_str());
    return dps[s];
}

int main()
{
    int cs; scanf("%d", &cs);
    while (cs--)
    {
        string s;
        cin >> s;
        cout << dp(s) << endl;
        if (cs-1) cout << endl;
    }

	return 0;
}

