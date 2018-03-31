#include <cstdio>
int const MAX = 100 ;
using namespace std ;
int a[MAX] ;
int b[MAX] ;
//bool find( int j , int a[] , int n ){
//    for( int i = 0 ; i < n ; i++ )
//        if( a[i] == b[j] ) return true;
//    
//    return false ;
//}
int main(){
    int n , m ;
    int x ;
   
    while( ~scanf( "%d" , &n ) ){
        for( int i = 0 ; i < n ; i++ ) scanf( "%d" , &a[i] ) ;
        scanf( "%d" , &m ) ;
       
        for( int j = 0 ; j < m ; j++ ) scanf( "%d" , &b[j] ) ;
//        for( int j = 0 ; j < m ; j++ ){
//            
//            if( find( j , a , n ) ) printf("YES\n") ;
//            else printf("No\n") ;
//        }
		for( int j = 0 ; j < m ; j ++){
			for( int i = 0 ; i < n ; i++ ){
				if( a[i] == b[j] ){
					printf( "YES\n" );
					break;
				}
				if( i == n-1 ) printf( "NO\n" );
			}
			
		}
    }
    return 0 ;
}
