#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Cell{
    int x;
    int y;
    int dist;
};
int main()
{
  int n, t;
  cin >> n >> t;
  vector<vector<int> > a(n,vector<int>(n));
  int posx, posy;
  string s;
  getline(cin,s);
  for(int i = 0; i < n; i++){
     getline(cin,s);
     for(int j = 0; j < n; j++){

         char inp;
         inp = s[j];
         if(inp == '#'){
             a[i][j] = 1;
         }else{
             a[i][j] = 0;
         }
         if(inp == 'Z'){
             posx = i;
             posy = j;
         }
     }
  }
  a[posx][posy] = 1;
  Cell cell;
  cell.x = posx;
  cell.y = posy;
  cell.dist = 0;
  queue<Cell> q;
  q.push(cell);
  int count = 0;
  while(!q.empty()){
      cell = q.front();
      q.pop();
      int movex[4] = {1,-1,0,0};
      int movey[4] = {0,0,1,-1};
      for(int i = 0; i < 4; i++){
          posx = movex[i]+cell.x;
          posy = movey[i]+cell.y;
          if(posx < n &&posy < n && posx >= 0 && posy >=0 && !a[posx][posy]){
              Cell c;
              a[posx][posy] = 1;
              c.x = posx;
              c.y = posy;
              c.dist = cell.dist+1;
              if(c.dist == t+1){
                  count+=1;
              }else{
                 q.push(c);
              }
          }
      }
  }
  cout << count;
}

