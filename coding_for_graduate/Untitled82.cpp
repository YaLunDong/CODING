#include <cstdio>

int buf[31] ;

int main(){
    buf[0] = 3 ;
    for( int i = 1 ; i <=30 ; i++ ){
        buf[i] = ( buf[i-1] -1 ) * 2 ;
    }
    int n ;
    scanf( "%d" , &n ) ;
    while( n-- ){
        int a ;
        scanf( "%d" , &a );
        printf( "%d\n " , buf[a] ) ;
    }
    return 0 ;
}
