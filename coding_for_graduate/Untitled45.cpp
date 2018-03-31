#include <cstdio>
#include <queue>

using namespace std ;

queue <int> Q ;

int main(){
	int n , k ;
	while( ~scanf( "%d%d" , &n , &k ) ){
		while( Q.size() > 0 ) Q.pop() ;
		for( int i = 1 ; i <= n ; i++ ){
			Q.push( i ) ;
		}
		int bomb = 1 ;
		while( Q.size() > 1 ){
			int tmp = Q.front() ;
			Q.pop() ;
			if( bomb % k == 0 || bomb % 10 == k ){}
			else{
				Q.push( tmp ) ;
			}
			bomb++ ;
		}
		printf( "%d\n" , Q.front() ) ;
	}
	return 0 ;
}
