// c1225-3 adapted from #7977 written by XC1900105AH on 16 July 2019
  
#include <bits/stdc++.h>
#define ll long long
#define dl double
  
using namespace std;
 
int num, upto;
 
struct anagram_exit{
    int type;
};
 
void anagram (const int rem_[], const int app_[], int rlen, int alen)
{
//d    cout << "  : anagram called, rlen: " << rlen << " and alen: " << alen << " and rem: ["; for (int i=0; i<num; ++i) cout << rem_[i] << " "; cout << "]" << endl;
    static int counter = 0;
    if (rlen == 0)
    {
 //d       cout << " " << counter << ": "; for (int i=0; i<alen; ++i) cout << app_[i]; cout << ", throw? " << (counter == upto) << endl;
        if (counter == upto)
        {
            for (int i=0; i<alen; ++i) printf("%d ", app_[i]);
            anagram_exit exitcode;
            exitcode.type = 0;
            throw exitcode;
        }
        ++ counter;
        return;
    }
     
    for (int i=0; i<num; ++i)
    {
//d        cout << "  :    (" << rlen << ", " << alen << ") i: " << i << " rem[i]: " << rem_[i] << endl;
        if (rem_[i] > 0 && (abs(rem_[i]-app_[alen-1]) > 1 || alen == 0))
        {
            int rem[11], app[11];
            for (int i=0; i<num; ++i) { rem[i] = rem_[i]; app[i] = app_[i]; }
 //d           cout << "  :!   " << i << ": " << rem[i] << ", rlen: " << rlen << "; alen: " << alen << endl;
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
     
    //cout << "num: " << num << " upto: " << upto << endl;
 //   for (int i=0; i<num; ++i) cout << gram[i] << " "; cout << endl;
     
    try
    {
        anagram (gram, app, num, 0);
    }
    catch (anagram_exit exitcode)
    {
       // cout << "exitcode thrown, exitting now.";
        if (exitcode.type == 0) return 0; // anagram was found, exiting safely
    }
     
    return 0;
}
