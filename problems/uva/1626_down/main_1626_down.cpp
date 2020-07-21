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
int from[maxn][maxn];
int dp(int l, int r, int lay=1)
{
    for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: ", l, r); for (int i=l; i<=r; ++i) printf("%c", S[i]); printf("\n");
    if (l > r) return 0;
    if (l == r) return 1;
    if (dps[l][r]) return dps[l][r];

    //int ret = 100000;
    int ret = dp(l, l, lay+1) + dp(l+1, r, lay+1);
    //int split = l;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("start %d\n", ret);
    for (int k=l+1; k<r; ++k)
    {
        //for (int i=0; i<lay; ++i) printf("|   "); printf("--\n");
        int cost = dp(l, k, lay+1) + dp(k+1, r, lay+1);
        if (cost < ret)
        {
            //for (int i=0; i<lay; ++i) printf("|   "); printf("min ^^^\n");
            ret = cost;
            //split = k;
        }
    }

    //for (int i=0; i<lay; ++i) printf("|   "); printf("%c == %c ?\n", S[l], S[r]);

    // FIX: need to check if S[l] < S[r] for across bracket match, else it will match )( as a pair
    //if (S[l] == ope(S[r]) && S[l] < S[r] && dp(l+1, r-1, lay+1) +2 < ret) ret = dp(l+1, r-1, lay+1)+2, split=-1;
    if (match(l, r) && dp(l+1, r-1, lay+1) < ret) ret = dp(l+1, r-1, lay+1);
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", ret);
    return dps[l][r] = ret;
}

void print(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: %d\n", l, r, from[l][r]);
    //if (l == r) cout << min(string({s[l], ope(s[l])}), string({ope(s[l]), s[l]}));
    if (l == r)
    {
        if (S[l] == '(' || S[l] == ')') printf("()");
        else printf("[]");
    }
    if (match(l, r) && dp(l, r) == dp(l+1, r-1))
    //if (l == r) cout << "()";
    //else if (from[l][r] < 0)
    {
        printf("%c", S[l]);
        print(l+1, r-1, lay+1);
        printf("%c", S[r]);
    }
    else
    {
        for (int k=l; k<r; ++k)
            if (dp(l, r) == dp(l, k) + dp(k+1, r))
            {
    //    //for (int i=0; i<lay; ++i) printf("|   "); printf("from[%d][%d] = %d\n", l, r, from[l][r]);
        print(l, from[l][r], lay+1);
        print(from[l][r]+1, r, lay+1);
                break;
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
        S.clear();
        cin >> S;
        dp(0, S.size()-1);

        //for (int len=0; len<N; ++len)
        //    for (int l=0, r=l+len; r<N; ++l, ++r)
        //    {
        //        if (l == r)
        //    }

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
        //print(0, S.size()-1);
        //print(0, len-1);
        printf("\n");
        if (cs) printf("\n");
    }

	return 0;
}

