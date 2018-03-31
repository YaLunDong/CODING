#include <cstdio>
#include <queue>

using namespace std ;

priority_queue < int , vector < int > , greater < int > > Q ;

int main(){
	int n ;
	int cost ;
	while( ~scanf( "%d" , &n ) ){
		
		while( !Q.empty() ) Q.pop() ;
		
		while( n-- ){
			scanf( "%d" , &cost ) ;
			Q.push( cost ) ; 
		}
		
		int sum = 0 ;
		while( Q.size() > 1 ){
			
			int a = Q.top() ;
			Q.pop() ;
			int b = Q.top() ;
			Q.pop() ;
			
			sum += a + b ;
			Q.push( a + b ) ; 
		}
		
		printf( "%d\n" , sum ) ;
	}
	return 0;
}
