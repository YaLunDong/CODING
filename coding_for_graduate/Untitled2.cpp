#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct E
{
    char name[101];
    int age;
    int score;
}stu[1001];

bool cmp( E a , E b )
{
    if( a.score != b.score )
        return a.score < b.score;
    else if( int flag = strcmp( a.name , b.name )!= 0 )
        return flag < 0;
    else return a.age < b.age;
}

int main()
{
    int n;
    while( scanf( "%d" , &n ) != EOF )
    {
         for(int i = 0 ; i < n ; i++ )
             scanf( "%s%d%d" , stu[i].name , &stu[i].age , &stu[i].score );
   
    
         sort( stu , stu + n , cmp );
    
         for( int i = 0 ; i < n ; i++ )
             printf( "%s %d %d\n" , stu[i].name , stu[i].age , stu[i].score );
    }
    return 0;
}
