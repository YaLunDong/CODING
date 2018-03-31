#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std ;

int main(){
    double x0 , y0 , z0 ;
    double x1 , y1 , z1 ;
    double r , s ;
    while( ~scanf( "%lf%lf%lf%lf%lf%lf" , &x0 , &y0 ,&z0 ,&x1 ,&y1 ,&z1 ) ){
        
        r = sqrt( pow( x1 - x0 , 2 ) + pow( y1 - y0 , 2 ) + pow( z1 - z0 , 2 ) ) ;
        s = 4.0 / 3 * acos(-1.0) * pow( r , 3 ) ;
        
        printf( "%.3lf %.3lf\n" , r , s ) ;
    }
    
    return 0 ;
}


