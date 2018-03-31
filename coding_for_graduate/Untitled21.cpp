//¶ÑÕ»µÄÊ¹ÓÃ
#include <cstdio>
#include <stack>

using namespace std ;

stack<int> S ;

int main(){
	int n ;
	char choice;
	int data ;
	 while( ~scanf( "%d" , &n ) && n != 0 ){
		
		while( !S.empty() ) S.pop() ;
		
		for( int i = 0 ; i< n ; i++ ){
			choice = getchar() ;
			scanf( "%c" , &choice ) ;
			if( choice == 'P'){
				scanf( "%d" , &data ) ;
				S.push( data ) ;
			}
			else if( choice == 'O' ){
				if( !S.empty() )
					S.pop() ;
			}
			else if( choice == 'A'){
				if( !S.empty() )
					printf( "%d\n" , S.top() ) ;
				else
					printf( "E\n" ) ;
			}
		}
		printf( "\n" ) ;
	}
	return 0 ;
} 
