#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std ;

struct E{
    int value ;
    int flage ;
}buf[80] ;

int main(){
    int k ;
    int cnt ;
    while( ~scanf( "%d" , &k ) ){
        cnt = 0;
        for( int i = 0 ; i < k ; i++ ){
            scanf( "%d" , &buf[i].value ) ;
            buf[i].flage = 0 ;
        }
        if( buf[0].value != buf[1].value ) { buf[0].flage = 1 ; cnt++ ; }
        if( buf[k-1].value != buf[k-2].value ) { buf[k-1].flage = 1 ; cnt++; }
        for( int i = 1 ; i < k-1 ; i++ )
            if( buf[i].value > buf[i-1].value && buf[i].value > buf[i+1].value || buf[i].value < buf[i-1].value && buf[i].value < buf[i+1].value )
            {    buf[i].flage = 1 ; cnt++ ; }
        
        for( int i = 0 ; i < k ; i++ ){
            if( buf[i].flage == 1 ){
                if( cnt > 1 ) printf( "%d " , i ) ;
                else printf( "%d\n" , i ) ;
                cnt-- ;
            }
        } 
    }
    return 0 ;
}
