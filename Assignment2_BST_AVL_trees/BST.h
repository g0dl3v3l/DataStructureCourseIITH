#include "stdio.h"
#include "stdlib.h"
#include "node.h"
#include <graphviz/gvc.h>
#define COUNT 10

//BST Node
struct BST{
    node *root;
    int height;
    int count;
};
typedef struct BST BST;


void createBST(BST* T){
   
    T->root = NULL;
    T->height = 0;
    T->count = 0;

}
// function to insert the node.
void BSTinsertNode(int key , BST* T){
    //printf("it has entered here\n");
    node *N = (node*)malloc(sizeof(node));
    N->key = key;
    N->left = NULL;
    N->right = NULL;
    N->parent = NULL;
    node* y = NULL;
    node* x ;
    x = T->root;
    while(x!=NULL){
        y = x;
        if(N->key < x->key){
            x = x->left;
            (T->count)++;
        }else{
            x = x->right;
            (T->count)++;
        }
    }
    N->parent = y;
    printf("the node is %d\n",N->key);
    if(y == NULL){
        T->root = N;
        (T->count)++;
    }else if(y->key < N->key){
        y->right = N;
        (T->count)++;
    }else{
        y->left = N;
        (T->count)++;
    }
}  
//to extract each key from the input and pass it to insert node.
void BSTarrayInsert(int *subArray,int n, BST *T){
   
    int key = 0;
    //printf("key %d ",key);
    for(int i = 0;i<n;i++){
       // printf("key %d ",key);
       
        key = *(subArray + i);
        //printf("it has entered here %d\n",i);
        //printf("key %d ",key);
        BSTinsertNode(key , T);

    }
}
// Function used to search the node in the tree
node * Find(int key ,node*root , BST* T){
    if(root == NULL){
        (T->count)++;
        return NULL;

    }
    if(key<root->key){
        (T->count)++;
        return Find(key , root->left , T);
    }
    if(key>root->key){
        (T->count)++;
        return Find(key,root->left, T);
    }
    return root;
}

node* BST_mimimum(node *x){
    while (x->left != NULL){
        x = x->left;
    }
    return x;

}

void translplant(BST* T,node* u,node* v){
    if(u->parent == NULL){
        (T->count)++;
        T->root = v;
    }else if(u == u->parent->left){
        (T->count)++;
        u->parent->left = v;
    }else{
        (T->count)++;
        u->parent->right = v;
    }
    if(v != NULL){
        (T->count)++;
        v->parent = u->parent;
    }
}

// function to delete the node.
void deleteNode(BST*T , node* z){

if(z != NULL){
    
    if(z->right == NULL && z->left == NULL){
            printf("it is happening in this block\n");
            if(z->parent !=NULL){
            node *temp = z->parent;
            if(temp->left == z){
                (T->count)++;
                temp->left = NULL;  
            }else if(temp->right == z){
                (T->count)++;
                temp->right = NULL;
            }
            z->parent = NULL;
            //free z;
        }else{
            
        }
           
        }
    else if (z->left == NULL){
        (T->count)++;
        printf("there\n");
        translplant(T,z,z->right);
    }
    else if(z->right ==NULL){
        (T->count)++;
        printf("where\n");
        translplant(T,z, z->left);
    }
    else{
        node*  y = (node*)malloc(sizeof(node));
        y = BST_mimimum(z->right);
        printf("the value of the minimum is %d\n",y->key);
        printf("the parent of the minimum value is %d\n",y->parent->key);
        if(y->parent != z){
            (T->count)++;
            translplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        translplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
        if(y->right != NULL){
            printf("the right node of p is %d\n",y->right->key);
        }else{
             printf("the right node of p is null\n");
        }
    
    }
}
}

//to generate graphic file
void generateDotFile(node* root, FILE* dotFile) {
    if (root == NULL) {
        return;
    }

    fprintf(dotFile, "  %d;\n", root->key); // Print the current node
   // printf("root->key %d\n",root->key);
    
    if (root->left != NULL) {
        fprintf(dotFile, "  %d -> %d;\n", root->key, root->left->key); // Edge to left child
        generateDotFile(root->left, dotFile); // Recurse into left subtree
    }

    if (root->right != NULL) {
        fprintf(dotFile, "  %d -> %d;\n", root->key, root->right->key); // Edge to right child
        generateDotFile(root->right, dotFile); // Recurse into right subtree
    }
}
