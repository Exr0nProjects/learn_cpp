#include <iostream>
#define ll long long

int main()
{
	int N, Q; scanf("%d%d", &N, &Q);
	ll *arr = new ll[N];
	for (int q=0; q<Q; ++q)
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

