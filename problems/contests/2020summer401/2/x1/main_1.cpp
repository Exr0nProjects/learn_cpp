/*
 * Problem 1 (contests/2020summer401/2/1)
 * Create time: Fri 19 Jun 2020 @ 10:32 (PDT)
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
const ll MX = -1;
stack<ll> expr;

ll solve()
{
	while (1)
	{
		//printf("hm\n");
		char c;
		scanf("%c", &c);
		ll d = 0;
		if (c >= '0' && c <= '9') while (1) // FIX: typo after change--&& not ||
		{
			//printf("c = %c, d = %d\n", c, d);
			if (c < '0' || c > '9')
			{
				//printf("pushing %d to expr\n", d);
				expr.push(d);
				break;
			}
			d = d*10+(c-'0');

			int r = scanf("%c", &c);
			if (r == -1 || c == '\n') return expr.top();
		}
		//printf("out of while\n");
		if (c == '$') continue;
		if (expr.size() < 2) return expr.top();
		ll b = expr.top(); expr.pop();
		ll a = expr.top(); expr.pop();
		//printf("calculating op %d %c %d...\n", a, c, b);
		if (c == '+') expr.push(a + b);
		if (c == '-') expr.push(a - b);
		if (c == '*') expr.push(a * b);
		if (c == '/') expr.push(a / b);
		//printf("expr.top() %d\n", expr.top());
	}
}

int main()
{
	printf("%lld\n", solve());

	return 0;
}

