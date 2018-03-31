#include <cstdio>
#include <cmath>

int prime[100001] ;
int primeSize ;
bool mark[100001] ;

void init(){
    for( int i = 0 ; i <= 100000 ; i++ ) mark[i] =  false ;
    
    primeSize = 0 ;
    for( int i = 2 ; i <= 100000 ; i++ ){
        if( mark[i] == true ) continue ;
        
        prime[ primeSize++ ] = i ;
        for( int j = i * i ; j <= 100000 ; j += i ){
            mark[j] = true ;
        }
    }
}

int main(){
    init() ;
    int N ;
    while( ~scanf( "%d" , &N ) ){
        int ansPrime[30] ;
        int ansSize = 0 ;
        int ansNum[30] ;
        for( int i = 0 ; i < primeSize ; i++ ){
            if( N % prime[i] == 0 ){
                ansPrime[ansSize] = prime[i] ; 
                ansNum[ansSize] = 0 ;
                while( N % prime[i] == 0 ){
                    ansNum[ansSize]++ ;
                    N /= prime[i] ;
                }
                ansSize++ ;
                if( N == 1 ) break ;
            }
        }
        if( N != 1){
            ansPrime[ansSize] = N ;
            ansNum[ansSize++] = 1 ;
        }
        int ans = 0 ;
        for( int i = 0 ; i < ansSize ; i++ ){
            ans += ansNum[i] ;
        }
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
