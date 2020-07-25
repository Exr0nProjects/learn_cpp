/*
 * Problem 9 (tc2020/9)
 * Create time: Sat 25 Jul 2020 @ 14:27 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int MX = 1e6+100;
int N, delta[MX];

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
    {
        int l, r; scanf("%d%d", &l, &r);
        ++delta[l], --delta[r+1];
    }
    int id=0;
    for (int i=0; i<MX; ++i)
    {
        delta[i+1] += delta[i];
        if (delta[id] < delta[i])
            id = i;
    }
    printf("%d\n", id);

	return 0;
}

