#include <cstdio>
#include <cstring>

int main(){
	
	char buf[20] ;
	while( ~scanf( "%s" , buf ) ){
		int idx = strlen ( buf ) - 1 ;
		int sum = 0 ;
		int c = 1 ;
		for( int i = idx ; i > 1 ; i-- ){
			if( buf[i] >= '0' && buf[i] <= '9')
			{
				sum += ( buf[i] - '0' ) * c ;
			 } 
			 else if( buf[i] >= 'A' && buf[i] <= 'F'){
			 	sum += ( buf[i] - 'A' + 10 ) * c ; 
			 }
			 else if( buf[i] >= 'a' && buf[i] <= 'f' ){
			 	sum += ( buf[i] - 'a' + 10 ) * c ;
			 }
			 c *= 16 ;
		}
		printf( "%d\n" , sum ) ;
	}
	return  0 ;
}
