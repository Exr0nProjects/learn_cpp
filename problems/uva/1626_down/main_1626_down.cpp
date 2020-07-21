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
#define maxn 105

using namespace std;
string S;
//char S[MX];

bool match(int i, int j)
{
    if (S[i] == '(' && S[j] == ')') return true;
    if (S[i] == '[' && S[j] == ']') return true;
    return false;
}

//map<pair<int, int>, int> dps;
int dps[maxn][maxn];
int dp[maxn][maxn];
int from[maxn][maxn];
int dpp(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: ", l, r); for (int i=l; i<=r; ++i) printf("%c", S[i]); printf("\n");
    if (l > r) return 0;
    if (l == r) return 1;
    if (dps[l][r]) return dps[l][r];

    int ret = dpp(l, l, lay+1) + dpp(l+1, r, lay+1);
    int split = l;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("start %d\n", ret);
    for (int k=l+1; k<r; ++k)
    {
        //for (int i=0; i<lay; ++i) printf("|   "); printf("--\n");
        int cost = dpp(l, k, lay+1) + dpp(k+1, r, lay+1);
        if (cost < ret)
        {
            //for (int i=0; i<lay; ++i) printf("|   "); printf("min ^^^\n");
            ret = cost;
            split = k;
        }
    }

    //for (int i=0; i<lay; ++i) printf("|   "); printf("%c == %c ?\n", S[l], S[r]);

    // FIX: need to check if S[l] < S[r] for across bracket match, else it will match )( as a pair
    if (match(l, r) && dpp(l+1, r-1, lay+1) < ret) ret = dpp(l+1, r-1, lay+1), split=-1;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", ret);
    from[l][r] = split;
    return dps[l][r] = ret;
}

void print(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: %d\n", l, r, from[l][r]);
    if (l == r)
    {
        if (S[l] == '(' || S[l] == ')') printf("()");
        else printf("[]");
    }
    //else if (match(l, r) && dp(l, r) == dp(l+1, r-1))
    else if (from[l][r] < 0)
    {
        printf("%c", S[l]);
        print(l+1, r-1, lay+1);
        printf("%c", S[r]);
    }
    else
    {
        //for (int k=l; k<r; ++k)
        //    if (dp(l, r) == dp(l, k) + dp(k+1, r))
        int k = from[l][r];
        if (k < l) { printf("uh %d %d, %d\n", l, r, k); return; }
            {
                print(l, k, lay+1);
                print(k+1, r, lay+1);
                //break;
            }
    }
}

int main()
{
    int cs, g=0; scanf("%d\n", &cs);
    while (cs--)
    {
        memset(from, 0, sizeof from);
        memset(dps, 0, sizeof dps); // fix: typo--sizeof dps not sizeof from
        //memset(s, 0, sizeof s);
        //S.clear();
        cin >> S;
        //dpp(0, S.size()-1);
        int N = S.size();

        for (int i=0; i<=maxn; ++i) dp[i][i] = 1;
        for (int len=1; len<N; ++len)
            for (int l=0, r=l+len; r<N; ++l, ++r)
            {
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

        //scanf("\n");
        //int len;
        //for (len=0;; ++len)
        //{
        //    s[len] = getchar();
        //    if (s[len] == '\n') {
        //        s[len] = 0;
        //        break;
        //    }
        //    //printf("%d : %c\n", len, s[len]);
        //}
        ////printf("len %d\n", len);
        //dp(0, len-1);

        //cout << "min len = " << dp(0, s.size()-1) << endl;
        //if (g) printf("\n"); g=1;
        print(0, S.size()-1);
        //print(0, len-1);
        printf("\n");
        if (cs) printf("\n");
    }

	return 0;
}

