#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define MAX 1003
struct Node{
	int value ;
	int start ;
	int last ;
}key[MAX];
int ans[MAX] ;
int main(){
	int n , k ;
	while( ~scanf( "%d%d" , &n , &k ) ){
		int w , s , c ;
		int end = 0 ;
		
		for( int i = 1 ; i <= n ; i++ ) ans[i] = i ;
		
		for( int i = 0 ; i < k ; i++ ){
			scanf( "%d%d%d" , &w , &s , &c)
			key[w].value = w ;
			key[w].start = s ;
			key[w].last = c ;
			if( max < s + c ) max = s + c ;
		}
	}
}
