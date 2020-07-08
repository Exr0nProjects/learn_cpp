/*
 * Problem 1882 (poj/1882)
 * Create time: Wed 08 Jul 2020 @ 09:50 (PDT)
 * Accept time: [!meta:end!]
 *
 *  This is just UVA 242
 *  except with freaking presentation error
 */


/*
 * Problem 6_uva242 (contests/dated/2020_07_07/6_uva242)
 * Create time: Tue 07 Jul 2020 @ 15:46 (PDT)
 * Accept time: Tue 07 Jul 2020 @ 16:07 (PDT)
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

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
const ll MX = 1011;
int N, S, M, stamps[MX], best[MX], best_size, best_max;

int tab[MX];
int find_max()
{
    //printf("stamps: "); for (int i=0; i<M; ++i) printf("%3d", stamps[i]); printf("\n");
    memset(tab, 0, sizeof tab);
    int i=1;
    for (; i<MX; ++i)
    {
        int mn = 1<<20;
        for (int j=0; j<M; ++j) if (stamps[j] <= i)
        {
            mn = min(mn, tab[i-stamps[j]]);
            //printf("    got %d (%d) from %d (%d) + %d\n", i, mn, i-stamps[j], tab[i-stamps[j]], stamps[j]);
        }
        tab[i] = mn+1;  // minimum stamps + 1 stamp to get to this price
        if (tab[i] > S) break;
        //printf("\n");
    }
    return i-1;
}

int main()
{
    while (scanf("%d", &S) && S)
    {
        best_size = 1<<20;
        best_max = 0;
        memset(best, 0x3f, sizeof best);
        scanf("%d", &N);
        for (int i=0; i<N; ++i)
        {
            memset(stamps, 0, sizeof stamps);
            scanf("%d", &M);
            for (int j=0; j<M; ++j) scanf("%d", &stamps[j]);
            int cur_max = find_max();
            //printf("max: %d\n", cur_max);
            bool should_replace = cur_max > best_max || (cur_max == best_max && M < best_size);
            if (!should_replace && cur_max == best_max && M == best_size)
                for (int j=M-1; j>=0; --j) if (stamps[j] != best[j])
                {
                    if (stamps[j] < best[j]) should_replace = 1;
                    break;
                }
            if (should_replace)
            {
                //printf("replacing!\n");
                memcpy(best, stamps, MX*sizeof(int));   // FIX: function args, good thing i looked them up
                best_size = M;
                best_max = cur_max;
            }
        }
        printf("max coverage = %2d :", best_max);
        for (int j=0; j<best_size; ++j) printf(" %d", best[j]);
        printf("\n");
    }
    printf("\n");

	return 0;
}

