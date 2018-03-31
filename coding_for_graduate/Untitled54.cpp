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
	bool operator < ( const Edge &A ) const {
		return cost < A.cost ; 
	}
}edge[N];

int main(){
	int n , m ;
	while( ~scanf( "%d%d" , &n , & m ) ){ // nÏßÂ· m´å×¯ 
		
		if( n == 0 ) break ;
		for( int i = 1 ; i <= n ; i++ ){
			scanf( "%d%d%d" , &edge[i].s , &edge[i].e , &edge[i].cost ) ;
		} 
		if( n < m - 1 ){
			printf( "?\n" ) ;
			continue ;
		}
		sort( edge + 1 , edge + 1 + n ) ;
		for( int i = 1 ; i <= m ; i++ ) Tree[i] = -1 ;
		int ans = 0 ;
		int cnt = 0 ;
		for( int i = 1 ; i <= n ; i++ ){
			if( cnt == n - 1 ) break ;
			int s = findRoot( edge[i].s ) ;
			int e = findRoot( edge[i].e ) ;
			if( s != e ){
				Tree[s] = e ;
				ans += edge[i].cost ;
				cnt++ ;
			}
		} 
		int cnt2 = 0 ;
		for( int i = 0 ; i<= m ; i++ ){
			if( Tree[i] == -1 ){
				cnt2++ ; 
			}
			if( cnt2 > 1){
				printf( "?\n" ) ;
				break ;
			}
		}
		
		if( cnt2 == 1 ){
			printf( "%d\n" , ans ) ;
		}
	}
	
	return 0 ;
}


