// Class on 12 May 2020

#include <iostream>
#include <climits>
//*****************************************************************************
// Point update, range query
const int MAXN = 1 << 17;
int n;
int t[2 * MAXN - 1];
void init(int _n) {
	n = 1;
	while (n < _n) n *= 2;  // capture the smallest power of 2 > n
	for (int i = 0; i < 2 * n - 1; ++i)
		t[i] = INT_MAX;
}
// update k-th(0-based) with v
void update(int k, int v) {
	k += n - 1;  // start from leaf, get [k, k]'s index
	t[k] = v;
	while (k > 0) {
   	    int lc = k * 2 + 1, rc = k * 2 + 2;
		k = (k - 1) / 2; // parent
		t[k] = min(t[lc], t[rc]);
	}
}
// query for min out of [a, b)
int query_helper(int qL, int qR, int k, int L, int R) {
	if (r <= qL || qR <= L) return INT_MAX;  // invalid interval
	if (qL <= L && R <= qR) return t[k];
	int mid = L + (R - L) / 2;
	int lc = k * 2 + 1;
	int rc = k * 2 + 2;
	return min(
	           query_helper(qL, qR, lc, L, mid),
	           query_helper(qL, qR, rc, mid + 1, R));
}
int query(int qL, int qR) {
	return query_helper(qL, qR, 0/*=k*/, 0/*=L*/, n/*=R*/);
}
//*****************************************************************************
// Range update, range query
//
void update_helper(int qL, int qR, int v, int k, int L, int R) {
	if (R < L) return;
	int lc = k * 2 + 1, rc = k * 2 + 2;
	if (qL <= L && qR >= R) {
		addv[k] += v;
	} else {
		int mid = L + (R - L) / 2;
		update_helper(qL, qR, v, lc, qL, mid);
		update_helper(qL, qR, v, rc, mid, qR);
	}
}
void update(int qL, int qR, int v) {
	return update_helper(qL, qR, v, 0/*=k*/, 0/*=L*/, n/*=R*/);
}
// helper for query()
// add means the sum of add label from the root
void query_helper(int qL, int qR, int k, int L, int R, int add) {
	if (L > R) return INT_MAX;
	int lc = k * 2 + 1, rc = k * 2 + 2;
	if (qL <= L && qR >= R) {
		min_ = min(min_, minv[k] + add);
	} else {
		int mid = L + (R - L) / 2;
		query_helper(qL, qR, lc, L, mid, add + addv[k]);
		query_helper(qL, qR, rc, mid + 1, R, add + addv[k]);
	}
}
// query(qL, qR) for min, max or sum
void query(int qL, int qR) {
	return query_helper(qL, qR, 0/*=k*/, 0/*=L*/, n/*=R*/, 0/*=add*/);
}

