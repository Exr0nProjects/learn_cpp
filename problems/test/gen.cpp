#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define rand(l,h) std::uniform_int_distribution<ll>(l,h)(rng)

std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    printf("%lld\n", rand(1, (ll)1e9));

    return 0;
}

