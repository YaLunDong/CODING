#include <cstdio>
#include <algorithm>

using namespace std ;
#define MAX 0x 7fffffff 
int weight[2001] ;
int dp[1001][2001] ;
int min( int a , int b ){
    return a < b ? a : b ;
}
int main(){
    int n , k ;
    while( ~scanf( "%d%d" , &n , &k ) ){
        for( int i = 1 ; i <= n ; i++ )
            scanf( "%d" , &weight[i] ) ;
        for( int i = 1 ; i <= n ; i++ )
            dp[0][i] = 0 ;
        
        sort( weight + 1 , weight + 1 + n ) ;
        
        for( int i = 1 ; i <= k ; i++ ){
            for( int j = 2 * i ; j <= n ; j++ ){
                //dp[i][j] = MAX ;
                //dp[i][j] = min( dp[i][j-1] , dp[i-1][j-1] + ( weight[j] - weight[j-1]) * ( weight[j] - weight[j-1] ))
                if( j > 2 * i )
                    dp[i][j] = dp[i][j-1] ;
                else
                    dp[i][j] = MAX ;
                
                dp[i][j] = min( dp[i][j] , dp[i-1][j-2] + ( weight[j] - weight[j-1]) * ( weight[j] - weight[j-1] )) ;
            }
        }
        printf( "%d\n" , dp[k][n] ) ;
    }
    return 0 ;
}
