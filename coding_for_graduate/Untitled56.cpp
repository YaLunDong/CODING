#include <cstdio>
#include <cstring>

using namespace std ;

int getTime( char c ){
    switch( c ){
        case 'a' :
        case 'd' :
        case 'g' :
        case 'j' :
        case 'm' :
        case 'p' :
        case 't' :
        case 'w' :
            return 1 ;
        case 'b' :
        case 'e' :
        case 'h' :
        case 'k' :
        case 'n' :
        case 'q' :
        case 'u':
        case 'x' :
            return 2 ;
        case 'c' :
        case 'f' :
        case 'i' :
        case 'l' :
        case 'o' :
        case 'r' :
        case 'v' :
        case 'y' :
            return 3 ;
        case 's' :
        case 'z' :
            return 4 ;
        
        
    }
    return 0 ;
}
int map( char c ){
    switch( c ){
        case 'a':
        case 'b':
        case 'c':
            return 2 ;
        case 'd':
        case 'e':
        case 'f':
            return 3 ;
        case 'g':
        case 'h':
        case 'i':
            return 4 ;
        case 'j':
        case 'k':
        case 'l':
            return 5 ;
        case 'm':
        case 'n':
        case 'o':
            return 6 ;
        case 'p':
        case 'q':
        case 'r':
        case 's':
            return 7 ;
        case 't':
        case 'u':
        case 'v':
            return 8 ;
        case 'w':
        case 'x':
        case 'y':
        case 'z':
            return 9 ;
        
    }
    return 0 ;
}

char str[100] ;

int main(){
    while( ~scanf( "%s" , str ) ){
        int ans = 0 ;
        int L = strlen( str ) ;
        ans = getTime( str[0] ) ;
        for( int i = 1 ; i < L ; i++ ){
        	if( map( str[i] ) == map( str[i-1] ) )
        		ans += 2 ;
            ans += getTime( str[i] ) ;
        }
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
