#include <cstdio>

int main(){
    int a[20] ;
    int n ;
    int min , max ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 0 ; i < n ; i++ ){
            scanf( "%d" , &a[i]) ; 
        }
        min = max = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( a[i] < a[min] ) min = i ;
            if( a[i] > a[max] ) max = i ;
        }
        int tmp = a[min] ;
        a[min] = a[max] ;
        a[max] = tmp ;
        
        for( int i = 0 ; i < n ; i++ ){
            if( i < n-1 ) printf( "%d " , a[i] ) ;
            else printf( "%d\n" , a[i] ) ;
        }
    }
    return 0;
    
}
