#include <bits/stdc++.h>
#define ll long long
#define cl const long long
using namespace std;

int arr[100];

ll sum(int arr[])
{
	ll ret = 0;
	for (int i=0; i<100; ++i)
	{
		ret += arr[i];
	}
	printf("sum is %d!\n", ret);
	return ret;
}
int main()
{
	printf("Hello world!");
	sum(arr);
	for (ll i=0; i<100; ++i)
	{
		arr[i] = i;
	}

	for (ll i=0; i<100; ++i)
	{
		printf("%3d\n", arr[i]);
	}

	return 0;
}
