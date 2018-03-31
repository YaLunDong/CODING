#include <cstdio>

#define MAX 101 
int max( int a , int b ){ return a > b ? a : b ; }
int T[MAX] ;
int dp1[MAX] ;
int dp2[MAX] ;

int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 1 ; i <= n ; i++ )
            scanf( "%d" , &T[i] ) ;
        
        for( int i = 1 ; i <= n ; i++ ){
            int tmax = 1 ;
            for( int j = 1 ; j < i ; j++ ){
                if( T[j] < T[i] ){
                    tmax = max( tmax , dp1[j] + 1 ) ;
                }
            }
            dp1[i] = tmax ;
        }
        for( int i = n ; i >= 0 ; i-- ){
            int tmax = 1 ;
            for( int j = n ; j > i ; j-- ){
                if( T[j] < T[i] ){
                    tmax = max( tmax , dp2[j] + 1 ) ;
                }
            }
            dp2[i] = tmax ;
        }
        int ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ){
            ans = max( ans , dp1[i] + dp2[i] - 1 ) ;
        }
        printf( "%d\n" , n - ans ) ;
    }
    return 0 ;
}
