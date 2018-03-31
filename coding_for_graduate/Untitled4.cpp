#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std ;

#define ISYAEP(x) x % 100 != 0 && x % 4 == 0 || x % 400 ==0 ? 1 : 0

int day_of_month[13][2] = {
    0 , 0 ,
    31 , 31 ,
    28 , 29 , 
    31 , 31 ,
    30 , 30 , 
    31 , 31 ,
    30 , 30 ,
    31 , 31 ,
    31 , 31 ,
    30 , 30 ,
    31 , 31 ,
    30 , 30 ,
    31 , 31 
};


int main(){
    
    int y , cnt ;
    int year , month , day ;
    while( scanf( "%d%d" , &y ,&cnt ) != EOF ){
        
        year = y ;
        month = 1 ;
        day = 0 ;
        
        int leap = ISYAEP( y ) ;
        while( cnt-- ){
            day++ ;
            if( day > day_of_month[ month ][ leap ]){
                day = 1 ;
                month++ ;
            }
        }
        if( month > 9 && day > 9)
        printf( "%d-%d-%d\n" , year , month , day );
        else  if( month > 9 && day <= 9)
        printf( "%d-%d-0%d\n" , year , month , day );
        else  if( month <= 9 && day > 9)
        printf( "%d-0%d-%d\n" , year , month , day );
        else
        printf( "%d-0%d-0%d\n" , year , month , day );
    }
    return 0;
}

