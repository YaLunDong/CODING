#include <cstdio>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#define MAX 2000
using namespace std ;
map<string,int> mp ;
int in[MAX] ;
int main(){
    int n ;
    while( ~scanf("%d" , &n ) ){
        if( n == 0 ) break ;
        memset( in , 0 , sizeof( in ) ) ;
        mp.clear() ;
        int in_num = 0 ;
        
        for( int i = 0 ; i < n ; i++ ){
            char player1[50] ={0}, player2[50] ={0};
            scanf( "%s%s" , player1 , player2 ) ;
            string a = player1 ;
            string b = player2 ;
            if( mp.find( a ) == mp.end() )
                mp[a] = in_num++ ;
            if( mp.find( b ) == mp.end() )
                mp[b] = in_num++ ;
            in[ mp[b] ]++ ;
        }
        
        int cnt = 0 ;
        for( int i = 0 ; i < in_num ; i++ )
            if( in[i] == 0 ) cnt++ ;
        
        if( cnt == 1 ) printf( "Yes\n" ) ;
        else printf( "No\n" ) ;
    }
    return 0 ;
}
