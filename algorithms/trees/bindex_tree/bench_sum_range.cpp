#include <iostream>
#define ll long long

ll arr[1000000];

int main()
{
	ll N, Q; scanf("%d%d", &N, &Q);
	for (ll q=0; q<Q; ++q)
	{
		char c = ' '; while (c <'a'||c>'z') scanf("%c", &c);
		ll a, b; scanf("%lld%lld", &a, &b);
		if (c == 'q')
		{
			ll tot = 0;
			for (ll i=a; i<=b; ++i)
				tot += arr[i];
			printf("%lld\n", tot);
		}
		if (c == 'u')
			arr[a] += b;
	}
}

