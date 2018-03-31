#include <cstdio>
#include <stack>
#include <queue>

using namespace std ;

priority_queue < int , vector < int > , greater < int > > Q ;

int main(){
	int n ;
	int weight ;
	while( ~scanf( "%d" , &n ) ){
		
		while( !Q.empty() ) Q.pop() ;
		for( int i = 0 ; i < n ; i++ ){
			scanf( "%d" , &weight ) ;
			Q.push( weight ) ;
		}
		int ans = 0 ;
		while( Q.size() > 1 ){
			
			int a = Q.top() ;
			Q.pop() ;
			int b = Q.top() ;
			Q.pop() ;
			
			ans += a + b ;
			Q.push( a + b ) ;
		}
		
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
