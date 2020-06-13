/*
 * Problem 4 (contests/standard-xjoi/1405/4)
 * Create time: Sat 13 Jun 2020 @ 10:16 (PDT)
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
const int MX = 20111;

int bidx[MX];
void update(int i)
{
	int v = i;
	for (; i<=MX; i+=i&-i)
		bidx[i] ^= v;
}
int query(int l, int r)
{
	int tot = 0;
	for (; r>l; r-=r&-r)
		tot ^= bidx[r];
	for (; l>r; l-=l&-l)
		tot ^= bidx[l];
	return tot;
}

int main()
{

	return 0;
}

