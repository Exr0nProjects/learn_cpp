/*
 * Problem #1418
 * seeing heads in  a line
 */
// #1418 written by XC1900105AH on 15 July 2019

#include <bits/stdc++.h>
#define ll long long
#define dl double

using namespace std;

int mq [5010];

int main ()
{
    int cansee=0, num, pos;
    cin >> num >> pos; --pos;
    for (int i=0; i<num; ++i) cin >> mq[i];

    int pt = pos + 1;

    dl mslope = -2000000000;
    for (; pt < num; ++pt)
    {
        dl tslope = (dl)(mq[pt] - mq[pos]) / (dl)(pt-pos);
//        cout << pt-mq << " (" << pt-mq-pos << ", " << *pt-mq[pos] << "): " << tslope << endl;
        if (tslope >= mslope) { mslope = tslope; ++cansee; }
    }

   // cout << "\n\ncansee: " << cansee << "\n\n";

    pt = pos - 1;
    mslope = -2000000000;
    for (; pt >= 0; --pt)
    {
        dl tslope = (dl)(mq[pos] - mq[pt]) / (dl)(pt-pos);
//        cout << pt-mq << " (" << pt-mq-pos << ", " << *pt-mq[pos] << "): " << tslope << endl;
        if (tslope >= mslope) { mslope = tslope; ++cansee; }
    }

    cout << cansee;

    return 0;
}
