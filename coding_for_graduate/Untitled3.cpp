#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct E
{
    char num[7];
    char name[9];
    int score;
}buf[100000];

bool cmp1( E a , E b )
{
    int state = strcmp( a.num , b.num );
    return state < 0;
}
bool cmp2( E a , E b)
{
    int flag = strcmp( a.name , b.name );
    if( flag != 0 )
        return flag < 0;
    else
        return cmp1( a , b );
}

bool cmp3( E a , E b )
{
    if( a.score != b.score ) return a.score < b.score;
    else return cmp1( a , b );
}

int main()
{
    int N,C;
    while( ~scanf( "%d%d" , &N , &C ) )
    {
        if( N ==0 ) break;
        else
        {
            for( int i = 0 ; i < N ; i++ )
            {
                scanf( "%s %s %d" , &buf[i].num , &buf[i].name , &buf[i].score );
               // scanf( "%s" , &buf[i].name );
               // scanf( "%d" , &buf[i].score );
            }
            if( C ==1 ) sort( buf , buf + N , cmp1 );
            else if( C== 2 ) sort( buf , buf + N , cmp2 );
            else sort( buf , buf + N , cmp3 );
            
            printf("Case:\n");
            for( int i = 0 ; i < N ; i++ )
            {
                printf("%s %s %d\n" , buf[i].num , buf[i].name , buf[i].score);
            }
        }
    }
    return 0;
}
