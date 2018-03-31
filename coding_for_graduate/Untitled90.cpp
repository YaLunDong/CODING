#include <cstdio>
#define M 101 
#define T 1001 

struct Node{
    int w ;
    int v ;
}plant[M] ;
int dp[M][T] ;
int max( int a , int b ){
    return a > b ? a : b ;
}
int main(){
    int t , m ;
    while( ~scanf( "%d%d" , &t , &m ) ){
        for( int i = 1 ; i <= m ; i++ ){
            scanf( "%d%d" , &plant[i].w , &plant[i].v ) ;
        }
        for( int i = 0 ; i <= t ; i++ )
            dp[0][i] = 0 ;
        
        for( int i = 1 ; i <= m ; i++ ){
            for( int j = t ; j >= plant[i].w ; j-- ){
                dp[i][j] = max( dp[i-1][j] , dp[i-1][j-plant[i].w] + plant[i].v ) ;
            }
            for( int j = plant[i].w - 1 ; j >= 0 ; j-- )
                dp[i][j] = dp[i-1][j] ;
        }
        printf( "%d\n" , dp[m][t] ) ;
    }
    return 0 ;
}
