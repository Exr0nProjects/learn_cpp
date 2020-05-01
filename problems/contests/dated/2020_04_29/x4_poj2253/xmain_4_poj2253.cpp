/*
TASK: 4_poj2253
LANG: C++14
*/

/*
 * Problem 4_poj2253 (contests/dated/2020_04_29/4_poj2253)
 * Create time: Thu 30 Apr 2020 @ 17:09 (PDT)
 * Accept time: Thu 30 Apr 2020 @ 17:23 (PDT)
 *
 */

#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;
const int MX = 211;
int x[MX], y[MX], N;

int djs[MX], djf[MX];
void init()
{
	for (int i=0; i<MX; ++i)
	{
		djs[i] = 1;
		djf[i] = i;
	}
}
int find(int n)
{
	if (djf[n] != n) djf[n] = find(djf[n]);
	return djf[n];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (djs[a] < djs[b])
		swap(a, b);
	djs[a] += djs[b];
	djf[b] = a;
}

inline double dist(int a, int b)
{ return sqrt(pow((double)x[a] - x[b], 2) + pow((double)y[a] - y[b], 2)); }
bool check(double len)
{
	init();
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			if (dist(i, j) <= len)
				merge(i, j);
	return find(0) == find(1);
}

int main()
{
	int kase=0;
	while (scanf("%d", &N))
	{
		if (!N) break;
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);

		for (int i=0; i<N; ++i) scanf("%d%d", &x[i], &y[i]);
		
		double l=0, r=1100;
		for (int i=0; i<100; ++i)
		{
			double m = (l+r)/2;
			if (check(m)) r = m;
			else l = m;
		}
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++kase, l);
	}

    return 0;
}

