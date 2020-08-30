#include <iostream>
using namespace std;

main() {

	int n, x, i, j; cin >> n >> x;
	int w[2*n], d[x+1] = {0};

	for (int &k: w) cin >> k;

	for (i = 0; i < n; i++)
		for (j = x; j >= w[i]; j--)
			d[j] = max(d[j], d[j - w[i]] + w[i+n]);

	cout << d[x];
}

