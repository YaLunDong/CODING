#include <cstdio>
#define N 1001

using namespace std ;

int Tree[N] ;

int findRoot( int x ){
	if( Tree[x] == -1 ) return x ;
	else{
		int tmp = findRoot( Tree[x] ) ;
		Tree[x] = tmp ;
		return tmp ;
	}
}

int main(){
	int T , n , m ;
	scanf( "%d" , &T ) ;
	while( T-- ){
		scanf( "%d%d" , &n ,&m ) ;
		for( int i = 1 ; i <= n ; i++ )
			Tree[i] = -1 ;
		while( m-- ){
			int x , y ;
			scanf( "%d%d" , &x , &y ) ;
			x = findRoot( x ) ;
			y = findRoot( y ) ;
			if( x != y )
				Tree[x] = y ;
		}
		int ans = 0 ;
		for( int i = 1 ; i <= n ; i++ )
			if( Tree[i] == -1 ) ans++ ;
		
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
	
}
