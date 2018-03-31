#include <cstdio>
#include <cstring>
#define N 100 

char str_in[N] ;
int main(){
    while( gets(str_in) ){
        int L = strlen( str_in ) ;
        for( int i = 0 ; i < L ; i++ ){
            if( 'a' <= str_in[i] && str_in[i] < 'z' || 'A' <= str_in[i] && str_in[i] < 'Z' ){
                str_in[i] = str_in[i] + 1 ;//printf( "%c" , str_in[i] + 1 ) ;
            }
             if( str_in[i] == 'z' ) str_in[i] = 'a' ;
             if( str_in[i] == 'Z' ) str_in[i] = 'A' ;
             //printf( "%c" , str_in[i] ) ;
        }
        puts( str_in ) ;
       // printf( "\n" ) ;
    }
    return 0 ;
}
