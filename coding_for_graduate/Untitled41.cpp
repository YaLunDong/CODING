#include <cstdio>
#include <cmath>
#define MAX 1000
int buf[ MAX + 1 ] ;
int main(){
    int N ;
    while( ~scanf( "%d" , &N ) ){
        for( int i = 0 ; i < N ; i++ ){
            scanf( "%d" , &buf[i] ) ;
        }
        
        for( int i = 0 ; i < N ; i++ ){
            
            double float_bound = sqrt( buf[i] ) ;
            
            int int_bound = int( float_bound ) ;
            
            int ans = 0 ;
            
            if( float_bound - int_bound < 0.00001 ){ 
                ans++ ;
            for( int j = 1 ; j < int_bound ; j++ ){
                if( buf[i] % j == 0 )
                    ans += 2 ;
            }
            }
			else{
			 for( int j = 1 ; j <= int_bound ; j++ ){
                if( buf[i] % j == 0 )
                    ans += 2 ;	
			} 
			} 
            printf( "%d\n" , ans ) ;
        }
        
    }
    return 0 ;
}
