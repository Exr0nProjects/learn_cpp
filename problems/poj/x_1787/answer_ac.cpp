#include <iostream>
#include <math.h>
using namespace std;
int dp [10005];
int path [4][10005];//
int main() {
	int n;
	while(true){
		cin >> n;
		if(n == 0){
			return 0;
		}else{
			int count [4];
			int value [4] = {1,5,10,25};
			for(int i = 0; i < 10005; i++){
				dp[i] = -1;
			}
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 10005; j++){
					path[i][j] = 0;
				}
			}
			dp[0] = 0;
			for(int i = 0; i < 4; i++){
				cin >> count[i];
			}
			for(int i = 0; i < 4; i++){
				for(int j = value[i]; j <= n; j++){
					if(dp[j-value[i]] != -1 && dp[j] < dp[j-value[i]]+1 && path[i][j-value[i]]+1 <= count[i]){
						dp[j] = dp[j-value[i]] + 1;
						path[i][j] = path[i][j-value[i]]+1;
						for(int k = 0; k < i; k++){
							path[k][j] = path[k][j-value[i]];
						}
					}
				}
			}
			if(dp[n] == -1){
				cout << "Charlie cannot buy coffee." << endl;
			}else{
				printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",
				path[0][n],path[1][n],path[2][n],path[3][n]);
			}
		}
	}
}

