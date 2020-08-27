#include <bits/stdc++.h>
using namespace std;
void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
const int maxn = 200010;

int n, m;
int ans[maxn];
vector <int> edge[maxn];//edges going toward each disjoint set
vector <int> ds[maxn];//cows in each disjoint set
int f[maxn];//the disjoint set each cow is in
queue <int> q;//disjoint sets with more than 1 disjoint set pointing to it

void merge(int x, int y) {
    int fx = f[x], fy = f[y];
    for (int i = 0; i < ds[fy].size(); i++) {
        f[ds[fy][i]] = fx;
        ds[fx].push_back(ds[fy][i]);
    }
    edge[fx].insert(edge[fx].end(), edge[fy].begin(), edge[fy].end());
    edge[fy].clear();
}

int main() {
    scanf("%d%d", &n, &m);
    int x, y;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        edge[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        ds[i].push_back(i);
        if (edge[i].size() > 1) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (edge[cur].size() <= 1) {
            continue;
        }
        for (int i = 1; i < edge[cur].size(); i++) {
            if (f[edge[cur][0]] == f[edge[cur][i]]) continue;
            merge(edge[cur][0], edge[cur][i]);
        }
        edge[cur].erase(edge[cur].begin() + 1, edge[cur].end());
        if (edge[f[edge[cur][0]]].size() > 1) q.push(f[edge[cur][0]]);
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
        if (!ans[f[i]]) ans[f[i]] = c++;
        printf("%d\n", ans[f[i]]);
    }
}

