/*
 * Problem 6 (tcp2020/6)
 * Create time: Sun 19 Jul 2020 @ 09:22 (PDT)
 * Accept time: Sun 19 Jul 2020 @ 09:27 (PDT)
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
const ll MX = -1;

int main()
{
    int head, feet;
    scanf("%d%d", &head, &feet);
    int rabbit = feet/2 - head;
    printf("%d\n%d\n", head-rabbit, rabbit);

	return 0;
}

