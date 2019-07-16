// c1225-1 (copied from 7977 written by XC1900105AH on 13 July 2019)
  
#include <bits/stdc++.h>
#define ll long long
#define dl double
  
using namespace std;

const int MAXSZ = 110;
int factorial[MAXSZ] = {1, 1};

string reduce (int digits[], const int num, const int upto)
{
    
    printf("  %d: ", num); for (int i=0; i<num; ++i) printf("%3d ", digits[i]); printf("\n");
    
    
    if (num == 1) return to_string(digits[0]);
    
    int idx = upto/factorial[num-1];
    string ret = to_string( digits[idx] ) + " ";
    // shift
    for (int i=idx; i<num-1; ++i)
        digits[i] = digits[i+1];
    // propogate
    return ret + reduce(digits, num-1, upto);
}

int main ()
{
    int num, upto;
    cin >> num >> upto;
    --upto;
    
    for (int i=2; i<=num; ++i) factorial[i] = factorial[i-1] * i;
    
    int digits[MAXSZ];
    for (int i=0; i<num; ++i) digits[i] = i+1;
    
    cout << reduce(digits, num, upto);
    
    return 0;
}
