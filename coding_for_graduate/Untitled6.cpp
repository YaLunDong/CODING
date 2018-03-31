#include <stdio.h>
#include <algorithm>
#include <string.h>

int main(){
    int N ;
    int x ;
    int score[101] ;
    while( scanf( "%d" ,  &N ) !=  EOF && N != 0){
        for( int i = 0 ; i < 101 ; i++ ) score[i] = 0 ;
        for( int i = 0 ; i < N ; i++ ){
            scanf( "%d" , &x ) ;
            score[x]++ ;
        }
        scanf( "%d" , &x ) ;
        printf( "%d\n" , score[x] ) ;
    }
    return 0 ;
}
