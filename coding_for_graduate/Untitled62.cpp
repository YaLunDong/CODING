#include <cstdio>
#include <vector>

using namespace std ;

struct Edge{
	int next ;
	int cost ;
};
vector<Edge> edge[ 101 ] ;
bool mark[ 101 ] ;
int Dis[ 101 ] ;

int main(){
	int n , m ;
	while( ~scanf( "%d%d" , &n , &m ) ){
		
		if( m == 0 && n == 0 ) break ;
		
		for( int i = 1 ; i <= n ; i++ ) edge[i].clear() ;
		
		while( m-- ){
			int a , b , c ;
			scanf( "%d%d%d" , &a , &b , &c ) ;
		    Edge tmp ;
			tmp.next = b ;
			tmp.cost = c ;
			edge[a].push_back( tmp ) ;
			tmp.next = a ;
			edge[b].push_back( tmp ) ;
		}
		for( int i = 1 ; i <= n ; i++ ){
			Dis[i] = -1 ;
			mark[i] = false ;
		}
		Dis[1] = 0 ;
		mark[1] = true ;
		int newp = 1 ;
		for( int i = 1 ; i < n ; i++ ){
			for( int j = 1 ; j < edge[newp].size() ; j++ ){
				
				int t = edge[newp][j].next ;
				int c = edge[newp][j].cost ;
				
				if( mark[t] ) continue ;
				if( Dis[t] == -1 || Dis[t] > Dis[newp] + c )
					Dis[t] = Dis[newp] + c ;  
			}
			
			int min = 999999 ; 
			for( int j = 1 ; j <=n ; j++ ){
				if( mark[j] ) continue ;
				if( Dis[i] == -1 ) continue ;
				if( Dis[j] < min ){
					min = Dis[j] ;
					newp = j ;
				}
			}
			mark[newp] = true ;
		}
		printf( "%d\n" , Dis[n] ) ;
		
	}
	return 0 ;
}
