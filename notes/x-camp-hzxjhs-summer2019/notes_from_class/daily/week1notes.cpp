/*
 * Note: the first two days were not recorded because not much was done
 * and it had not yet occured to me to save and document everything.
 * These notes are not in the same format as the others because they were done 
 * in a rushed manner and were not properly planned out or formatted. 
 * Additionally, some information is missing as is common with saving stuff on pastebin
 * with a faulty internet connection.
 */

/* Original pastebin links:

10 July:
https://pastebin.com/qy7TcX89 (AM)
https://pastebin.com/kDSxTvCE (PM)

11 July:
https://pastebin.com/jagcMVxn (AM)
https://pastebin.com/DZUH6mmC (PM)

12 July
https://pastebin.com/K2u339nb (AM 1)
https://pastebin.com/3j9hBd7Z (AM 2)
https://pastebin.com/HK30GRkQ (PM)

13 July
https://pastebin.com/3UDvKswz (AM)
(lost pm class code)

15 July
(lost all code on this day)
*/

// #3657 by XC1900105AH on 10 July 2019 < TODO : WIP >
// number pyramid, find greatest possible sum traversingthe tree

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int size = 110;
int pyramid [size][size];

int main ()
{
	int layers;
	cin >> layers;
	
	for (int i=0; i<layers; ++i) for (int j=0; j<=i; ++j) cin >> pyramid[i][j];
	
	for (int i=layers-2; i>=0; --i)
	{
		for (int j=0; j<=i; ++j)
		{
			pyramid[i][j] = max(pyramid[i+1][j], pyramid[i+1][j+1]) + pyramid[i][j];
		}
	}
	
	cout << pyramid[0][0];
	
	return 0;
}

// #9402 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll last[110];

int main ()
{
	ll n, k;
	cin >> n >> k;
	
	last[0] = 1;
	ll pt = 1;
	
	while (pt < n+k)
	{
		ll ways = 0;
		for (ll i=1; i<=k; ++i)
		{
			ways = (ways + last[ (pt + k - i) % k ]) % 1000000007;
		}
		last[pt%k] = ways;
		++pt;
	}
	
	cout << last[pt%k];
	
	return 0;
}

// #7985 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
	int n;
	cin >> n;
	
	int nsub = 1, nsubsub = 0;
	for (int i=0; i<n; ++i)
	{
		nsub += nsubsub;
		nsubsub = nsub - nsubsub;
	}
	
	cout << nsub;
	
	return 0;
}

// #7974 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
	ll num, end = 1;
	cin >> num;
	
	for (int i=1; i<=num; ++i) end = (end * i) % 998244353;
	
	cout << end;
	
	return 0;
}


// #7180 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 2010;
int matrix [maxsize][maxsize];

int main ()
{
	int size;
	cin >> size;
	
	int tx, ty, tv;
	cin >> ty >> tx >> tv;
	while (! (tx == ty && ty == tv && tv == 0))
	{
		matrix[ty-1][tx-1] = tv;
		cin >> ty >> tx >> tv;
	}
	
	// init top row and left column
	for (int i=1; i<size; ++i)
	{
		matrix[0][i] += matrix[0][i-1];
		matrix[i][0] += matrix[i-1][0];
	}
	
	// dp
	for (int i=1; i<size; ++i)
	{
		for (int j=1; j<size; ++j)
		{
			matrix[i][j] += max(matrix[i-1][j], matrix[i][j-1]);
		}
	}
	
	cout << matrix[size-1][size-1];
	
	return 0;
}


// #7181 by XC1900105AH on 10 July 2019 < TODO : WIP >
// apple picking with two runs

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int matrix [2*maxsize][maxsize][maxsize];
// meaning: tot_steps  y_val_1  y_val_2

int main ()
{
	int size;
	cin >> size; 
	
	int tx, ty, tv;
	cin >> ty >> tx >> tv;
	while (! (tx == ty && ty == tv && tv == 0))
	{
		matrix[ty+tx][ty][ty] = tv;
		cin >> ty >> tx >> tv;
	}
	
	// init top row and left column
	for (int i=1; i<size; ++i)
	{
		matrix[i][i][i] += matrix[i-1][i-1][i-1];
		matrix[i][0][0] += matrix[i-1][0][0];
	}
	
	for (int i=1; i<2*size; ++i)
	{
		for (int j=1; j<=i; ++j)
		{
			for (int k=1; k<=i; ++k)
			{
				matrix[i][j][k] = (
				    max(matrix[i-1][j-1][k-1],
					    matrix[i-1][j-1][k],
				        matrix[i-1][j][k-1],
						matrix[i-1][j][k])
						
				)
			}
		}
	}
	
	cout << matrix[size-1][size-1][size-1][size-1];
	
	return 0;
}

/*

int main ()
{
	int size;
	cin >> size; 
	
	int tx, ty, tv;
	cin >> ty >> tx >> tv;
	while (! (tx == ty && ty == tv && tv == 0))
	{
		matrix[ty][tx][ty][tx] = tv;
		cin >> ty >> tx >> tv;
	}
	
	// init top row and left column
	for (int i=1; i<size; ++i)
	{
		matrix[0][i][0][i] += matrix[0][i-1][0][i-1];
		matrix[i][0][i][0] += matrix[i-1][0][i-1][0];
	}
	
	for (int i=1; i<size; ++i)
	{
		for (int j=1; j<size; ++j)
		{
			for (int k=1; k<size; ++k)
			{
				int l = i + j - k; // ensure that both "runs" have the same numberof steps 
				
				if (!(i == k && j == l)) matrix[i][j][k][l] *= 2;
				
				matrix[i][j][k][l] += (max( matrix[i-1][j][k-1][l],
				                            matrix[i-1][j][k][l-1], 
											matrix[i][j-1][k-1][l],
											matrix[i][j-1][k][l-1]))
			}
		}
	}
	
	cout << matrix[size-1][size-1][size-1][size-1];
	
	return 0;
}
*/


// #3661 by XC1900105AH on 10 July 2019 < TODO : WIP >

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int missles[maxsize];
int caught[maxsize];
int backpt[maxsize];

int find (size)
{
	caught[0] = 1;
	for (int i=0; i<size; ++i)
	{
		int max = 1;
		for (int j=0; j<i; ++j) if (caught[j] > max && missles[j] <= missles[i])
		{
			max = caught[j];
			backpt[i] = j;
		}
		caught[i] = max + 1;
	}
	return caught[size - 1];
}

int main ()
{
	int temp, pt = 0;
	while (cin >> temp)
	{
		missles[pt] = temp;
		//cout << "\"" << temp << "\"";
		++ pt;
	}
	
	cout << find(pt);
	while ()
	
	for (int i=0; i<5; ++i) cout << missles[i] << " ";
	
	return 0;
}



// #3276 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int arr [maxsize];
int dp [maxsize];

int main ()
{
	int size;
	cin >> size;
	
	arr[0] = 1;
	for (int i=0; i<size; ++i)
	{
		int temp, max = 0;
		cin >> temp;
		for (int j=0; j<i; ++j)
		{
			if (arr[j] < temp && )
		}
	}
	
	return 0;
}

// c1210-1 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 5010;
int start[maxsize];
int endt[maxsize];
int used[maxsize];

int main ()
{
	int num, totmax = 0; 
	cin >> num;
	
	for (int i=0; i<num; ++i)
	{
		cin >> start[i] >> endt[i];
		
		// insertion sort
		int pt = i, temp;
		while (pt > 0 && start[pt] < start[pt-1])
		{
			temp = start[pt-1];
			start[pt-1] = start[pt];
			start[pt] = temp;
			
			temp = endt[pt-1];
			endt[pt-1] = endt[pt];
			endt[pt] = temp;
		}
	}
	
	
	for (int i=0; i<num; ++i)
	{
		int maxu = 0; 
		
		for (int j=0; j<i; ++j)
		{
			if (endt[j] <= start[i] && used[j] > maxu) maxu = used[j];
		}
		used[i] = (endt[i] - start[i]) + maxu;
		if (used[i] > totmax) totmax = used[i];
	}
	
	cout << totmax;
	
	return 0;
}

// #c1210-2 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int infinity = 2000000000;

string words [110];
int dp [110];

bool match (string final, int start, int end, int idx)
{
	if (words[idx].length() + start - 1 != end) return false;
	for (int i=0; i<words[idx].length(); ++i)
	{
		//cout << ": comparing '" << final[start+i] << "' !/= '" << words[idx][i] << "'\n";
		if (final[start+i] != words[idx][i]) return false;
	}
	return true;
}

int main ()
{
	string final;
	cin >> final;
	int num;
	cin >> num;
	for (int i=0; i<num; ++i) cin >> words[i];
	
	for (int i=0; i<final.length(); ++i) 
	{// for each character in final
	    int mmin = infinity;
	    for (int k=0; k<num; ++k) if (match(final, 0, i, k)) mmin = 1;
		for (int j=0; j<i; ++j)
		{// for character that we have dp'd up to 
			if (dp[j] +1 < mmin)
			    for (int k=0; k<num; ++k)
		    	{// for each word we can use
		    		if (match(final, j, i, k)) mmin = dp[j] + 1;
		    	}
		}
		dp[i] = mmin;
	}
	
	cout << dp[final.length()-1];
	
	//cout << endl; for (int i=0; i<final.length(); ++i) cout << dp[i] << " ";
	
	/*debug
	cout << match((string) "balala", 1, 0)
	     << "\n\n" << match((string)"balala", 2, 0)
	     << "\n\n" << match((string)"balala", 3, 0);
	*/
	
	return 0;
}

// #c1210-3 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int start [maxsize];
int endb [maxsize];
int feed [maxsize];

bool overlap (int starta, int enda, int startb, int endb)
{
	return (starta <= startb && startb <= enda) || (startb <= starta && starta <= endb);
}

int main ()
{
	int num, totmax = 0;
	cin >> num;
	
	for (int i=0; i<num; ++i)
	{
		cin >> start[i] >> endb[i];
		
		// insertion sort
		int pt = i, temp;
		while (pt > 0 && start[pt] < start[pt-1])
		{
			temp = start[pt-1];
			start[pt-1] = start[pt];
			start[pt] = temp;
			
			temp = endb[pt-1];
			endb[pt-1] = endb[pt];
			endb[pt] = temp;
		}
	}
	
	for (int i=0; i<num; ++i)
	{
		int mmax = 0;
		for (int j=0; j<i; ++j)
		{
			if (!overlap(start[i], endb[i], start[j], endb[j]) && feed[j] > mmax) mmax = feed[j]; 
		}
		feed[i] = mmax + endb[i] - start[i] + 1;
	    if (feed[i] > totmax) totmax = feed[i];	
	}
	
	cout << totmax;
	
	return 0;
}

// c1210-4 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int arr [maxsize];
int dp [maxsize];

int main ()
{
	int size, totmax;
	cin >> size;
	
	for (int i=0; i<size; ++i)
	{
		cin >> arr[i];
		int mmax = 0;
		for (int j=0; j<i; ++j)
		{
			if (arr[j] < arr[i] && dp[j] > mmax) mmax = dp[j];
		}
		dp[i] = mmax + arr[i];
		if (dp[i] > totmax) totmax = dp[i];
	}
	
	cout << totmax; 
	
	return 0;
}

/*
topics done today
dp practice, 
dp is based on making a bigger problem smaller, and saving the answers to those smaller subproblems to access them later
it is known as "dynamic programming", where programming means "to order tasks" so the whole idea of dp is to organize the subproblems so that we only need to solve them once and so that when it comes time to solve a subproblem all of its prerequisite subproblems are already solved. DP is good at solving a variety of problems, especially those which can be represented as DAGs. This is because a DAG representable problem is able to be linearized topographically, and this linear ordering is the order in which the dp algo can solve the subproblems. Famous problems solveable by DP include the apple picking problem (a grid of different values, you can only move right or down starting in the top left), the knapsack problem, and the non-decreasing sublist problem. Some DP resources include: https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf - a chapter from the book "approximation algorithms" about DP
https://courses.csail.mit.edu/6.006/fall11/rec/rec21_knapsack.pdf - an explination and walkthrough of the knapsack problem using DP
*/












// #8450 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main ()
{
	int num;
	cin >> num;
	for (int i=0; i<num; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << min(a, b);
	}
	
	return 0;
}

// #8452 by XC1900105AH on 10 July 2019

#include <bits/stdc++.h>
#define ll long long
#define db double

using namespace std;

db one (db c)
{
	return c * (db) 9 / (db) 5 + (db) 32; 
}
db two (db f)
{
	return (f - (db)32) * (db) 5 / (db) 9;
}

int main ()
{
	int num;
	cin >> num;
	
	for (int i=0; i<num; ++i)
	{
		double temp, typ;
		cin >> temp >> typ;
		cout.precision(3);
		if (typ == 1) cout << one(temp);
		else cout << two(temp);
	}
	
	return 0;
}


// #7181 by XC1900105AH on 10 July 2019
// apple picking with two runs

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 70;

int matrix [maxsize][maxsize];
int dp [2*maxsize][maxsize][maxsize];
//      tot_steps  y_val_1  y_val_2

int main ()
{
	int size;
	cin >> size; 
	
	int tx, ty, tv;
	cin >> ty >> tx >> tv;
	while (! (tx == ty && ty == tv && tv == 0))
	{
		matrix[ty-1][tx-1] = tv;
		cin >> ty >> tx >> tv;
	}
	
	/*/ init top row and left column
	dp[0][0][0] = matrix[0][0];
	for (int i=1; i<size; ++i)
	{
		dp[i][i][i] = dp[i-1][i-1][i-1] + matrix[0][i];
		dp[i][0][0] = dp[i-1][0][0] + matrix[i][0];
	}
	/**/
	
	memset(dp,0,sizeof(dp));
	
	dp[0][0][0] = matrix[0][0];
	for (int i=1; i<2*size-1; ++i)
	{
		for (int j=max(0, i-size); j<=i && j<size; ++j)
		{
			for (int k=max(0, i-size); k<=i && k<size; ++k)
			{
			    int temp = dp[i-1][j][k];
			    if (j > 0) temp = max(temp, dp[i-1][j-1][k]);
			    if (k > 0) temp = max(temp, dp[i-1][j][k-1]);
			    if (j>0&&k>0) temp = max(temp, dp[i-1][j-1][k-1]);
			    
			    temp += matrix[i-j][j];
			    if (j != k) temp += matrix[i-k][k];
			    
			    dp[i][j][k] = temp;
			}
		}
	}
	
	cout << dp[size*2-2][size-1][size-1];
	
//debug	cout << endl; for (int i=0; i<size; ++i) { for (int j=0; j<size; ++j) cout << matrix[i][j] << " "; cout << endl; }
//debug	for (int i=0; i<size*2-1; ++i) { cout << i; for (int j=0; j<size; ++j) for (int k=0; k<size; ++k) cout << "  (" << j << "|" << k << ": " << dp[i][j][k] << ")"; cout << endl; }
	
	return 0;
}

/*

int main ()
{
	int size;
	cin >> size; 
	
	int tx, ty, tv;
	cin >> ty >> tx >> tv;
	while (! (tx == ty && ty == tv && tv == 0))
	{
		matrix[ty][tx][ty][tx] = tv;
		cin >> ty >> tx >> tv;
	}
	
	// init top row and left column
	for (int i=1; i<size; ++i)
	{
		matrix[0][i][0][i] += matrix[0][i-1][0][i-1];
		matrix[i][0][i][0] += matrix[i-1][0][i-1][0];
	}
	
	for (int i=1; i<size; ++i)
	{
		for (int j=1; j<size; ++j)
		{
			for (int k=1; k<size; ++k)
			{
				int l = i + j - k; // ensure that both "runs" have the same numberof steps 
				
				if (!(i == k && j == l)) matrix[i][j][k][l] *= 2;
				
				matrix[i][j][k][l] += (max( matrix[i-1][j][k-1][l],
				                            matrix[i-1][j][k][l-1], 
											matrix[i][j-1][k-1][l],
											matrix[i][j-1][k][l-1]))
			}
		}
	}
	
	cout << matrix[size-1][size-1][size-1][size-1];
	
	return 0;
}
*/


#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int dp [maxsize][maxsize];

int main ()
{
	int totmax = 0;
	string sa, sb;
	cin >> sa >> sb;
	
	for (int i=0; i<sa.length(); ++i)
	{
		for (int j=0; j<sb.length(); ++j)
		{
			if (sa[i] == sb[j]) dp[i][j] = 1;
			
			int mmax = 0;
			for (int k=0; k<i; ++k) if (j > 0 && dp[k][j-1] > mmax) mmax = dp[k][0];
			for (int l=0; l<j; ++l) if (i > 0 && dp[i-1][l] > mmax) mmax = dp[0][l];
			
			dp[i][j] += mmax;
			if (dp[i][j] > totmax) totmax = dp[i][j];
		}
	}
	
	cout << totmax; 
	
	return 0;
}

/*
   a  c  a  e
a  1  0  1  0
b  0  1  1  1
c  0  2  1  1
d  0  1  2  2

// OLD VERSION (full looping)
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int dp [maxsize][maxsize];

int main ()
{
	int totmax = 0;
	string sa, sb;
	cin >> sa >> sb;
	
	for (int i=0; i<sa.length(); ++i)
	{
		for (int j=0; j<sb.length(); ++j)
		{
			if (sa[i] == sb[j])
			{
				int mmax = 0;
				for (int k = 0; k<i; ++k)
				{
					for (int l=0; l<j; ++l)
				    {
					    if (dp[k][l] > mmax) mmax = dp[k][l];
				    }
				}
				
				dp[i][j] = mmax + 1;
				if (dp[i][j] > totmax) totmax = dp[i][j];
			}
		}
	}
	
	cout << totmax; 
	
	return 0;
}

*/


/*

today in class:

funcitons
they are wirtten <return type> <name> (<type> <argname>)
they allow recursion, etc

debugging,
look at important variables, where for loops are intitated, look for arr out of bound errors. some compilers are differnt from others so maybe it will silently pass errors which the system will not allow. Weiming says use cpp.sh.

*/




// #3587 written by XC1900105AH on 11 July 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxsize = 1010;
int dp [maxsize][maxsize];

int main ()
{
	int totmax = 0;
	string sa, sb;
	cin >> sa >> sb;
	
	for (int i=0; i<sa.length(); ++i)
	{
		for (int j=0; j<sb.length(); ++j)
		{
		    int mmax = 0;
		    if (i == j && j == 0) mmax = 0;
		    else if (i == 0) mmax = dp[0][j-1];
		    else if (j == 0) mmax = dp[i-1][0];
		    else 
		    { 
		        if (sa[i] == sb[j]) mmax = dp[i-1][j-1];
		        else mmax = max(dp[i-1][j], dp[i][j-1]);
		    }
		
			dp[i][j] = mmax;
			if (sa[i] == sb[j] && !((i==0||j==0) && mmax!=0)) ++dp[i][j];
			
			if (dp[i][j] > totmax) totmax = dp[i][j];
		}
	}
	
	cout << totmax; 
	
	
	//cout << endl << "   "; for (int i=0; i<sa.length(); ++i) cout << sb[i] << "  "; cout << endl; for (int i=0; i<sa.length(); ++i) { cout << sa[i] << ": "; for (int j=0; j<sb.length(); ++j) cout << dp[i][j] << "  "; cout << endl; }
	
	return 0;
}

/*

a b c
b c c

  a b c
b 0 1 1
c 0 1 2
c 0 1 2




   a  c  a  e
a  1  0  1  0
b  0  1  1  1
c  0  2  1  1
d  0  1  2  2
*/



// c1213-1 by XC1900105AH on 11 July 2019

#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

bool isprime(int n)
{
	if (n <= 1) return false;
	if (!(n%2)) return false;
	int sq = sqrt(n)+1;
	for (int i=3; i<sq; i += 2)
	{
		if (!(n%i)) return false;
	}
	return true;
}

int main ()
{
	int num, half;
	cin >> num;
	if (num == 4) { cout << "4=2+2"; return 0; }
	
	half = num/2;
	
	//for (int i=0; i<num; ++i) cout << i << ": " << isprime(i) << endl;
	
	for (int i=3; i<half; i += 2)
	{
		if (isprime(i) && isprime(num-i)) cout << num << "=" << i << "+" << num-i;
		break;
	}
	
	return 0;
}




// c1213-2 by XC1900105AH on 11 July 2019

#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

string codes [] {
"#_##__",
"##_#_#_#__",
"##_#_##_#__",
"##_#_#__",
"#__",
"#_#_##_#__",
"##_##_#__",
"#_#_#_#__",
"#_#__",
"#_##_##_##__",
"##_#_##__",
"#_##_#_#__",
"##_##__",
"##_#__",
"##_##_##__",
"#_##_##_#__",
"##_##_#_##__",
"#_##_#__",
"#_#_#__",
"##__",
"#_#_##__",
"#_#_#_##__",
"#_##_##__",
"##_#_#_##__",
"##_#_##_##__",
"##_##_#_#__"
};

int main ()
{
	int num;
	cin >> num;
	for (int set=0; set<num; ++set)
	{
		string code, ans = "";
		cin >> code;
		code = code + "__";
		
		
		int pt = 0;
		while (pt < code.length())
		{
		    for (int w=0; w<26; ++w)
		    {
		       // cout << w << ": " << ans << endl;
			    string let = codes[w];
			    
			    bool bad = false;
			    for (int i=0; i<let.length(); ++i) if (let[i] != code[pt+i]) { bad = true; break; }
			    if (!bad)
			    {
			        pt += let.length();
			        ans += (char) (w + 65);
			        break;
			    }
		    }
	    }
	    cout << ans << endl;
	}
	
	return 0;
}




// c1213-3 by XC1900105AH on 11 July 2019

#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

char nums [] {'A', 'B', 'C', 'D', 'E', 'F'};

char from10 (int num)
{
	if (0 <= num && num <= 9) return (char) (num + 48);
	else if (10 <= num <= 15) return nums[num-10];
}

int to10 (char digit)
{
	if (65 <= (int) digit && (int) digit <= 70) return (int) digit - 55;
	else if (48 <= (int) digit && (int) digit <= 57) return (int) digit - 48;
}

string conv (int base, int num)
{
	string end;
	int tsz = base;
	while (tsz < num) tsz *= base;
	tsz /= base;
	
	while (num)
	{
		end += from10(num/tsz);
		num %= tsz; 
		tsz /= base;
	}
	
	return end;
}

bool ispal (string pal)
{
	for (int i=0; i<pal.length()/2; ++i)
	{
		if (pal[i] != pal[pal.length()-i-1]) return false;
	}
	return true;
}

int main ()
{
	int amt, srt;
	cin >> amt >> srt;
	
	while (amt > 0)
	{
		++srt; 
		for (int i=2; i<16; ++i)
		{
			if (i == 10) continue;
			if (ispal( conv(i, srt) )) 
			{
				cout << srt << endl;
				-- amt;
				break;
			}
		}
	}
	
	return 0;
}




// #8183 by XC1900105AH on 11 July 2019

#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

const int maxboard = 400;
const int maxcards = 50;
int board [maxboard];
int dp [maxcards][maxcards][maxcards][maxcards]; 

int main ()
{
	
	
	return 0;
}




/*
pm class contents

primarily spent time doing contest problems. These problems were relatively easier brain wise and was mostly just a coding exercise.

more dp work: 
try and reduce the search space for each layer of dp. carry over the best so far even if a condition isnt met, and try to only search the imediate previous spaces. For the character problem (3587) , this meant not looking for the max overthe entire area, and instead only looking two places if the characters didnt match and only in one place if they did. This vastly reduces the search space and increases efficiency, which is the whole point of storing so many numbers anywys. 

think about what the most essential state information and discard everything else. However, keep in mind what parts of the state need to be modifiable and independant of eachother. for the turtle problem (8183), this means using the dp array to store what cards are remaining. the dp array need not store the values on each square because those don't change over the course of the crawling. instead, a simple 4d array is needed to store the state of the cards and the best score at each, (independant from the numbers on the board). otherwise the storage space needed would be far too big. Basically, in DP try and simplify the states as much as possible. 


*/









// 1218 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

void exchange (int * a, int * b)
{
    cout << a << " " << b << endl;
    int * temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

void swap (int& a, int& b)
{
    int temp = a;
    a = b; 
    b = temp;
}

int main ()
{
    int a, b;
    cin >> a >> b;
    
    //exchange(&a, &b);
    
    swap (a, b);
    
    cout << a << " " << b;
    
    return 0;
}



// 1219 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

void checkmin (int& orig, int noob)
{
    if (noob < orig) orig = noob;
}

void checkmax (int& orig, int noob)
{
    if (noob > orig) orig = noob;
}

int main ()
{
    int num, mmin, mmax;
    cin >> num;
    
    int temp; cin >> temp;
    mmin = mmax = temp;
    
    for (int i=1; i<num; ++i)
    {
        cin >> temp;
        checkmin(mmin, temp);
        checkmax(mmax, temp);
    }
    cout << mmax << " " << mmin;
    
    return 0;
}



// 7068 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

void F(int &x) {
    x ^= x & (x << 3);
    x ^= x & (x >> 2);
    x %= 65536;
}

void G(int &x) {
    x ^= x & (x << 2);
    x ^= x & (x >> 3);
    x %= 65536;
}

int main ()
{
    string commands;
    int valu;
    
    cin >> commands;
    cin >> valu;
    
    for (int i=0; i<commands.length(); ++i)
    {
        if (commands[i] == 'F') F(valu);
        else if (commands[i] == 'G') G(valu);
    }
    
    cout << valu;
    
    return 0;
}




// 1220 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

int getmax(int* arr, int size)
{
    int mmax = arr[0];
    for (int i=1; i<size; ++i)
    {
        if (arr[i] > mmax) mmax = arr[i];
    }
    return mmax;
}

int getmin (int* arr, int size)
{
    int mmin = arr[0];
    for (int i=1; i<size; ++i)
    {
        if (arr[i] < mmin) mmin = arr[i];
    }
    return mmin;
}

int main ()
{
    int num;
    while (cin >> num)
    {
        int arr [110];
        for (int i=0; i<num; ++i) cin >> arr[i];
        cout << getmax(arr, num) << " " << getmin(arr, num) << endl;
    }
    
    return 0;
}



// 1222 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

template <class T>
T add (T a, T b)
{
    return a + b;
}

int sum (int a, int b)
{
    return a + b;
}
int sum (int a, int b, int c)
{
    return a + b + c;
}

int main ()
{
    int a, b;
    cin >> a >> b;
    
    cout << sum(a, b);
    
    return 0;
}




// 9295 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

void product (int a, int b)
{
    cout << a * b;
}

int main ()
{
    int a, b;
    cin >> a >> b;
    
    product(a, b);
    
    return 0;
}



// 1221 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

void sum (int a[][110], int b[][110], int size)
{
    for (int i=0; i<size; ++i)
    {
        for (int j=0; j<size; ++j)
        {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << endl;
    }
}

int main ()
{
    int num;
    cin >> num;
    
    int a[110][110];
    int b[110][110];
    
    for (int i=0; i<num; ++i) for (int j=0; j<num; ++j) cin >> a[i][j];
    for (int i=0; i<num; ++i) for (int j=0; j<num; ++j) cin >> b[i][j];
    
    sum(a, b, num);
    
    return 0;
}




// 7065 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

int F() {
    static int pre = 0;
    pre += 2;
    return pre;
}

int main ()
{
    int num;
    cin >> num;
    
    for (int i=0; i<num; ++i) cout << F() << endl;
    
    return 0;
}



// 7065 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

int init;

int Gen ()
{
    static int x = init;
    x ^= (x/32);
    x ^= (x*8);
    x ^= (x>>2);
    x = x % 65536;
    return x;
}

int main ()
{
    int times;
    cin >> init >> times;
    
    for (int i=0; i<times; ++i) cout << Gen() << endl;
    
    return 0;
}



/* wip
// 1217 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;

using namespace std;

int board[1010][1010]

int main ()
{
    int h, w, pi=0, pj, cycle = 0;
    cin >> h >> w >> pj;
    
    for (int i=0; i<h; ++i)
        for (int j=0; j<w; ++j)
            char temp;
            cin >> temp;
            switch (temp)
            {
                case 
            }
            
    while (true)
    {
        board[pi][pj] = cycle ++;
    }
    
    
    
    return 0;
}
*/







// 1217 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;
 
using namespace std;
 
int board[1010][1010];


void move (int& pi,int& pj)
{
    switch (board[pi][pj])
    {
        case -1: --pi; break;
        case -2: ++pj; break;
        case -3: ++pi; break;
        case -4: --pj; break;
    }
}

int main ()
{
    int h, w, pi=0, pj, lpi=0, lpj=0, cycle = 0;
    cin >> h >> w >> pj;
    -- pj; // fencepost
   
    for (int i=0; i<h; ++i)
        for (int j=0; j<w; ++j)
        {
            char temp;
            cin >> temp;
            switch (temp)
            {
                case 'N': board[i][j] = -1; break;
                case 'E': board[i][j] = -2; break;
                case 'S': board[i][j] = -3; break;
                case 'W': board[i][j] = -4; break;
            }
        }
    
    //debugfor (int i=0; i<h; ++i) { for (int j=0; j<w; ++j) cout << board[i][j] << ' '; cout << endl; }
    
    while (true)
    {
        lpi = pi; lpj = pj;
        //debugcout << cycle << ": (" << pi << ", " << pj << "): " << board[pi][pj] << endl;
        move(pi, pj);
        board[lpi][lpj] = cycle ++;
        if (board[pi][pj] >= 0)
        {
            cout << board[pi][pj] << " step(s) before a loop of " << cycle - board[pi][pj] << " step(s)";
            break;
        }
        else if (pi < 0 || pi > h || pj < 0 || pj > w)
        {
            cout << cycle << " step(s) to exit";
            break;
        }
    }
   
    return 0;
}



// 1135 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;
 
using namespace std;

int egcd (int a, int b)
{
    if (b == 0) return a;
    return egcd(b, a%b);
}

int main ()
{
    int a, b, mgcd;
    cin >> a >> b;
    
    mgcd = egcd(a, b);
    
    cout << mgcd << "\n" << a / mgcd * b;
   
    return 0;
}



/* wip


// 8454 written by XC1900105AH on 12 July 2019
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;
 
using namespace std;

const bool maxsize = 1000010;
int sieve [maxsize];
int primes [maxsize/2];

int main ()
{
    int * newprimepointer = primes;
    for (int i=3; i<maxsize; i+= 2)
    {
        if (!sieve[i])
        {
            *newprimepointer = i;
            ++ newprimepointer;
            for (int j=2*i; j<maxsize; j += i) sieve[i] = 1;
        }
    }
    
    int num;
    cin >> num;
    for (int i=0; i<num; ++i)
    {
        int temp, pfs = 0; cin >> temp;
        if (temp %2 == 0) ++ pfs;
        for (int i=0; i<temp; ++i)
        {
            if (!(temp%primes[i])) ++pfs;
            if (primes[i] >= sqrt(temp)) break;
        }
        cout << pfs << endl;
    }
   
    return 0;
}
*/










// 8454 written by XC1900105AH on 12 July 2019 <TODO: not accepted>
#include <bits/stdc++.h>
#define ll long long
#define dl double
const int infinity = 2000000000;
 
using namespace std;

const int maxsize = 1000010;
bool sieve [maxsize];
int primes [maxsize/2];

int main ()
{
    int nppt = 0;
    for (int i=3; i<maxsize; i+= 2)
    {
        if (sieve[i] == false)
        {
            primes[nppt] = i;
            ++ nppt;
            for (int j=2*i; j<maxsize; j += i) sieve[i] = 1;
        }
    }
    
    //for (int i=0; i<100; ++i) cout << primes[i] << " ";
    
    int num;
    cin >> num;
    for (int i=0; i<num; ++i)
    {
        int temp, pfs = 0; cin >> temp;
        if (temp %2 == 0) ++ pfs;
        for (int j=0; j<temp; ++j)
        {
            if (temp%primes[j] == 0) { ++pfs; temp /= primes[j]; }
            if (primes[j] >= sqrt(temp) + 5) break;
        }
        cout << pfs << endl;
    }
   
    return 0;
}


// 8451 written by XC1900105AH on 12 july 2019 <TODO: not accepted>

#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;
    cout << min (a, b);
}



// 7985 written by XC1900105AH on 12 july 2019 < TODO: Not accepted> 

#include <bits/stdc++.h>

using namespace std;

int fib (int total)
{
    static int a = 0;
    static int b = 1;
 
    if (total == 0) return a + b;
    
    a += b;
    b = a-b;
    return fib(total-1);
}

int main ()
{
    int num;
    cin >> num;
    
    cout << fib(num);
    
    return 0;
}

// 7073 written by XC1900105AH on 12 july 2019

#include <bits/stdc++.h>

using namespace std;

int prog (int num)
{
    if (num <= 3) return 1;
    return prog(num-1) + 2*prog(num-3);
}

int main ()
{
    int num;
    cin >> num;
    
    cout << prog(num);
    
    return 0;
}


// 7075 written by XC1900105AH on 12 july 2019 <TODO: not accepted>

#include <bits/stdc++.h>

using namespace std;

int prog (int x, int y)
{
    if (x <= 0 || y <= 0) return 1;
    return prog(x-1, y) + 2*prog(x-1, y-1) + 3*prog(x, y-1);
}

int main ()
{
    int x, y;
    cin >> x >> y;
    
    cout << prog(x, y);
    
    return 0;
}


// 7080 written by XC1900105AH on 12 july 2019

#include <bits/stdc++.h>

using namespace std;

void prog (string st)
{
   for (int i=0; i<st.length(); ++i) cout << st[i] << endl; 
}

int main ()
{
    string st;
    cin >> st;
    
    prog(st);
    
    return 0;
}


// 7988 written by XC1900105AH on 12 july 2019 <TODO: not accepted>

#include <bits/stdc++.h>
#define ll long long

using namespace std;

void reduce (ll& num, ll& bpt, const ll base)
{
    //cout << num << " / " << bpt << " = " << num / bpt << " ";
    num = num % bpt;
    bpt /= base;
}

int main ()
{
    ll num, base;
    cin >> num >> base;
    
    if (num < base) { cout << num; return 0; }
    
    ll bpt = base;
    while (bpt <= num) bpt *= base;
    bpt /= base;
    
    while (bpt)
    {
        reduce(num, bpt, base);
    }
    
    return 0;
}


// 7074 written by XC1900105AH on 12 july 2019

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll egcd (ll a, ll b)
{
    if (b == 0) return a;
    return egcd(b, a %b);
}

int main ()
{
    ll a, b;
    cin >> a >> b;
    
    cout << egcd(a, b);
    
    return 0;
}

/*
recap of today:
many problems to do, and not that much time to do it. I need to spend more time outside of school and get these problems done. This is a good practice for this kind of situation when I am required to do something difficult and boring. These tasks may be easier to get out of than others but I will continue to do them to exercise this skill.

coding related:
not much class today - pointers are helpful. You can pass arrays to functions and pass references to functions so that the function itself can modify a variable usually only accesable in main.

static variables: they dont get recycled, so you can have a function with one as the initializer. the next time the function is called, the static var is still there so it won't be initialized again. This allows us to create generators as if in python, which is pretty cool.

function overloading: you can have many functions with the same name and if they have different "structures", as in they have different arg types or numbers of args, then the complier will know which one to call. this is helpful for having a "sum" function for both ints and doubles, for example. You can also overload default functions with this tactic, and write your own "max" function if you would like.

debugging: again, look at areas that are likely to be messed up, spot check them. The comparison opperators in for, if, and while for example. The point at which a for loop starts and stops. Fence post errors are very common and need to be spotted. 

for now, the plan is simply to continue working and try and spend more time outside of class working on this. do not slack, because the goal of this is to practice being under pressure as these situations will happen in the pressure. 
*/










// #7982 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

string steps[20];

string swapstacks (string proc, char a, char b)
{
    for (int i=0; i<proc.length(); ++i)
    {
        if (proc[i] == a) proc[i] = b;
        else if (proc[i] == b) proc[i] = a;
    }
    return proc;
}

int main ()
{
    int num;
    cin >> num;
    steps[0] = "A->B\n";
    for (int i=1; i<num; ++i)
    {
        steps[i] = swapstacks(steps[i-1], 'B', 'C') + "A->B\n" + swapstacks(steps[i-1], 'A', 'C');
        //cout << "----\n\n" << steps[i] << "\n\n";
    }
    
    cout << steps[num-1];
    
    return 0;
}


// #8469 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

string steps[20];

string swapstacks (string proc, char a, char b)
{
    for (int i=0; i<proc.length(); ++i)
    {
        if (proc[i] == a) proc[i] = b;
        else if (proc[i] == b) proc[i] = a;
    }
    return proc;
}

int main ()
{
    int num;
    cin >> num;
    steps[0] = "1 A B\n";
    for (int i=1; i<num; ++i)
    {
        steps[i] = swapstacks(steps[i-1], 'B', 'C') + to_string(i+1) + " A B\n" + swapstacks(steps[i-1], 'A', 'C');
        //cout << "----\n\n" << steps[i] << "\n\n";
    }
    
    cout << steps[num-1];
    
    return 0;
}



// #7077 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

string parse (string code)
{
    int sum = 0;
    for (int i=0; i<code.length(); ++i) sum += (int) code[i] - 48;
    if (sum == 0) return (string) "A";
    if (sum == code.length()) return (string) "B";
    
    string cd1, cd2;
    for (int i=0; i<code.length()/2; ++i)
    {
        cd1 += code[i];
        cd2 += code[i+code.length()/2];
    }
    //cout << "----\n" << cd1 << endl << cd2 << "\n\n";
    
    string ret = "C" + parse(cd1) + parse(cd2);
    
    return ret;
}

int main ()
{
    string code;
    cin >> code;
    
    cout << parse(code);
    
    return 0;
}



// #7975 written by XC1900105AH on 13 July 2019 < TODO: NOT ACCEPTED >
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;
 
int main ()
{
    ll num, base = 1;
    cin >> num;
    
    while (base < num) base *= 2;
    while (base)
    {
        cout << num / base << " ";
        base /= 2;
    }
    
    return 0;
}



// #7976 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

void f (int n)
{
    if (n == 1) { cout << 1 << " "; return;}
    f(n/2);
    cout << n << ' ';
    f(n-n/2);
}

int main ()
{
    int num;
    cin >> num;
    
    f (num);
    
    return 0;
}



// #7081 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

void anagram(string rem, string app)
{
    if (rem.length() == 0)
    {
        for (int i=0; i<app.length(); ++i) printf("%c ", app[i]);
        printf("\n");
        return;
    }
    
    for (int i=0; i<rem.length()-1; ++i)
    {
        anagram(rem.substr(0, i) + rem.substr(i+1), app + rem[i]);
    }
    anagram(rem.substr(0, rem.length()-1), app + rem[rem.length()-1]);
}

int main ()
{
    int num;
    cin >> num;
    
    string gram;
    for (int i=1; i<=num; ++i)
    {
        gram += to_string(i) + "";
    }
    
    anagram (gram, (string) "");
    
    return 0;
}




// #7082 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

void anagram(string rem, string app)
{
    if (rem.length() == 0)
    {
        for (int i=0; i<app.length(); ++i) printf("%c ", app[i]);
        printf("\n");
        return;
    }
    
    for (int i=0; i<rem.length()-1; ++i)
    {
        if ((int) rem[i] - 49 != app.length()) anagram(rem.substr(0, i) + rem.substr(i+1), app + rem[i]);
    }
    if ((int) rem[rem.length()-1] - 49 != app.length()) anagram(rem.substr(0, rem.length()-1), app + rem[rem.length()-1]);
}

int main ()
{
    int num;
    cin >> num;
    
    string gram;
    for (int i=1; i<=num; ++i)
    {
        gram += to_string(i) + "";
    }
    
    anagram (gram, (string) "");
    
    return 0;
}



// #7978 written by XC1900105AH on 13 July 2019
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

int num, upto=1;

void anagram(string rem, string app)
{
    static int counter = upto;
    if (rem.length() == 0)
    {
        //cout << "  " << counter << ": " << app << endl;
        if (counter == num)
        {
            for (int i=0; i<app.length(); ++i) printf("%c ", app[i]);
            throw 0;
        }
        ++ counter;
        return;
    }
    
    for (int i=0; i<rem.length()-1; ++i)
    {
        anagram(rem.substr(0, i) + rem.substr(i+1), app + rem[i]);
    }
    anagram(rem.substr(0, rem.length()-1), app + rem[rem.length()-1]);
}

int main ()
{
    cin >> num;
    
    switch (num)
    {
        case 1:
            cout << "1"; 
            return 0;
        case 2:
            cout << "1 2";
            return 0;
    }
    
    
    string gram;
    
    for (int i=1; i<num; ++i)
    {
        int temp=1;
        for (int j=2; j<=i; ++j) temp *= j;
        if (upto + temp > num)
        {
            for (int j=1; j<=i; ++j) gram += to_string(j);
            break;
        }
        upto += temp;
    }
    
    
    //cout << num << " " << upto << ": " << gram << endl;
   // return 1;
    
    
    try
    {
        anagram (gram, (string) "");
    } 
    catch (int throwcode)
    {
        if (throwcode == 0) return 0; // anagram was found, exiting safely
    }
    
    return 0;
}



/* WIP, TODO: NOT ACCEPTED
// #7977 written by XC1900105AH on 13 July 2019 < TODO: NOT ACCEPTED >
 
#include <bits/stdc++.h>
#define ll long long
#define dl double
 
using namespace std;

int num, upto;

void anagram (int rem[], int app[], int rlen, int alen)
{
    static int counter = 0;
    if (rlen == 0)
    {
        cout << "  " << counter << ": "; for (int i=0; i<alen; ++i) cout << app[i]; cout << endl;
        if (counter == upto)
        {
            for (int i=0; i<alen; ++i) printf("%d ", app[i]);
            throw 0;
        }
        ++ counter;
        return;
    }
    
    for (int i=0; i<num; ++i)
    {
        if (rem[i] > 0)
        {
            app[alen] = rem[i];
            rem[i] = 0;
            anagram(rem, app, rlen - 1, alen + 1);
        }
    }
}

int main ()
{
    int gram[11], app[11];
    cin >> num >> upto;
    
    -- upto; // fencepost
    
    for (int i=1; i<=num; ++i)
    {
        gram[i-1] = i;
    }
    
    for (int i=0; i<num; ++i) cout << gram[i] << " "; cout << endl;
    
    try
    {
        anagram (gram, app, num, 0);
    } 
    catch (int throwcode)
    {
        if (throwcode == 0) return 0; // anagram was found, exiting safely
    }
    
    return 0;
}

*/
/*

today's recap
output speed: cout is very slow, and you should always use printf if dealing with large datasets.


recursion: very powerful, functions call eachother

*/








/* 13 july recap:
limits: when in doubt, check the limits and ensure that your code can handle them. if it says something like `a<=10e9`, its still safer to do long long because two of those numbers added together could overflow it. Also, check your code for the extremes of the bounds when debugging, in case there is a chance of overflow that you didn’t notice.

Test with values that are really big and really small, and if there are multiple. inputs then check the program with inputs that are close together and far apart, multiples of each other, relatively prime, negative, etc;

struct:
basically like a class, has data members
you can have pointers to them, there is a member dereference operator “->” where `structptr->member` is equivalent to `(*structptr).member` which is pretty cool.
helpful for all things classes are good at, but they cant have methods so its just like a data class. Still nice and lightweight though. can be used for custom exceptions.

exceptions and exiting outside of main:
best practice: use a custom exception, like a struct mentioned above. in a function, throw it when it is time to exit and then in main catch that exception and exet by `return 0` there like normal. this is good because it allows for proper clean up of everything that happened, while something like std::exit is just bad. good stackoverflow answer here: https://stackoverflow.com/questions/30250934/how-to-end-c-code 
*/







/* 15 july recap

not much lecture today, but we did many problems. There were not many new concepts but still i learned some important meta concepts:
Sleep
{
require enough sleep to have a good productive day, otherwise towards the end it will become difficult to focus and work efficiently
it is still possible to work with less than normal amounts of sleep, but it means that the work towards the end of the day will be of lower quality.
}

contests - what is good enough?
{
sometimes there will be contest problems that are very difficult. If sometimes the best you can do is to brute force or even guess test cases and try and hard code.
The goal is to get as many points as possible so it can be helpful sometimes to spend more time in places where it is easier to get pinots and not waste time doing difficult problems and getting nowhere with them.
}

debugging
{
make sure that your variables can hold the values they will have to, and make sure that you start your for loops in the right place. 
it is easy to mix up <, >, <=, and >= so get those straight as well.
}

Recursion
{
(with function) can be really elegant when written correctly. Remember that return chains can have modifiers on them (return !self(args)) can be really elegant, as well as switching the position of args in the next calling such as with the euclidian algorithm for egcd.
}

*/