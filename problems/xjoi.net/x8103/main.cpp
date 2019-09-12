/*
ID: spoytie2
TASK: XXXX
LANG: C++14                 
*/

/*
 * Problem 8103 (xjoi.net/8103)
 * Created Wed 11 Sep 2019 @ 07:08 (PDT)
 * Accepted Thu 12 Sep 2019 @ 07:23 (PDT)
 * 
 */

#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>
#include <math.h>
#include <random>
#include <set>
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

#define UN unsigned
#define ST static
#define CN const
#define LL long long
#define DL double
#define LD long double
#define INF 1047483647
#define PI 3.14159265358979323846264338

using namespace std;

const int MAXSZ = 5010; // todo
int apples[MAXSZ];

int main()
{
    int num, s, a, b, ret;
    scanf("%d%d%d%d", &num, &s, &a, &b);

    priority_queue<int> pq;
    for (int i = 0; i < num; ++i)
    {
        int t, c;
        scanf("%d%d", &t, &c);
        if (t <= a + b) // should be <?
            pq.push(c);
    }

    for (; !pq.empty; pq.pop())
    {
        if (pq.top() > s) break; // should be >=?
        ++ ret;
        s -= pq.top();
    }

    return 0;
}
