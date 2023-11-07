/*****************************************
 * Assignment 3 - Question 2
 * Name:    Dheeraj M
 * E-mail:  ee21btech11015@iith.ac.in
 * Course:      ID2230
 * Submitted:    7/10/2023
 * Quesition 2: 
 * Open Addressing with double hashing: You are free to choose the hash functions, but
 * you have to implement them yourself. Choose two sizes of tables: one slightly larger
 * than 1000 and one larger than 2000.
***********************************************/
#include "stdio.h"
#include "stdlib.h"
#include "openAddress.h"
#include "time.h"
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



// writing the data to a csv file
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



int main(){

    // generating 1000 unique random numbers
    
    // Create a hash table of size 1000
    hashTable *h1 = createHashTable(1003);

    // Allocate memory for an input array of size 1000 to be inserted in the hash table
    long *input1 = malloc(sizeof(long) * 1000);

    // Allocate memory for an array of remaining values from the space of 10 million numbers which are not inserted in the hash table
    long *input_remaining = malloc(sizeof(long) * 1000);

    // Generate an input array of size 1000 and an array of remaining values
    int size = inputGenerator(input1, input_remaining, 1000);
    writeToCSV("inserted keys", "keysInserted_1003.csv", input1, 1000);

    // Allocate memory for an array of 100 data points from the input array for searching in the hash table
    long *searchinput = malloc(sizeof(long) * 100);

    // Generate 100 data points from the input array for searching in the hash table
    subArray(input1, searchinput, 1000, 100);
    writeToCSV("searched keys", "keysSearched_1003_(Q a).csv", searchinput, 100);
    // Insert the input array in the hash table and get the probing value
    long ser = hashInsertArray(h1, input1, 1000);

    // Allocate memory for an array of 100 data points from the remaining values for searching in the hash table
    long *searchinput_remaining = malloc(sizeof(long) * 100);

    // Generate 100 data points from the remaining values for searching in the hash table
    subArray(input_remaining, searchinput_remaining, size, 100);
    writeToCSV("remaining keys", "keysRemainingSearched_1003_(Q d).csv", searchinput_remaining, 100);
    
   

   
   //a) 100 succesfull searches

    int flag1 = 0;
    long sum1 = 0;
    long *prob1 = (long*)malloc(sizeof(long));
    
    for(int i = 0 ;i < 100 ; i++){
       int index =  hashSearch(h1, searchinput[i],&prob1);
       sum1 += *prob1;
       //printf("the valus of prob is %ld\n", *prob1);
       if(index != -1){
           //printf("the value %lu is found at index %d\n", searchinput[i], index);
           flag1++;
       }
       else{
           //printf("the value %lu is not found\n", searchinput[i]);
       }

    }
// printf("the number of succesfull searches are %d\n", flag1);
// printf("the value of the sum is %ld\n", sum1);
writeToCSV("probing value", "probingValue_1003_(Q a).csv", &sum1, 1);
//deleating keys
for(int i = 0 ;i < 100 ; i++){
       hashDelete(h1, searchinput[i]);
    }

//printf("done\n");

// c) another 100 successful searches

long *searchinput1_2 = malloc(sizeof(long) * 100);
removeCommonValues(input1, searchinput, 1000, 100);

subArray(input1, searchinput1_2, 900 , 100);
writeToCSV("searched keys", "keysSearched_1003_(Q c).csv", searchinput1_2, 100);


int flag2 = 0;
long sum2 = 0;
long *prob2 = (long*)malloc(sizeof(long));
for(int i = 0 ;i < 100 ; i++){
       int index =  hashSearch(h1, searchinput1_2[i], &prob2);
       sum2 += *prob2;
       if(index != -1){
           //printf("the value %lu is found at index %d\n", searchinput1_2[i], index);
           
       }
       else{
           //printf("the value %lu is not found\n", searchinput1_2[i]);
           flag2++;
       }

    }
// printf("the number of unsuccesfull searches are %d\n", flag2);
// printf("the value of the sum is %ld\n", sum2);
writeToCSV("probing value", "probingValue_1003_(Q c).csv", &sum2, 1);
//d) 100 unsuccesfull searches
int flag3 = 0;
long sum3 = 0;
long* prob3 = (long*)malloc(sizeof(long));
for(int i = 0 ;i < 100 ; i++){
       int index =  hashSearch(h1, searchinput_remaining[i],&prob3);
         sum3 += *prob3;
       if(index != -1){
           //printf("the value %lu is found at index %d\n", searchinput_remaining[i], index);
          
       }
       else{
           //printf("the value %lu is not found\n", searchinput_remaining[i]);
            flag3++;
       }

    }


    // printf("number of unsuccesfull searches are %d\n", flag3);
    // printf("the value of the sum is %ld\n", sum3);
    writeToCSV("probing value", "probingValue_1003_(Q d).csv", &sum3, 1);



 // Create a hash table of size 2000
    
    
// Create a hash table of size 2003
hashTable *h2 = createHashTable(2003);

// Allocate memory for an input array of size 1000 to be inserted in the hash table
long *input2 = malloc(sizeof(long) * 1000);

// Allocate memory for an array of remaining values from the space of 10 million numbers which are not inserted in the hash table
long *input_remaining2 = malloc(sizeof(long) * 1000);

// Generate an input array of size 1000 and an array of remaining values
int size2 = inputGenerator(input2, input_remaining2, 1000);
writeToCSV("inserted keys", "keysInserted_2003.csv", input2, 1000);
// Allocate memory for an array of 100 data points from the input array for searching in the hash table
long *searchinput2 = malloc(sizeof(long) * 100);

// Generate 100 data points from the input array for searching in the hash table
subArray(input2, searchinput2, 1000, 100);
writeToCSV("searched keys", "keysSearched_2003_(Q a).csv", searchinput2, 100);
// Insert the input array in the hash table and get the probing value
ser = hashInsertArray(h2, input2, 1000);

// Allocate memory for an array of 100 data points from the remaining values for searching in the hash table
long *searchinput_remaining2 = malloc(sizeof(long) * 100);

// Generate 100 data points from the remaining values for searching in the hash table
subArray(input_remaining2, searchinput_remaining2, size2, 100);
writeToCSV("remaining keys", "keysRemainingSearched_2003_(Q d).csv", searchinput_remaining2, 100);

//a) 100 succesfull searches

flag1 = 0;
sum1 = 0;
prob1 = (long*)malloc(sizeof(long));
for(int i = 0 ;i < 100 ; i++){
   int index =  hashSearch(h2, searchinput2[i],&prob1);
    sum1 += *prob1;
   if(index != -1){
       //printf("the value %lu is found at index %d\n", searchinput2[i], index);
       flag2++;
   }
   else{
       //printf("the value %lu is not found\n", searchinput2[i]);
   }

}
// printf("the number of succesfull searches are %d\n", flag2);
// printf("the value of the sum is %ld\n", sum1);
writeToCSV("probing value", "probingValue_2003_(Q a).csv", &sum1, 1);

//deleting keys

for(int i = 0 ;i < 100 ; i++){
   hashDelete(h2, searchinput2[i]);
}
//printf("done\n");

//c) another 100 successful searches
long *searchinput2_2 = malloc(sizeof(long) * 100);
removeCommonValues(input2, searchinput2, 1000, 100);
subArray(input2, searchinput2_2, 900 , 100);
writeToCSV("searched keys", "keysSearched_2003_(Q c).csv", searchinput2_2, 100);

flag2 = 0;
sum2 = 0;
prob2 = (long*)malloc(sizeof(long));

for(int i = 0 ;i < 100 ; i++){
   int index =  hashSearch(h2, searchinput2_2[i],&prob2);
    sum2 += *prob2;
   if(index != -1){
       //printf("the value %lu is found at index %d\n", searchinput2_2[i], index);

   }
   else{
       //printf("the value %lu is not found\n", searchinput2_2[i]);
       flag2++;
   }

}
// printf("the number of unsuccesfull searches are %d\n", flag2);
// printf("the value of the sum is %ld\n", sum2);
writeToCSV("probing value", "probingValue_2003_(Q c).csv", &sum2, 1);

//d) 100 unsuccesfull searches
flag2 = 0;
sum3 = 0;
prob3 = (long*)malloc(sizeof(long));
for(int i = 0 ;i < 100 ; i++){
   int index =  hashSearch(h2, searchinput_remaining2[i],&prob3);
    sum3 += *prob3;
   if(index != -1){
       //printf("the value %lu is found at index %d\n", searchinput_remaining2[i], index);

   }
   else{
       //printf("the value %lu is not found\n", searchinput_remaining2[i]);
        flag2++;
   }

}


    // printf("number of unsuccesfull searches are %d\n", flag2);
    // printf("the value of the sum is %ld\n", sum3);
    writeToCSV("probing value", "probingValue_2003_(Q d).csv", &sum3, 1);

    return 0;
}