#include <cstdio>

int max (int x , int y){ return x > y ? x : y ; }
int height[26] ;
int dp[26] ;

int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
        
        for( int i = 1 ; i <= n ; i++ )
            scanf( "%d" , &height[i] ) ;
        
        for( int i = 1 ; i <= n ; i++ ){
            int tmax = 1 ;
            for( int j = 1 ; j < i ; j++ ){
                if( height[j] >= height[i] ){
                    tmax = max( tmax , dp[j] + 1 ) ;
                }
            }
            dp[i] = tmax ;
        }
        int ans = 1 ;
        for( int i = 1 ; i <= n ; i++ )
            ans = max( ans , dp[i] ) ;
        
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
