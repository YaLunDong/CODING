#include <cstdio>
#include <cmath>

int main(){
    int mod ;
    int N ;
    int tmp ;
    while( ~scanf( "%d" , &N ) ){
        mod = 1 ;
        tmp = N * N ;
        bool flage = false ;
        while( tmp % mod < tmp ){
            if( tmp % mod == N ){
                flage = true ;
                break ;
            }
            mod *= 10 ;
        }
        if( flage ) printf( "Yes!\n" ) ;
        else printf( "No!\n" ) ;
    }
    return 0 ;
}
