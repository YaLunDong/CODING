#include <cstdio>

struct Node{
    int a ;
    int b ;
    int c ;
}buf[532];
int size = 0 ;
int main(){
    for( int a = 0 ; a <= 9 ; a++ ){
        for( int b = 0 ; b <= 9 ; b++ ){
            for( int c = 0 ; c <= 9 ; c++ ){
                if( a * 100 + b * 10 + c + b * 100 + c * 10 + c == 532){
                    buf[size].a = a ;
                    buf[size].b = b ;
                    buf[size++].c = c ;
                 
                }
               
      }
        }
    }
    for( int i = 0 ; i < size ; i++){
        printf( "%d %d %d\n" , buf[i].a , buf[i].b , buf[i].c ) ;
    }
    return 0 ;
}
