/*
 * Problem 3_ZOJ2112 (contests/dated/2020_06_19/3_ZOJ2112)
 * Create time: Tue 23 Jun 2020 @ 10:22 (PDT)
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
const ll MX = 100111;
const ll MXTN = MX<<7;

// segment tree
int alc=1, lc[MXTN], rc[MXTN], rt_org[MX], rt_bit[MX];
int tsum[MXTN], addt[MXTN];

void dupe(int &k);
void apply(int addv, int &k, int tl, int tr);
void push(int &k, int tl, int tr):
void comb(int k);

void update(int q, int addv, int &k, int tl=1, int tr=N);
int querykth(int k1, int k2, int kth, int tl=1, int tr=N);
int aligned_query(int ql, int qr, int k, int tl=1, int tr=N);

// BIT
void bit_rupdate(int v, int t, int x);
void bit_update(int l, int r, int t, int x);
int bit_query(int v, int tl, int tr);

int main()
{

	return 0;
}

