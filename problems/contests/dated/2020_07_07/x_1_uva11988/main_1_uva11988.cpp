/*
 * Problem 1_uva11988 (contests/dated/2020_07_07/1_uva11988)
 * Create time: Tue 07 Jul 2020 @ 15:00 (PDT)
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
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
const ll MX = 1000000;
//list<pair<int, int> > seq
list<int> seq;
char buf[MX];

void print(int c)
{
    while (buf[c]) putchar(buf[c++]);
}

void place(int pre, int cur)
{
    //printf("adding '"); print(cur); printf("' to %d\n", pre);
    if (pre < 0) seq.push_front(cur);
    if (pre >= 0) seq.push_back(cur);
}

int main()
{
    while (~scanf("%s", buf))
    {
        int len = strlen(buf);
        buf[len++] = ']'; // process last segment
        buf[len] = 0; // null terminate

        int start=0, prevdir=0; // -1 = front, 1 = back
        for (int i=0; i<len; ++i)
        {
            if (buf[i] == '[')
            {
                buf[i] = 0;
                place(prevdir, start);
                start = i+1;
                prevdir = -1;
            }
            else if (buf[i] == ']')
            {
                buf[i] = 0;
                place(prevdir, start);
                start = i+1;
                prevdir = 1;
                //printf("adding '"); print(start); printf("' to back\n");
            }
        }
        for (int shift : seq)
        {
            print(shift);
            //printf("\n");
        }
            //printf("%s", buf+shift);
        printf("\n");
        memset(buf, 0, sizeof buf); // FIX: clears
        seq.clear();
    }

	return 0;
}

