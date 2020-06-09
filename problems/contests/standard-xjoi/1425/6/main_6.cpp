/*
 * Problem 6 (contests/standard-xjoi/1425/6)
 * Create time: Tue 09 Jun 2020 @ 08:21 (PDT)
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

int N;

int heap[MX*MX], alloc=1;
void heapup(int cur)
{
	if (cur == 1) return;
	if (heap[cur] < heap[cur/2])
	{
		swap(heap[cur], heap[cur/2]);
		heapup(cur/2);
	}
}
void heapdown(int cur)
{
	printf("heapdown %d\n", cur);
	if (!cur) return;
	if (cur*2 >= alloc) return;
	printf("but what?\n");
	if (cur*2+1 == alloc)
	{
		if (heap[cur] > heap[cur*2])
		{
			swap(heap[cur], heap[cur*2]);
			heapdown(cur*2);
		}
	}
	else
	{
		printf("so either is possible\n");
		int lo = cur*2 + heap[cur*2] > heap[cur*2+1];
		if (heap[cur] > heap[lo])
		{
			swap(heap[cur], heap[lo]);
			heapdown(lo);
		}
	}
}

void insert(int d)
{
	heap[alloc] = d;
	heapup(alloc++);
}
int pop()
{
	printf("uhm\n");
	if (alloc == 1) return 0;
	printf("uhm\n");
	swap(heap[1], heap[--alloc]);
	printf("uhm\n");
	heapdown(1);
	printf("uhm\n");
	return heap[alloc];
}

int main()
{
	while (true)
	{
		int c, d; scanf("%d", &c);
		if (c == 1) { scanf("%d", &d); insert(d); }
		if (c == 2) printf("%d\n", pop());
	}

	return 0;
}

