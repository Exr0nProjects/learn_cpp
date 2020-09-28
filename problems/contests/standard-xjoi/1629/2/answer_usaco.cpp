#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <array>
#define ll long long

#define f first
#define s second
using namespace std;


//// a set of up to 5 ints
//struct S5 {
//    int n;
//    int v[5]; // zero-pad if not used
//};
//
//S5 A[100000];
//
//bool operator< (const S5 &a, const S5 &b)
//{
//    for (int j=0; j<5; j++) {
//        if (a.v[j] < b.v[j]) return true;
//        if (a.v[j] > b.v[j]) return false;
//    }
//    return false;
//}
//
//S5 get_subset(S5 &a, int x)
//{
//    S5 result = { 0, {0,0,0,0,0} };
//    for (int j=0; j<5; j++)
//        if ((1<<j)&x) result.v[result.n++] = a.v[j];
//    return result;
//}
//

typedef pair<array<ll, 5>, int> S5;

map<S5, int> subsets;
S5 get_subset(S5 &a, int x)
{
    //S5 result = mp(array<ll, 5>{}, 0);
    S5 result;
    for (int j=0; j<5; j++)
        if ((1<<j)&x) result.f[result.s++] = a.f[j];
    return result;
}

//map<array<ll, 5>, ll> cnt;

ll inc_exc[] = { -1, +1, -1, +1, -1, +1 };

ll N, pie[10];

S5 A[100000];


int main()
{
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w+", stdout);
    //ifstream fin("cowpatibility.in");
    cin >> N;
    for (int i=1; i<=N; ++i)
    {
        A[i].s = 5;
        for (int j=0; j<5; j++)
            cin >> A[i].f[j];
        sort(A[i].f.begin(), A[i].f.end());
        for (int x=1; x<32; ++x)
        {
            subsets[get_subset(A[i], x)]++;
        }
    }

    long long answer = N * (N-1) / 2;
    for (auto &p : subsets)
    {
        answer -= inc_exc[p.first.s] * p.second * (p.second - 1) / 2;
        pie[p.first.s] += p.second*(p.second-1)/2;
    }

    //for (int i=1; i<=5; ++i) printf("%d ", pie[i]);

    ll tot = N*(N-1)/2 - pie[1] + pie[2] - pie[3] + pie[4] - pie[5];
    printf("%lld\n", tot);
}

