#include <cstdio>
#include <cmath>
int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
        bool flage = true ;
        if( n == 1 ) flage = false ;
        int bound = int( sqrt( n ) ) + 1 ;
        for( int i = 2 ; i <= boundn ; i++ )
            if( n % i == 0 ){
                flage = false ;
                break ;
            }
        if( flage ) printf( "yes\n" ) ;
        else printf( "no\n" ) ;
    }
    return 0 ;
}
