/*
 * Problem 3_uva10100 (contests/dated/2020_07_02/3_uva10100)
 * Create time: Mon 06 Jul 2020 @ 12:29 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdio>
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

using namespace std;
const ll MX = 600;
int a[MX], b[MX], tab[MX][MX];
map<string, int> desc;

int input()
{
    int tot = 0;
    string s;
    char c = getchar();
    for (;; c = getchar())
    {
        if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        {
            if (!s.size() && c == '\n') break;
            if (!s.size()) continue;
            if (!desc.count(s)) desc[s] = desc.size();
            printf("got '%s' : %d\n", s.c_str(), desc[s]);
            s.clear();
            ++tot;
            if (c == '\n') break;
        }
        else
            s.push_back(c);
    }
    printf("line ended\n");
    return tot;
}

int main()
{
    while (true)
        printf("got %d words\n", input());

	return 0;
}

