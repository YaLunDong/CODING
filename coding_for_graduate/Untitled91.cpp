#include <cstdio>
#define M 101 
#define T 1001 

struct Node{
    int w ;
    int v ;
}plant[M] ;
int dp[T] ;
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
            dp[i] = 0 ;
        
        for( int i = 1 ; i <= m ; i++ ){
            for( int j = t ; j >= plant[i].w ; j-- ){
                dp[j] = max( dp[j] , dp[j-plant[i].w] + plant[i].v ) ;
            }
        }
        printf( "%d\n" , dp[t] ) ;
    }
    return 0 ;
}
