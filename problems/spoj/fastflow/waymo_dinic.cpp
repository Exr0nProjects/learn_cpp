#include <bits/stdc++.h>

#define max_v 5100
#define LOGN 50
#define int_max (long long)0x3f3f3f3f3f
#define MXE 30010
#define ll long long
using namespace std;

ll graph[5100][5100], flow[max_v][max_v];
ll dep[max_v], vis[max_v];
ll head[max_v];
ll n, m, src, dest;
//vector<ll> adj[max_v];
//struct Edge { ll t, w, n; } eg[MXE<<1]; ll hd[max_v], ecnt=2;
//void addEdge(ll u, ll v, ll w)
//{
//    printf("addedge %d %d %d\n", u, v, w);
//    eg[ecnt] = { v, w, hd[u] };
//    hd[u] = ecnt++;
//}
//
//bool bfs(){
//    queue<ll> q;
//    q.push(src);
//    memset(dep, 0x3f, sizeof(dep));
//    memset(head, 0, sizeof(head));
//    dep[src] = 0;
//    while(!q.empty()){
//        ll u = q.front(); q.pop();
//        printf("bfs at %d\n", u);
//        if(u == dest) return 1;
//        //for(ll i : adj[u]){
//        for (int e=hd[u]; e; e=eg[e].n)
//        {
//            ll i = eg[e].t;
//            if(graph[u][i] - flow[u][i] > 0ll && dep[i] > (ll)n + 1){
//                dep[i] = dep[u] + 1;
//                q.push(i);
//            }
//        }
//    }
//
//    return 0;
//}
//
//long long dfs(ll u, long long cap){
//    printf("dfs at %d\n", u);
//    long long ans = 0ll;
//    if(u == dest || cap == 0ll) return cap;
//    //for(ll i = head[u]; i<adj[u].size(); i++){
//    for (int e=head[u]; e; e=eg[e].n)
//    {
//        ll v = eg[e].t;
//        //ll v = adj[u][i];
//        long long C = graph[u][v] - flow[u][v];
//        if(u != v && dep[v] == dep[u] + 1 && C > 0ll){
//            if(long long sent = dfs(v, min(cap, C))){
//                flow[u][v] += sent;
//                flow[v][u] -= sent;
//                ans += sent;
//                cap -= sent;
//            }
//        }
//        if (cap) head[u] = eg[e].n;
//        else break;
//    }
//    if(!ans) dep[u] = int_max;
//    return ans;
//}
//
//long long dinics(){
//    long long tot = 0ll;
//    while(bfs()){
//        long long sent = dfs(src, int_max);
//        tot += (long long)sent;
//    }
//    return tot;
//}

int main(){

    scanf("%d%d", &n, &m);
    src = 1, dest = n;
    while(m--){
        ll a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(!c) continue;
        printf("got %d %d %d (cur %d)\n", a, b, c, graph[1][2]);
        //if(!graph[a][b]){
        if(true){
            //addEdge(a, b, c);
            //addEdge(b, a, 0);
            //adj[a].push_back(b);
            //adj[b].push_back(a);
        }
        graph[a][b] += (long long)c;
        //graph[a][b] += 1;
        graph[b][a] += (long long)c;

    }

    //printf("%lld\n", dinics());
    return 0;
}
