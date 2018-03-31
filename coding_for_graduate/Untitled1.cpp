#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct E
{
    char name[200];
    int grade;
}stu[1000];

bool cmp(E a, E b)
{
    return  a.grade < b.grade;
}
int main()
{
    int n;
    int choice;
    while(scanf( "%d" , &n)!=EOF)
    {
     scanf("%d" , &choice);
     for( int i = 0 ; i < n ; i++ )
    {
        scanf( "%s%d" , stu[i].name , &stu[i].grade);
    }
   
    
    printf("shuru:\n");
    for( int i =0 ; i < n ; i++ )
       printf("%s %d\n" , stu[i].name , stu[i].grade );
    printf(">>>>>>>>>>>>>>>>>>>>>>>>\n");
    
     sort(stu,stu+n,cmp);
     
    if( choice == 1 )
    {
        for( int i =0 ; i < n ; i++ )
            printf("%s %d\n" , stu[i].name , stu[i].grade );
       // printf("%s %d\n" , stu[n-1].name , stu[n-1].grade );
    }
    else
    {
       for( int i = n-1 ; i >= 0 ; i-- )
            printf("%s %d\n" , stu[i].name , stu[i].grade );
       // printf("%s %d\n" , stu[0].name , stu[0].grade );
    }
    }
    return 0;
}
