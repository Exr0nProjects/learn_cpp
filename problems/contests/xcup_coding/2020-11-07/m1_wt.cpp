#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>

using namespace std;

#define INF 1000000000

int n, m, x0, firsty, x2, y2;
int g[2000][2000];
int lo[2000][2000][2]; // down/up, l/r

bool inb(int a, int b) {return (a >= 0 && a < n && b >= 0 && b < m);}
vector<pair<int,int> > gethoriz(int a, int b) {
	vector<pair<int,int> > res;
	if (inb(a+1, b) && !g[a+1][b]) res.push_back(make_pair(a+1,b));
	if (inb(a-1, b) && !g[a-1][b]) res.push_back(make_pair(a-1,b));

	return res;
}
vector<pair<int,int> > getvert(int a, int b) {
	vector<pair<int,int> > res;
	if (inb(a, b+1) && !g[a][b+1]) res.push_back(make_pair(a,b+1));
	if (inb(a, b-1) && !g[a][b-1]) res.push_back(make_pair(a,b-1));
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		//string s; cin >> s;
		for (int j = 0; j < m; j++) {
			lo[i][j][0] = INF, lo[i][j][1] = INF;
			cin >> g[i][j];
		}
	}
	cin >> x0 >> firsty >> x2 >> y2;
	x0--; x2--; firsty--; y2--;

    if (x0 == x2 && firsty == y2) { printf("-1\n"); return 0; }

	lo[x0][firsty][0] = 0;
	lo[x0][firsty][1] = 0;

	queue<pair<int,int> > q;

	q.push(make_pair(x0, firsty));

	while (q.size()) {
		pair<int,int> p = q.front(); q.pop();

		int x = p.first, y = p.second;

		for (auto i : gethoriz(x, y)) {

			int cost2 = min(lo[x][y][0] + 1, lo[x][y][1]);

			if (lo[i.first][i.second][1] > cost2) {
				lo[i.first][i.second][1] = cost2;
				q.push(make_pair(i.first, i.second));
			}
		}

		for (auto i : getvert(x, y)) {
			int cost1 = min(lo[x][y][0], lo[x][y][1] + 1);
			//bool a = false;
			if (lo[i.first][i.second][0] > cost1) {

				lo[i.first][i.second][0] = cost1;
				q.push(make_pair(i.first, i.second));
			}

		}

	}

	int ans = min(lo[x2][y2][0], lo[x2][y2][1]);
	if (ans >= INF/2) ans = -1;
	cout << ans << endl;

}
