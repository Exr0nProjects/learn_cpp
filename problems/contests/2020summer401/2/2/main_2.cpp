/*
 * Problem 2 (contests/2020summer401/2/2)
 * Create time: Fri 19 Jun 2020 @ 11:57 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 100111;
ll N, gonedepth=0;
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

	//while (inp[l] == '(' && inp[r] == ')') ++l, --r;	// FIX: cannot just assume begin and end w/ parens means whole thing is parens
	ll paren = 0;
	//printf("    nvm  %d..%d\n", l, r);
	for (ll i=r; i>=l; --i)
	{
		if (inp[i] == ')') ++paren;
		if (inp[i] == '(') --paren;
		//printf("c %c @ %d paren %d\n", inp[i], i, paren);
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

	if (inp[l] == '(' && inp[r] == ')')
		return build(l+1, r-1);	// FIX: deal with full parens wrap by checking if op exists first

	ll d = 0;
	for (ll i=l; i<=r; ++i)
		d = d*10 + inp[i]-'0';
	//printf("d = %lld\n", d);
	return new Node(d);
}

void print(Node *&cur, ll lay=1)
{
	if (cur->isnum) printf("%lld", cur->val);
	else
	{
		if (cur->L->isnum && cur->R->isnum && lay > gonedepth)	// FIX: typo after change--check `!hasgone++` not `hasgone++`
		//if (cur->L->isnum && cur->R->isnum)
		{
			//printf("setting calc at op %c\n", cur->op);
			gonedepth = lay;
			calc = cur;
		}
		print(cur->L, lay);
		printf(" ");
		print(cur->R, lay);
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
		//if (calc) printf("calc = %d : %d %c\n", calc->isnum, calc->val, calc->op);
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
		gonedepth = 0;
		print(root); printf("\n");
	//} while (!calc->isnum);
	} while (!calc->isnum);

	return 0;
}

