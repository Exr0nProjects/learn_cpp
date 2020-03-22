#include <iostream>

using namespace std;
const int MX = 1000010;
int N, S, nums[MX];

int main () {
    scanf("%d%d", &N, &S);
    for (int i=0; i<N; ++i) scanf("%d", &nums[i]);

    int l=0, r=N;
    for (int i=0; i<20; ++i)
    {
        int m = (l+r)/2;
        if (nums[m] >= S) r = m;
        else l = m;
    }
    if (nums[l+1] != S) printf("0\n");
    else printf("%d\n", l+1+1);
}

