#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#define rand(l,h) (rand()%(h-l+1)+l)
using namespace std;

//const int MX = 1e5;
//const int MXM = 5e4;
const int MX = 5;
const int MXM = 4;
int arr[MX+10];

int main()
{
    srand(time(0));
    int N = rand(MX/10, MX);
    int M = rand((int)fmin((int)(MXM/10), (int)N), (int)fmin((int)MXM, (int)N));
    printf("%d %d\n", N, M);

    iota(arr, arr+N, 1);
    for (int i=0; i<N; ++i)    // generate a random permutation
        swap(arr[i], arr[rand(0, N-1)]);

    for (int i=0; i<N; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    } printf("\n");

    for (int i=0; i<N; ++i)    // generate a random permutation
        swap(arr[i], arr[rand(0, N-1)]);
    for (int i=0; i<M; ++i) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    } printf("\n");

    return 0;
}

