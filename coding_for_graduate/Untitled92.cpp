#include <cstdio>
#define INF 0x7ffffff
int min( int a , int b ){
    return a < b ? a : b ;
}
struct Node{
    int w ;
    int v ;
}coin[501] ;
int dp[10001] ;
int main(){
    int T ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        int s , tmp ;
        scanf( "%d%d" , &s , &tmp ) ;
        s -= tmp ;
        int n ;
        scanf( "%d" , &n ) ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d%d" , &coin[i].v , &coin[i].w ) ;
        }
        dp[0] = 0 ;
        for( int i = 1 ; i <= s ; i++ ) dp[i] = INF ;
        
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = coin[i].w ; j <= s ; j++ ){
                if( dp[j-coin[i].w] != INF ){
                    dp[j] = min( dp[j], dp[i-coin[i].w] + coin[i].v ) ;
                }
            }
        }
        if( dp[s] != INF )
            printf( "The minimum amount of money in the piggy-bank is %d\n" , dp[s] ) ;
        else
            printf( "This is impossible.\n" ) ;
    }
    return 0 ;
}
