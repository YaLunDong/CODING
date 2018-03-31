#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std ;

const int MAX=10001 ;

int L[ MAX ] ;

int main(){
    int l , m ;
    int left , right ;
    int sum ;
    while( ~scanf( "%d%d" , &l , &m ) ){
        for( int i = 0 ; i <= l ; i++ ) L[ i ] = 0 ;
        sum = 0 ;
        
        for( int j = 0 ; j < m ; j++ ){
            scanf( "%d%d" , &left , &right );
            for( int k = left ; k <= right ; k++ )
                L[ k ] = 1 ;
        }
        for( int i = 0 ; i <= l ; i++ )
            sum += L[ i ] ;
        
        int res = l + 1 - sum ;
        
        printf( "%d\n" , res );
    }
    return 0;
}
