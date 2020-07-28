/*
 * Problem 8 (tcp2020/8)
 * Create time: Sun 19 Jul 2020 @ 09:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ll long long
#define dl double

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define lr tl, (tl+((tr-tl)>>1))
#define rr (tl+((tr-tl)>>1)+1), tr

using namespace std;
//const ll MX = 1000111;
const int MX = 1000111;

bool primes[MX];
int count[MX];

int main()
{
    int cnt =0;
    for (int i=2; i<MX; ++i)
    {
        if (!primes[i])
        {
            ++cnt;
            for (int j=0; i*j<MX; ++j)
                primes[i*j] = 1;
        }
        count[i] = cnt;
        //printf("%3d: %d\n", i, cnt);
    }

    int cs;
    scanf("%d", &cs);
    while (cs--)
    {
        int d; scanf("%d", &d);
        printf("%d\n", count[d]);
    }

	return 0;
}

