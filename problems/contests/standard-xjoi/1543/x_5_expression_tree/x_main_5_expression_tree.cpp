/*
 * Problem 5_expression_tree (contests/standard-xjoi/1543/5_expression_tree)
 * Create time: Sat 01 Aug 2020 @ 15:35 (PDT)
 * Accept time: Sat 01 Aug 2020 @ 17:19 (PDT)
 *
 */

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
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
#include <algorithm>
#include <functional>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = -1;
string inp;

int apply(int i, int a, int b, int lay)
{
    int ret = 0;
    if (inp[i] == '*') ret = a * b;
    if (inp[i] == '+') ret = a + b;
    if (inp[i] == '-') ret = a - b;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", ret);
    return ret;
}
bool valid_loc(int l, int i)
{
    return (i == l || inp[i-1] == ')' || isdigit(inp[i-1]));
}

int parse(int l, int r, int lay=0)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d:  '", l, r); for (int i=l; i<=r; ++i) printf("%c", inp[i]); printf("'\n");
    if (l > r) return 0;
    if (inp[l] == '(' && inp[r] == ')')
    {   // FIX: logic/equ--paren checking is hard. can't just test left and right, might be weird stuff in middle
        int pcnt = 0, mn=0;
        for (int i=l+1; i<r; ++i)
        {
            if (inp[i] == '(') ++pcnt;
            if (inp[i] == ')') --pcnt;
            mn = min(mn, pcnt);
        }
        if (mn == 0 && pcnt == 0)
            return parse(l+1, r-1, lay+1);
    }
    int pcnt = 0;//, zcnt=0;
    for (int i=r; i>=l; --i)
    {
        if (inp[i] == ')') ++pcnt;
        if (inp[i] == '(') --pcnt;
        //for (int i=0; i<lay; ++i) printf("|   "); printf("add @ %d pcnt %d\n", i, pcnt);
        //if (!pcnt) ++zcnt;
        if (!pcnt && (inp[i] == '+' || inp[i] == '-') && valid_loc(l, i))   // FIX: order of ops, parens around the ||
            return apply(i, parse(l, i-1, lay+1), parse(i+1, r, lay+1), lay);
    }
    pcnt = 0;
    for (int i=r; i>=l; --i)
    {
        if (inp[i] == ')') ++pcnt;
        if (inp[i] == '(') --pcnt;
        //for (int i=0; i<lay; ++i) printf("|   "); printf("mul @ %d pcnt %d\n", i, pcnt);
        if (!pcnt && inp[i] == '*' && valid_loc(l, i))
            return apply(i, parse(l, i-1, lay+1), parse(i+1, r, lay+1), lay);
    }
    // just a number
    int tot=0;
    for (int i=l; i<=r; ++i)
        tot = tot * 10 + inp[i]-'0';
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", tot);
    return tot;
}

int main()
{
    cin >> inp;
    printf("%d\n", parse(0, inp.size()-1));

	return 0;
}

