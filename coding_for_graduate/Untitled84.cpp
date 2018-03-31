#include <cstdio>

int main(){
    long long buf[21] , p ;
    buf[1] = 0 ;
    buf[2] = 1 ;
    for( int i = 3 ; i < 21 ; i++ )
        buf[i] = ( i - 1 ) * ( buf[i-1] + buf[i-2] ) ;
    int c ;
    int n , m ;
    scanf( "%d" , &c ) ;
    while( c-- ){
    	
        scanf( "%d%d" , &n , &m ) ;
        p = 1 ;
        for( int i = n - m + 1 ; i <= n ; i++ ) p *= i ;
        for( int i = 1 ; i <= m ; i++ ) p /= i ;
    
        printf( "%lld\n" , p * buf[m]) ;
    }
    return 0 ;
}
