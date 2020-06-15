/*
 * Problem 4_hdu4578 (contests/dated/2020_06_12/4_hdu4578)
 * Create time: Mon 15 Jun 2020 @ 14:23 (PDT)
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
const int MX = 10111;
int N, D, segt[MX<<1], mult[MX<<1], addt[MX<<1];

void push_down(int k, int tl, int tr)
{
	if (!(mult[k] + addt[k])) return;
	const int lc = k<<1, rc=lc|1;

	mult[lc] = mult[rc] = mult[k];
	addt[lc] = addt[rc] = addt[k];

	if (addt[k] == 0)
	{
		segt[lc] *= mult[k];
		segt[rc] *= mult[k];
	}
	else
	{
		const int mod = addt[k] * (tr-tl+1>>1);
		if (mult[k])
		{
			segt[lc] += mod;
			segt[rc] += mod;
		}
		else
		{
			segt[lc] = segt[rc] = mod;
		}
	}
}
void collect(int k, int tl, int tr)
{
	segt[k] = segt[k<<1] + segt[k<<1|1];
}

int main()
{

	return 0;
}

