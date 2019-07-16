// c1225-1 (copied from 7977 written by XC1900105AH on 13 July 2019)
  
#include <bits/stdc++.h>
#define ll long long
#define dl double
  
using namespace std;

const int MAXSZ = 1010;
ll factorial[MAXSZ] = {1, 1};

struct anagram_exit{
    int type;
};
 
void anagram (const ll rem_[], const ll app_[], ll rlen, ll alen, const ll num, const ll upto)
{
//   cout << "  : anagram called, rlen: " << rlen << " and alen: " << alen << " and rem: ["; for (int i=0; i<num; ++i) cout << rem_[i] << " "; cout << "]" << endl;
    static ll counter = 0;
    if (rlen == 0)
    {
  //      cout << " " << counter << ": "; for (int i=0; i<alen; ++i) cout << app_[i]; cout << ", throw? " << (counter == upto) << endl;
        if (counter == upto)
        {
            for (ll i=0; i<alen; ++i) printf("%d ", app_[i]);
            anagram_exit exitcode;
            exitcode.type = 0;
            throw exitcode;
        }
        ++ counter;
        return;
    }
     
    for (ll i=0; i<num; ++i)
    {
 //       cout << "  :    (" << rlen << ", " << alen << ") i: " << i << " rem[i]: " << rem_[i] << endl;
        if (rem_[i] > 0)
        {
            ll rem[MAXSZ], app[MAXSZ];
            for (ll i=0; i<num; ++i) { rem[i] = rem_[i]; app[i] = app_[i]; }
//            cout << "  :!   " << i << ": " << rem[i] << ", rlen: " << rlen << "; alen: " << alen << endl;
            app[alen] = rem[i];
            rem[i] = 0;
            anagram(rem, app, rlen - 1, alen + 1, num, upto);
        }
    }
}

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
    
    if (num < 20) cout << reduce(digits, num, upto);
    else 
    {
        try
        {
            ll app[MAXSZ];
            anagram (digits, app, num, 0, num, upto);
        }
        catch (anagram_exit exitcode)
        {
            if (exitcode.type == 0) return 0; // anagram was found, exiting safely
        }
    }
    
    return 0;
}
