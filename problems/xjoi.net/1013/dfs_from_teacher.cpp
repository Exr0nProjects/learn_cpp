#include <bits/stdc++.h>
using namespace std;
  int n,ans=210000000,tot=0;
  int map1[60][60],f[60][60];
  int dx[5]={0,-1,0,1,0};
  int dy[5]={0,0,1,0,-1};
void dfs(int x,int y,int step){
  if (step>ans)
    return ;
  if (x==n&&y==n){
   if (step==ans) {
    ans=step;tot++;
   } 
   else if (step<ans){
    ans=step; tot=1;
   }   
   return ;
  }
   
  for (int i=1; i<=4;i++){
   int xx=x+dx[i]; 
   int yy=y+dy[i];
 //  if (xx>=1 && xx<=n&&yy>=1&&yy<=n&&f[xx][yy]==0)
   if (map1[xx][yy]==0 && f[xx][yy]==0)
    {
      f[xx][yy]=1;
      dfs(xx,yy,step+1);
      f[xx][yy]=0;
    }
  }
}
int main(){
  cin>>n;
  for(int i=0;i<=n+1; i++)
   for (int j=0; j<=n+1; j++){
    map1[i][j]=1;
    f[i][j]=0;
   }
  for( int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      cin>>map1[i][j];
  
  dfs(1,1,1);
  cout << tot << endl << ans << endl;
  return 0;
} 