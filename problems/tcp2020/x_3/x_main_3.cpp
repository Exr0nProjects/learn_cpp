/*
 * Problem 3 (tcp2020/3)
 * Create time: Sun 19 Jul 2020 @ 09:20 (PDT)
 * Accept time: Sun 19 Jul 2020 @ 09:25 (PDT)
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
    char buf[10];
    scanf("%s", buf);
    for (int i=2; i>=0; --i) if (i<2 || buf[i] != '0') printf("%c", buf[i]);
    printf("\n");
	return 0;
}

