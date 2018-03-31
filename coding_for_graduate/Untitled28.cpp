//¶ş²æÅÅĞòÊ÷
#include <cstdio>
#include <cstring>

struct Node{
	Node *lchild ;
	Node *rchild ;
	int val ;
}Tree[200];

int loc ;
Node *creat(){
	Tree[loc].lchild = Tree[loc].rchild = NULL ;
	return &Tree[loc++] ;
} 

void preOrder( Node *T ){

	printf( "%d " , T->val ) ;
		
	if( T->lchild != NULL )
		preOrder( T->lchild ) ;
		
	if( T->rchild != NULL )
		preOrder( T->rchild ) ;
	
}

void inOrder( Node *T ){
	
	if( T->lchild != NULL )
		inOrder( T->lchild ) ;
		
	printf( "%d " , T->val ) ;
	
	if( T->rchild != NULL )
		inOrder( T->rchild ) ;
	
}

void postOrder( Node *T ){
	
	
	if( T->lchild != NULL )
		postOrder( T->lchild ) ;
		
	if( T->rchild != NULL )
		postOrder( T->rchild ) ;
	
	printf( "%d " , T->val ) ;
}

Node *Insert( Node *T , int x ){
	if( T == NULL ){
		T = creat() ;
		T->val = x ;
		return T ;
	}
	else if( x < T->val )
		T->lchild  = Insert( T->lchild , x ) ;
	else if( x > T->val )
		T->rchild = Insert( T->rchild , x ) ;
		
	return T ;
}

int main(){
	int n ;
	int x ;
	while( ~scanf( "%d" , &n ) ){
		loc = 0 ;
		Node *T = NULL ; 
		for( int i = 0 ; i < n ; i++ ){
			scanf( "%d" , &x ) ;
			T = Insert( T , x ) ;
		}
		
		preOrder( T ) ;
		printf( "\n" ) ;
		
		inOrder( T ) ;
		printf( "\n" ) ;
		
		postOrder( T ) ;
		printf( "\n" ) ;
		
	}
	return 0 ;
}
