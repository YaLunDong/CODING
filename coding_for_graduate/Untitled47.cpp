#include <cstdio>

int bufe[60];
int bufg[60];
int size1 , size2 ;

int SumOfYinzi( int x ){
    int sum = 0 ;
    for( int i = 1 ; i < x ; i++ ){
        if( x % i == 0 )
            sum += i ;
    }
    return sum ;
}
int main(){
    size1 = size2 = 0 ;
    for( int x = 2 ; x <= 60 ; x++){
        if( SumOfYinzi(x) == x ){
            bufe[size1++] = x ;
        }
        if( SumOfYinzi(x) > x ){
            bufg[size2++] = x ;
        }
    }
    printf("E: ");
    for( int i = 0 ; i < size1 ; i++ ){
        if( i != size1 - 1 )
            printf( "%d " , bufe[i] ) ;
        else
            printf( "%d\n" , bufe[i] ) ;
    }
    printf("G: ");
    for( int i = 0 ; i < size2 ; i++ ){
        if( i != size2 - 1 )
            printf( "%d " , bufg[i] ) ;
        else
            printf( "%d\n" , bufg[i] ) ;
    }
    return 0 ;
}
