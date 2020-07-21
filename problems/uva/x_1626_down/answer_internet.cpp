// https://programmer.group/uva-1626-brackets-sequence-dp.html

#include<stdio.h>
#include<cstring>
#include<set>
#define maxn 105
#define INF 1<<30
#define min(a,b) (a>b)? b:a
#define max(a,b) (a>b)? a:b
using namespace std;

char S[maxn];
int dp[maxn][maxn];

bool match(int i, int j)
{
    if (S[i] == '(' && S[j] == ')') return true;
    if (S[i] == '[' && S[j] == ']') return true;
    return false;
}

void print(int l, int r)
{
    //printf("\n%d %d\n",l,r);
    if (l > r) return;
    if (l == r)
    {
        if (S[l] == '(' || S[l] == ')') printf("()");
        else printf("[]");
        return;
    }
    else if (match(l, r) && dp[l][r] == dp[l+1][r-1])
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
            print(l, k);
            print(k+1, r);
            break;
        }
    }
}

int main ()
{
    int cs;
    scanf("%d", &cs);
    getchar();
    //freopen("out.txt","w",stdout);
    while (cs--)
    {
        //scanf("%s",S+1);
        //getchar();
        //scanf("\n");
        int N;
        for (N=1;; ++N)
        {
            S[N] = getchar();
            if (S[N] == '\n')
            {
                S[N] = '\0';
                break;
            }
        }
        --N;
        //int N = strlen(S+1);

        for (int i=1; i<=N; ++i) dp[i][i] = 1;

        for (int i=N-1; i>=1; i--)
        //for (int i=1; i<N; ++i)
        {
            for(int j = i+1; j<=N; j++)
            {
                dp[i][j] = INF;
                if(match(i,j)) dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
                int tmp = INF;
                for(int k = i; k < j; k++)
                {
                    tmp = min(tmp,dp[i][k]+dp[k+1][j]);
                }
                dp[i][j] = min(dp[i][j],tmp);
            }
        }
        //printf("%d\n",dp[1][N]);

        print(1, N);
        printf("\n");
        if(cs!=0) printf("\n");
    }
    //fclose(stdin);
}

/*
Sample Input
1
([(]
Sample Output
()[()]
*/

