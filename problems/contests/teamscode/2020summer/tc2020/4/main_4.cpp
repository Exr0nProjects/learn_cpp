// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string arr[100];
  for(int i = 0; i < n; i++){
     cin >> arr[i];
  }
  cout << arr[0] << " ";
  for(int i = 1; i < n; i++){
     if(arr[i-1] == arr[i]){
         continue;
     }else{
         cout << arr[i] << " ";
     }
  }
  cout << endl;
}

