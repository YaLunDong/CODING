#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;

struct NODE{
    int Ti_s ;
    int Ti_e ;
    bool operator < (const NODE & A) const {
        return Ti_e < A.Ti_e ;
    }
}buf[100];

int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
    	if( !n ) break ;
        for( int i = 0 ; i < n ; i++ ){
            scanf( "%d%d" , &buf[i].Ti_s , &buf[i].Ti_e ) ;
        }
        int cnt = 0 ;
        int current_time = 0 ;
        sort( buf , buf + n ) ;
        for( int i = 0 ; i < n ; i++ ){
            if( buf[i].Ti_s >= current_time ){
                cnt++ ;
                current_time = buf[i].Ti_e ;
            }
        }
        printf( "%d\n" , cnt ) ;
    }
    
    return 0 ;
}
