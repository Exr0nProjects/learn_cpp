// 14 May 2020

#include <iostream>
#include <numeric>
using namespace std;

const int MX = 100111;
const int LOGMX = 30;
int N, table[MX][LOGMX];

void build_table()
{
	scanf("%d", &N);
	memset(table, 0x3f, sizeof table);
	for (int i=0; i<N; ++i)
		scanf("%d", &table[i][0]);

	for (int j=1; j<(int)log2(N) +1; ++j) // FIX: start from 1, j=0 already done
		for (int i=0; i<N; ++i)
			if (i + (1<<j) <= N) // le because both are exclude right
				table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]); // FIX: i+2**(j-1) not 2**j 
}

int query(int lhs, int rhs) // incl left, excl right
{
	//printf("querying %d.. %d\n", lhs, rhs);
	int pow = log2(rhs-lhs);
	//printf("    pow: %d\n    %d..%d and %d..%d\n", pow, lhs, lhs+(1<<pow), rhs-(1<<pow), rhs);
	return min(table[lhs][pow], table[rhs-(1<<pow)][pow]);
}

int main()
{
	build_table();
	int Q;
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
}

