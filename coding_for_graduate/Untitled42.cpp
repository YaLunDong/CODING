// 大数加法 
#include <cstdio>
#include <cstring>
#define MAX 1002

struct bigInteger{
    int buf[ MAX + 1 ] ;
    int size ;
    
    void init(){
        for( int i = 0 ; i < MAX ; i++ ) buf[i] = 0 ;
        size = 0 ;
    }
    
    void set( char str[] ){
        init() ; 
        int L = strlen( str ) ;
        for( int i = L - 1 , j = 0 , t = 0 , c = 1 ; i >= 0 ; i-- ){
            t += ( str[i] - '0' ) * c ;
            j++ ;
            c *= 10 ;
            if( j == 4 || i == 0 ){
                buf[size++] = t ;
                j = 0 ;
                t = 0 ;
                c = 1 ;
            }
        }
    }
    
    void output(){
        for( int i = size -1 ; i >= 0 ; i-- ){
            if( i != size - 1 )
                printf( "%04d" , buf[i] ) ;
            else
                printf( "%d" , buf[i] ) ;
        }
        printf( "\n" ) ;
    }
    
    bigInteger operator + ( const bigInteger & A ) const {
        bigInteger ret ;
        ret.init() ;
        int carry = 0 ;
        for( int i = 0 ; i < size || i < A.size ; i++ ){
            int tmp = A.buf[i] + buf[i] + carry ;
            carry = tmp / 10000 ;
            tmp %= 10000 ;
            ret.buf[ ret.size++ ] = tmp ;
        }
        if( carry != 0 ){
            ret.buf[ ret.size++ ] = carry ;
        }
        return ret ;
    } 
}a , b , c ;
int main(){
    char str1[1003] , str2[1003] ;
    while( scanf( "%s%s" , str1 , str2 ) != EOF ){
        a.set( str1 ) ;
        b.set( str2 ) ;
        c = a + b ;
        c.output() ;
    }
    return 0;
}
