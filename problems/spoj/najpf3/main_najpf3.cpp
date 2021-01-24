/*
 * Problem najpf3 (spoj/najpf3)
 * Create time: Sat 23 Jan 2021 @ 20:40 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=1; i<=N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e6+10;
ll T, N, P;
char str[MX], pat[MX];
ll pi[MX];

void kpi()
{
	pi[0] = -1;
	for (int i=1; i<N; ++i) {
		for (pi[i] = pi[i-1]; ~pi[i] && pat[pi[i]+1] == pat[i]; pi[i] = pi[pi[i]]);
		if (pat[pi[i]+1] == pat[i]) ++pi[i];
	}
}

int main()
{
	scanf("%lld", &T);
	F(tt, T) {
		scanf("%s%s", str, pat);
		memset(pi, 0, sizeof pi);
		N = strlen(str);
		P = strlen(pat);

		kpi();
	}
}
