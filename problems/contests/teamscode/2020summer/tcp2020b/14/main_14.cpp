/*

   william, 20 pts
NUMBER 14

*/

#include <iostream>

using namespace std;

#define MAXN 120000


struct Node
{
	int val, cmin, cmax;
	Node *l, *r;

	Node(int v, int lo, int hi) {
		val = v;
		cmin = lo;
		cmax = hi;
		l = NULL;
		r = NULL;
	}
};

int n, m;

int inds[MAXN], arr[MAXN];
Node* pst[MAXN];
Node* bit[MAXN];

// builds the first pst, all nodes are 0
void buildz(Node* curr) {
	if (curr->cmin == curr->cmax) return;

	int mid = (curr->cmin + curr->cmax) / 2;

	curr->l = new Node(0, curr->cmin, mid);
	curr->r = new Node(0, mid+1,      curr->cmax);

	buildz(curr->l);
	buildz(curr->r);
}

// builds other pst nodes
void build(Node* curr, Node* corresp, int ind) {
	if (curr->cmin == curr->cmax) return;
	int mid = (curr->cmin + curr->cmax) / 2;

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
int query(Node* curr, int minb, int maxb) {
	if (!curr || curr->cmin > maxb || curr->cmax < minb) return 0;
	if (curr->cmin >= minb && curr->cmax <= maxb) return curr->val;
	return query(curr->l, minb, maxb) + query(curr->r, minb, maxb);
}

// builds a node for a st in the bit
void buildBITST(Node* curr, int ind) {
	if (curr->cmin == curr->cmax) return;
	curr->val++;
	int mid = (curr->cmin + curr->cmax) / 2;
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
void updateBIT(int num) {
	int curr = inds[num];
	while (curr <= MAXN) {
		if (!bit[curr])
			bit[curr] = new Node(0, 0, MAXN);
		buildBITST(bit[curr], num);
		curr += (curr & -curr);
	}
}

int bitQuery(int curr, int minb, int maxb) {
	int res = 0;
	while (curr > 0) {
		res += query(bit[curr], minb, maxb);
		curr -= (curr & -curr);
	}
	return res;
}

int main() {
	cin >> n >> m;

	pst[0] = new Node(0, 0, MAXN);
	buildz(pst[0]);

	for (int i = 0; i < n; i++) {
		int elem; cin >> elem;
		arr[i] = elem;
		inds[elem] = i + 1;

		pst[i + 1] = new Node(i + 1, 0, MAXN);

		build(pst[i + 1], pst[i], elem);
	}

	long long inv = 0;
	for (int i = 0; i < n; i++) {
		inv += query(pst[i], arr[i], MAXN);
	}

	//cout << inv << endl;


	for (int i = 0; i < m; i++) {
		int elem; cin >> elem;

		cout << (inv) << endl;

		// nums that come before this elem in the array that cause inversions
		int invCaused = query(pst[inds[elem] - 1], elem, MAXN);
		invCaused -= bitQuery(inds[elem] - 1, elem, MAXN);
		//cout << " " << invCaused << endl;
		// nums that come after
		invCaused +=  query(pst[n], 0, elem - 1) - query(pst[inds[elem]], 0, elem - 1);
		invCaused -= (bitQuery(n, 0, elem - 1) - bitQuery(inds[elem], 0, elem - 1));
		//cout << " " << invCaused << endl;

		inv -= invCaused;

		updateBIT(elem);


	}


}


