#include <iostream>
#include <cstdio>
#define max_v 22000
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

int BIT[max_v];

//int S(int k){
//  if(k <= 0) return 0;
//  return BIT[k] ^ S(k - lsb(k));
//}
//
//void U(int k, int i){
//  if(k >= max_v) return ;
//  BIT[k] = BIT[k] ^ i;
//  U(k + lsb(k), i);
//}
//
//int S(int a, int b){
//  if(b < a) return 0;
//  return S(b) ^ S(a - 1);
//}

void U(int n, int m)
{
    int v = n;
    for (; n<=max_v; n+=n&-n)
        BIT[n] ^= v;
}
int S(int l, int r)
{
    if (l > r) return 0;
    int tot=0; --l;
    for (; r>l; r-=r&-r)
        tot ^= BIT[r];
    for (; l>r; l-=l&-l)
        tot ^= BIT[l];
    return tot;
}

int main(){
    string com;
  while(!cin.eof()){
    cin >> com;
    if(com[0] == 'A'){
      int a;
      cin >> a;
      U(a, a);
    }else if(com[0] == 'R'){
      int a;
      cin >> a;
      U(a, a);
    }else {
      cin >> com;
      int a, b;
      cin >> a >> com >> b;
      cout << S(a, b) << endl;
    }


  }

    return 0;
}

