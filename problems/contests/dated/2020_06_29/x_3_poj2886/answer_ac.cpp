#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#define ll long long
using namespace std;
struct Node{
    int sum;
    int lc;
    int rc;
};
int nnext = 0;
Node nodes [13000000];
string kids [500000];
int candies [500001];
int numbers [500000];
int root = 0;
int construct(int left, int right){
    if(left == right){
        nodes[++nnext].sum = 1;
        nodes[nnext].lc = 0;
        nodes[nnext].rc = 0;
        return nnext;
    }else{
        int a = construct(left,(left+right)/2);
        int b = construct((left+right)/2 + 1,right);
        nodes[++nnext].lc = a;
        nodes[nnext].rc = b;
        nodes[nnext].sum = right-left+1;
        return nnext;
    }
}
void modify(int position, int left, int right, int cur){
    nodes[cur].sum--;
    if(left != right){
        if(position <= (left+right)/2){
            modify(position,left,(left+right)/2,nodes[cur].lc);
        }else{
            modify(position,(left+right)/2 + 1, right, nodes[cur].rc);
        }
    }
}
int findkth(int num, int left, int right, int cur){
    //cout << num << " " << left << " " << right << " " << cur << endl;
    if(left == right){
        return left;
    }else{
        if(num >= nodes[nodes[cur].lc].sum){
            //go to rseie
            return findkth(num-nodes[nodes[cur].lc].sum, (left+right)/2 + 1, right, nodes[cur].rc);
        }else{
            //go to elsie
            return findkth(num, left, (left+right)/2, nodes[cur].lc);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n,k;
    while(cin >> n){
        cin >> k;
        k--;
        for(int i = 1; i <= n; i++){
            candies[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n; j+=i){
                candies[j]++;
            }
        }
        nnext = 0;
        root = construct(0,n-1);
        char buff [13];
        for(int i = 0; i < n; i++){
            scanf("%10s",buff);
            kids[i] = buff;
            //cout << kids[i] << endl;
            scanf("%d",&numbers[i]);
            //cout << kids[i] << "---" << numbers[i] << endl;
        }
        int curbest = 0;
        string kid = "";
        for(int i = 1; i <= n; i++){
            //cout << k << endl;
            //cout << kid << " " << curbest << endl;
            int x = findkth(k,0,n-1,root);
            //cout << x << endl;
            //cout << x << endl;
            if(candies[i] > curbest){
                kid = kids[x];
                curbest = candies[i];
            }
            //move and update k.
            modify(x,0,n-1,root);
            if(i != n){
                if(numbers[x] > 0){
                    k += numbers[x];
                    k = k-1;
                    k += 2*(n-i);
                    k = k % (n-i);
                }else{
                    numbers[x] = -numbers[x];
                    numbers[x] = numbers[x]%(n-i);
                    k -= numbers[x];
                    k += 2*(n-i);
                    k = k%(n-i);
                }
            }
        }
        printf("%s %d\n", kid.c_str(), curbest);
    }
    return 0;
}

