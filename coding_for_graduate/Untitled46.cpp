#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 1010 
using namespace std ;

struct bigInteger{
	int val[ MAX + 1 ];
	int size ;
	
	void init(){
		for( int i = 0 ; i< MAX ; i++ ){
			val[i] = 0 ;
		}
		size = 0 ;
	}
	
	void output(){
		for( int i = size -1 ; i >= 0 ; i-- ){
			if( i != size -1 )
				printf( "%04d" , val[i] ) ;
			else
				printf( "%d" , val[i] ) ;
		}
		printf( "\n" ) ;
	}
	
    void set( char str[]){
    	init() ; 
    	int L = strlen( str ) ;
    	for( int i = L - 1 , j = 0 , t = 0 , c = 1 ; i >= 0 ; i-- ){
    		t += ( str[i] - '0' ) * c ;
			j++ ;
			c *= 10 ;
			if( j == 4 || i == 0 ){
				val[size++] = t ;
				t = 0 ;
				j = 0 ;
				c = 1 ;
			}  
		}
	}
	
	bool operator < ( const bigInteger &A ) const {
		if( size < A.size ) return true ;
		else if( size > A.size ) return false ;
		else{
			for( int i = size - 1 ; i >= 0 ; i-- ){
				if( val[i] > A.val[i] )
					return false ;
				else if( val[i] < A.val[i] )
					return true ;
			}
		}
		return true ;// ==
	}
}buf[ MAX+1 ];

int main(){
	int N ;
	char str_in[1001];
	while( ~scanf( "%d" , &N ) ){
		for( int i = 0 ; i < N ; i++ ){
			scanf( "%s" , str_in) ;
			buf[i].set( str_in ) ;
		}
		
		sort( buf , buf + N ) ;
		
		for( int i = 0 ; i < N ; i++ ){
			buf[i].output() ;
		}
		
	}
	return 0 ;
}
