#include <cstdio>

#define MAX 10000001

using namespace std ;

struct Node{
	int root ;
	int size ;
}Tree[MAX];

int findRoot( int x ){
	if( Tree[x].root == -1 ) return x ;
	else{
		int tmp = findRoot( Tree[x].root ) ;
		Tree[x].root = tmp ;
		return tmp ;
	}
}

int main(){
	int n , A , B ;
	while( ~scanf( "%d" , &n ) ){
		for( int i = 1 ; i < MAX; i++ ){
			Tree[i].root = -1 ;
			Tree[i].size = 1 ;
		}
		while( n-- ){
			scanf( "%d%d" , &A , &B ) ;
			A = findRoot( A ) ;
			B = findRoot( B ) ;
			if( A != B ){
			
				Tree[B].size += Tree[A].size ;
				Tree[A].root = B ;
			}
		}	
		int ans = 1 ;
		for( int i = 1 ; i <= MAX ; i++ ){
			if( Tree[i].root == -1 && Tree[i].size > ans )
				ans = Tree[i].size ;
		}
		printf( "%d\n" , ans ) ;
	
	}
	return 0 ;
}
