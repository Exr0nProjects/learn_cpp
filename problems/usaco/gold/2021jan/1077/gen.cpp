#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define rand(l,h) std::uniform_int_distribution<ll>(l,h)(rng)
std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());

ll N = 8;
char clo = 'a', chi = 'c';

int main()
{
    for (int i=1; i<=N; ++i) printf("%c", rand(clo, chi));
    printf("\n");

    return 0;
}

