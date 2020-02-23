#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
#define INF 0x3f3f3f3f
int N,K;
int w[MAX],v[MAX];
double y[MAX];

bool C(double x)
{
    for(int i=0;i<N;i++)
        y[i]=v[i]-w[i]*x;
    sort(y,y+N);

    // Get k
    int t=N-1-K;
    double sum=0;
    for(int i=N-1;i>t;i--)
    {
        sum+=y[i];
    }
    return sum>=0;
}
void solve()
{
    double lb=0,ub=INF,mid;
    for(int i=0;i<100;i++)
    {
        mid=(lb+ub)/2;
        if(C(mid))
            lb=mid;
        else
            ub=mid;
    }
    printf("%.2f\n",ub);
}
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&v[i]);
    solve();
    return 0;
} 
