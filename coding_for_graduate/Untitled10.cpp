#include <cstdio>

int main(){
    int n , x ;
    int flag;
    int buf[200];
    while( ~scanf( "%d" , &n ) ){
        flag = -1 ;
        for( int i = 0 ; i < n ; i++ )
            scanf( "%d" , &buf[i] ) ;
        scanf( "%d" , &x ) ;
        for( int i =0 ; i < n ; i++ )
            if( buf[i] == x ){
                flag = i ;
                break ;
            }
        printf( "%d\n" , flag ) ;
    }
    return 0;
}
