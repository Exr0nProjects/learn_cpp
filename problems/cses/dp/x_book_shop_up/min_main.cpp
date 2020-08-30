#include <iostream>
#define f(i,b) for(int i=0;i<b;++i)
using namespace std;
int main(){
    int N,X,j;cin>>N>>X;
    int v[N*2],d[X+1]={0};
    f(i,N)cin>>v[i];
    f(i,N)for(j=X;j>=v[i];--j)
        d[j]=max(d[j],d[j-v[i]]+v[i+N]);
    printf("%d",d[X]);
}

