#include <cstdio>
#include <vector>
#include <queue>

using namespace std ;

#define MAX 501 

vector < int > edge[MAX] ;
queue < int > Q ;
int main(){
	int inDegree[MAX] ;
	int n , m ;
	while( ~scanf( "%d%d" , &n , &m ) ){
		if( n == 0 && m == 0 ) break ;
		for( int i = 0 ; i < n ; i++){
			inDegree[i] = 0 ;
			edge[i].clear() ;
		}
		for( int i = 0 ; i < m ; i++ ){
			int a , b ;
			scanf( "%d%d" , &a , &b ) ;
			inDegree[b]++ ;
			edge[a].push_back( b ) ;
		
		}
		while( Q.empty() == false ) Q.pop() ;
		
		for( int i = 0 ; i < n ; i++ ){
			if( inDegree[i] == 0 )
				Q.push( i ) ;
		}
		
		int cnt = 0 ;
		while( Q.empty() == false ){
			int tmp = Q.front() ;
			Q.pop() ;
			cnt++ ;
			for( int i = 0 ; i < edge[tmp].size() ; i++ ){
				inDegree[ edge[tmp][i] ]-- ;
				if( inDegree[edge[tmp][i]] == 0 ){
					Q.push( edge[tmp][i] ) ;
				}
			}
		}
		if( cnt == n )
			printf( "YES\n" ) ;
		else
			printf( "NO\n" ) ;
    }
	return 0 ;
} 
