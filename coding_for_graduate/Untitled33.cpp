#include <cstdio>
#include <cmath>

int main(){
	int m ;
	long long a , b ;
	while( ~scanf( "%d" , &m ) && m != 0 ){
		scanf( "%lld%lld" , &a , &b ) ;
		long long res = a + b ;
		int buf[50] ;
		int size = 0 ;
		while( res > 0 ){
			buf[size++] = res % m ;
			res /= m ;
		}
		
		for( int i = size - 1 ; i >= 0 ; i-- )
			printf( "%d" , buf[i] ) ; 
			
		printf( "\n" ) ;
	} 
	
	return 0 ;
}
