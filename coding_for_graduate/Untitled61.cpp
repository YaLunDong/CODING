#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAX 101

int ans[MAX][MAX] ;

int main(){
    int n , m ;
    while( ~scanf( "%d%d" , &n , &m ) ){
        if( n == 0 && m == 0 ) break ;
        for( int i = 1 ; i <=n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i != j ) ans[i][j] = -1 ;
                else ans[i][j] = 0 ;
            }
        }
        while( m-- ){
            int A , B , C ;
            scanf( "%d%d%d" , &A , &B , &C ) ;
            ans[A][B] = C ;
            ans[B][A] = C ;
        }
        for( int k = 1 ; k <= n ; k++ ){
            for( int i = 1 ; i <= n ; i++ ){
                for( int j = 1 ; j <= n ; j++ ){
                    if( ans[i][k] == -1 || ans[k][j] == -1) continue ;
                    if( ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j] )
                        ans[i][j] = ans[i][k] + ans[k][j] ;
                    
                }
            }
        }
        printf( "%d\n" ,ans[1][n] ) ;
    }
    return 0 ;
}

