#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#define ll long long
#define db(...) fprintf(stderr, __VA_ARGS__)
#define rand(l,h) (rng()%(h-l+1)+l)

const ll N = 2e1;
const ll P = 1e1;
//const ll N = 1e9;
//const ll P = 1e5;

bool vis[N][N];

int main()
{
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    //while (true) printf("%d\n", rand(1, 20));
    printf("%d %d\n", N, P);
    for (int i=1; i<=P; ++i)
    {
        ll x1, y1, x2, y2;
        do
            x1 = rand(0 , N), y1 = rand(0 , N),
            x2 = rand(x1, N), y2 = rand(y1, N),
            db("%d %d %d %d\n", x1, y1, x2, y2);
        while (!vis[x1][y1] && !vis[x2][y2]);
        //do db("%d %d %d\n", i, x1, y1), x1 = rand(0, N), y1 = rand(0, N); while (vis[x1][y1]);
        vis[x1][y1] = 1;
        //do db("%d %d %d\n", i, x2, y2), x2 = rand(x1, N), y2 = rand(y1, N); while (vis[x2][y2]);
        vis[x2][y2] = 1;
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }

    return 0;
}

