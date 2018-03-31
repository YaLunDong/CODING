#include <cstdio>
#include <cmath>
#define min( x , y ) x < y ? x : y
int Tree[1001] ;

int main(){
    int n , d ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d" , &Tree[i] ) ;
        }
        scanf( "%d" , &d ) ;
        int H = log( n ) / log( 2 ) + 1 ;
        if( d > H ) printf( "EMPTY\n" ) ;
        else{
            for( int i = int( pow( 2 , d - 1 ) ) ; i < int( pow( 2 , d ) ) - 1 && i < n - 1 ; i++ )
                printf( "%d " , Tree[i] ) ;
            printf( "%d\n" ,  Tree[ min( int( pow( 2 , d ) ) - 1 , n) ] ) ;
        }
        
    }
    return 0 ;
}
