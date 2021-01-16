#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define rand(l,h) std::uniform_int_distribution<ll>(l,h)(rng)
std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

ll N = 2e2;
ll MX = 2e3;

int main()
{
    printf("%lld %lld\n", N, N*(N+1)/2);
    for (int i=1; i<=N; ++i) printf("%3lld", rand(1, MX)); printf("\n");
    for (int i=1; i<=N; ++i) for (int j=i; j<=N; ++j) printf("%d %d\n", i, j);

    return 0;
}

