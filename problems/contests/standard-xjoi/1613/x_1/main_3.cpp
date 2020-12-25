/*
 * Problem 1 (contests/standard-xjoi/1613/1)
 * Create time: Tue 25 Aug 2020 @ 16:21 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e5+11;

int N, c[MX], b[MX];
ll a[MX];
void update(int x)
{
    for (; x<=N; x+=x&-x)
        ++b[x];
}
ll query(int x)
{
    ll sum=0;
    for (; x; x-=x&-x)
        sum += b[x];
    return sum;
}

int main()
{
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w+", stdout);
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", c+i);
    for (int i=1; i<=N; ++i) c[i] += 1;
    //for (int i=1; i<=N; ++i) printf("%3d", c[i]); printf("\n");

    for (int i=1; i<=N; ++i)
    {
        update(c[i]);
        a[c[i]] += i-query(c[i]);   // FIX: equ--don't query c[i]-1 cuz we are doing subtraction -> insert to BIT then query directly
        //printf("a[%d] = %d\n", c[i], a[c[i]]);
    }

    ll tot=0;
    for (int i=0; i<N; ++i)
        printf("%lld\n", tot += a[i]);

	return 0;
}

