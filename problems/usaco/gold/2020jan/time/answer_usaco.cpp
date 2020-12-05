#include <bits/stdc++.h>
#define ll long long
#define _gc getchar_unlocked
inline bool sc(ll &n)
{
    int neg = 1;
    register char c;
    do c = _gc(); while (isspace(c));
    if (c == '-') neg = -1, c = _gc();
    for (n=0; c >= '0' && c <= '9'; c=_gc())
        (n *= 10) += (c-'0');
    n *= neg;
    return c != EOF;
}
inline ll sc() { ll x; sc(x); return x; }
#define _ilb inline bool
_ilb sc(int&a){ll x;bool b=sc(x);a=x;return b;}
_ilb sc(int&a,int&b){return sc(a)&&sc(b);}
_ilb sc(int&a,int&b,int&c){return sc(a,b)&&sc(c);}
_ilb sc(int&a,int&b,int&c,int&d){return sc(a,b)&&sc(c,d);}
_ilb sc(ll&a,ll&b){return sc(a)&&sc(b);}
_ilb sc(ll&a,ll&b,ll&c){return sc(a,b)&&sc(c);}
_ilb sc(ll&a,ll&b,ll&c,ll&d){return sc(a,b)&&sc(c,d);}
ll gcd(ll a, ll b) { while (b^=a^=b^=a%=b); return a; }
using namespace std;
//const int MX = 1e3+11;
const int MX = 10+11;
struct Edge { int f, t, n; } eg[MX<<2]; int hd[MX], ecnt=2;
void addEdge()
{
    // insert edges backwards
    int u = sc(); int v = sc();
    eg[ecnt].f = v;
    eg[ecnt].t = u;
    eg[ecnt].n = hd[v];
    //eg[ecnt] = { v, u, hd[v] };
    //printf("pre %d : %d -> %d\n", ecnt, eg[ecnt].f, eg[ecnt].t);
    hd[v] = ecnt++;
}

ll N, M, C, m[MX];
ll dp[MX][MX], ans=0;  // day, city

vector<pair<int, int>> edges;

int main() {
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    //cin >> N >> M >> C;
    sc(N, M, C);

    for (int i=1; i<=N; ++i) sc(m[i]);
    //for (int i = 1; i <= N; i++) {
    //    cin >> m[i];
    //}
    //int a, b;
    //for (int i = 0; i < M; i++) {
    //    cin >> a >> b;
    //    edges.push_back(make_pair(a, b));
    //}
    for (int i=1; i<=M; ++i) addEdge();
    memset(dp, -1, sizeof dp);
    dp[0][1] = 0;

    for (int i=1; i<MX; ++i)
    {
        //int p = t % 2;
        //memset(dp[p], -1, sizeof dp[p]);
        //for (auto& e : edges) {
        for (int e=2; e<ecnt; ++e)
        {
            int a = eg[e].t;
            int b = eg[e].f;
            printf("%d -> %d\n", a, b);
            if (dp[i-1][a] >= 0)
                dp[i][b] = max(dp[i][b], dp[i-1][a] + m[b]);
            //if (dp[i-1][a] >= 0)
            //    dp[i][b] = max(dp[i][b], dp[i-1][a] + m[b]);

        }
        //for (int e=2; e<ecnt; ++e)
        //{
        //    int a = eg[e].t;
        //    int b = eg[e].f;
        //    printf("%d -> %d\n", a, b);
        //    if (dp[i-1][a] >= 0)
        //        dp[i][b] = max(dp[i][b], dp[i][a] + m[b]);
        //}
        //printf("%d\n", dp[p][1] - C*t*t);
        //printf("%d - %d = %d\n", dp[t][1], C*t*t, dp[t][1] - C*t*t);
        ans = max(ans, dp[i][1] - C * i * i);
    }
    cout << ans << "\n";
}

