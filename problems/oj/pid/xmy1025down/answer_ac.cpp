#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int forward_trains [50];
int backward_trains [50];//arrival times
int forward_arrivals [50][50];//train, station
int backward_arrivals [50][50];
int m1;
int m2;
int N,T;
int next_forward_train(int t, int station){
    //cout << "Called " << t << " " << station << endl << endl;
    //returns the wait time at the station
    if(t <= forward_arrivals[0][station]){
        //cout << "Ran Successfully" << endl;
        return forward_arrivals[0][station]-t;
    }else if(t > forward_arrivals[m1-1][station]){
        //cout << "Ran Successfully" << endl;
        return 10000;
    }
    int low = 0;
    int high = m1-1;
    //forward_arrivals[low] < t <= forward_arrivals[high]
    while(high-low != 1){
        //cout << low << " " << high << endl;
        if(t <= forward_arrivals[(low+high)/2][station]){
            high = (low+high)/2;
        }else{
            low = (low+high)/2;
        }
    }
    //cout << "Ran Successfully" << endl;
    return forward_arrivals[high][station]-t;
}
int next_backward_train(int t, int station){
    //returns the wait time at the station
    if(t <= backward_arrivals[0][station]){
        return backward_arrivals[0][station]-t;
    }else if(t > backward_arrivals[m2-1][station]){
        return 10000;
    }
    int low = 0;
    int high = m2-1;
    //forward_arrivals[low] < t <= forward_arrivals[high]
    while(high-low != 1){
        if(t <= backward_arrivals[(low+high)/2][station]){
            high = (low+high)/2;
        }else{
            low = (low+high)/2;
        }
    }
    return backward_arrivals[high][station]-t;
}


int main() {
    int it = 0;
    while(true){
        it++;
        cin >> N;
        if(N == 0){
            break;
        }
        cin >> T;
        int stationdist [N-1];
        for(int i = 0; i < N-1; i++){
            cin >> stationdist[i];
        }
        
        cin >> m1;
        for(int i = 0; i < m1; i++){
            cin >> forward_trains[i];
        }
        cin >> m2;
        for(int i = 0; i < m2; i++){
            cin >> backward_trains[i];
        }
        for(int i = 0; i < m1; i++){
            forward_arrivals[i][0] = forward_trains[i];
            for(int j = 1; j < N; j++){
                forward_arrivals[i][j] = forward_arrivals[i][j-1] + stationdist[j-1];
            }
        }
        for(int i = 0; i < m2; i++){
            backward_arrivals[i][N-1] = backward_trains[i];
            for(int j = N-2; j >= 0; j--){
                backward_arrivals[i][j] = backward_arrivals[i][j+1] + stationdist[j];
            }
        }
        int dp [T+1][N];
        for(int i = 0; i <= T; i++){
            for(int j = 0; j < N; j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        for(int t = 0; t <= T; t++){
            for(int s = 0; s < N; s++){
                if(dp[t][s] == -1){
                    continue;
                }
                int wait_time = next_forward_train(t,s);
                if(s != N-1 && wait_time != -1 && t+wait_time+stationdist[s] <= T){
                    if(dp[t+wait_time+stationdist[s]][s+1] == -1){
                        dp[t+wait_time+stationdist[s]][s+1] = dp[t][s]+wait_time;
                    }else{
                        dp[t+wait_time+stationdist[s]][s+1] = min(dp[t+wait_time+stationdist[s]][s+1],dp[t][s]+wait_time);
                    }
                }
                wait_time = next_backward_train(t,s);
                if(s != 0 && wait_time != -1 && t+wait_time+stationdist[s-1] <= T){
                    if(dp[t+wait_time+stationdist[s-1]][s-1] == -1){
                        dp[t+wait_time+stationdist[s-1]][s-1] = dp[t][s]+wait_time;
                    }else{
                        dp[t+wait_time+stationdist[s-1]][s-1] = min(dp[t+wait_time+stationdist[s-1]][s-1],dp[t][s]+wait_time);
                    }
                }
                //wait 1 time step;
                if(t+1 <= T){
                    if(dp[t+1][s] == -1){
                        dp[t+1][s] = dp[t][s]+1;
                    }else{
                        dp[t+1][s] = min(dp[t+1][s],dp[t][s]+1);
                    }
                }
            }
        }
        cout << "Case Number " << it << ": ";
        if(dp[T][N-1] == -1){
            cout << "impossible" << endl;
        }else{
            cout << dp[T][N-1] << endl;
        }
    }
}

