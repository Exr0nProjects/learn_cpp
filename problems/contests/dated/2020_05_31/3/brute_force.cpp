// 15:01 (PDT)

#include <iostream>

#define ll long long
using namespace std;

const ll MX = 60111;
ll N, S, R, train[MX];

int main()
{
	scanf("%lld%lld%lld", &N, &S, &R);
	for (ll i=0; i<R; ++i)
	{
		ll u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		ll mx=0;
		for (ll j=u; j<=v; ++j)
			mx = max(mx, train[j]);
		if (mx + w <= S)
		{
			printf("T\n");
			for (ll j=u; j<=v; ++j)
				train[j] += w;
		}
		else
		{
			printf("N\n");
		}
	}
}

