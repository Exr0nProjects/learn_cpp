/*
TASK: 6
LANG: C++14
*/

/*
 * Problem 6 (contests/dated/2020_04_20/6)
 * Create time: Mon 20 Apr 2020 @ 09:39 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;
const int MX = 1111;
int N, a[MX], b[MX], ret=0;

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i) scanf("%d", &a[i]);
    for (int i=0; i<N; ++i) scanf("%d", &b[i]);
    sort(a, a+N);
    sort(b, b+N);
    for (int i=0; i<N; ++i) ret += abs(a[i]-b[i]);
    printf("%d\n", ret);

    return 0;
}
