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

//int solve()
//{
//    //printf("alen %d blen %d\n", alen, blen);
//    for (int i=1; i<alen; ++i)
//    {
//        for (int j=1; j<blen; ++j)
//        {
//            //printf("%d %d: %s %s\n", i, j, a[i].c_str(), b[j].c_str());
//            //if (a[i] == 0) printf("a[i] = 0! i=%d j=%d\n", i, j);
//            //if (i == 1 && j == 25) printf("a[1] %d b[25] %d\n", a[i], b[j]);
//            //if (a[i] == b[j] && a[i] >= 0)  // FIX: >= 0 not > 0 cuz first element gets descretized to 0 not 1
//            if (a[i] == b[j])
//            {
//                //printf("%3d %3d same!\n\n", i, j);
//                tab[i][j] = tab[i-1][j-1] + 1;
//            }
//            //tab[i][j] = max(tab[i][j], max(tab[i-1][j], tab[i][j-1]));
//            else
//                tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
//            //printf("%3d", tab[i][j]);
//        }
//        //printf("\n");
//    }
//    //printf("\n");
//    //for (int i=1; i<=alen; ++i)
//    //{
//    //    for (int j=1; j<=blen; ++j)
//    //        printf("%3d", tab[i][j]);
//    //    printf("\n");
//    //}
//    return tab[alen-1][blen-1];
//}

//void process(string arr[], int &len)
//{   // TODO: yoinked from answer_ad
//    string inp;
//    getline(cin, inp);
//
//    if (!inp.size())
//    { len = 0; return; }
//
//    for (int i=0; i<inp.size(); ++i)
//        if (!isalpha(inp[i]) && !isdigit(inp[i]))
//            inp[i] = ' ';
//
//    inp += " !\n";
//    stringstream ss1(inp);
//    len = 0;
//    while (ss1 >> arr[++len]) {
//        if (arr[len][0] == '!') break;
//    }
//}

int main()
{
    //scanf("%d", &alen); for (int i=1; i<=alen; ++i) scanf("%d", &a[i]);
    //scanf("%d", &blen); for (int i=1; i<=blen; ++i) scanf("%d", &b[i]);
    //printf("lcs: %d\n", solve());
    //return 0;

    //while (true)
    //    printf("got %d words\n", input());
    int T=0;
    //for (; !cin.eof(); ++T)
    for (; !cin.eof();)
    {
        //process(a, alen);
        //process(b, blen);
        getline(cin, s1);
        getline(cin, s2);
        if (!s1.size() || !s2.size()) {
            printf("%2d. Blank!\n", ++T);
            continue;
        }
        for (int i = 0; i < s1.size(); i++) {
            if (!isalpha(s1[i]) && !isdigit(s1[i])) s1[i] = ' ';
        }
        for (int i = 0; i < s2.size(); i++) {
            if (!isalpha(s2[i]) && !isdigit(s2[i])) s2[i] = ' ';
        }
        s1 += " !\n";
        stringstream ss1(s1);
        alen = 0;
        while (ss1 >> a[++alen]) {
            if (a[alen][0] == '!') break;
        }
        s2 += " !\n";
        stringstream ss2(s2);
        blen = 0;
        while (ss2 >> b[++blen]) {
            if (b[blen][0] == '!') break;
        }

        ////memset(a, 0, sizeof a); // FIX: clears, even though the shouldn't be needed
        ////memset(b, 0, sizeof b);
        ////memset(tab, 0, sizeof tab);
        ////desc = {};
        ////alen = input(a); if (alen < 0) break;
        ////blen = input(b); if (blen < 0) break;
        //////printf("\na: "); for (int i=1; i<=alen; ++i) printf("%3d", a[i]); printf("\n");
        //////printf("b: "); for (int i=1; i<=blen; ++i) printf("%3d", b[i]); printf("\n");
        //printf("%2d. ", T);
        ////printf("Blank!\n");
        ////if (!alen || !blen) printf("Blank!\n");
        ////else printf("Length of longest match: %d\n", solve());
        //printf("Length of longest match: %d\n", solve());
        ////else printf("Length of longest match: %d\n", 0);

        for (int i=1; i<alen; ++i)
        {
            for (int j=1; j<blen; ++j)
            {
                //printf("%d %d: %s %s\n", i, j, a[i].c_str(), b[j].c_str());
                //if (a[i] == 0) printf("a[i] = 0! i=%d j=%d\n", i, j);
                //if (i == 1 && j == 25) printf("a[1] %d b[25] %d\n", a[i], b[j]);
                //if (a[i] == b[j] && a[i] >= 0)  // FIX: >= 0 not > 0 cuz first element gets descretized to 0 not 1
                if (a[i] == b[j])
                {
                    //printf("%3d %3d same!\n\n", i, j);
                    tab[i][j] = tab[i-1][j-1] + 1;
                }
                //tab[i][j] = max(tab[i][j], max(tab[i-1][j], tab[i][j-1]));
                else
                    tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
                //printf("%3d", tab[i][j]);
            }
            //printf("\n");
        }
        printf("%2d. Length of longest match: %d\n", ++T, tab[alen-1][blen-1]);
        //printf("\n");
        //for (int i=1; i<=alen; ++i)
        //{
        //    for (int j=1; j<=blen; ++j)
        //        printf("%3d", tab[i][j]);
        //    printf("\n");
        //}
        //return tab[alen-1][blen-1];

        //for (int i = 1; i < alen; i++) {
        //    for (int j = 1; j < blen; j++) {
        //        //if (cmp(a[i], b[j]))
        //        if (a[i] == b[j])
        //        {
        //            tab[i][j] = tab[i - 1][j - 1] + 1;
        //            //printf("%3d %3d same!\n", i, j);
        //        }
        //        else
        //        {
        //            tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        //        }
        //    }
        //}
        //printf("%2d. Length of longest match: %d\n", ++T, tab[alen - 1][blen - 1]);
    }
    //printf("%2d. Blank!\n", T);

	return 0;
}

