#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
  
int n, k;
double a[10001], l, r, m;
  
bool check(double t){
    int total = 0;
    for (int i = 1; i <= n; i ++){
        total += floor(a[i] / t);
        if (total >= k){
            return 1;
        }
    }
    return 0;
}
  
int main (){
    cin >> n >> k;
    l=0;r=0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        r += a[i];
    }
    for(int i=0;i<100;i++){
        m = (r + l) / 2;
        if (check(m)){
            l = m;
        }else{
            r = m;
        }
    }
    printf("%.2f", floor(l * 100) / 100);
    return 0;
} 
