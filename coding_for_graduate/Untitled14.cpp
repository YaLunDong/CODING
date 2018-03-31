#include <cstdio>
#include <algorithm>

const int MAX = 200 ;
using namespace std ;

int  a[MAX];

int main(){
    int N , M ;
    while( ~scanf( "%d%d" , &N , &M ) ){
        for( int i = 0 ; i <  N ; i++ ) scanf( "%d" , &a[i] ) ;
        
        for( int i = 0 ; i < N ; i++ ){
            int cnt = 0 ;
            for( int j = 0 ; j < N ; j++ ){
                if( j != i && a[j] == a[i] ) cnt++ ;
            }
            if( cnt ) printf( "%d\n" , cnt ) ;
            else printf( "BeiJu\n" ) ;
        }
    }
    
    return 0 ;
}
