#include<cstdio>
#include<algorithm>
using namespace std;
int a[50],n,maxd,T;
bool fl;
inline int hh()
{
    int cnt=(a[n]!=n),i;
    for(i=1;i<n;++i)
    {
        if(abs(a[i+1]-a[i])>1)
        {
        	cnt++;
		}        	
	}    
    return cnt;
}
void dfs(int x,int last)
{
    int h=hh(),i;
    if(!h)
	{
		fl=1;
		return;
	}
    if(x+h>maxd) 
	{
		return ;	
	} 
    for(i=2;i<=n;i++)
    {
        if(i!=last)
		{
            reverse(a+1,a+i+1);
            dfs(x+1,i);
            if(fl) 
            {
            	return;
			}				
            reverse(a+1,a+i+1);
        }    	
	}
}
int main()
{
    int i;
    scanf("%d",&T);
    while(T--)
	{
        fl=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
        	scanf("%d",&a[i]);
		}          
        for(maxd=0;maxd<=40;maxd++)
		{
            dfs(0,0);
            if(fl)  
			{
				break;	
			}
        }
        printf("%d\n",maxd);
    }
    return 0;
}

