//¿®∫≈∆•≈‰ £®£© {} °æ°ø
#include <cstdio>
#include <stack>
using namespace std ;

int const MAX = 100 ;
stack<char> S ;
char str[MAX] ;

int main(){
	bool flage ;
	while( ~scanf( "%s" , str ) ){
		flage = true ;
		for( int i = 0 ; str[i] != 0 ; i++ ){
			if( str[i] == '(' || str[i] == '[' || str[i] == '{' )
				S.push( str[i] ) ;
				
			else if( str[i] == ')' || str[i] == ']' || str[i] == '}' ){
				if( !S.empty() ){
				
					if( str[i] == ')' && S.top() == '(' || str[i] == ']' && S.top() == '[' || str[i] == '}' && S.top() == '{' ) S.pop() ;
			  		else{
						flage = false ;//printf( "not match\n") ;
						break ;
					}
				}
				else{
					flage = false ;//	printf( "not match\n") ;
					break ;
				}
			}
			else{}
		}
		//printf("%d",flage);
		if( S.empty() ==  true && flage == true ) printf( "match\n" ) ;
		else printf( "not match\n" ) ;
	}
	return 0 ;
			
}

