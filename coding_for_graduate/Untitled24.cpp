//¶þ²æÊ÷µÄ±éÀú 
#include <cstdio>
#include <cstring>

struct Node{
	Node *left ;
	Node *right ;
	char c;
}Tree[50] ;

int loc ;
char str1[200] ;
char str2[200] ;

Node *create(){
	Tree[loc].left = Tree[loc].right = NULL ;
	return &Tree[loc++] ;
}

void postOrder( Node *T ){
	
	if( T->left != NULL ) postOrder( T->left ) ;
	
	if( T->right != NULL ) postOrder( T->right ) ;
	
	printf( "%c" , T->c ) ;
}

Node *build( int s1 , int e1 , int s2 , int e2 ){
	
	Node *ret = create() ;
	ret->c = str1[s1] ;
	int rootidx ;
	for( int i = s2 ; i <= e2 ; i++ ){
		if( str2[i] == str1[s1]){
			rootidx = i ;
			break ;
		}
	}
	if( rootidx != s2 )
		ret->left = build( s1 + 1 , s1 + ( rootidx - s2 ) , s2 , rootidx -1 ) ;
	if( rootidx != e2 )
		ret->right = build( s1+ ( rootidx - s2 ) + 1 , e1 , rootidx + 1 ,e2 ) ;
	
	return ret ;
}

int main(){
	while( ~scanf( "%s" , str1 ) ){
		
		scanf( "%s" , str2 ) ;
		
		loc = 0 ;
		int len1 = strlen( str1 ) ;
		int len2 = strlen( str2 ) ; 
		
		Node *T = build( 0 , len1 - 1 , 0 , len2 - 1 ) ;
		
		postOrder( T ) ;
		printf( "\n" ) ;
	} 
	return 0 ;
}
