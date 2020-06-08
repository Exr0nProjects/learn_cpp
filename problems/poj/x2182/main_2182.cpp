/*
 * Problem 2182 (poj/2182)
 * Create time: Sun 07 Jun 2020 @ 13:14 (PDT)
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
const int MX = 8111;
ll N, arr[MX], ans[MX];

int main()
{
	scanf("%lld", &N);
	for (int i=2; i<=N; ++i)
		scanf("%d", &arr[i]);

	for (int k=1; k<=N; ++k)
		for (int i=N; i>0; --i)
			if (!arr[i])
			{
				for (int j=i; j<=N; ++j)
					--arr[j];	// FIX: arr[j] not arr[i]
				ans[i] = k;
				break;
			}

	for (int i=1; i<=N; ++i)
		printf("%lld\n", ans[i]);

	return 0;
}

