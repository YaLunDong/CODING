#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define N 101 

using namespace std ;

struct M{
    int weight ;
    char color[10] ;
    
    bool operator < ( const M &m ) const {
        return weight < m.weight ;
    }
}mouse[N] ;

int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 0 ; i < n ; i++ ){
            scanf( "%d%s" , &mouse[i].weight , mouse[i].color ) ;
        }
        sort( mouse , mouse + n ) ;
        
        for( int i = n-1 ; i >= 0 ; i-- ){
            puts( mouse[i].color ) ;
        }
    }
    return 0 ;
}


