#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std ;

int main(){
    int n ;
    int buf[10000] ;
    while( ~scanf( "%d" , &n ) ){
        if( n == 0 ) break ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d" , &buf[i] ) ;
        sort( buf , buf + n ) ;
        
        int ans ;
        if( n % 2 == 0 )
           ans = ( buf[ ( n - 1 ) / 2 ] + buf[ ( n - 1 ) / 2 + 1 ] ) / 2 ;
        else
            ans = buf[ n / 2 ] ;
        
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
