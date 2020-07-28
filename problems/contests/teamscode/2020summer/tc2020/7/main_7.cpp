// Example program
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> arr(6);
  for(int i = 0; i < 6; i++){
      cin >> arr[i];
  }
  for(int j = 0; j < n; j++){
      vector<int> newarr = arr;
      for(int i = 1; i < 6; i++){
          if(arr[i-1] > arr[i]){
              newarr[i]+=newarr[i-1]/2;
              newarr[i-1] = newarr[i-1]-newarr[i-1]/2;
          }
      }
      if(arr[5] > arr[0]){
          newarr[0]+=newarr[5]/2;
          newarr[5]-=newarr[5]/2;
      }
      arr = newarr;
  }
  for(int i = 0; i < 6; i++){
      cout << arr[i] << endl;
  }
}

