/*
TASK: 116up
LANG: C++14
*/

/*
 * Problem 116up (oj/pid/116up)
 * Create time: Wed 22 Apr 2020 @ 16:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
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
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define g(t, i) get<i>(t)
#define mt make_tuple

#define FOR_(i, b, e) for (long long i = (b); i < (e); ++i)
#define FOR(i, e) FOR_(i, 0, (e))
#define FORR_(i, b, e) for (long long i = (e)-1; i >= (b); --i)
#define FORR(i, e) FORR_(i, 0, e)
#define TRAV(a, x) for (auto &a : x)

using namespace std;
const int MXN = 20;
const int MXM = 110;
int M, N, tab[MXN][MXM], pre[MXN][MXM];

//void reconstruct(int i, int j)
//{
//    if (j)
//    {
//        reconstruct(pre[i][j], j-1);
//        printf(" %d", i+1);
//    }
//    else
//        printf("%d", i+1);
//}

inline int mod(int num)
{ return (num+N) %N; }

int main()
{
	// freopen("test.out", "w+", stdout);
	while (scanf("%d%d", &N, &M) == 2)
	{
		memset(tab, 0, sizeof tab);
		memset(pre, 0, sizeof pre);

		FOR(n, N) FORR(m, M)		// FIX: big brain: input backwards so that everything else works nicely
			scanf("%d", &tab[n][m]);

		FOR_(j, 1, M)
			FOR(i, N)
			{
				// get min previous step
				pair<int, int> mn = mp(1<<30, 1<<30);	// pair< cost, i-val >
				FOR_(k, i-1, i+2)
					mn = min(mn, mp(tab[mod(k)][j-1], mod(k)));

				// printf("min at (%d %d) is from %d\n", i, j, mn.S);

				// use min
				tab[i][j] += tab[mn.S][j-1];
				pre[i][j] = mn.S;
			}

		int ret=0;
		FOR(i, N)
			if (tab[ret][M-1] > tab[i][M-1])
				ret = i;

		int ogret = ret;

		FORR(j, M)
		{
			printf("%d", ret+1);
			if (j) printf(" ");
			ret = pre[ret][j];
		}

		printf("\n%d\n", tab[ogret][M-1]);
	}

	return 0;
}
