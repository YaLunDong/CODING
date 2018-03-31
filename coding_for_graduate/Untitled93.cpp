#include <cstdio>
using namespace std ;

struct Node{
	int w ;
	int v ;
}mice[2001];

int dp[101] ;

int max( int a , int b ){
	return a > b ? a : b ;
}

int main(){
	int T ;
	scanf( "%d" , &T ) ;
	while( T-- ){
		int n , m ;
		scanf( "%d%d" , &n , &m ) ;
		int cnt = 0 ;
		for( int i = 1 ; i <= m ; i++ ){
			int p , h , c ;
			scanf( "%d%d%d" , &p , &h , &c ) ;
			
			
			int weight = 1 ;
			while( c - weight > 0 ){
				mice[++cnt].v = p * weight ;
				mice[cnt].w = h * weight ;
				c -= weight ;
				weight *= 2 ;
			}
			mice[++cnt].v = p * c ;
			mice[cnt].w = h * c ;
		}
		for( int i = 1 ; i <= n ; i++ ) dp[i] = 0 ;
		
		for( int i = 1 ; i <= cnt ; i++ ){
			for( int j = n ; j >= mice[i].v ; j-- ){
				dp[j] = max( dp[j] , dp[ j - mice[i].v ] + mice[i].w ) ; 
			}
		}
		printf( "%d\n" , dp[n] ) ;
	}
	return 0 ;
}
