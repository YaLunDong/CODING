#include <cstdio>

long long buf[51] ;

int main(){
    buf[1] = 3 ;
    buf[2] = 6 ;
    buf[3] = 6 ;
    for( int i = 4 ; i < 51 ; i++ )
        buf[i] = buf[i-1] + 2 * buf[i-2] ;
    int n ;
    while( ~scanf( "%d" , &n ) ){
        printf( "%lld\n" , buf[n] ) ;
    }
    return 0 ;
}
