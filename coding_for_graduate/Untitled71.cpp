//gcd
#include <cstdio>

using namespace std ;

int gcd( int a , int b ){
    if( b == 0 ) return a ;
    else
        return gcd( b , a % b) ;
}

int main(){
    int n ;
    int buf[600] ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d" , &buf[i] ) ;
        int ans = 0 ;
        for( int i = 0 ; i < n-1 ; i++ ){
            for( int j = i + 1 ; j < n ; j++ ){
                if( gcd( buf[i] , buf[j] ) == 1 )
                    ans++ ;
            }
        }
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
