// xy, class 12 may 2020

#include<iostream>
void init(int n, int a[], int d[]) {
	for (int i = 0; i < n; ++i) d[i][0] = a[i];
    // d(i, j) = min out of interval [i, i + 2^j]
	for (int j = 1; (1 << j) <= n; +j)
		for (int i = 0; i + (1 << j) - 1 < n; ++i)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}
int static_rmq(int L, int R) {
	int k = 0;  // find the max k so that 2^k <= R-L+1
	while ((1 << (k+1)) <= R - L + 1) ++k;
	return min(d[L][k], d[R-(1<<k)+1][k]);
}

