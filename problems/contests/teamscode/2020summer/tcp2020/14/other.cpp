/*

prob 14

*/
#include <iostream>
#include <iomanip>
#include <list>
#include <set>
using namespace std;
#define INF 10e16
#define ld long double
struct Edge
{
    int e, cost;

    Edge(int _e, int _c) {
        e = _e;
        cost = _c;
    }
};
int n, m;
list<Edge> graph[3000];
long double cost[3000];
bool visited[3000];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        cost[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int n1, n2, c; cin >> n1 >> n2 >> c;
        --n1; --n2;
        graph[n1].push_back(Edge(n2, 100-c));
        graph[n2].push_back(Edge(n1, 100-c));
    }
    int a, b;
    cin >> a >> b;
    --a, --b;
    for (int i = 0; i < n; i++)
        cost[i] = INF;
    cost[b] = 100.0;
    for (int c = 0; c < n; c++) {
        int minelem = -1;
        ld val = INF + 1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && cost[i] <= val) {
                minelem = i;
                val = cost[i];
            }
        }

        visited[minelem] = true;
        //for (Edge e : graph[minelem]) {
        for (list<Edge>::iterator it = graph[minelem].begin(); it != graph[minelem].end(); ++it) {
            Edge e = *it;
            if (visited[e.e]) continue;
            ld thiscost = cost[minelem] * 100.0 / (ld) e.cost;
            if (thiscost < cost[e.e])
                cost[e.e] = thiscost;
        }

    }
    cout.precision(8);
    cout << fixed << cost[a] << endl;
}

