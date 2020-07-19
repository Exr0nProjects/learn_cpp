#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 1e8 + 100;
int N, bit[MX], ans[MX];
pair<int, int> stars[MX];

void update(int n)
{
    for (; n<=MX; n += n&-n)
    {
        printf("updating %d\n", n);
        ++bit[n];
    }
}
int query(int n)
{
    int ret=0;
    for (; n; n-=n&-n)
        ret += bit[n];
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i=0; i<N; ++i)
        scanf("%d%d", &stars[i].first, &stars[i].second);
    printf("how segfalut\n");
    sort(stars, stars+N);
    for (int i=0; i<N; ++i)
    {
        ++ans[query(stars[i].second)];
        update(stars[i].second);
    }
    for (int i=0; i<N; ++i)
        printf("%d\n", ans[i]);
}

