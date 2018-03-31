#include <cstdio>

using namespace std ;
#define OFFSET 2000 
#define INF 0x7fffffff
int w[101] ;
int dp[101][4001] ;

int main(){
    int T ;
    int cas = 0 ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        int cnt = 0 ;
        int n ;
        bool flage = false ;
        scanf( "%d" , &n ) ;
        for( int i = 0 ; i < n ; i++ ){
            int x ;
            scanf( "%d" , &x ) ;
            if( x != 0 ){
                w[++cnt] = x ;
            }
            if( x == 0 ) flage = true ;
        }
        n = cnt ;
        for( int i = -2000 ; i <= 2000 ; i++ ){
            dp[0][i + OFFSET ] = -INF ;
        }
        dp[0][ 0 + OFFSET ] = 0 ;
        
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = -2000 ; j <= 2000 ; j++ ){
                int tmp1 = -INF ;
                int tmp2 = -INF ;
                if( j + w[i] <= 2000 && dp[i-1][j + w[i] + OFFSET] != -INF )
                    tmp1 = dp[i-1][j + OFFSET + w[i]] + w[i] ;
                if( j - w[i] >= -2000 && dp[i-1][j-w[i]+ OFFSET] != -INF)
                    tmp2 = dp[i-1][j-w[i]+OFFSET] + w[i] ;
                if( tmp1 < tmp2) tmp1 = tmp2 ;
                if( tmp1 < dp[i-1][j+OFFSET] ) tmp1 =dp[i-1][j+OFFSET] ;
                dp[i][j+OFFSET] = tmp1 ;
            }
        }
        printf( "Case %d: " , ++cas ) ;
        if( dp[n][0+OFFSET] == 0 ){
            puts( flage == true ? "0" : "-1" ) ;
        }
        else{
            printf( "%d\n" , dp[n][0+OFFSET] / 2 ) ;
        }
      
    }
    return 0 ;
}
