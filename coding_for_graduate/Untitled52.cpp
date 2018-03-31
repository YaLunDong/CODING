#include <cstdio>
#include <algorithm>

using namespace std ;

#define N 101

int Tree[N] ;

int findRoot( int x ){
	if( Tree[x] == -1 ) return x ;
	else{
		int tmp = findRoot( Tree[x] ) ;
		Tree[x] = tmp ;
		return tmp ;
	}
}

struct Edge{
	int s ;
	int e ;
	int cost ;
	
	bool operator < ( const Edge &A ) const{
		return cost < A.cost ;
	}
}edge[ 5000 ];

int main(){
	int n ;
	while( ~scanf( "%d" , &n ) && n != 0 ){
		for( int i = 1 ; i <= n ; i++ ) Tree[i] = -1 ;
		for( int i = 1 ; i<= n * ( n - 1 ) / 2 ; i++ ){
			scanf( "%d%d%d" , &edge[i].s , &edge[i].e , &edge[i].cost ) ;
		}
		
		sort( edge + 1 , edge + 1 + n * ( n - 1 ) / 2 ) ;
		
		int cnt = 0 ;
		int ans = 0 ;
		for( int i = 1 ; i <= n * ( n - 1 ) / 2 ; i++ ){
			if( cnt == n - 1 ) break ;
			int a = findRoot( edge[i].s ) ;
			int b = findRoot( edge[i].e ) ;
			if( a != b ){
			
				Tree[a] = b ;
				ans += edge[i].cost ;
				cnt++ ;
			}
		}
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
