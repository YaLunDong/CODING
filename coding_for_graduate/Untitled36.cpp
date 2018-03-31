#include <cstdio>

int main(){
    int N ;
    while( ~scanf( "%d" , &N ) ){
        int ans[40] ;
        int size = 0 ;
        do{
            ans[ size++ ] = N % 8 ;
            N /= 8 ;
        }while( N > 0 ) ;
        for( int i = size - 1 ; i >= 0 ; i-- ){
            printf( "%d" , ans[i] ) ;
        }
        printf( "\n" ) ;
    }
    return 0 ;
}
