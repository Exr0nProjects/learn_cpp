#include <iostream>
using namespace std;
int arr[10000];

int main()
{
    //int N; scanf("%d", &N);
    int N; cin >> N;
    for (int i=1; i<=N; ++i)
        //scanf("%d", &arr[i]);
        cin >> arr[i];
    int cnt=0;
    for (int i=1; arr[i]; i=arr[i])
        ++cnt;
    cout << cnt << endl;
    //printf("%d\n", cnt);
}

