#include <iostream>
using namespace std;
int tle(){
    int count;
    for(int i = 0; i < 193843294; i++){
        count += i*3%8;
    }
    return count;
}
int main() {
	int cash;
	int dp [101533];//-1, 1
	while(cin >> cash){
		int n;
		cin >> n;
		int billdenom [11];
		int avalible [11];
		for(int i = 0; i < n; i++){
			cin >> avalible[i] >> billdenom[i];
		}
		for(int i = 0; i < 101533; i++){
			dp[i] = -1;
		}
		dp[0] = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 101533; j++){
				if(dp[j] != -1){
					dp[j] = avalible[i];
				}
			}
			for(int j = 0; j < 101533 - billdenom[i]; j++){
				if(dp[j] != -1){
					dp[j+billdenom[i]] = max(dp[j+billdenom[i]],dp[j]-1);
				}
			}
		}
	//	for(int i = cash; i >= 0; i--){
	//		cout << dp[i] << " ";
	//	}
	//	cout << endl;
		for(int i = min(101533,cash); i >= 0; i--){
			if(dp[i] != -1){
				cout << i << endl;
				break;
			}
		}
	}
}

