/*
 * Problem 644 (uva/644)
 * Create time: Wed 08 Jul 2020 @ 11:53 (PDT)
 * Accept time: Wed 08 Jul 2020 @ 12:04 (PDT)
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
const ll MX = 2100;
int trie[MX][2], alc=2; // FIX: bounds--trie needs # of nodes not # of strings
bool isend[MX], legit=1;
char buf[MX];

int main()
{
    int cs = 0;
    while (~scanf("%s", buf))
    {
        if (buf[0] == '9')
        {
            printf("Set %d is ", ++cs);
            if (!legit) printf("not ");
            printf("immediately decodable\n");

            memset(buf, 0, sizeof buf); // TODO: not needed?
            memset(trie, 0, sizeof trie);
            memset(isend, 0, sizeof isend);

            alc = 2;
            legit = 1;
            continue;
        }
        int cur = 1;    // position before processing buf[i]
        for (int i=0; buf[i]; ++i)
        {
            if (isend[cur]) legit=0;
            int &nxt = trie[cur][buf[i]-'0'];
            if (!buf[i+1] && nxt) legit=0; // at last and this node already exists, aka self is a prefix of another
            if (!nxt) nxt = alc++;
            cur = nxt;
        }
        isend[cur] = 1;
    }

	return 0;
}

