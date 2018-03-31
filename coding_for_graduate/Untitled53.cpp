#include <cstdio>
#include <cmath>
#include <algorithm>

#define N 101

using namespace std ;

int  Tree[N] ;

int findRoot( int x ){
	if( Tree[x] == -1 ) return x ;
	else{
		int tmp = findRoot( Tree[x] ) ;
		Tree[x] = tmp ;
		return tmp ;
	}
}

struct Edge{
	int a ;
	int b ;
	double cost ;
	bool operator < ( const Edge &A ) const{
		return cost < A.cost ;
	}
}edge[5005];

struct node{
	double x ;
	double y ;
	double getDistance( struct node &A ){
		double tmp = ( x - A.x ) * ( x - A.x ) + ( y - A.y ) * ( y - A.y ) ;
		return sqrt( tmp ) ;
	}
}list[N];

int main(){
	int n ;
	while( ~scanf( "%d" , &n ) ){
		for( int i = 1 ; i <= n ; i++ ){
			scanf( "%lf%lf" , &list[i].x , &list[i].y ) ;
		}
		int size = 0 ;
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = i + 1 ; j <= n ; j++ ){
				edge[size].a = i ;
				edge[size].b = j ;
				edge[size++].cost = list[i].getDistance( list[j] ) ;
			}
		}
		sort( edge , edge + size ) ;
		
		for( int i = 1 ; i <= n ; i++ ) Tree[i] = -1 ;
		
		int cnt = 0 ;
		double ans = 0.0 ;
		for( int i = 0 ; i < size ; i++ ){
			if( cnt == n - 1 ) break ;
			int a = findRoot( edge[i].a ) ;
			int b = findRoot( edge[i].b ) ;
			if( a != b ){
				Tree[a] = b ;
				ans += edge[i].cost ;
				cnt++ ;
			} 
		}
		printf( "%.2lf\n" , ans ) ;
	}
	return 0 ;
}
