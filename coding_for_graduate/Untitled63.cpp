#include <cstdio>
#include <vector>

using namespace std ;

struct E{
	int next ;
	int past ;
	int cost ;
};
vector<E> edge[1001] ;

int Dis[1001] ;
bool mark[1001] ;
int cost[1001] ;

int main(){
	int n , m ;
	while( ~scanf( "%d%d" , &n , &m ) ){
		if( n == 0 && m == 0 ) break ;
		for( int i = 1 ; i <= n ; i++ ) edge[i].clear() ;
		while( m-- ){
			
			int a , b , d , p ;
			scanf( "%d%d%d%d" , &a , &b , &d , &p ) ;
			E tmp ;
			tmp.next = b ;
			tmp.past = d ;
			tmp.cost = p ;
			edge[a].push_back( tmp ) ;
			
			tmp.next = a ;
			edge[b].push_back( tmp ) ;
		}
		int S , T ;
		scanf( "%d%d" , &S , &T ) ;
		
		for( int i = 1 ; i<= n ; i++ ){
			Dis[i] = -1 ;
			mark[i] = false ;	
		}
		
		Dis[S] = 0 ;
		mark[S] = true ;
		int newp = S ;
		
		for( int i = 1 ; i < n ; i++ ){
			
			for( int j = 0 ; j < edge[newp].size() ; j++ ){
				int tx = edge[newp][j].next ;
				int pastx = edge[newp][j].past ;
				int costx = edge[newp][j].cost ;
				
				if( mark[tx] ) continue ;
				if( Dis[tx] == -1 || Dis[ tx ] > Dis[newp] + pastx || Dis[tx] == Dis[newp] + pastx && cost[tx] > cost[newp] + costx ){
					Dis[tx] = Dis[newp] + pastx ;
					cost[tx] = cost[newp] + costx ;
				}
				
			}
			int min = 99999 ;
			for( int j = 1 ; j<=n ; j++ ){
				if( mark[j] ) continue ;
				if( Dis[j] == -1 ) continue ;
				if( Dis[j] < min ){
					min = Dis[j] ;
					newp = j ;
				}
			}
			mark[newp] = true ;
		}
		printf( "%d %d\n" , Dis[T] , cost[T] ) ;
	} 
	return 0 ;
}
