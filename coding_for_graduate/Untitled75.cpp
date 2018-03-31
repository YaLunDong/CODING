#include<cstdio>

using namespace std ;

long long F( int x ){
    if( x == 1 ) return 2 ;
    else
        return 3 * F( x - 1 ) + 2 ;
}

int main(){
    int n ;
    while(~scanf( "%d" , &n ) ){
        printf( "%lld\n" , F( n ) ) ;
    }
    return 0 ;
}
