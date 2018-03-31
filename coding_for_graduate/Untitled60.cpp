#include <cstdio>
using namespace std ;

#define N 100 
#define MOD 100000
int ans[N][N] ;

int main(){
    int n , m ;
    while( ~scanf( "%d%d" , &n , &m ) ){
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( i == j ) ans[i][j] = 0 ;
                else ans[i][j] = -1 ;
            }
        }
        int cost = 1 ;
        for( int i = 1 ; i <=m ; i++ ){
            int x , y ;
            scanf( "%d%d" , &x , &y ) ;
            
            ans[x][y] = cost ;
            cost = cost * 2 % MOD ;
        }
        for( int k = 0 ; k < n ; k++ ){
            for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j< n ; j++ ){
                    if( ans[i][k] == -1 || ans[k][j] == -1 ) continue ;
                    if( ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j] )
                        ans[i][j] = ans[i][k] + ans[k][j] ;
                }
            }
        }
        
        for( int i = 1 ; i < n ; i++ )
            printf( "%d\n" , ans[0][i] ) ;
    }
    return 0 ;
}
