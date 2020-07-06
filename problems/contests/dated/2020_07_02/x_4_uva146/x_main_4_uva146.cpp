/*
 * Problem 4_uva146 (contests/dated/2020_07_02/4_uva146)
 * Create time: Mon 06 Jul 2020 @ 13:32 (PDT)
 * Accept time: Mon 06 Jul 2020 @ 13:53 (PDT)
 *
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char buf[60];

int main()
{
    int N;
    while (~scanf("%s", buf) && buf[0] != '#')
    {
        N = strlen(buf);
        int i=N-2, j=N-1;
        for (; i>=0 && buf[i]>=buf[i+1]; --i);
        if (i<0 && buf[0] >= buf[1])
            printf("No Successor\n");
        else
        {
            for (; buf[j] <= buf[i]; --j);
            swap(buf[i], buf[j]);
            sort(buf+i+1, buf+N);
            printf("%s\n", buf);
        }
    }

	return 0;
}

