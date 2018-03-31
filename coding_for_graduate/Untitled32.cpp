#include <cstdio>
#include <cmath>

int main(){
    int n ;
    int sum ;
    while( ~scanf( "%d" , &n ) ){
        
        do{
            sum = 0 ;
            while( n > 0 ){
                sum += n % 10 ;
                n /= 10 ;
            }
            if( sum >= 10 ) n = sum ;
        }while( sum >= 10 ) ;
        printf( "%d\n" , sum ) ;
    }
    return 0 ;
}
