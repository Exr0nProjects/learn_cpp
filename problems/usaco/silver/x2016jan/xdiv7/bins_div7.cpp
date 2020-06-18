// revisit on 17 June 2020
// Create time: Wed 17 Jun 2020 @ 20:58 (PDT)
// nvm, this actually doesn't work. there's no sorting property

#include <iostream>
#define ll long long
using namespace std;

const ll MX = 50111;
ll N, pfs[MX];

int main()
{
	scanf("%d", &N);
	for (ll i=1; i<=N; ++i)
	{
		scanf("%d", &pfs[i]);
		pfs[i] = (pfs[i] + pfs[i-1]) % 7;
	}
	ll l=1, r=N+1; // inc exc
	for (ll i=0; i<30; ++i)
	{
		ll mid = l + (r-l>>1);
		printf("mid = %d\n", mid);
		bool ok = 0;
		for (int i=0; i+mid <= N; ++i)
		{
			printf("sum %d..%d: %d\n", i, i+mid, pfs[i+mid] - pfs[i-1]);
			if (pfs[i+mid] - pfs[i-1] % 7 == 0)
				ok = 1;
		}
		if (ok) l = mid;
		else r = mid;
	}
	printf("%d\n", l);
}

