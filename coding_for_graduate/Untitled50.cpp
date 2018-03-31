#include <cstdio>

#define MAX 1002
using namespace std ;

int Tree[MAX] ;

int findRoot( int x ){
	if( Tree[x] == -1 ) return x ;
	else{
		int tmp = findRoot( Tree[x] ) ;
		Tree[x] = tmp ;
		return tmp ;
	}
}

int main(){
	int n , m ;
	while( ~scanf( "%d%d" , &n , &m ) ){
		
		for( int i = 1 ; i <= n ; i++ )
			Tree[i] = -1 ;
		
		int x , y ;
		
		while( m--){

			scanf( "%d%d" , &x , &y ) ;

			x = findRoot( x ) ;
			y = findRoot( y ) ;
			if( x != y ){
				Tree[x] = y ;
			}
		}
		int cnt = 0 ;
		for( int i = 1 ; i <= n ; i++ )
			if( Tree[i] == -1 ) cnt++ ;
		
		if( cnt > 1 ) printf( "NO\n" ) ;
		else printf( "YES\n" ) ;
	}
	return 0 ;
}
