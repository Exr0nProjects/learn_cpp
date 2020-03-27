// alex d
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n, a[5];
vector <int> v;
map <vector <int>, int> m[6];
void ins() {
	int len = v.size();
	m[len][v]++;
}
long long solve(int len, int sgn) {
	long long ans = 0;
    for (auto it = m[len].begin(); it != m[len].end(); it++) {
        long long num = it->s;
    	ans += num * (num - 1) / 2;
    // for (auto p : m[len]) {
        // ans += p.s * (p.s - 1) / 2;
	}
	return ans * sgn;
}
int main() {
    ifstream fin("cowpatibility.in");
    ofstream fout("cowpatibility.out");
	fin >> n;
	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < 5; j++) {
        	fin >> a[j];
    	}
    	sort(a, a + 5);
    	for (int j = 1; j < 32; j++) {
        	v.clear();
        	for (int k = 0; k < 5; k++) {
            	if ((1 << k) & j) v.push_back(a[k]);
        	}
        	ins();
    	}
	}
	int sgn = 1;
	long long ans = 0;
	for (int i = 1; i <= 5; i++) {
    	ans += solve(i, sgn);
    	sgn *= -1;
        printf("%lld (%d)\n", ans, sgn);
	}
	long long tot = (long long)n * (n - 1) / 2;
	fout << tot - ans;
}
