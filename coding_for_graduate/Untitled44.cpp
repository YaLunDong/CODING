#include <cstdio>
#include <cstring>

#define MAX 1010 

struct bigInteger{
	int buf[ MAX + 1 ] ;
	int size ;
	
	void init(){
		for( int i = 0 ; i < MAX ; i++ ){
			buf[i] = 0 ;
		}
		size = 0 ;
	}
	
	void set( int x ){
		init() ; 
		do{
			buf[ size ++ ] = x % 10000 ;
			x /= 10000 ;
		}while( x != 0 ) ;
	}
	
	void output(){
		for( int i = size - 1 ; i >= 0 ; i-- ){
			if( i != size - 1 ) printf( "%04d" , buf[i] ) ;
			else printf( "%d" , buf[i] ) ;
		}
		printf( "\n" ) ;
	}
	
	bigInteger operator * ( int x ) const {
		bigInteger ret ;
		ret.init() ;
		int carry = 0 ;
		
		for( int i = 0 ; i < size ; i++ ){
			int tmp = buf[i] * x + carry ;
			carry = tmp / 10000 ;
			tmp %= 10000 ;
			ret.buf[ ret.size ++ ] = tmp ;
		}
		if( carry != 0 ){
			ret.buf[ ret.size++ ] = carry ;
		}
		return ret ;
	}
	
	bigInteger operator + ( const bigInteger &A ) const {
		bigInteger ret ;
		ret.init() ;
		int carry = 0 ;
		for( int i = 0 ; i < size || i < A.size ; i++ ){
			int tmp = buf[i] + A.buf[i] + carry ;
			carry = tmp / 10000 ;
			tmp %= 10000 ;
			ret.buf[ret.size++] = tmp ;
		}
		if( carry != 0 ){
			ret.buf[ ret.size++ ] = carry ;
		}
		return ret ;
	}
	
	bigInteger operator / ( const int x ) const {
		bigInteger ret ;
		ret.init() ;
		int remainder = 0 ;
		for( int i = size - 1 ; i >= 0 ; i-- ){
			int tmp = remainder * 10000 + buf[i] ;
			int t = tmp / x ;
			int r = tmp % x ;
			
			ret.buf[i] = t ;
			remainder = r ; 
		}
		ret.size = 0 ;
		for( int i = 0 ; i < MAX ; i++ ){
			if( buf[i] != 0 ) ret.size = i ;
		}
		ret.size++ ;
		
		return ret ;
	}
	
	int operator % ( int x ) const{
		int remainder = 0 ;
		for( int i = size - 1 ; i >= 0 ; i-- ){
			int tmp = remainder * 10000 + buf[i] ;
			remainder = tmp % x ;
		}
		return remainder ;
	}
} a , b , c ;

char str[10000];
char ans[10000];
int main(){
	int n , m ;
	while( ~scanf( "%d%d" , &m , &n ) ){
		scanf( "%s" , str ) ;
		int L = strlen( str ) - 1 ;
		a.set( 0 ) ;
		b.set( 1 ) ;
		for( int i = L ; i >= 0 ; i-- ){
			int t ;
			if( str[i] >= '0' && str[i] <= '9' ){
				t = str[i] - '0' ;	
			}
			else t = str[i] - 'A' + 10 ;
			a = a + b * t ;
			b = b * m ;
			
		}
		int size = 0 ;
		do{
			int t = a % n ;
			if( t >= 10 ) ans[size++] = t - 10 + 'a' ;
			else ans[size++] = t + '0' ;
			a = a / n ;
		}while( a.buf[0] != 0 || a.size != 1 ) ;
		
		for( int i = size - 1 ; i >= 0 ; i-- ){
			printf( "%c" , ans[i] ) ;
		}
		printf( "\n" ) ;
	}  
	return 0 ;
}
