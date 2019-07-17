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
int totmin = 1000000000; // 1 billion;

void dfs (const int jobs, const int ppls, int tmax)
{
    if (jobs == 0)
    {
        totmin = tmax; // base case 
		return;	
	}
	
    for (int j=0; j<ppls; ++j)
    {
	    if (ppltime[j] + jobtime[jobs-1] < totmin) // optimization
		{
		    ppltime[j] += jobtime[jobs-1];
            dfs( jobs-1, ppls, max(ppltime[j], tmax) );
            ppltime[j] -= jobtime[jobs-1];	
		}
    }
    return;
}

int main ()
{
    int jobs, ppls;
    cin >> jobs >> ppls;

    for (int i=0; i<jobs; ++i) //cin >> jobtime[i];
        scanf("%d",&jobtime[i]);
    sort(jobtime, jobtime+jobs);
    dfs(jobs, ppls, 0);
    
    printf("%d", totmin);
}
