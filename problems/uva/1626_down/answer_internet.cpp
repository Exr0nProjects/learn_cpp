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

bool match(int i,int j)
{
    if(S[i] == '(' && S[j] == ')') return true;
    if(S[i] == '[' && S[j] == ']') return true;
    return false;
}

void print(int i,int j)
{
    //printf("\n%d %d\n",i,j);
    if(i>j) return;
    if(i==j)
    {
        if(S[i] == '(' || S[i]==')') printf("()");
        else printf("[]");
    }
    if(match(i,j) && dp[i][j]==dp[i+1][j-1])
    {
        printf("%c",S[i]);
        print(i+1,j-1);
        printf("%c",S[j]);
        return;
    }
    for(int k = i; k<j; k++)
    {
        if(dp[i][j] == (dp[i][k] + dp[k+1][j]))
        {
            print(i,k);
            print(k+1,j);
            return;
        }
    }
}

int main ()
{
    int N;
    scanf("%d",&N);
    getchar();
    //freopen("out.txt","w",stdout);
    while(N--)
    {
        //scanf("%s",S+1);
        getchar();
        for(int i = 1;; i++)
        {
            S[i] = getchar();
            if(S[i] == '\n')
            {
                S[i]='\0';
                break;
            }
        }
        int len = strlen(S+1);

        for(int i = 1; i<=len; i++) dp[i][i] = 1,dp[i][i+1] = 0;

        for(int i = len-1; i>=1; i--)
        {
            for(int j = i+1; j<=len; j++)
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
        //printf("%d\n",dp[1][len]);

        print(1,len);
        printf("\n");
        if(N!=0) printf("\n");
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

