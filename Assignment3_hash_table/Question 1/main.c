/*****************************************
 * Assignment 3 - Question 1
 * Name:    Dheeraj M
 * E-mail:  ee21btech11015@iith.ac.in
 * Course:      ID2230
 * Submitted:    7/10/2023
 * Quesition 1: 
 * Separate Chaining: You are free to choose the hash function and size of the hash table.
 * The “chain” should be implemented as an AVL tree. You can re-use the code for the AVL
 * tree that you have implemented in the previous assignment.
 * (5 marks each for insert, search and delete).
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adharGeneration.h"
#include "seperateChaining.h"
#include <sys/stat.h>

void removeCommonValues(long *a, long *b, int sizeA, int sizeB) {
    int i, j, k;
    for (i = 0; i < sizeA; i++) {
        for (j = 0; j < sizeB; j++) {
            if (a[i] == b[j]) {
                for (k = i; k < sizeA - 1; k++) {
                    a[k] = a[k + 1];
                }
                sizeA--;
                i--;
                break;
            }
        }
    }
}


void writeToCSV(char *columnName, char *fileName, long *data, int size) {
    char dirName[] = "outputcsv";
    mkdir(dirName, 0777);
    char filePath[100];
    sprintf(filePath, "%s/%s", dirName, fileName);
    FILE *fp = fopen(filePath , "w");
    fprintf(fp, "%s\n", columnName);
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%ld\n", data[i]);
    }
    fclose(fp);
}


// shuffling the array 
void shuffleArray(long *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        long temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// generating data from the space of the in put array(searchSpace)
void subArray(long *searchSpace, long *searchArray, int N ,int M){
    
    if(M > N){
        printf("input value size is greater that the search size");

    }

    shuffleArray(searchSpace, N);
    for(int i=0;i<M;i++){
       //printf("%ld\n", searchSpace[i]);
        searchArray[i] = searchSpace[i];

    }
}

// Generating two arrays of unique random numbers each having no commnon numbers

int inputGenerator(long * Array,  long * Array_remaining, int size){
    // long * Array = (long*)malloc(sizeof(long*)*100);
    // long * Array_remaining = (long*)malloc(sizeof(long*));
    int in,im;
    im = 0;
    long N = 10000000;
    //Array_remaining = (long*)malloc(sizeof(long*)*(N-size));
    long M = size;
    int j = 0;
    srand(time(0));
    for (long in = 1; in <= N; ++in) {
        if (im < M && (rand() % (N - in + 1) < (M - im))) {
            Array[im++] = in;
        } else if (j < M) {
            Array_remaining[j++] = in;
        }
    }

    
    //shuffleArray(Array, M);  
    return j;
}



int main() {
    
    // Create a hash table of size 1003
   int tableSize = 1003;
   int size = 1000;
   hashTable *table = (hashTable *)malloc(sizeof(hashTable));
    hashTableCreate(table, tableSize);  

    // Allocate memory for an input array of size 1000 to be inserted in the hash table
    
    long  *adharNumber = (long  *)malloc(size * sizeof(long));
    // Allocate memory for an array of remaining values from the space of 10 million numbers which are not inserted in the hash table
    long *adharNumber_remaining = malloc(sizeof(long) * 1000);

    // Generate an input array of size 1000 and an array of remaining values
    int size1 = inputGenerator(adharNumber, adharNumber_remaining, 1000);
    writeToCSV("inserted keys", "keysInserted_1003.csv", adharNumber, 1000);

    // Allocate memory for an array of 100 data points from the input array for searching in the hash table
    long *searchinput = malloc(sizeof(long) * 100);

    // Generate 100 data points from the input array for searching in the hash table
    subArray(adharNumber, searchinput, 1000, 100);
    writeToCSV("searched keys", "keysSearched_1003_(Q a).csv", searchinput, 100);
    // Insert the input array in the hash table and get the probing value
    hashChainArrayInsert(table, adharNumber, size);

    // Allocate memory for an array of 100 data points from the remaining values for searching in the hash table
    long *searchinput_remaining = malloc(sizeof(long) * 100);

    // Generate 100 data points from the remaining values for searching in the hash table
    subArray(adharNumber_remaining, searchinput_remaining, size, 100);
    writeToCSV("remaining keys", "keysRemainingSearched_1003(Q d).csv", searchinput_remaining, 100);
    // Print the probing value after 100 insertions on a hash table of size 1000
   
    // a) searching the hashtable for the 100 values
   long* prob = (long*)malloc(sizeof(long));
   long sum= 0;
   int flag = 0;
   for(int i = 0 ; i < 100 ; i++){
       int index = hashSearch(table, searchinput[i], &prob);
       sum = sum + *prob;
         if(index != -1){
              flag +=1;
         }
       //printf("the index is %d\n", index);
   }
   //printf("number of successful searches %d\n", flag);
   writeToCSV("probing value", "probingValue_1003_(Q a).csv", &sum, 1);


// b) deleating the searched value from the hash table
    for(int i = 0 ;i<100;i++){
        hashDelete(table, searchinput[i]);
    }



long *searchinput2 = malloc(sizeof(long) * 100);
removeCommonValues(adharNumber, searchinput, 1000, 100);

subArray(adharNumber, searchinput2, 900 , 100);
writeToCSV("searched keys", "keysSearched_1003_(Q c).csv", searchinput2, 100);


// c)another 100 successful searches
    long* prob2 = (long*)malloc(sizeof(long));
    long sum2= 0;
    int flag2 = 0;
    for(int i = 0 ; i < 100 ; i++){
        //printf("the value is \n");
        int index = hashSearch(table, searchinput2[i], &prob2);
        //printf("the probvalue %p", prob2);
        sum2 = sum2 + *prob2;
        if(index != -1){
            flag2 +=1;
        }
       // printf("the index is %d\n", index);
    }

 writeToCSV("probing value", "probingValue_1003_(Q c).csv", &sum2, 1);
//d) 100 unsuccessful searches (chosen u.a.r from the remaining).
    long* prob3 = (long*)malloc(sizeof(long));
    long sum3= 0;
    int flag3 = 0;
    for(int i = 0 ; i < 100 ; i++){
        int index = hashSearch(table, searchinput_remaining[i], &prob3);
        sum3 = sum3 + *prob3;
        if(index == -1){
            flag3 +=1;
        }
        //printf("the index is %d\n", index);

    }
 writeToCSV("probing value", "probingValue_1003_(Q d).csv", &sum3, 1);

    tableSize = 2003;
    // Create a hash table of size 2003
    hashTable *table2 = (hashTable *)malloc(sizeof(hashTable));
    hashTableCreate(table2, tableSize);  
    hashChainArrayInsert(table, adharNumber, size);

    // Allocate memory for an input array of size 1000 to be inserted in the hash table
    
    long  *adharNumber2 = (long  *)malloc(size * sizeof(long));
    // Allocate memory for an array of remaining values from the space of 10 million numbers which are not inserted in the hash table
    long *adharNumber_remaining2 = malloc(sizeof(long) * 1000);

    // Generate an input array of size 1000 and an array of remaining values
    int size1_2 = inputGenerator(adharNumber2, adharNumber_remaining2, 1000);
    writeToCSV("inserted keys", "keysInserted_2003.csv", adharNumber2, 1000);

    // Allocate memory for an array of 100 data points from the input array for searching in the hash table
    long *searchinput2_1 = malloc(sizeof(long) * 100);

    // Generate 100 data points from the input array for searching in the hash table
    subArray(adharNumber2, searchinput2_1, 1000, 100);
    writeToCSV("searched keys", "keysSearched_2003_(Q a).csv", searchinput2_1, 100);
    // Insert the input array in the hash table and get the probing value
    hashChainArrayInsert(table2, adharNumber2, size);

    // Allocate memory for an array of 100 data points from the remaining values for searching in the hash table
    long *searchinput_remaining2 = malloc(sizeof(long) * 100);

    // Generate 100 data points from the remaining values for searching in the hash table
    subArray(adharNumber_remaining2, searchinput_remaining2, size, 100);
    writeToCSV("remaining keys", "keysRemainingSearched_2003_(Q d).csv", searchinput_remaining2, 100);
    // Print the probing value after 100 insertions on a hash table of size 1000
   


    // a) searching the hashtable for the 100 values
    sum= 0;
    flag = 0;
    for(int i = 0 ; i < 100 ; i++){
        int index = hashSearch(table2, searchinput2_1[i], &prob);
        sum = sum + *prob;
        if(index != -1){
            flag +=1;
        }
    }
    writeToCSV("probing value", "probingValue_2003_(Q a).csv", &sum, 1);

    // b) deleting the searched value from the hash table
    for(int i = 0 ;i<100;i++){
        hashDelete(table2, searchinput2_1[i]);
    }

    // c) another 100 successful searches
    long *searchinput2_2 = malloc(sizeof(long) * 100);
    removeCommonValues(adharNumber2, searchinput2_1, 1000, 100);

    subArray(adharNumber2, searchinput2_2, 900 , 100);
    
    writeToCSV("searched keys", "keysSearched_2003_(Q c).csv", searchinput2_2, 100);
    sum2= 0;
    flag2 = 0;
    for(int i = 0 ; i < 100 ; i++){
        int index = hashSearch(table2, searchinput2[i], &prob2);
        sum2 = sum2 + *prob2;
        if(index != -1){
            flag2 +=1;
        }
    }
    writeToCSV("probing value", "probingValue_2003_(Q c).csv", &sum2, 1);

    // d) 100 unsuccessful searches (chosen u.a.r from the remaining).
    sum3= 0;
    flag3 = 0;
    for(int i = 0 ; i < 100 ; i++){
        int index = hashSearch(table2, searchinput_remaining2[i], &prob3);
        sum3 = sum3 + *prob3;
        if(index == -1){
            flag3 +=1;
        }
    }
    writeToCSV("probing value", "probingValue_2003_(Q d).csv", &sum3, 1);

    // Free allocated memory
    

    return 0;


}