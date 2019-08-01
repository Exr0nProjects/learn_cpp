/*
 * Problem c1231-1
 * 
 */
#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 1000010;

int dp[MAXSZ];

int main ()
{
    int beg, end, sa, sb;
    scanf("%d %d\n%d %d", &beg, &end, &sa, &sb);
    
    end = beg - end;
    
    dp[0] = 1;
    for (int i=1; i<=end; ++i)
    {
        if (i-sa >= 0) dp[i] += dp[i-sa];
        if (i-sb >= 0) dp[i] += dp[i-sb];
    }
    
    printf("%d", dp[end]);
    
    return 0;
}
