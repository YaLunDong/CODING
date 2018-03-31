#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define N 500

using namespace std ;

vector < int > edge[N*N] ;
priority_queue< int , vector < int > , greater < int > > Q ;
int in[ N + 1 ] ;
int ans[ N + 1 ] ;

int main(){
    int n , m ;
    int cnt ;
    while( ~scanf( "%d%d" , &n , &m ) ){
        
        cnt = 0 ;
        memset( in , 0 ,sizeof( in ) ) ;
        for( int i = 1 ; i <= n ; i++ ) edge[i].clear() ;
        while( !Q.empty() ) Q.pop() ;
        
        while( m-- ){
            int a , b ;
            scanf( "%d%d" , &a , &b ) ;
            edge[a].push_back( b ) ;
            in[b]++ ;
        }
        
        for( int i = 1 ; i <= n ; i++ ){
            if( in[i] == 0 )
                Q.push( i ) ;
        }
        while( !Q.empty() ){
            int p = Q.top() ;
            Q.pop() ;
            ans[cnt++] = p ;
            for( int j = 0 ; j < edge[p].size() ; j++ ){
                if( --in[edge[p][j]] == 0 )
                    Q.push( edge[p][j] ) ;
            }
        }
        
        for( int i = 0 ; i < cnt ; i++ ){
            if( i == cnt - 1 ) printf( "%d\n" , ans[i] ) ;
            else printf( "%d " , ans[i] ) ;
        }
    }
    return 0 ;
}

