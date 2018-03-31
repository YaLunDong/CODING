#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX 9999
int num[ MAX ] ;
int main(){
    
    int N ;
    int ind , cnt ;
    while( ~scanf( "%d" , &N ) ){
        cnt = 0 ;
        for(int i = 0 ; i < MAX ; i++ ) num[ i ] = 0 ;
        for( int i = 0 ;i < N ; i++ ){
            scanf( "%d" , &ind ) ;
            if( num[ind] == 0 ){
                num[ ind ] = 1 ;
                cnt++ ;
            }
        }
        
        for( int i = 0 ; i < MAX ; i++ ){
            if( num[ i ] != 0 ) {
                printf( "%d" , i ) ;
                cnt--;
                if( cnt ) printf( " " ) ;
                else printf( "\n" ) ;
            }
        }
    }
    return 0;
}
