#include <cstdio>

using namespace std ;

#define MOD 10 ;

bool Relation( int x ){
    if( x % 7 == 0 ) return true ;
    while( x > 0 ){
        int tmp = x % MOD ;
        if( tmp == 7 ) return true ;
        x /= MOD ;
    }
   return false ;
}
int main(){
    int n ;
    int sum ;
    while( ~scanf( "%d" , &n) ){
        sum = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            if( !Relation( i )) sum += i * i ;
        }
        printf( "%d\n" , sum ) ;
    }
    return 0 ;
}
