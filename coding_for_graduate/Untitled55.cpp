#include <cstdio>
#include <algorithm>
#include <cmath>

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
	
	bool operator < ( const struct Edge &A ) const{
		return cost < A.cost ;
	}	
}edge[5005];

int main(){
	int n ;
	while( ~scanf( "%d" , &n ) ){
		if( n == 0 ) break ;
		int flage ;
		for( int i = 1 ; i <= n * ( n - 1 ) / 2 ; i++ ){
			scanf( "%d%d%d%d" , &edge[i].s , &edge[i].e , &edge[i].cost , &flage ) ;
			if( flage ){
				edge[i].cost = 0 ;
			} 
		}
		sort( edge + 1 , edge + 1 + n * ( n - 1 ) / 2 ) ;
		for( int i = 1 ; i <= n ; i++ ) Tree[i] = -1 ;
		
		int ans = 0 ;
		for( int i = 1 ; i <= n * ( n - 1 ) / 2 ; i++ ){
			int a = findRoot( edge[i].s ) ;
			int b = findRoot( edge[i].e ) ;
			if( a != b ){
				Tree[a] = b ;
				ans += edge[i].cost ;
			}
		}
		
		printf( "%d\n" , ans ) ;
		
	}
	
	return 0 ;
} 


