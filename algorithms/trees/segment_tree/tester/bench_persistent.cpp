#include <iostream>
#define ll long long

const ll MX = 10010;
const ll MOD = 1e9 + 7;
ll N, M, arr[MX][MX];

int main()
{
	scanf("%lld%lld", &N, &M);
	for (ll i=1; i<=M; ++i)
	{
		ll c, l, r, v;
		for (int j=1; j<=N; ++j)
			arr[i][j] = arr[i-1][j];
		scanf("%lld%lld%lld%lld", &c, &l, &r, &v);
		if (c == 1) for (int j=l; j<=r; ++j) arr[i][j] += v;
		if (c == 2)
		{
			ll s = 0;
			for (int j=l; j<=r; ++j)
				s = (s + arr[v][j]) % MOD;
			printf("%lld\n", s % MOD);
		}
	}
}

