/*****************************************
 * Assignment 2
 * Name:    Dheeraj M
 * E-mail:  ee21btech11015
 * Course:      ID2230
 * Submitted:    18/10/23
 *
 * The main driver program for project 2.
 * displays the results in the format specified in the project description.
 *
***********************************************/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "BST.h"
#include "AVL.h"
//Knuth algorithm
void shuffleArray(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
int ** inputGenerator(){
    int ** Array = (int**)malloc(sizeof(int*)*100);
    int in,im;
    im = 0;
    int N = 10000;
    int M =1000;
    int len = 100;
    for(int i = 0 ;i < len;i++){
        srand(time(0));
        Array[i] = (int*)malloc(sizeof(int)*M);
        for(in = i; in<N && im<M; ++in){
            int rn = N-in;
            int rm = M-im;
            if(rand()%rn<rm){
                Array[i][im++] = in+1;
            }          
        }
        im = 0;

        shuffleArray(Array[i], M);  
    }
   
    return Array;
}
int *RandomKey(){
    int M = 100;
    int N =1000;
    int * keys = (int*)malloc(sizeof(int)*M);
    int in , im;
    im = 0;
    srand(time(0));
    for(int in = 300;in<N && im<M;++in){
        int rn = N-in;
        int rm = M - im;
        if(rand()% rn<rm){
        keys[im++] = in+1;
        }
    }
    //printf("the value of im++ %d\n",im);
    return keys;
}
// int areElementsUnique(int* arr, int size) {
//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             if (arr[i] == arr[j]) {
//                 return 0; // Not all elements are unique
//             }
//         }
//     }
//     return 1; // All elements are unique
// }


int main(){
    //random number generator
    //input generator
    int ** input = inputGenerator();    
    BST **T =(BST**)malloc(sizeof(BST*)*100); // creation of 100 trees
    AVL **A = (AVL**)malloc(sizeof(AVL*)*100);    
    int *compAVL = (int*)malloc(sizeof(int)*100);
    int *compBST = (int*)malloc(sizeof(int)*100);

    //BST tree

    for(int i = 0;i<100;i++){
        *(T+i) = (BST*)malloc(sizeof(BST));
        createBST(*(T+i));
        BSTarrayInsert(input[i],1000,*(T+i));
        //printf("the address if T[i] is %p\n",*(T+i));
        //(*(T+i))->height = 99;
       

        // if(i == 0){
        //     FILE* dotFile = fopen("treeBST.dot", "w");
        //         if (!dotFile) {
        //             perror("Error opening DOT file");
        //             exit(EXIT_FAILURE);
        //         }
        //     // Write DOT file header
        //     fprintf(dotFile, "digraph BST {\n");
        //     // Call the function to generate DOT content
        //     generateDotFile((*(T+i))->root, dotFile);
        //     fprintf(dotFile, "}\n");
        //     fclose(dotFile);
        // }
    
        
        int * keys = RandomKey();
        for(int j = 0;j<100;j++){
            node * n = Find(input[i][j] , (*(T+i))->root,*(T+i));
             
            if(n != NULL){
            printf("the node that will be deleted is %d\n",n->key);
            deleteNode((*(T+i)) ,n);
            //printf("the node is getting deleated\n");
            }
        }
        *(compAVL+i) =(*(T+i))->count;
        // if(i == 0){
        //     FILE* dotFile = fopen("treeDeleteBST.dot", "w");
        //         if (!dotFile) {
        //             perror("Error opening DOT file");
        //             exit(EXIT_FAILURE);
        //         }
        //     // Write DOT file header
        //     fprintf(dotFile, "digraph BST {\n");
        //     // Call the function to generate DOT content
        //     generateDotFile((*(T+i))->root, dotFile);
        //     fprintf(dotFile, "}\n");
        //     fclose(dotFile);
        // }


        
    }
    FILE* csv = fopen("BST.csv", "w");
        for(int i = 0;i<100;i++){
            fprintf(csv,"%d%s",*(compAVL+i),",");
        }
    //AVL Tree
    
    
    for(int i = 0;i<100;i++){
       
        *(A+i) = (AVL*)malloc(sizeof(AVL));
        createAVL(*(A+i));
        //printf("the address if T[i] is %p\n",*(T+i));
        AVLarrayInsert(input[i],1000,*(A+i));
        (*(A+i))->height = 99;
        //printf("the value of root is %d\n",(*(A+i))->root->key);
        
        // if(i == 0){
        //     FILE* dotFile = fopen("treeAVL.dot", "w");
        //         if (!dotFile) {
        //             perror("Error opening DOT file");
        //             exit(EXIT_FAILURE);
        //         }
        //     // Write DOT file header
        //     fprintf(dotFile, "digraph BST {\n");
        //     // Call the function to generate DOT content
        //     generateDotFileAVL((*(A+i))->root ,dotFile);
        //     fprintf(dotFile, "}\n");
        //     fclose(dotFile);
        // }
        int * keys = RandomKey();
       
        for(int j = 0;j<100;j++){
           
            nodeAVL * n1 = FindAVL(keys[j] , (*(A+i))->root , *(A+i));
            
            if(n1 != NULL){
                
               // printf("the node that will be deleted is %d\n",n1->key);
                deleteNodeAVL((*(A+i)) ,n1);
            }
        }
        *(compAVL+i) = (*(A+i))->comp;
        // if(i == 0){
        //     FILE* dotFile = fopen("treeDeleteAVL.dot", "w");
        //         if (!dotFile) {
        //             perror("Error opening DOT file");
        //             exit(EXIT_FAILURE);
        //         }
        //     // Write DOT file header
        //     fprintf(dotFile, "digraph BST {\n");
        //     // Call the function to generate DOT content
        //     generateDotFileAVL((*(A+i))->root ,dotFile);
        //     fprintf(dotFile, "}\n");
        //     fclose(dotFile);
        // }
        
    }
        FILE* csv1 = fopen("AVL.csv", "w");
        for(int i = 0;i<100;i++){
            fprintf(csv1,"%d%s",*(compAVL+i),",");
        }

        FILE* in = fopen("Input.csv", "w");
        for(int i = 0;i<100;i++){
            for(int j = 0;j<1000;j++){
            fprintf(in,"%d%s",input[i][j],",");
            }
            fprintf(in,"\n");
        }
        fclose(in);

    return 0;
}