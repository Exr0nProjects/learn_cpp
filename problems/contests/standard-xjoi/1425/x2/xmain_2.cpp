/*
 * Problem 2 (contests/standard-xjoi/1425/2)
 * Create time: Tue 09 Jun 2020 @ 07:27 (PDT)
 * Accept time: Tue 09 Jun 2020 @ 07:36 (PDT)
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
const int MX = 1000111;
int N, alloc=1, heap[MX];

void heapup(int cur)
{
	if (cur == 1) return;
	if (heap[cur] < heap[cur/2])
	{
		swap(heap[cur], heap[cur/2]);
		heapup(cur/2);
	}
}

void heapdo(int cur)
{
	if (cur * 2 >= alloc) return;
	if (cur * 2 + 1 == alloc)
	{
		if (heap[cur] > heap[cur*2])
			swap(heap[cur], heap[cur*2]);
	}
	else if (heap[cur] > min(heap[cur*2], heap[cur*2+1]))
	{
		int lo = cur*2 + (heap[cur*2] > heap[cur*2+1]);
		swap(heap[cur], heap[lo]);
		heapdo(lo);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
	{
		int d; scanf("%d", &d);
		heap[alloc] = d;
		heapup(alloc++);
	}

	for (int i=0; i<N; ++i)
	{
		printf("%d ", heap[1]);
		swap(heap[1], heap[--alloc]);
		heapdo(1);
	}
	printf("\n");

	return 0;
}

