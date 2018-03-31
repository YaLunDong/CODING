#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
//不能从 2 阵营到 1 阵营 
using namespace std ;
#define M 10001
#define N 601
struct E{
    int next ;
    int cost ;
};
vector <E> edge[M] ;
int Dis[N] ;
int state[N] ;
bool mark[N] ;

int main(){
    int n , m ;
    while( ~scanf( "%d" , &n ) ){
        if( n == 0 ) break ;
        scanf( "%d" , &m ) ;
        for( int i = 1 ; i <= n ; i++ ) edge[i].clear() ;
        while( m-- ){
            int x , y , c ;
            scanf( "%d%d%d" , &x , &y , &c ) ;
            E tmp ;
            tmp.next = x ;
            tmp.cost = c ;
            edge[y].push_back( tmp ) ;
            tmp.next = y ;
            edge[x].push_back( tmp ) ;
        }
        
        for( int i = 1 ; i<= n ; i++ ){
            scanf( "%d" , &state[i] ) ;
            Dis[i] = -1 ;
            mark[i] = false ;
        }
        
        Dis[1] = 0 ;
        mark[1] = true ;
        int newp = 1 ;
        for( int i = 1 ; i < n ; i++ ){
            for( int j = 0 ; j < edge[newp].size() ; j++ ){
                int t = edge[newp][j].next ;
                int c = edge[newp][j].cost ;
                
                if( mark[t] ) continue ;
                
                if( state[newp] == 2 && state[t] == 1) continue ; //若从 2 阵营到 1 阵营 ， 则自动跳过  即 不允许从 2 阵营到 1 阵营 。 
                
                if( Dis[t] == -1 || Dis[t] > Dis[newp] + c ){
                 
                    Dis[t] = Dis[newp] + c ;
                   
                }
            }
            int min = 999999;
            for( int j = 1 ; j <= n ; j++ ){
                if( mark[j] == true ) continue ;
                if( Dis[j] == -1 ) continue ;
                if( Dis[j] < min ){
                    newp = j ;
                    min = Dis[j] ;
                }
            }
            mark[newp] = true ;
        }
        printf( "%d\n" , Dis[2] ) ;
    }
    return 0 ;
}



