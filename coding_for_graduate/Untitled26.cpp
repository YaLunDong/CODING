#include <cstdio>
#include <cmath>
int countNode( int n , int m ){
    if( m > n ) return 0 ;
    else return countNode( n , 2 * m ) + countNode( n ,2 * m + 1 ) + 1 ;
}
int main(){
    int n , m ;
    int cnt ;
    while( ~scanf( "%d%d" , &n , &m ) ){
        
        int res = countNode( n , m ) ;
        
        printf( "%d\n" , res ) ;
        
    }
    return 0 ;
}

