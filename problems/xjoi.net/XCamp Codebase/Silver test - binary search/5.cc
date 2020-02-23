#include <bits/stdc++.h>
using namespace std;
int n;
double x[70000],a[70000],l,r,mid;
struct point
{
	double p,q;
}w[100000];
bool cmp(point a,point b)
{
	return a.q<b.q;
}
bool check(double k)
{
	for (int i=1;i<=n;i++)
	{
		w[i].p=x[i]-k*a[i];
		w[i].q=x[i]+k*a[i];
	}
	sort(w+1,w+n+1,cmp);
	for (int i=2;i<=n;i++)
	  if (w[1].q<w[i].p) return 0;
	return 1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf",&x[i]);
    for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
    l=0,r=1000000000.0;
    while (r-l>0.0000001)
    {
    	mid=(l+r)/2;
    	if (check(mid)) r=mid;
    	else l=mid;
    }
    printf("%.5lf",l);
} 
