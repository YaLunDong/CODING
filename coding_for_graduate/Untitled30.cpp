#include <cstdio>
#include <cstring>

struct Node{
    Node *lchild ;
    Node *rchild ;
    int val ;
}Tree[300];

int loc ;
char str1[23] , str2[23] ;
int size1 , size2 ;
char *str ;
int *size ;
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

void preOrder( Node *T ){
    
   
    str[ ( *size )++ ] = T->val + '0' ;
    
    if( T->lchild != NULL )
        preOrder( T->lchild ) ;
    
    if( T->rchild != NULL )
        preOrder( T->rchild ) ;
}

void inOrder( Node *T ){
	
    if( T->lchild != NULL )
        inOrder( T->lchild ) ;
    
     str[ ( *size )++ ] = T->val + '0' ;
    
    if( T->rchild != NULL )
        inOrder( T->rchild ) ;
}

int main(){
    int n ;
    char tmp[23] ;
    while( ~scanf( "%d" , &n ) && n != 0 ){
        
        loc = 0 ;
        Node *T = NULL ;
        scanf( "%s" , tmp) ;
        for( int i = 0 ; tmp[i] != 0 ; i++ ){
            T = Insert( T , tmp[i] - '0' ) ;
        }
        size1 = 0 ;
        str = str1 ;
        size = &size1 ;
        preOrder( T ) ;
        inOrder( T ) ;
        str1[size1] = 0 ;
        
        while( n-- ){
            
            scanf( "%s" , tmp ) ;
            Node *T2 = NULL ;
            for( int i = 0 ; tmp[i] != 0 ; i++ ){
                T2 = Insert( T2 , tmp[i] - '0' ) ;
            }
            size2 = 0 ;
            str = str2 ;
            size = &size2 ;
            preOrder( T2 ) ;
            inOrder( T2 ) ;
            str2[size2] = 0 ;
            if( strcmp( str1 , str2 ) == 0 ) puts( "YES\n" ) ;
            else puts( "NO\n" ) ;
        }
    }
    return 0 ;
}
