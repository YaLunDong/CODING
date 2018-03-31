#include <cstdio>

#define Max 200000
int prime[Max] ;
int primeSize ;
bool mark[Max+1] ;

void init(){
    for( int i = 1 ; i <= Max ; i++ ) mark[i] = false ;
    primeSize = 0 ;
    for( int i = 2 ; i <= Max ; i++ ){
        if( mark[i] == true ) continue ;
        
        prime[primeSize++] = i ;
        for( int j = i * i ; j <= Max ; j += i ){
            mark[j] = true ;
        }
    }
}

int main(){
    int k ;
    init() ;
    while( ~scanf( "%d" , &k ) ){
        printf( "%d\n" , prime[k - 1 ] ) ;
    }
    return 0 ;
}
