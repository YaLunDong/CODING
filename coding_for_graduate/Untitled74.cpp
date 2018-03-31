#include <cstdio>
#include <queue>
using namespace std ;

struct Node{
    int a , b , c ;
    int t ;
};

queue<Node> Q ;
bool mark[101][101][101] ;
void AtoB( int &a , int sa , int &b , int sb ){
    if( sb - b >= a ){
        b = b + a ;
        a = 0 ;
    }
    else{
        a = a - ( sb - b ) ;
        b = sb ;
    }
}

int BFS( int s , int n , int m ){
    while( !Q.empty() ){
        Node now = Q.front() ;
        Q.pop() ;
        int ax , bx , cx ;
        
        //a->b
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( ax , s , bx , n ) ;
        if( mark[ax][bx][cx]== false){
		
        mark[ax][bx][cx] = true ;
        Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
    }
        //b->a
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( bx , n , ax , s ) ;
        if( mark[ax][bx][cx] == false) {
		
        mark[ax][bx][cx] = true ;
   		Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
    }
        //a->c
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( ax , s , cx , m ) ;
        if( mark[ax][bx][cx] == false ) {
		
        mark[ax][bx][cx] = true ;
        Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
    }
        //c->a
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( cx , m , ax , s ) ;
        if( mark[ax][bx][cx] == false ) {
        mark[ax][bx][cx] = true ;
        Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
    }
        //b->c
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( bx , n , cx , m ) ;
        if( mark[ax][bx][cx] ==false ) {
        mark[ax][bx][cx] = true ;
        Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
    }
        //c->b
        ax = now.a ;
        bx = now.b ;
        cx = now.c ;
        AtoB( cx , m , bx , n ) ;
        if( mark[ax][bx][cx] == false ) {
        mark[ax][bx][cx] = true ;
        Node temp ;
        temp.a = ax ;
        temp.b = bx ;
        temp.c = cx ;
        temp.t = now.t + 1 ;
        if( ax == s / 2 && bx == s / 2 || ax == s / 2 && cx == s / 2 || bx == s / 2 && cx == s / 2 )
            return temp.t ;
        Q.push( temp ) ;
       }
    }
    return -1 ;
}

int main(){
    int  s , n , m ;
    while( scanf( "%d%d%d" , &s , &n , &m ) != EOF ){
        if( s==0 ) break ;
        if( s %2 == 1 ){
            printf( "NO\n" ) ;
            continue ;
        }
        for( int i = 0 ; i <=s ; i++ ){
            for( int j = 0 ; j <= n ; j++ ){
                for( int k = 0 ; k <= m ; k++ )
                    mark[i][j][k] = false ;
            }
        }
        Node tmp ;
        tmp.a = s ; 
		tmp.b = tmp.c = tmp.t = 0 ;
        while( !Q.empty() ) Q.pop() ;
        
        Q.push( tmp ) ;
        mark[s][0][0] = true ;
        int ans = BFS( s , n , m ) ;
        if( ans == -1 ) printf( "NO\n" ) ;
        else printf( "%d\n" , ans ) ;
    }
    return 0 ;
}
