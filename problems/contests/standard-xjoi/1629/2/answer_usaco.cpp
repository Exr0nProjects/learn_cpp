#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define ll long long
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
//map<S5, int> subsets;

map<array<ll, 5>, ll> cnt;

ll inc_exc[] = { -1, +1, -1, +1, -1, +1 };

ll N, pie[10];


int main()
{
    //ifstream fin("cowpatibility.in");
    cin >> N;
    for (int i=1; i<=N; ++i)
    {
        A[i].n = 5;
        for (int j=0; j<5; j++)
            cin >> A[i].v[j];
        sort(A[i].v, A[i].v+5);
        for (int x=1; x<32; x++) subsets[get_subset(A[i], x)]++;
    }

    long long answer = N * (N-1) / 2;
    for (auto &p : subsets)
    {
        answer -= inc_exc[p.first.n] * p.second * (p.second - 1) / 2;
        ans[p.first.n] += p.second*(p.second-1)/2;
    }

    for (int i=1; i<=5; ++i) printf("%d ", pie[i]);

    ll tot = N*(N-1)/2 - pie[1] + pie[2] - pie[3] + pie[4] - pie[5];
    printf("%lld\n", tot);
}

