/*
ID: spoytie2
TASK: loan
LANG: C++14
*/

/*
 * Problem loan (usaco/silver/2020jan/loan)
 * Create time: Sun 19 Jan 2020 @ 07:59 (PST)
 * Accept time: Sat 15 Feb 2020 @ 08:08 (PST)
 *
 */

#include <iostream>
#include <cstdio>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <chrono>
#include <utility>
#include <exception>
#include <algorithm>
#include <functional>

#define cn const int
#define ll long long
#define cl const long long
#define ca const auto &

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 0x7FFFFFFF

// for macro overloading, see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// this set is designed for one indexed collections
#define FOR_(i,b,e) for (int i=(b); i<(e); ++i)
#define FOR(i,e) FOR_(i,0,(e))
#define FORR_(i,b,e) for (int i=(e)-1; i>=(b); --i)
#define FORR(i,e) FORR_(i,0,e)
#define SORT(a,n) std::sort((a), (a)+(n))
#define TRAV(a,x) for (auto& a: x)
#define SORTV(v) std::sort((v).begin(), (v).end())

void setIO(const std::string &name="loan");

typedef struct {
    int f, t, w, n;
} Edge;
#define TRAVE(s,e) for (int e=head[s]; e; e=edges[e].n)

const int MX=1;
//#define __USING_EDGELIST
//void addEdge(cn a, cn b, cn w=1);
//Edge edges[MX*MX];
//int ect=1, head[MX];

using namespace std;
ll N, K, M;

bool sim(cl x)
{
    // https://www.youtube.com/watch?v=gaSGtzlumwA&feature=youtu.be&t=520
    ll days=0, given=0;
    while (days <= K && given <= N)
    {
        ll y = (N-given)/x;
        if (y < M)
        {
            return (K-days)*M >= N-given;
        }
        ll max_given = N-(x*y); // max value of given and still get the same value of y
        ll n_days = (max_given-given)/y +1; // n_days giving this y of milk - +1 because when max_given == given we still give for one day, and etc
        days += n_days;
        given += n_days*y;
    }
    return given >= N;
}

ll binarySearch(ll l, ll r) // include l, exclude r
{
    if (l+1 >= r) return l;
    ll m = (l+r)/2;
    if (sim(m)) return binarySearch(m, r);
    else return binarySearch(l, m);
}

int main()
{

    setIO();
    scanf("%lld%lld%lld", &N, &K, &M);

    // FOR(i, N+5) printf("%2d : %3d\n", i+1, sim(i+1));
    ll ans = binarySearch(1, N+10);
    // while (sim(ans+1)) ++ans;
    // while (!sim(ans)) --ans;
    printf("%lld\n", ans);

    return 0;
}

// boilerplate functions
void setIO(const string &name)
{
    ios_base::sync_with_stdio(0); cin.tie(0); // fast cin/cout
    if (fopen((name+".in").c_str(), "r") != nullptr)
    {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w+", stdout);
    }
}

#ifdef __USING_EDGELIST
void addEdge(cn a, cn b, cn w)
{
    edges[ect].f = a;
    edges[ect].t = b;
    edges[ect].w = w;
    edges[ect].n = head[a];
    head[a] = ect++;
}
#endif

/*
   Benjamin Qi
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
*/

/*
   thecodingwizard

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define SORT(vec) sort(vec.begin(), vec.end())

#define INF 1000000000
#define LL_INF 4500000000000000000
#define LSOne(S) (S & (-S))
#define EPS 1e-9
#define A first
#define B second
#define mp make_pair
#define pb push_back
#define PI acos(-1.0)
#define ll long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
*/
