#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
#define MAXK 100010
int n, k, ranks[MAXK], lcp[MAXK];
char str[MAXK];
int aux1[MAXK], aux2[MAXK], aux3[MAXK], aux4[MAXK];
int second(int ind, int c) {
	if (ind + c/2 >= n) return 0;
	return ranks[ind + c/2];
}
void compsuff() {
	for (int i = 0; i < n; i++) ranks[i] = str[i];
	int iter = max(n + 10, 130);

	for (int c = 2; c / 2 <= n; c *= 2) {
		for (int i = 0; i < iter; i++) {aux1[i] = 0; aux4[i] = 0;}
		for (int i = 0; i < n; i++) {aux1[second(i, c) + 1]++; aux4[ranks[i] + 1]++;}
		for (int i = 1; i < iter; i++) {aux1[i] += aux1[i - 1]; aux4[i] += aux4[i - 1];}
		for (int i = 0; i < n; i++) aux2[aux1[second(i, c)]++] = i;
		for (int i = 0; i < n; i++) aux3[aux4[ranks[aux2[i]]]++] = aux2[i];
		int curr = 1;
		for (int i = 0; i < n; i++) {
			if (i > 0 && second(aux3[i - 1], c) == second(aux3[i], c) && ranks[aux3[i - 1]] == ranks[aux3[i]]) curr--;
			aux2[aux3[i]] = curr++;
		}
		for (int i = 0; i < n; i++) ranks[i] = aux2[i];
	}
}
int bruteforce(int ind1, int ind2, int start) {
	int curr = max(start, 0);
	for (; ind1 + curr <= n && ind2 + curr <= n && str[ind1 + curr] == str[ind2 + curr]; curr++);
	return max(0, curr);
}
void complcp() {
	for (int i = 0; i < n; i++) {
		if (ranks[i] - 1 == 0) lcp[ranks[i] - 1] = 0;
		else lcp[ranks[i] - 1] = bruteforce(i, aux3[ranks[i] - 1 - 1], (i == 0) ? 0 : lcp[ranks[i - 1] - 1] - 1);
	}
}
int main() {
	int t; scanf("%d", &t);
	for (int c = 0; c < t; c++) {
		scanf("%d%s", &k, str);
		n = strlen(str);
		compsuff();
		complcp();
		multiset<int> curr;
		if (k > n) printf("%d\n", 0);
		else {
			for (int i = 0; i < k - 1; i++)
				curr.insert(lcp[i]);
			int ans = 0;
			for (int i = k - 1; i < n; i++) {
				int lo = *curr.begin();
				if ((i - k < 0 || lcp[i - k] < lo) && (lcp[i] < lo))
					ans += lo - max((i-k < 0)?0:lcp[i-k], lcp[i]);

				curr.erase(curr.find(lcp[i-k+1]));
				curr.insert(lcp[i]);
			}
			if (n - k < 0 || lcp[n - k] < *curr.begin())
				ans += *curr.begin() - ((n-k < 0)?0:lcp[n-k]);

			printf("%d\n", ans);
		}
	}
}

