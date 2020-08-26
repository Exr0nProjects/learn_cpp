/*
 * Problem 1 (contests/standard-xjoi/1613/1)
 * Create time: Tue 25 Aug 2020 @ 19:00 (PDT)
 * Accept time: [!meta:end!]
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>

#define ll long long
#define dl double

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;
const ll MX = 1e4+10;

//int N, M, vec[MX], vis[MX][MX], tot=0;
int N, M, vec[MX], tot=0;
//unordered_set<int> ddup;
const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109}, pcnt = 29; // that moment when you write linear sieve but its shorter, faster, and more mem efficient to just da biao
int lcm_temp[40];
//int sieve[110], pri[110], pcnt=0;
//void kpri()
//{
//    for (int i=2; i<110; ++i)
//    {
//        if (!sieve[i])
//            pri[pcnt++] = i;
//        for (int j=0; j<pcnt && pri[j]*i < 110; ++j)
//        {
//            sieve[pri[j]*i] = i;
//            if (i % pri[j] == 0) break;
//        }
//    }
//    for (int i=0; i<pcnt; ++i) printf("%d, ", pri[i]); printf("\n");
//}

void klcm(int n)
{
    memset(lcm_temp, 0, sizeof lcm_temp);
    int prod=1;
    //for (int i=0; i<n; ++i) printf("%3d", vec[i]);
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<pcnt; ++j)
        {
            int cur=1;
            while (vec[i] % (cur*pri[j]) == 0)
                cur *= pri[j];
            lcm_temp[j] = max(lcm_temp[j], cur);
        }
    }
    for (int j=0; j<pcnt; ++j)
        prod *= lcm_temp[j];
    tot = (prod + tot) % M;
    //printf(" -> %d\n", prod);
}

void gen(int i, int r)
{
    //if (vis[i][r]) return;    // TODO: i can't just memoize can i
    //vis[i][r] = 1;
    klcm(i);
    for (int d=(i?vec[i-1]:1)+1; d<=r; ++d) {
        vec[i] = d;
        gen(i+1, r-d);
    }
}

int main()
{
    //kpri();
    scanf("%d%d", &N, &M);
    gen(0, N);
    printf("%d\n", tot+1);

	return 0;
}

