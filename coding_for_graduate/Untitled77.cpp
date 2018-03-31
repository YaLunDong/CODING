#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

#define MAX 8

string str ;
char ans[MAX] ;
;
void slove( int idx ){
	if( idx == str.length() ){
		for( int i = 0 ; i < str.length() ; i++ )
			cout << ans[i] ;
		cout << endl ;
	}
	else{
		bool flage = false ;
		for( int j = 0 ; j < str.length() ; j++ ){
	
			flage = false ;
			char tmp = str[j] ;
			for( int i = 0 ; i < idx ; i++ )
				if( tmp == ans[i] ){
					flage = true ;
					break ;
				}
		
			if( !flage ){
	
				ans[idx] = tmp ;
				slove( idx + 1 ) ;
				}
			}
		}
}
int main(){
	while( cin >> str ){
		sort( str.begin() , str.end() ) ;
		slove( 0 ) ;
		cout << endl ;
	}
	return 0 ;
}
