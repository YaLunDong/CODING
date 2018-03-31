#include <cstdio>
#include <algorithm>

#define N 101
using namespace std ;

struct STU{
    int p ;
    int q ;
    
    bool operator < ( const struct STU &S ) const {
        if( q < S.q ){
            return true ;
        }
        else if( q == S.q ){
            return p < S.p ;
        }
        else
            return false ;
    }
}stu[N];

int main(){
    int n ;
    while( ~scanf( "%d" , &n ) ){
        for( int i = 0 ; i < n ; i++ ){
            scanf( "%d%d" , &stu[i].p , &stu[i].q ) ;
        }
        sort( stu , stu + n ) ;
        
        for( int i = 0 ; i < n ; i++ ){
            printf( "%d %d\n" , stu[i].p , stu[i].q ) ;
        }
                                      
    }
    return 0 ;
}
