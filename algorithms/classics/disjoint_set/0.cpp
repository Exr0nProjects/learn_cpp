#include <iostream>

using namespace std;
const int MX = 1000111;

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
	if (djs[a] < djs[b]) swap(a, b);
	djs[a] += djs[b];
	djf[b] = a;
}

int main()
{
	init();
	int M;
	scanf("%*d%d", &M);
	int x, y, z;
	for (int i=0; i<M; ++i)
	{
		scanf("%d%d%d", &z, &x, &y);
		//printf("%d %d\n", x, y);
		if (z == 1) merge(x, y);
		if (z == 2) printf("%c\n", find(x) == find(y) ? 'Y' : 'N');
	}
}

