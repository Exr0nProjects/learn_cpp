#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s = 0 , w = 1 ;
    char ch = getchar() ;
    while ( ch < '0' || ch > '9' ){
        if ( ch == '-' )
            w = -1;
        ch = getchar();
    }
    while ( ch >= '0' && ch <= '9' ){ 
        s = s*10+ch-'0';
        ch = getchar();
    }
    return s*w;
}
int a [ 100005 ] , n , m ;
bool mrz_check( int k ){
    int p = 1 , q = 1 , d = a [ 1 ] , d_ = 1 ;  //p means which cow have we done, q means which room have we done
    while ( q < n ){                             //d means the coordination of the room of the last cow, d_ means the index
        q ++ ;
        if ( a [ q ] - d >= k ){  // min distance
            p ++ ;
            d = a [ q ] ;
            d_ = p ;
        }
        if ( p == m ) 
            return true ;
    }
    return false ;
}
int main(){
    n = read() ; m = read() ;
    for (int i=1 ; i <= n ; i ++ )
        a [ i ] = read() ;
    sort( a + 1 , a + n + 1 );
    int mid , l = 1 , r = 1000000000 ;
    while ( l < r )
    {
        mid = ( l + r ) / 2 + 1 ;
        bool bo = mrz_check ( mid ) ;
        if ( bo == true ) 
            l = mid ;
        else 
            r = mid - 1 ;  
    }
    printf("%d\n" , l );
    return 0;
} 
