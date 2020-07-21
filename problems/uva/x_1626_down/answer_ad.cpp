#include<bits/stdc++.h>
using namespace std;
int dp[111][111];
struct path{
	int x, y;
}a[111][111];
const int inf = 1000;
string str;
int dfs(int l, int r) {
	if (l > r) return 0;
	if (dp[l][r] != inf) return dp[l][r];
	int &ans = dp[l][r];
	if (str[l] == '(') {
		for (int i = l + 1; i <= r; i++) {
			if (str[i] == ')') {
				int t1 = dfs(l + 1, i - 1), t2 = dfs(i + 1, r);
				if (t1 + t2 < ans) {
					ans = t1 + t2;
					a[l][r] = {l, i};
				}
			}
		}
	}
	if (str[l] == '[') {
		for (int i = l + 1; i <= r; i++) {
			if (str[i] == ']') {
				int t1 = dfs(l + 1, i - 1), t2 = dfs(i + 1, r);
				if (t1 + t2 < ans) {
					ans = t1 + t2;
					a[l][r] = {l, i};
				}
			}
		}
	}
	int t1 = dfs(l + 1, r);
	if (t1 + 1 < ans) {
		ans = t1 + 1;
		a[l][r] = {l, l};
	}
	return ans;
}
void print(int x, int y) {
	if (x > y) return;
	int nx = a[x][y].x, ny = a[x][y].y;
	if (nx == ny) {
		if (str[nx] == '(' || str[nx] == ')') cout << "()";
		else cout << "[]";
		print(ny + 1, y);
	}
	else {
		print(x, nx - 1);
		cout << str[nx];
		print(nx + 1, ny - 1);
		cout << str[ny];
		print(ny + 1, y);
	}
}
int main() {
	//ifstream fin("in.txt");
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			for (int k = j; k < str.length(); k++) {
				dp[j][k] = inf;
				a[j][k] = {0, 0};
			}
		}
		dfs(0, str.length() - 1);
		/*for (int j = 0; j < str.length(); j++) {
			for (int k = j; k < str.length(); k++) {
				cout << dp[j][k] << ' ';
			}
			cout << endl;
		}
		for (int j = 0; j < str.length(); j++) {
			for (int k = j; k < str.length(); k++) {
				cout << a[j][k].x << ' ' << a[j][k].y << "  ";
			}
			cout << endl;
		}*/
		print(0, str.length() - 1);
		cout << endl;
	}
	return 0;
}

