#include "stdio.h"
#include "stdlib.h"
#include "nodeAVL.h"
struct AVL{
    nodeAVL *root;
    int height;  
    int comp;
};
typedef struct AVL AVL;

void createAVL(AVL* tree){
    tree->root = NULL;
    tree->height = 0;
    tree->comp = 1;

}
int max(int a, int b){
    return a>b ? a: b;
}
int TreeHeight(nodeAVL *n){
    
    if(n == NULL){
        return 0;
    }
    //printf("We are in the height function!!!!!!!!!");
   // printf("node %d\n",n->key);
    if(n->left != NULL){
       //printf("the left value in the height fuction value%d\n",n->left->key);
    }else{
        //printf("the left node in the height function is null %p\n",n->left);
    }
    int TreeHeightLeft = TreeHeight(n->left);
     if(n->right != NULL){
        //printf("the right value in height function value%d\n",n->right->key);
    }else{
        //printf("the right node in the height function is null %p\n",n->right);
    }
    int TreeHeightRight =  TreeHeight(n->right);
    //printf("the treeHeight function returns %d\n",1 + max(TreeHeightLeft , TreeHeightRight));
    return 1 + max(TreeHeightLeft , TreeHeightRight);    
}
nodeAVL* AVL_mimimum(nodeAVL *x){
    while (x->left != NULL){
        x = x->left;
    }
    return x;

}
int isBalanced(nodeAVL* p){
     //printf("the value of p this is %d\n",p->key);
    if(p == NULL){
        return 1;
    }
    if(p->left != NULL){
        //printf("the left value%d\n",p->left->key);
    }else{
        //printf("the left node is null %p\n",p->left);
    }
    int leftHeight = TreeHeight(p->left);
   // printf("the left height is %d\n",leftHeight);

    if(p->right != NULL){
       // printf("the right value%d\n",p->right->key);
    }else{
       // printf("the right node is null %p\n",p->right);
    }
    int rightHeight = TreeHeight(p->right);
    //printf("the right height is %d\n",rightHeight);
     if (abs(leftHeight - rightHeight) > 1) {
        return 0;
    }

    return 1;
}

int k_factor(nodeAVL* p){
    if(p == NULL){
        return 0;
    }
    return TreeHeight(p->left) - TreeHeight(p->right);
}
void rightRotation(nodeAVL *c ,nodeAVL *b, AVL *T){
    c->left = b->right;

    if(b->right != NULL){
        b->right->parent = c;
        (T->comp)++;
    }
    b->right = c;

    // if(c->parent != NULL){
    //     c->parent->left = c;
    // }
    if(c == T->root){ 
        b->parent = c->parent;
       
        //c->parent->right = c;
        c->parent = b;
      
        T->root = b;
  
    }else{
        if(c->parent->left == c){
            b->parent = c->parent;
          
            b->parent->left = b;
      
            c->parent = b;
            
        }else if(c->parent->right == c){
            b->parent = c->parent;
        
            b->parent->right = b;
  
            c->parent = b;
            (T->comp)++;
        }
        
    }
}
void leftRotation(nodeAVL *a , nodeAVL *b, AVL *T){
    a->right = b->left;
    
    if(b->left != NULL){
        b->left->parent = a;
        (T->comp)++;
    }
    b->left = a;
   
    if(a == T->root){
        b->parent = a->parent;
       
        a->parent = b;
        
        T->root = b;
        (T->comp)++;

    }else{
        //printf("it has not attacket the root node\n");
        if(a->parent->right == a){
            b->parent = a->parent;
          
            b->parent->right = b;
         
            a->parent = b;
            (T->comp)++;
        }else if(a->parent->left == a){
            b->parent = a->parent;
            
            b->parent->left = b;
           
            a->parent = b;
            (T->comp)++;
        }
    }

    //printf("the values of b-key%d\n", b->key);
}


void rebalace(nodeAVL *N,nodeAVL *v, nodeAVL *a,AVL* T){
    //printf("%d\n",isBalanced(N->parent));
  
    if(isBalanced(N) == 0){
        if(N->left == v){
            if(v->right == a){
                //double rotation
                //printf("double rotation\n");
                leftRotation(v , a, T);
                rightRotation(N,a,T);
                //N = a->parent;
                //printf("the value of v->parent %p\n",N);
                //v = a;
                //a = a->left;
                // printf("the middle node is %d\n",a->key);
                // printf("the left node is%d\n",a->left->key);
                // printf("the right node is %d\n",a->right->key);
                // printf("the root is %d\n",T->root->key);

            }else{
                //single rotation
                //printf("single rotations\n");
                rightRotation(N,v,T);
               // N = v->parent;
               //// printf("the value of v->parent %p\n",N);
              //  a = v->left; 
                // printf("the middle node is %d\n",v->key);
                // printf("the left node is%d\n",v->left->key);
                // printf("the right node is %d\n",v->right->key);
                // printf("the root is %d\n",T->root->key);
            }
        }else if(N->right == v){
            if(v->left == a){
                //printf("double rotation right\n");
                rightRotation(v ,a,T);
                leftRotation(N,a,T);
                //N = a->parent;
                //printf("the value of v->parent %p\n",N);
               // v = a;
               // a = a->right;
                // printf("the middle node is %d\n",a->key);
                // printf("the left node is%d\n",a->left->key);
                // printf("the right node is %d\n",a->right->key);
                // printf("the root is %d\n",T->root->key);
            }else{
                //printf("single rotations left\n");
                leftRotation(N,v,T);
               // N = v->parent;
                //printf("the value of v->parent %p\n",N);
                //a = v->right;
                // printf("the middle node is %d\n",v->key);
                // printf("the left node is%d\n",v->left->key);
                // printf("the right node is %d\n",v->right->key);
                // printf("the root is %d\n",T->root->key);
                
            }
        }
    }else{
    //    if(N->right == v){
    //         N=N->parent;
    //         v = N->right;
    //         a = v->right;
            
    //     }else if(N->left == v){
    //         N = N->parent;
    //         v = N->left;
    //         a = v->left; 


        }
    }



nodeAVL * FindAVL(long key ,nodeAVL*root , AVL* T){
    if(root == NULL){
        (T->comp)++;
        return NULL;

    }
    //printf("the value of key is %lld, the value of root key is %lld\n",key,root->key);
    if(key<root->key){
        (T->comp)++;
        return FindAVL(key , root->left , T);
    }
    if(key>root->key){
        (T->comp)++;
        return FindAVL(key,root->right, T);
    }
    //printf("the value being returned is %d\n",root->key);
    return root;
}

void AVLinsertNode(long key , AVL* T){

    nodeAVL *N = (nodeAVL*)malloc(sizeof(nodeAVL));
    N->key = key;
    N->left = NULL;
    N->right = NULL;
    N->parent = NULL;
    nodeAVL* y = NULL;
    nodeAVL* x ;
      
    x = T->root;
    while(x!=NULL){ 
        y = x;
        if(N->key < x->key){
            x = x->left;
            (T->comp)++;
        }else{
            x = x->right;
            (T->comp)++;
        }
         
    }
 
    N->parent = y;
    
    if(y == NULL){
       
        T->root = N;
        (T->comp)++;
    }else if(y->key < N->key){
     
        y->right = N;
        (T->comp)++;
    }else{
      
        y->left = N;
        (T->comp)++;
    }
    //printf("the node getting insereted is%d\n",N->key);
    if(N->parent != NULL){
    //printf("the nodes parent is %d\n", N->parent->key);
    }
    // if(N->parent != NULL){
    //     if(N->parent->parent != NULL){
    //         if(isBalanced(N->parent->parent) == 0){
    //                 rebalace(N->parent->parent,N->parent,N,T);
    //         }else if(N->parent->parent->parent != NULL){
    //             if(isBalanced(N->parent->parent->parent) == 0){
    //                 rebalace(N->parent->parent->parent,N->parent->parent,N->parent,T);
    //             }
    //         }
    //     }
    // }
    if(N->parent != NULL){
        if(N->parent->parent != NULL){
            nodeAVL * temp;
            temp = N;
            while(N->parent->parent != NULL){
                if(isBalanced(N->parent->parent) == 0){
                    //printf("the node getting balanced is %d\n",N->parent->parent->key);
                    rebalace(N->parent->parent,N->parent,N,T);
                    if(temp->parent != NULL){
                       // printf("now the parent of the added node is %d\n",temp->parent->key);
                    }
                    break;
                }else{
                    N = N->parent;
                }
            }
        }
    }
}


void AVLarrayInsert(int *subArray,int n, AVL *T){
    
    int key = 0;
    //printf("key %d ",key);
    for(int i = 0;i<n;i++){
       // printf("key %d ",key);
        key = *(subArray + i);
        //printf("key %d ",key);
    AVLinsertNode(key , T);

    }
}
// the paramenter is the parent node 


void translplantAVL(AVL* T,nodeAVL* u,nodeAVL* v){
    if(u->parent == NULL){
        T->root = v;
        (T->comp)++;
    }else if(u == u->parent->left){
        u->parent->left = v;
        (T->comp)++;
    }else{
        u->parent->right = v;
        (T->comp)++;
    }
    if(v != NULL){
        v->parent = u->parent;  
        u->parent = NULL;
        (T->comp)++;
    }
}
void deleteNodeRebalance(nodeAVL * y,AVL * T){
    //printf("the nodes are getting deleated!!!!!!!!!!!!\n");
    while (y != NULL && isBalanced(y) != 0) {
        // Perform rebalancing steps
        //printf("the value of y which is now balanced is %d\n",y->key);
        y = y->parent;
   
        
    }


    if(y != NULL){
        //printf("it is entering the balanced part\n");
        int k = k_factor(y);
        nodeAVL *c ;
        nodeAVL *b;
       // printf("the value of k factor is %d\n", k);
        if(k >0){
        
        b = y->left;
            if(k_factor(b) >= 0){
               // printf("r rotation\n");
                c = b->left;
               
                rightRotation(y , b,T);
            }else if(k_factor(b) < 0){
                //printf("lr rotation\n");
                c = b->right;
              
                leftRotation(b,c,T);
                rightRotation(y,c,T);
            }
        }else{
            b = y->right;
            if(k_factor(b) < 0){
               // printf("l rotation");
                c = b->right;
       
                leftRotation(y,b,T);
            }else if(k_factor(b) >= 0){
                //printf("rl rotation");
                c = b->left;
            
                rightRotation(b,c,T);
                leftRotation(y,c,T);
            }

        }
    }
}

void deleteNodeAVL(AVL*T , nodeAVL* z){
    if(z->parent != NULL){
        if(z->right == NULL && z->left == NULL){
            //printf("it is happening in this block\n");
            nodeAVL *temp = z->parent;
            if(temp->left == z){
                temp->left = NULL;  
                (T->comp)++;
            }else if(temp->right == z){
                temp->right = NULL;
                (T->comp)++;
            }
            z->parent = NULL;
            //free z;
            deleteNodeRebalance(temp,T);
        
        }else if (z->left == NULL){
            translplantAVL(T,z,z->right);
            //rebalace( z,z->parent,T);
            deleteNodeRebalance(z->right,T);
            (T->comp)++;
        }
        else if(z->right ==NULL ){
            translplantAVL(T,z, z->left);
            //rebalace(z, z->parent,T);
            deleteNodeRebalance(z->left,T);
            (T->comp)++;
        } 
        else{
            nodeAVL*  y = (nodeAVL*)malloc(sizeof(nodeAVL));
            y = AVL_mimimum(z->right);
            //printf("the value of the minimum is %d\n",y->key);
            //printf("the parent of the minimum value is %d\n",y->parent->key);
            if(y->parent != z){
                (T->comp)++;
                translplantAVL(T,y,y->right);
                y->right = z->right;
                y->right->parent = y;
                //printf("the value of y->right %d and y->right->parent %d\n",y->right->key,y->right->parent->key);                printf("the node got transplanted\n");
            }
            translplantAVL(T,z,y);
            y->left = z->left;
            
            y->left->parent = y;
            if(y->right != NULL){
            //printf("the right node of p is %d\n",y->right->key);
            }else{
               // printf("the right node of p is null\n");
            }
            //rebalace(y , y->parent, T);
            //printf("the error is happing here\n");
            //printf("the value of y is now %p\n,",y->right);
            deleteNodeRebalance(y,T);
        }   
    }else{
        
        if(z->right == NULL && z->left == NULL){
            //printf("it is happening in this block\n");
            //printf("the root node is being deleted\n");
            z = NULL;
            T->root = z;
        
        }else if (z->left == NULL){
           // printf("right node deletion\n");
            z->right->parent = NULL;
            z = z->right;
            T->root = z;
        }else if(z->right == NULL){
            //printf("left node deletion \n");
            z->left->parent = NULL;
            z = z->left;
            T->root = z;
        }else{
            nodeAVL*  y = (nodeAVL*)malloc(sizeof(nodeAVL));
            y = AVL_mimimum(z->right);
            //printf("the value of the minimum is %d\n",y->key);
            //printf("the parent of the minimum value is %d\n",y->parent->key);
            if(y->parent != z){
                (T->comp)++;
                translplantAVL(T,y,y->right);
                y->right = z->right;
                y->right->parent = y;
                //printf("the value of y->right %d and y->right->parent %d\n",y->right->key,y->right->parent->key);                printf("the node got transplanted\n");
            }
            translplantAVL(T,z,y);
            y->left = z->left;
            
            y->left->parent = y;
            if(y->right != NULL){
            //printf("the right node of p is %d\n",y->right->key);
            }else{
               // printf("the right node of p is null\n");
            }
            //rebalace(y , y->parent, T);
            //printf("the error is happing here\n");
            //printf("the value of y is now %p\n,",y->right);
            deleteNodeRebalance(y,T);
        }
        
    }
}


void generateDotFileAVL(nodeAVL* root, FILE* dotFile) {
    if (root == NULL) {
        return;
    }

    fprintf(dotFile, "  %lld;\n", root->key); // Print the current node
    //printf("root->key %d\n",root->key);
    
    if (root->left != NULL) {
        fprintf(dotFile, "  %lld -> %lld;\n", root->key, root->left->key); // Edge to left child
        generateDotFileAVL(root->left, dotFile); // Recurse into left subtree
    }

    if (root->right != NULL) {
        fprintf(dotFile, "  %lld -> %lld;\n", root->key, root->right->key); // Edge to right child
        generateDotFileAVL(root->right, dotFile); // Recurse into right subtree
    }
}

void printAVL(AVL *tree){
    FILE* dotFile = fopen("avl.dot", "w");
    fprintf(dotFile, "digraph BST {\n");
    generateDotFileAVL(tree->root, dotFile);
    fprintf(dotFile, "}\n");
    fclose(dotFile);
    system("dot -Tpng avl.dot -o avl.png");
    system("xdg-open avl.png");
}
