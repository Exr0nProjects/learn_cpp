#include <iostream>

using namespace std;


#define N 300000

struct Node
{
	int val;
	int cmin, cmax;
	Node* left, *right;

	void create(int v, int lo, int hi) {
		val = v;
		cmin = lo;
		cmax = hi;
		left = nullptr;
		right = nullptr;
	}
};

int n, q;
int arr[N + 1];
Node* freq_from_zero[N + 1];
int stsize, bstart;

int query(Node* curr, int minb, int maxb) {
	if (curr->cmin > maxb or curr->cmax < minb) return 0;
	if (curr->cmin >= minb and curr->cmax <= maxb) return curr->val;
	return (query(curr->left, minb, maxb) +
			query(curr->right,minb, maxb));
}



void update(int ind1, int num) {
	int cmin = 0, cmax = bstart;

	Node* corresp = freq_from_zero[ind1 - 1];

	freq_from_zero[ind1] = new Node;
	freq_from_zero[ind1]->create((corresp->val + 1), 0, bstart);
	Node* curr = freq_from_zero[ind1];

	while (cmin != cmax) {
		int mid = (cmin + cmax) / 2;
		if (num <= mid) {
			curr->right = corresp->right;
			curr->left = new Node;
			curr->left->create((1 + corresp->left->val), cmin, mid);
			curr = curr->left;
			corresp = corresp->left;
			cmax = mid;
		}
		else {
			curr->left = corresp->left;
			curr->right = new Node;
			curr->right->create((1 + corresp->right->val), mid + 1, cmax);
			curr = curr->right;
			corresp = corresp->right;
			cmin = mid + 1;
		}
	}
}


// initializes the segment tree to all zero
void init_st(Node* curr) {
	if (curr->cmin == curr->cmax) return;
	int mid = (curr->cmin + curr->cmax) / 2;
	curr->left = new Node;
	curr->left->create(0, curr->cmin, mid);
	curr->right = new Node;
	curr->right->create(0, mid + 1, curr->cmax);

	init_st(curr->left);
	init_st(curr->right);
}

int ans(Node* lo, Node* hi, int minapp) {
	int cmin = lo->cmin, cmax = lo->cmax;
	if ((hi->val - lo->val) <= minapp) return 999999;
	if (lo->cmin == lo->cmax) return lo->cmin;
	return min(ans(lo->left, hi->left, minapp),
			   ans(lo->right,hi->right,minapp));
}

int ans(int lo, int hi, int k) {
	int minapp = (hi - lo + 1) / k;
	//cout << " " << minapp << endl;
	int res = ans(freq_from_zero[lo - 1], freq_from_zero[hi], minapp) + 1;
	if (res >= 500000) return -1;
	return res;
}

int main() {
	scanf("%d%d", &n, &q);

	stsize = 1;
	while (stsize < n)
		stsize *= 2;
	bstart = stsize - 1;
	stsize *= 2; stsize--;

	freq_from_zero[0] = new Node;
	freq_from_zero[0]->create(0, 0, bstart);


	init_st(freq_from_zero[0]);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i]--;
		update(i, arr[i]);
	}
	for (int i = 0; i < q; i++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", ans(l, r, k));
	}
}

