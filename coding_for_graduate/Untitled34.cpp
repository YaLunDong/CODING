#include <cstdio>
#include <cstring>
 
int getVal( char c ){
    switch(c){
        case '0' : return 0 ;
        case '1' : return 1 ;
        case '2' : return 2 ;
        case '3' : return 3 ;
        case '4' : return 4 ;
        case '5' : return 5 ;
        case '6' : return 6 ;
        case '7' : return 7 ;
        case '8' : return 8 ;
        case '9' : return 9 ;
        case 'a' : return 10 ;
        case 'A' : return 10 ;
        case 'b' : return 11 ;
        case 'B' : return 11 ;
        case 'c' : return 12 ;
        case 'C' : return 12 ;
        case 'd' : return 13 ;
        case 'D' : return 13 ;
        case 'e' : return 14 ;
        case 'E' : return 14 ;
        case 'f' : return 15 ;
        case 'F' : return 15 ;
    }
}

char getChar( int val ){
    switch(val){
        case 0 : return '0' ;
        case 1 : return '1' ;
        case 2 : return '2' ;
        case 3 : return '3' ;
        case 4 : return '4' ;
        case 5 : return '5' ;
        case 6 : return '6' ;
        case 7 : return '7' ;
        case 8 : return '8' ;
        case 9 : return '9' ;
        case 10 : return 'A' ;
        case 11 : return 'B' ;
        case 12 : return 'C' ;
        case 13 : return 'D' ;
        case 14 : return 'E' ;
        case 15 : return 'F' ;
    }
}

int main(){
    int a , b ;
    char buf_in[20] , buf_out[20];
    long tmp ;
    int len ;
    while( ~scanf( "%d%s%d" , &a , buf_in , &b ) ){
        tmp = 0 ;
        len = strlen( buf_in ) ;
        for( int i = 0 ; i < len ; i++ )
        {
            tmp = tmp * a + getVal( buf_in[i] ) ;
        }
        int size = 0 ;
        int elem ;
        while( tmp > 0 ){
            elem = tmp % b ;
            buf_out[size++] = getChar( elem ) ;
            tmp /= b ;
        }
        
        for( int i = size - 1 ; i >= 0 ; i-- ){
            printf( "%c" , buf_out[i] ) ;
        }
        printf( "\n" ) ;
    }
    return 0 ;
}
