/*
 * Problem #7999
 * work division v2
 */

#include <bits/stdc++.h> // includes "everything"
#include <iostream>
#include <cstdio>
#define ll long long
#define dl double

using namespace std;

const int MAXSZ = 30;
int ppltime[MAXSZ] = { };
int jobtime[MAXSZ];
int jobs, ppls,totmin = 1000000000;

void dfs (const int step, int time)
{
    //static int totmin = 1000000000;
    
    int tmax = 0;
    if (time>totmin){
    	return;
	}
    if (step>jobs){
    	if (time<totmin){
    		totmin = time;
		}
    	return;	
	}
//    {
//    	 for (int j=0; j<ppls; ++j)
//        {
//        	if (ppltime[j] > tmax) tmax = ppltime[j]; // calculate max over current workers
//        }
//        if (tmax < totmin) { totmin = tmax; return totmin; } // base case 
//		return totmin;	
//	}
   
    for (int j=1; j<=ppls; ++j)
    {
	    if (ppltime[j] <= time) // optimization
		{
		    ppltime[j] += jobtime[step];
            dfs(step+1, max(time,ppltime[j]));
            ppltime[j] -= jobtime[step];	
		}
    }
   // return;
}

int main ()
{
    cin >> jobs >> ppls;

    //int ppltime[MAXSZ] = { };
    //int jobtime[MAXSZ];
    for (int i=1; i<=jobs; ++i) //cin >> jobtime[i];
        scanf("%d",&jobtime[i]);
    //sort(jobtime, jobtime + jobs);
    memset(ppltime,0,sizeof(ppltime));
    dfs(1,0);
    printf("%d", totmin);
}
