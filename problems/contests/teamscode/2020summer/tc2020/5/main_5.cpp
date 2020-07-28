// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  int arr[m];
  int count = 0;
  bool done = false;
  for(int i = 0; i < m; i++){
     int a;
     cin >> a;
     count+=a;
     int venom = count*(i+1);
     if(venom > n and !done){
         cout << (i) << endl;
         done = true;
     }
  }
  if(!done){
     cout << m << endl;
  }
}

