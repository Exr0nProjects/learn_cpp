// c1225-1 (copied from 7977 written by XC1900105AH on 13 July 2019)
  
#include <bits/stdc++.h>
#define ll long long
#define dl double
  
using namespace std;

const int MAXSZ = 110;
ll factorial[MAXSZ] = {1, 1};

string reduce (ll digits[], const ll num, const ll upto)
{
    if (num == 1) return to_string(digits[0]);
    
    ll idx = upto/factorial[num-1];
    string ret = to_string( digits[idx] ) + " ";
    // shift
    for (ll i=idx; i<num-1; ++i)
        digits[i] = digits[i+1];
    // propogate
    return ret + reduce(digits, num-1, upto%factorial[num-1]);
}

int main ()
{
    ll num, upto;
    cin >> num >> upto;
    -- upto; // fencepost
    
    for (ll i=2; i<=num; ++i) factorial[i] = factorial[i-1] * i;
    
    ll digits[MAXSZ];
    for (ll i=0; i<num; ++i) digits[i] = i+1;
    
    cout << reduce(digits, num, upto);
    
    return 0;
}
