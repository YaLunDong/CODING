// write your code here cpp
#include <cstdio>

int main(){
    int x , y ;
    int common_Root ;
    while( ~scanf( "%d%d" , &x , &y ) ){
        while( true ){
            if( x == y ) { common_Root = x ; break ; }
            if( x / 2 == y ) { common_Root = y ; break ; }
            if( y / 2 == x ) { common_Root = x ; break ; }
            if( y / 2 == x / 2) { common_Root = x / 2 ; break ; }
            x /= 2 ;
            y /= 2 ;
        }
        printf( "%d\n" , common_Root ) ;
    }
    return 0 ;
}
