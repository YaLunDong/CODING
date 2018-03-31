#include <cstdio>
#include <cmath>
using namespace std ;

int main(){
	int buf[1001];
	int n;
	int res = 10000 ;
	scanf( "%d" , &n ) ;
	for( int i = 0 ; i < n ; i++ ){
		scanf( "%d" , &buf[i] ) ;
	}
	for( int i = 0 ; i < n - 1 ; i++ ){
		
		for( int j = i + 1 ; j < n ; j++ ){
			if( abs( buf[j] - buf[i] ) < res )
			res = abs( buf[j] - buf[i] ) ;
			if( res == 0 ) break ;
		}
	}
	printf( "%d\n" , res ) ;
	
	return 0 ;
}
