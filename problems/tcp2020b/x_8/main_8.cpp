// miles
// 8
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  int arr[n], arr2[m];
  for(int i = 0; i < n; i++){
      cin >> arr[i];
  }
  for(int i = 0; i < m; i++){
      cin >> arr2[i];
  }
  int i = 0, j = 0;
  vector<int> out;
  while(i<n && j<m){
      if (arr[i] < arr2[j]){
          out.push_back(arr[i]);
          i+=1;
      }else{
          out.push_back(arr2[j]);
          j+=1;
      }
  }
  for(int I = i; I < n; I++){
      out.push_back(arr[I]);
  }
  for(int I = j; I < m; I++){
      out.push_back(arr2[I]);
  }
  for(int i = 0; i < out.size(); i++){
      cout << out[i] << " ";
  }
}

