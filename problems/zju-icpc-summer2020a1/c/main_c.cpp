// miles
#include <iostream>
#include <string>
#include <set>
using namespace std;
const int MX = 1e5 + 100;
set<int> head[MX];
int main()
{
    int n, m;
    int a,b,c;
    cin >> n >> m;
    //vector<vector<int> > arr(n,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if(a == 1){
            head[b-1].insert(c-1);
            head[c-1].insert(b-1);
        }else if(a == 2){
            bool works = false;
            for (int thru : head[c-1])
                if (head[b-1].count(thru))
                {
                    //printf("thru %d\n", thru);
                    works = true;
                    break;
                }
            //printf("works? %d\n", works);

            //for(int j = 0; j < n; j++){
            //    if (arr[b-1][j] == 1 and arr[c-1][j] == 1){
            //        works = true;
            //    }
            //}
            if(!head[c-1].count(b-1) && works == true){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}

