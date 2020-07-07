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
const ll MX = 6000;
const ll MXL = 1100;
//int a[MX], b[MX];
//map<string, int> desc;
string s1, s2;
string a[1000], b[1000];
int tab[MX][MX], alen, blen;

//int input(int arr[])
//{
//    int tot = 0;
//    string s;
//    char c = getchar();
//    for (;; c = getchar())
//    {
//        if (c == EOF) return -1;
//        //if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && !(c >= '0' && c <= '9'))
//        if (!isalpha(c) && !isdigit(c))
//        {
//            if (!s.size() && c == '\n') break;
//            //if (!s.size()) continue;
//            if (!desc.count(s)) desc[s] = desc.size();
//            ++tot;
//            if (!s.size()) arr[tot] = -1;   // FIX: order matters--increment tot before using, clear `s` after using
//            else arr[tot] = desc[s];
//            //printf("got '%s' (%d): %2d at %2d           arr[%2d] = %d\n", s.c_str(), s.size(), desc[s], tot, tot, arr[tot]);
//            s.clear();
//            if (c == '\n') break;
//        }
//        else
//            s.push_back(c);
//    }
//    return tot;
//}

int solve()
{
    for (int i=1; i<alen; ++i)
    {
        for (int j=1; j<blen; ++j)
        {
            if (a[i] == b[j])
                tab[i][j] = tab[i-1][j-1] + 1;
            else
                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
        }
    }
    return tab[alen-1][blen-1];
}

bool process(string arr[], int &len)
{   // TODO: yoinked from answer_ad
    string inp;
    getline(cin, inp);

    if (!inp.size()) return false;

    for (int i=0; i<inp.size(); ++i)
        if (!isalpha(inp[i]) && !isdigit(inp[i]))
            inp[i] = ' ';

    inp += " !\n";
    stringstream ss1(inp);
    len = 0;
    while (ss1 >> arr[++len]) {
        if (arr[len][0] == '!') break;
    }
    return true;
}

int main()
{
    int T=0;
    for (; !cin.eof();)
    {
        if (!process(a, alen) || !process(b, blen))
            printf("%2d. Blank!\n", ++T);

        //getline(cin, s1);
        //getline(cin, s2);
        //if (!s1.size() || !s2.size()) {
        //    printf("%2d. Blank!\n", ++T);
        //    continue;
        //}
        //for (int i = 0; i < s1.size(); i++) {
        //    if (!isalpha(s1[i]) && !isdigit(s1[i])) s1[i] = ' ';
        //}
        //for (int i = 0; i < s2.size(); i++) {
        //    if (!isalpha(s2[i]) && !isdigit(s2[i])) s2[i] = ' ';
        //}
        //s1 += " !\n";
        //stringstream ss1(s1);
        //alen = 0;
        //while (ss1 >> a[++alen]) {
        //    if (a[alen][0] == '!') break;
        //}
        //s2 += " !\n";
        //stringstream ss2(s2);
        //blen = 0;
        //while (ss2 >> b[++blen]) {
        //    if (b[blen][0] == '!') break;
        //}

        printf("%2d. Length of longest match: %d\n", ++T, solve());
    }

	return 0;
}

