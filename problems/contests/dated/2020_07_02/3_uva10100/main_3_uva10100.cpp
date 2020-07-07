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
int a[MX], b[MX], tab[MX][MX], alen, blen;
map<string, int> desc;

int input(int arr[])
{
    int tot = 0;
    string s;
    char c = getchar();
    for (;; c = getchar())
    {
        if (c == EOF) return -1;
        if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        {
            if (!s.size() && c == '\n') break;
            //if (!s.size()) continue;
            if (!desc.count(s)) desc[s] = desc.size();
            //printf("got '%s' (%d): %d\n", s.c_str(), s.size(), desc[s]);
            s.clear();
            ++tot;
            if (!s.size()) arr[tot] = -1;
            else arr[tot] = desc[s];
            if (c == '\n') break;
        }
        else
            s.push_back(c);
    }
    return tot;
}

int solve()
{
    for (int i=1; i<=alen; ++i)
    {
        for (int j=1; j<=blen; ++j)
        {
            if (a[i] == b[j] && a[i] > 0)
                tab[i][j] = tab[i-1][j-1] + 1;
            else
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            //printf("%3d", tab[i][j]);
        }
        //printf("\n");
    }
    return tab[alen][blen];
}

int main()
{
    //scanf("%d", &alen); for (int i=0; i<alen; ++i) scanf("%d", &a[i]);
    //scanf("%d", &blen); for (int i=0; i<blen; ++i) scanf("%d", &b[i]);
    //
    //printf("lcs: %d\n", solve());

    //while (true)
    //    printf("got %d words\n", input());

    for (int T=1; ; ++T)
    {
        memset(a, 0, sizeof a); // FIX: clears, even though the shouldn't be needed
        memset(b, 0, sizeof b);
        memset(tab, 0, sizeof tab);
        desc = {};
        alen = input(a); if (alen < 0) break;
        blen = input(b); if (blen < 0) break;
        printf("%2d. ", T);
        //printf("Blank!\n");
        if (!alen || !blen) printf("Blank!\n");
        else printf("Length of longest match: %d\n", solve());
        //else printf("Length of longest match: %d\n", 0);
    }

	return 0;
}

