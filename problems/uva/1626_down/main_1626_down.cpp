/*
 * Problem 1626_down (uva/1626_down)
 * Create time: Sat 18 Jul 2020 @ 09:01 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define maxn 1005

using namespace std;
//string S;
char S[maxn];
int dp[maxn][maxn];
int from[maxn][maxn];

bool match(int i, int j)
{
    if (S[i] == '(' && S[j] == ')') return true;
    if (S[i] == '[' && S[j] == ']') return true;
    return false;
}

void print(int l, int r)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: %d\n", l, r, from[l][r]);
    if (l == r)
    {
        if (S[l] == '(' || S[l] == ')') printf("()");
        else printf("[]");
        return;
    }
    else if (match(l, r) && dp[l][r] == dp[l+1][r-1])
    //else if (from[l][r] < 0)
    {
        printf("%c", S[l]);
        print(l+1, r-1);
        printf("%c", S[r]);
        return;
    }
    for (int k=l; k<r; ++k)
    {
        if (dp[l][r] == dp[l][k] + dp[k+1][r])
        {
            //int k = from[l][r];
            //if (k < l) { printf("uh %d %d, %d\n", l, r, k); return; }
            //{
            print(l, k);
            print(k+1, r);
            break;
            //}
        }
    }
}

int main()
{
    int cs;
    scanf("%d", &cs);
    getchar();
    while (cs--)
    {
        //memset(from, 0, sizeof from);
        //memset(dp, 0, sizeof dp); // FIX: typo--sizeof dp not sizeof from
        //memset(s, 0, sizeof s);

        //scanf("\n");
        getchar();  // FIX: getchar() not scanf("\n");
        int N;
        for (N=1;; ++N)
        {
            S[N] = getchar();
            if (S[N] == '\n')
            {
                S[N] = '\0';
                break;
            }
            //printf("%d : %c\n", len, s[len]);
        }
        --N;
        //printf("len %d\n", N);
        //cin >> S;
        //int N = S.size();

        for (int i=0; i<=N; ++i) dp[i][i] = 1;

        for (int ln=1; ln<=N; ++ln)
            for (int l=0, r=l+ln; r<=N; ++l, ++r)
            {
                //printf("%d..%d\n", l, r);
                int ret=dp[l][l]+dp[l+1][r], split = l;
                for (int k=l+1; k<r; ++k)
                    if (ret > dp[l][k] + dp[k+1][r])
                        ret = dp[l][k] + dp[k+1][r], split = k;
                if (match(l, r) && ret > dp[l+1][r-1])
                    split = -1,    ret = dp[l+1][r-1];
                dp[l][r] = ret;
                from[l][r] = split;
            }

        //for (int i=0; i<20; ++i) { for (int j=0; j<20; ++j) dps[i][j] ? printf("%3d", dps[i][j]) : printf("  ."); printf("\n"); } printf("\n");
        //for (int i=0; i<20; ++i) { for (int j=0; j<20; ++j) dp[i][j] ? printf("%3d", dp[i][j]) : printf("  ."); printf("\n"); }

        print(1, N);

        printf("\n");
        if (cs) printf("\n");
    }

	return 0;
}

