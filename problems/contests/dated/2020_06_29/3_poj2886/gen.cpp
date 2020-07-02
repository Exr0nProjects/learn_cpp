#include <cstdio>
#include <cstdlib>
#define ll long long

inline ll r(ll a, ll b)
{ return rand() % (b-a+1) + a; }
//inline char c(string s)
//{ return s[r(0, s.length()-1)]; }

const ll T = 10;
//const ll N = 5e5;
//const ll MXM = 1e8;
const ll N = 460000;
const ll MXM = 1e8;

int main()
{
    for (ll i=0; i<T; ++i)
    {
        printf("%d %d\n", N, r(1, N));
        for (ll j=0; j<N; ++j)
            printf("%d %d\n", r(1, MXM), (r(0, 1)*2-1)*(r(1, MXM)));
    }
}

