/*
 * Problem 6 (tc2020/6)
 * Create time: Sat 25 Jul 2020 @ 14:16 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <bits/stdc++.h>
#define dl double

using namespace std;
const int MX = 30;

int N, S, T, cnt[MX];

int main()
{
    scanf("%d%d%d", &S, &T, &N);
    for (int i=0; i<N; ++i)
    {
        int s, t; scanf("%d%d", &s, &t);
        for (int j=max(S, s); j<min(T, t); ++j)
            ++cnt[j];
    }

    int tot=0;
    for (int i=0; i<30; ++i) tot += cnt[i];
    printf("%.0lf\n", (1-pow(0.98, tot))*100);
    //printf("%lf\n", 1-pow(0.98, tot));
    //for (int i=0; i<30; ++i) printf("%3d", cnt[i]); printf("\n");

	return 0;
}

