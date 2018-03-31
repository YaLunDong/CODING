#include <cstdio>
#include <cmath>

using namespace std ;

int main(){
	int n ;
	while( ~scanf( "%d" , &n ) ){
		int ans = 0 ;
		while( n >= 50 ){
			ans += 7 ;
			n-= 50 ;
		}
		while( n >= 30 ){
			ans += 4 ;
			n -= 30 ;
		}
		ans += n / 10 ;
		
		printf( "%d\n" , ans ) ;
	}
	return 0 ;
}
