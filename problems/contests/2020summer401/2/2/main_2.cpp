/*
 * Problem 2 (contests/2020summer401/2/2)
 * Create time: Fri 19 Jun 2020 @ 11:57 (PDT)
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
ll N;
char inp[MX];

struct Node
{
	bool isnum;
	ll val;
	char op;
	Node *L, *R;

	Node(ll v): isnum(1), val(v), L(nullptr), R(nullptr) {}
	Node(char c, Node *l, Node *r): isnum(0), op(c), L(l), R(r) {}
} *root = nullptr, *calc=nullptr;

Node *build(ll l, ll r)
{
	//printf("building %d..%d: \"", l, r);
	//for (ll i=l; i<=r; ++i) printf("%c", inp[i]); printf("\"\n");
	while (inp[l] == '(' && inp[r] == ')') ++l, --r;
	ll paren = 0;
	//printf("    nvm  %d..%d\n", l, r);
	for (ll i=r; i>=l; --i)
	{
		if (inp[i] == ')') ++paren;
		if (inp[i] == '(') --paren;
		if (!paren && (inp[i] == '+' || inp[i] == '-'))
			return new Node(inp[i], build(l, i-1), build(i+1, r));
	}

	//paren=0; // TODO: shouldn't be needed
	for (ll i=r; i>=l; --i)
	{
		if (inp[i] == ')') ++paren;
		if (inp[i] == '(') --paren;
		if (!paren && (inp[i] == '*' || inp[i] == '/'))
			return new Node(inp[i], build(l, i-1), build(i+1, r));
	}

	ll d = 0;
	for (ll i=l; i<=r; ++i)
		d = d*10 + inp[i]-'0';
	//printf("d = %lld\n", d);
	return new Node(d);
}

void print(Node *&cur)
{
	if (cur->isnum) printf("%lld", cur->val);
	else
	{
		if (cur->L->isnum && cur->R->isnum)
			calc = cur;
		print(cur->L);
		printf(" ");
		print(cur->R);
		printf(" %c", cur->op);
	}
}

int main()
{
	scanf("%s%n", inp, &N);	// TODO: input hecka sketch, invis characters messes up %n count
	//printf("got %d chars\n", N);
	root = build(0, N-1);	// FIX: indexing--build takes inclusive so upper is N-1 not N
	print(root); printf("\n");

	//printf("starting calculation\n");
	do
	{
		//printf("calc = %d : %d %c\n", calc->isnum, calc->val, calc->op);
		if (!calc->isnum)
		{
			ll val, a=calc->L->val, b=calc->R->val;
			delete calc->L;
			delete calc->R;
			if (calc->op == '+') val = a + b;
			if (calc->op == '-') val = a - b;
			if (calc->op == '*') val = a * b;
			if (calc->op == '/') val = a / b;
			calc->isnum = 1;
			calc->val = val;
		}
		print(root); printf("\n");
	//} while (!calc->isnum);
	} while (!calc->isnum);

	return 0;
}

