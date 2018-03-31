#include <cstdio>

using namespace std ;

int main(){
    int n , x , y , z ;
    int per_price , first , last ;
    while( ~scanf( "%d" , &n ) ){
        per_price = 0 ;
        
        scanf( "%d%d%d" , &x , &y , &z ) ;
        for( int f = 1 ; f <= 9 ; f++){
            for( int l = 0 ; l <= 9 ; l++ ){
                if( ( f * 10000 + x * 1000 + y * 100 + z * 10 + l ) % n == 0 ){
                    per_price = ( f * 10000 + x * 1000 + y * 100 + z * 10 + l ) / n ;
                    first = f ;
                    last = l ;
                }
            }
        }
        if( per_price)
            printf( "%d %d %d\n" , first , last , per_price ) ;
        else
            printf( "0\n" ) ;
    }
    return 0 ;
}
