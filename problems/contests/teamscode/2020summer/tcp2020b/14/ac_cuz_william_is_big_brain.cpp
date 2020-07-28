/*

NUMBER 14

*/

#include <iostream>

using namespace std;

#define MAXN 110000


struct Node
{
	long long val, cmin, cmax;
	Node *l, *r;

	Node(long long v, long long lo, long long hi) {
		val = v;
		cmin = lo;
		cmax = hi;
		l = NULL;
		r = NULL;
	}
};

long long n, m;
long long bstart = 1;
long long inds[MAXN], arr[MAXN];
Node* pst[MAXN + 1];
Node* bit[MAXN + 1];

// builds the first pst, all nodes are 0
void buildz(Node* curr) {
	if (curr->cmin == curr->cmax) return;

	long long mid = (curr->cmin + curr->cmax) / 2;

	curr->l = new Node(0, curr->cmin, mid);
	curr->r = new Node(0, mid+1,      curr->cmax);

	buildz(curr->l);
	buildz(curr->r);
}

// builds other pst nodes
void build(Node* curr, Node* corresp, long long ind) {
	if (curr->cmin == curr->cmax) return;
	long long mid = (curr->cmin + curr->cmax) / 2;

	if (ind <= mid) {
		curr->l = new Node(corresp->l->val + 1, curr->cmin, mid);
		curr->r = corresp->r;
		build(curr->l, corresp->l, ind);
	}

	else {
		curr->r = new Node(corresp->r->val + 1,mid+1,curr->cmax);
		curr->l = corresp->l;
		build(curr->r, corresp->r, ind);
	}
}

// query functoin for pst and bit of pst nodes
long long query(Node* curr, long long minb, long long maxb) {
	if (!curr || curr->cmin > maxb || curr->cmax < minb) return 0;
	if (curr->cmin >= minb && curr->cmax <= maxb) return curr->val;
	return query(curr->l, minb, maxb) + query(curr->r, minb, maxb);
}

// builds a node for a st in the bit
void buildBITST(Node* curr, long long ind) {
	if (curr->cmin == curr->cmax) return;
	curr->val++;
	long long mid = (curr->cmin + curr->cmax) / 2;
	if (ind <= mid) {
		if (!curr->l)
			curr->l = new Node(0, curr->cmin, mid);
		buildBITST(curr->l, ind);
	}
	else {
		if (!curr->r)
			curr->r = new Node(0,mid+1,curr->cmax);
		buildBITST(curr->r, ind);
	}
}

// updates the bit using the buildBITST function
void updateBIT(long long num) {
	long long curr = inds[num];
	while (curr < MAXN) {
		if (!bit[curr])
			bit[curr] = new Node(0, 0, bstart);
		buildBITST(bit[curr], num);
		curr += (curr & -curr);
	}
}

long long bitQuery(long long curr, long long minb, long long maxb) {
	long long res = 0;
	while (curr > 0) {
		res += query(bit[curr], minb, maxb);
		curr -= (curr & -curr);
	}
	return res;
}

int main() {
	cin >> n >> m;

	while (bstart <= n) bstart *= 2;
	bstart = bstart - 1;

	pst[0] = new Node(0, 0, bstart);
	buildz(pst[0]);

	for (long long i = 0; i < n; i++) {
		long long elem; cin >> elem;
		arr[i] = elem;
		inds[elem] = i + 1;

		pst[i + 1] = new Node(i + 1, 0, bstart);

		build(pst[i + 1], pst[i], elem);
	}

	long long inv = 0;
	for (long long i = 0; i < n; i++) {
		inv += query(pst[i], arr[i], bstart);
	}

	//cout << inv << endl;


	for (long long i = 0; i < m; i++) {
		long long elem; cin >> elem;

		cout << inv << endl;
		updateBIT(elem);

		// nums that come before this elem in the array that cause inversions

		long long invCaused = query(pst[inds[elem] - 1], elem, bstart);
		invCaused -= bitQuery(inds[elem] - 1, elem, bstart);
		//cout << " " << invCaused << endl;
		// nums that come after
		invCaused +=  query(pst[n], 0, elem) - query(pst[inds[elem]], 0, elem);
		invCaused -= (bitQuery(n, 0, elem) - bitQuery(inds[elem], 0, elem));
		//cout << " " << invCaused << endl;

		inv -= invCaused;



	}

}


