// nµÄ½×³Ë 
#include <cstdio>
#include <cstring>

#define MAX 1000
struct bigInteger{
	int buf[ MAX + 1 ] ;
	int size ;
	
	void init(){
		for( int i = 0 ; i < MAX ; i++ )
			buf[i] = 0 ;
		
		size = 0 ;
	}	
	
	void set( int x ){
		init() ;
		do{
			buf[ size++ ] = x % 10000 ;
			x /= 10000 ;
		}while( x!= 0 );
	}
	
	void output(){
		for( int i = size - 1 ; i >= 0 ; i-- ){
			if( i != size - 1)
				printf( "%04d" , buf[i] ) ;
			else
				printf( "%d" , buf[i] ) ;
		}
		printf( "\n" ) ;
	}
	
	bigInteger operator * ( int x ) const {
		
		bigInteger ret ;
		ret.init() ;
		int carry = 0 ;
		for( int i = 0 ; i < size ; i++ ){
			int tmp = x * buf[i] + carry ;
			carry = tmp / 10000 ;
			tmp %= 10000 ;
			ret.buf[ ret.size++ ] = tmp ;	
		}
		if( carry != 0 ){
			ret.buf[ret.size++] = carry ;
		}
		return ret ;
	}
} a ;

int main(){
	int n ;
	while( ~scanf( "%d" , &n ) ){
		a.init() ;
		a.set( 1 ) ;
		for( int i = 2 ; i <= n ; i++ ){
			a = a * i ;
		}
		a.output() ;
	}
	return 0 ;
}

