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
//int ppltime[MAXSZ] = { };
//int jobtime[MAXSZ];

int dfs (const int jobtime[], int ppltime[], const int jobs, const int ppls)
{
    static int totmin = 1000000000;
    
    int tmax = 0;
    if (jobs == 0)
    {
    	 for (int j=0; j<ppls; ++j)
        {
        	if (ppltime[j] > tmax) tmax = ppltime[j]; // calculate max over current workers
        }
        if (tmax < totmin) { totmin = tmax; return totmin; } // base case 
		return totmin;	
	}
	
    for (int j=0; j<ppls; ++j)
    {
	    if (ppltime[j] + jobtime[jobs-1] < totmin) // optimization
		{
		    ppltime[j] += jobtime[jobs-1];
            dfs( jobtime, ppltime, jobs-1, ppls );
            ppltime[j] -= jobtime[jobs-1];	
		}
    }
    return totmin;
}

int main ()
{
    int jobs, ppls;
    cin >> jobs >> ppls;

    int ppltime[MAXSZ] = { };
    int jobtime[MAXSZ];
    for (int i=0; i<jobs; ++i) //cin >> jobtime[i];
        scanf("%d",&jobtime[i]);
    
    printf("%d", dfs(jobtime, ppltime, jobs, ppls) );
}
