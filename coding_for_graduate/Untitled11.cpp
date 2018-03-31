#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std ;

struct STU{
    char num[100] ;
    char name[100] ;
    char sex[5] ;
    int age ;
    bool operator < (const STU & A) const{
        return strcmp( num , A.num ) < 0 ;
    }
}buf[1000];

int main(){
    int N , M ;
    char x[100];
    scanf( "%d" , &N ) ; 
    for( int i = 0 ;i < N ; i++ ){
        scanf( "%s%s%s%d" , buf[i].num , buf[i].name , buf[i].sex , &buf[i].age ) ;
    }
    sort( buf , buf + N );
    scanf( "%d" , &M ) ;
    for( int j = 0 ; j < M ; j++ ){
        scanf( "%s" , x ) ;
        int base = 0 ;
        int top = N - 1 ;
        
        int res = -1 ;
        while( base <= top ){
            int middle = ( base + top ) / 2 ;
            if( !strcmp ( x , buf[middle].num) ) {
                res = middle ;
                break;
            }
            if(strcmp( x , buf[middle].num) < 0 ) top = middle -1 ;
            if(strcmp( x , buf[middle].num) > 0 ) base = middle + 1 ;
        }
        if( res == -1 ) printf( "No Answer!\n" ) ;
        else{
            printf( "%s %s %s %d\n" , buf[res].num , buf[res].name , buf[res].sex , buf[res].age ) ;
        }
    }
    return 0 ;
}


