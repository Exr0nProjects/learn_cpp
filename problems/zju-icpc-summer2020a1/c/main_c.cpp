// miles
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
const int MX = 1e5 + 100;
int arr[MX][MX];
int main()
{
    int n, m;
    int a,b,c;
    cin >> n >> m;
    //vector<vector<int> > arr(n,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a == 1){
            arr[b-1][c-1] = 1;
            arr[c-1][b-1] = 1;
        }else if(a == 2){
            bool works = false;
            for(int j = 0; j < n; j++){
                if (arr[b-1][j] == 1 and arr[c-1][j] == 1){
                    works = true;
                }
            }
            if(arr[b-1][c-1] == 0 && works == true){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}

