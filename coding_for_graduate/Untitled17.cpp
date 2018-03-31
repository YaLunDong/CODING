//¿®∫≈∆•≈‰
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std ;

char str[100] ; 
char ans[100] ;
stack<int> S ;

int main(){
	while( ~scanf( "%s" , str ) ){
		for( int i = 0 ; str[i] != 0 ; i++ ){
			if( str[i] == '(' ) {
				S.push( i ) ;
				ans[i] = ' ' ;
			}
			else if( str[i] == ')' ){
				if( !S.empty() ){
					S.pop() ; 
					ans[i] = ' ' ;
				}
				else ans[i] = '?' ;
			} 
			else ans[i] = ' ' ;
		}
		while( !S.empty() ){
			ans[S.top()] = '$' ;
			S.pop() ;
		}
		puts(str);
		puts(ans);
	}
	
	
	return 0 ;
}
