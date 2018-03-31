#include<cstdio>
#include<string>
#include<string.h>
#include<iostream>
using namespace std ;

int main(){
    char str[10000] ;
    while( gets( str ) ){
    	getchar() ;
        int L = strlen( str ) ;
        char a ;
        scanf( "%c" , &a ) ;
        //for( int i = 0 ; i < str.size() ; i++ )
        for( int i = 0 ; i < L ; i++ ){
        	if( str[i] != a )
        		printf( "%c" , str[i] ) ;
		}
		printf( "\n" ) ;
    }
    return 0 ;
}
