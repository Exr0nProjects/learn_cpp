/*
 * Problem 2 (contests/2020summer401/2/2)
 * Create time: Fri 19 Jun 2020 @ 11:57 (PDT)
 * Accept time: Fri 19 Jun 2020 @ 14:39 (PDT)
 *
 */

#include <iostream>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;
const ll MX = 100111;
int N, gone=0;
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

inline ll pemdas(char c)
{
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	return 0;	// FIX: return something or it will undefined behavior
}

Node *build(const ll l, const ll r)
{

	ll paren = 0;
	for (ll t=1; t<=3; ++t)
		for (ll i=r; i>=l; --i)
		{
			if (inp[i] == ')') ++paren;
			if (inp[i] == '(') --paren;
			if (!paren && pemdas(inp[i]) == t)
				return new Node(inp[i], build(l, i-1), build(i+1, r));
		}

	if (inp[l] == '(' && inp[r] == ')')
		return build(l+1, r-1);	// FIX: deal with full parens wrap by checking if op exists first

	ll d = 0;
	for (ll i=l; i<=r; ++i)
		d = d*10 + inp[i]-'0';
	return new Node(d);
}

void print(Node *&cur)
{
	if (cur->isnum) printf("%lld", cur->val);
	else
	{
		if (cur->L->isnum && cur->R->isnum && !gone++)	// FIX: typo after change--check `!hasgone++` not `hasgone++`
			calc = cur;
		print(cur->L); printf(" ");
		print(cur->R); printf(" %c", cur->op);
	}
}

int main()
{
	scanf("%s%n", inp, &N);
	root = build(0, N-1);	// FIX: indexing--build takes inclusive so upper is N-1 not N
	print(root); printf("\n");
	while (!calc->isnum)
	{
		ll val, a=calc->L->val, b=calc->R->val;
		delete calc->L;
		delete calc->R;
		if (calc->op == '+') val = a + b;
		if (calc->op == '-') val = a - b;
		if (calc->op == '*') val = a * b;
		if (calc->op == '/') val = a / b;
		if (calc->op == '^') val = pow(a, b);
		calc->isnum = 1;
		calc->val = val;

		gone=0;
		print(root); printf("\n");
	}

	return 0;
}

