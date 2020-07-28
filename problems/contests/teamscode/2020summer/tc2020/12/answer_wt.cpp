#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define pint pair<int,int>
#define f first
#define s second

int n, c;
int grid[55][55];
int maxval[55][55];
bool visited[55][55];

bool check(int a) {
    return true;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            maxval[i][j] = -99999;
            visited[i][j] = false;
        }
    }

    maxval[0][0] = c;

    queue<pint > bfs;
    bfs.push(make_pair(0, 0));
    // cout << bfs.size() << endl;
    while (bfs.size() > 0) {
        pint f = bfs.front(); bfs.pop();

        int r = f.f, c = f.s;
        if (visited[r][c]) continue;
        if (r + 1 < n) {
            maxval[r+1][c] = max(maxval[r+1][c], maxval[r][c] + grid[r+1][c]);
            if (check(maxval[r+1][c]))
                bfs.push(make_pair(r+1,c));
        }
        if (c + 1 < n) {
            maxval[r][c+1] = max(maxval[r][c+1], maxval[r][c] + grid[r][c+1]);
            if (check(maxval[r][c+1]))
                bfs.push(make_pair(r,c+1));
        }
        visited[r][c] = true;
    }

    cout << maxval[n-1][n-1] << endl;

}

