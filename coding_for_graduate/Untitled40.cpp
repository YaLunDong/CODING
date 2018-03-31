#include <cstdio>
#define MAX 1010
int prime[ MAX + 1 ] ;
int primeSize ;
bool mark[ MAX + 1 ] ;

void init(){
    for( int i = 1 ; i <= MAX ; i++ ) mark[i] = false ;
    
    primeSize = 0 ;
    for( int i = 2 ; i <= MAX ; i++ ){
        if( mark[i] == true ) continue ;
        prime[ primeSize++ ] = i ;
        for( int j = i * i ; j <=MAX ; j += i ){
            mark[j] = false ;
        }
    }
}
int cnt[ MAX + 1 ] ;
int cnt2[ MAX + 1 ] ;
int main(){
    int n , a ;
    init() ;
    while( ~scanf("%d%d" , &n , &a ) ){
    	
        for( int i = 0 ; i <= MAX ; i++ ) cnt[i] = cnt2[i] = 0 ;
        
        for( int i = 0 ; i < primeSize ; i++ ){//¶Ô n£¡ 
            int t = n ;
            while( t > 0 ) {
                cnt[i] += t / prime[i] ;
                t /= prime[i] ;
            }
        }
        
        int ans = 99999;
        
        for( int j = 0 ; j < primeSize ; j++ ){ //¶Ô a 
            while( a % prime[j] == 0 ){
                cnt2[j]++ ;
                a /= prime[j] ;
                }
            if( cnt2[j] == 0 ) continue ;
            if( cnt[j] / cnt2[j] < ans ) ans = cnt[j] / cnt2[j] ;
        }
        
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
