#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define rand(l,h) std::uniform_int_distribution<ll>(l,h)(rng)
std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

ll N = 1e5;
ll M = 1e4;
ll MX = 2e9;

int main()
{
    printf("%lld %lld\n", N, M);
    for (int i=1; i<=N; ++i) printf("%3lld ", rand(1, MX)); printf("\n");
    //for (int i=1; i<=N; ++i) for (int j=i; j<=N; ++j) printf("%d %d\n", i, j);
    for (int i=1; i<=M; ++i) printf("%lld %lld\n", rand(1, N), rand(1, N));

    return 0;
}

