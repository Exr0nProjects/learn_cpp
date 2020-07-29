#include <iostream>
#include <math.h>
using namespace std;
bool inbound(int x, int y){
    return (x >= 0) && (x < y);
}
int lol [10111];
char c[70], d[70];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> lol[i];
    }
    char c [lol[0]];
    for(int i = 0; i < lol[0]; i++){
        cin >> c[i];
    }
    int totmax = 0;
    for(int i = 1; i <= n; i++){
        char d [lol[i]];
        for(int j = 0; j < lol[i]; j++){
            cin >> d[j];
        }
        int maxrides = 0;
        //we shift d. so we match the jth in d with the j+kth in c.
        for(int k = -26; k <= 26; k++){
            int curmax = 0;
            for(int j = 0; j < 26; j++){
                if(inbound(j,lol[i]) && inbound(j+k,lol[0]) && d[j] == c[j+k]){
                    curmax++;
                }
            }
            maxrides = max(maxrides, curmax);
        }
        totmax += maxrides;
    }
    cout << totmax << endl;

}


