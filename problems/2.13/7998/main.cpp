/*
 * Problem #7998
 * work distribution: todo not accepted;
 */

#include <bits/stdc++.h> // includes "everything"
#define ll long long
#define dl double
#define i32x 2147483647

using namespace std;

const int MAXSZ = 25; // can be up to 31, otherwise the i32 snowflake doesn't work

int main ()
{
	int num;
	cin >> num;
	
	int dp[MAXSZ][MAXSZ][2] = {};
	for (int i=0; i<num; ++i) for (int j=0; j<num; ++j)
	{
		cin >> dp[i][j][0];
		dp[i][j][1] = 1 << j; // init snowflake
	}
	
	// dp
	for (int i=1; i<num; ++i)
	{
		for (int j=0; j<num; ++j)
		{
			int mmin = 1000000, jdx = 0;
			for (int k=0; k<num; ++k) if (dp[i-1][k][0] < mmin && !(dp[i-1][k][1] >> j)&1)
			{
				printf("(%d, %d) k: %d ?%d\n", j, i, k, !(dp[i-1][k][1] >> j)&1);
				mmin = i;
				jdx = k;
			}
			
			dp[i][j][0] += mmin;
			dp[i][j][1] |= dp[i-1][i][1];
		}
	}
	
	for (int i=0; i<num; ++i)
	{
		for (int j=0; j<num; ++j)
		{
			printf("%3d", dp[i][j][0]);
		}
		printf("\n");
	}
	
	int mmin = 1000000;
	for (int i=0; i<num; ++i) if (dp[num-1][i][0] < mmin) mmin = dp[num-1][i][0];
	printf("%d", mmin);
		
    return 0;
}
