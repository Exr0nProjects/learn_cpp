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

using namespace std;
const int MX = 1011;
//string inp;
char inp[MX];

char ope(char c) // oposite
{
    switch (c)
    {
        case '(': return ')';
        case ')': return '(';
        case '[': return ']';
        case ']': return '[';
    }
    return 'x';
}

//map<pair<int, int>, int> dps;
int dps[MX][MX];
int from[MX][MX];
int dp(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: ", l, r); for (int i=l; i<=r; ++i) printf("%c", inp[i]); printf("\n");
    if (l > r) return 0;
    if (l == r) return 2;
    if (dps[l][r]) return dps[l][r];

    int ret = dp(l, l, lay+1) + dp(l+1, r, lay+1);
    //for (int i=0; i<lay; ++i) printf("|   "); printf("start %d\n", ret);
    int split = l;
    for (int k=l+1; k<r; ++k)
    {
        //for (int i=0; i<lay; ++i) printf("|   "); printf("--\n");
        int cost = dp(l, k, lay+1) + dp(k+1, r, lay+1);
        if (cost < ret)
        {
            //for (int i=0; i<lay; ++i) printf("|   "); printf("min ^^^\n");
            ret = cost,
            split = k;
        }
    }

    //for (int i=0; i<lay; ++i) printf("|   "); printf("%c == %c ?\n", inp[l], inp[r]);

    // FIX: need to check if inp[l] < inp[r] for across bracket match, else it will match )( as a pair
    if (inp[l] == ope(inp[r]) && inp[l] < inp[r] && dp(l+1, r-1, lay+1) +2 < ret) ret = dp(l+1, r-1, lay+1)+2, split=-1;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("=> %d\n", ret);
    from[l][r] = split;
    return dps[l][r] = ret;
}

void print(int l, int r, int lay=1)
{
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d\n", l, r);
    if (l > r) return;
    //for (int i=0; i<lay; ++i) printf("|   "); printf("%d..%d: %d\n", l, r, from[l][r]);
    if (l == r) cout << min(string({inp[l], ope(inp[l])}), string({ope(inp[l]), inp[l]}));
    //if (l == r) cout << "()";
    else if (from[l][r] < 0)
    {
        printf("%c", inp[l]);
        print(l+1, r-1, lay+1);
        printf("%c", inp[r]);
    }
    else
    {
        //for (int i=0; i<lay; ++i) printf("|   "); printf("from[%d][%d] = %d\n", l, r, from[l][r]);
        print(l, from[l][r], lay+1);
        print(from[l][r]+1, r, lay+1);
    }
}

int main()
{
    int cs, g=0; scanf("%d", &cs);
    getchar();
    while (cs--)
    {
        memset(from, 0, sizeof from);
        memset(dps, 0, sizeof from);
        //cin >> inp;
        //dp(0, inp.size()-1);
        //scanf("\n");
        getchar();  // FIX: need to getchar not scanf("\n"); cuz that will RE
        int len;
        for (len=0;; ++len)
        {
            inp[len] = getchar();   // FIX: need to use custom input, cin>>inp causes WA
            if (inp[len] == '\n') {
                inp[len] = 0;
                break;
            }
            //printf("%d : %c\n", len, inp[len]);
        }
        //printf("len %d\n", len);
        dp(0, len-1);
        //cout << "min len = " << dp(0, inp.size()-1) << endl;
        //if (g) printf("\n"); g=1;
        //print(0, inp.size()-1);
        print(0, len-1);
        printf("\n");
        if (cs) printf("\n");
    }

	return 0;
}

