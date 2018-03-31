#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std ;

#define MAX 55 
int maze[MAX][MAX][MAX] ;
bool mark[MAX][MAX][MAX] ;

struct Node{
    int x , y , z ;
    int t ;
};
int direct[][3]{
    1 , 0 , 0 ,
    -1 , 0 , 0  ,
    0 , 1 , 0 ,
    0 , -1 , 0 ,
    0 , 0 , 1 ,
    0 , 0 , -1
};
queue<Node> Q ;
int BFS( int a , int b , int c ){
    while( !Q.empty() ){
        Node now = Q.front() ;
        Q.pop() ;
        for( int i = 0 ; i < 6 ; i++ ){
            int nx = now.x + direct[i][0] ;
            int ny = now.y + direct[i][1] ;
            int nz = now.z + direct[i][2] ;
            if( nx < 0 || nx > a - 1 || ny < 0 || ny > b - 1 || nz < 0 || nz > c - 1 ) continue ;
            if( maze[nx][ny][nz] == 1 ) continue ;
            if( mark[nx][ny][nz] ) continue ;
            Node temp ;
            temp.x = nx ;
            temp.y = ny ;
            temp.z = nz ;
            temp.t = now.t + 1 ;
            Q.push( temp ) ;
            mark[nx][ny][nz] = true ;
            if( nx == a - 1 && ny == b - 1 && nz == c - 1 ) return temp.t ;
        }
    }
    return -1 ;
}

int main(){
    int k ;
    int a , b , c , t ;
    scanf( "%d" , &k ) ;
    while( k-- ){
        scanf( "%d%d%d%d" , &a , &b , &c , &t ) ;
        for( int x = 0 ; x < a ; x++ ){
            for( int y = 0 ; y < b ; y++ ){
            for( int z = 0 ; z < c ; z++ ){
                scanf( "%d" , &maze[x][y][z] ) ;
                mark[x][y][z] = false ;
            }
          }
        }
        while( !Q.empty() ) Q.pop() ;
        
        mark[0][0][0] = true ;
        Node tmp ;
        tmp.t = tmp.x = tmp.y = tmp.z = 0 ;
        Q.push( tmp ) ;
        int ans = BFS( a , b , c ) ;
        if( ans <= t ) printf( "%d\n" , ans ) ;
        else printf( "-1\n" ) ;
    } 
    return 0 ;
}
