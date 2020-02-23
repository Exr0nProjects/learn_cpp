// From Teacher Yuan 25 Nov 2019, Slack
#include <bits/stdc++.h>
using namespace std;
struct tripint{
    int i;
    int j;
    int steps;
};
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};
int minstep[50][50] = {0};
int ways[50][50] = {0};
int ans = -1, numways = 0;
int main() {
    queue <tripint> q;
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cin >> a[i][j];
	    }
	}
	tripint t;
	t.i = 0;
	t.j = 0;
	t.steps = 0;
	q.push(t);
	minstep[t.i][t.j] = -1;
	ways[t.i][t.j] = 1;
	while (!q.empty()) {
	    tripint t0 = q.front();
	    q.pop();
	    t0.steps++;
	    for (int k = 0; k < 4; k++) {
	        t = t0;
	        int i1 = t.i + di[k];
	        int j1 = t.j + dj[k];
	        if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= n || a[i1][j1] == 1) {
	            continue;
	        }
            if (t.steps == minstep[i1][j1] || minstep[i1][j1] == 0) {
                ways[i1][j1] += ways[t.i][t.j];
	            t.i = i1;
	            t.j = j1;
	            if (minstep[i1][j1] == 0) {
	                q.push(t);
	            }
	            minstep[i1][j1] = t.steps;
	        }
	    }
	}
	cout << ways[n-1][n-1] << endl << minstep[n-1][n-1]+1 << endl;
} 

