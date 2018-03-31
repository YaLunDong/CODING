#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

#define ISleap(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0

int day_of_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int Y , M , D ;
    while( ~scanf("%d%d%d" , &Y , &M , &D )){
        int state = ISleap( Y ) ;
        int res = 0 ;
        for( int i = 1 ; i < M ; i++ ){
            if( i != 2 )
            res += day_of_month[ i ] ;
            else{
                res += day_of_month[ i ] + state ;
            }
        }
        res += D ;
        printf("%d\n",res);
    }
    return 0;
}
