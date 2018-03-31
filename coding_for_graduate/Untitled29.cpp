#include <cstdio>
#include <cstring>

struct Node{
    Node *lchild ;
    Node *rchild ;
    int val ;
}Tree[110];
int loc ;
Node *creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL ;
    return &Tree[loc++] ;
}

Node *Insert( Node *T , int x ){
    if( T == NULL ){
        T = creat() ;
        T->val = x ;
        return T ;
    }
    else if( x < T->val ){
        T->lchild = Insert( T->lchild , x ) ;
    }
    else{
        T->rchild = Insert( T->rchild , x ) ;
    }
    return T ;
}

void printFather( Node *T , int y ){
	
	if( T != NULL ){
	
		if( T->lchild != NULL && T->lchild->val == y || T->rchild != NULL && T->rchild->val == y ){
	
			printf("%d\n" , T->val ) ;
			return ;
		
		}
	
	
	
		printFather( T->lchild , y ) ;
		
	
		printFather( T->rchild , y ) ;
   }
}

int main(){
    int N ;
    int x ;
    while( ~scanf( "%d" , &N ) ){
    	
        Node *T = NULL ;
        loc = 0 ;
        
        for( int i = 0 ; i < N ; i++ ){
        	
            scanf( "%d" , &x ) ;
            T = Insert( T , x ) ;
            if( i == 0 ) 
                printf("-1\n") ;
            else
                printFather( T , x );
        }
        
        
    }
    return 0 ;
}
