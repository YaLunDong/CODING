#include <cstdio>
#include <cstring>
using namespace std ;

#define MAX 102
int dp[MAX][MAX] ;
int max( int a , int b ){ return a > b ? a : b ; }

int main(){
    char buf1[MAX] , buf2[MAX] ;
    while( ~scanf( "%s%s" , buf1 , buf2 ) ){
        int L1 = strlen( buf1 ) ;
        int L2 = strlen( buf2 ) ;
        for( int i = 0 ; i <= L1 ; i++ ) dp[i][0] = 0 ;
        for( int j = 0 ; j <= L2 ; j++ ) dp[0][j] = 0 ;
        
        for( int i = 1 ; i <= L1 ; i++ ){
            for( int j = 1 ; j <= L2 ; j++ ){
                if( buf1[i-1] != buf2[j-1] ){
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) ;
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                }
            }
        }
        printf( "%d\n" , dp[L1][L2] ) ;
    }
    return 0 ;
}
