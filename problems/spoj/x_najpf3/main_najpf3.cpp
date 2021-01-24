/*
 * Problem najpf3 (spoj/najpf3)
 * Create time: Sat 23 Jan 2021 @ 20:40 (PST)
 * Accept time: [!meta:end!]
 *
 */
#include <bits/stdc++.h>
#define ll long long
#define mt make_tuple
#define F(i, N) for (int i=0; i<N; ++i)
#define db(...) fprintf(stderr, __VA_ARGS__)
using namespace std;

const ll MX = 1e6+10;
ll T, N, P;
char str[MX], pat[MX];
ll pi[MX];
ll ans[MX], acnt=0;

void kpi()
{
	pi[0] = -1;
	for (int i=1; i<P; ++i) {
		for (pi[i] = pi[i-1]; ~pi[i] && pat[pi[i]+1] != pat[i]; pi[i] = pi[pi[i]]);
		if (pat[pi[i]+1] == pat[i]) ++pi[i];
	}
}

int main()
{
	scanf("%lld", &T);
	F(tt, T) {
		scanf("%s%s", str, pat);
		memset(pi, 0, sizeof pi);
		memset(ans, 0, sizeof ans);
		acnt = 0;
		N = strlen(str);
		P = strlen(pat);
		db("str '%s' pat '%s'\n", str, pat);

		kpi();
		db("case %d\n", tt); F(i, P) db("%3d", pi[i]); db("\n");

		ll cur = -1;
		for (int i=0; i<N; ++i) {
			for (; ~cur && pat[cur+1] != str[i]; cur=pi[cur]);
			if (pat[cur+1] == str[i]) ++cur; // FIX: kmp pat goes with cur/pi, str goes with i (pat[cur...], str[i] not str[cur...], pat[i]) smah
			if (cur+1 == P) cur = pi[cur], ans[++acnt] = i-P+2;
			// db("i=%d cur = %d\n", i, cur);
		}

		if (acnt) {
			printf("%d\n", acnt);
			for (int i=1; i<=acnt; ++i) printf("%d ", ans[i]);
		} else {
			printf("Not Found\n");
		}
		printf("\n");
	}
}
