// generating 1000 unique random numbers
    
    // Create a hash table of size 1000
   hashTable *table = (hashTable *)malloc(sizeof(hashTable));
    hashTableCreate(table, tableSize);  

    // Allocate memory for an input array of size 1000 to be inserted in the hash table
    
    long  *adharNumber = (long  *)malloc(size * sizeof(long));
    // Allocate memory for an array of remaining values from the space of 10 million numbers which are not inserted in the hash table
    long *adharNumber_remaining = malloc(sizeof(long) * 1000);

    // Generate an input array of size 1000 and an array of remaining values
    int size = inputGenerator(adharNumber, adharNumber_remaining, 1000);
    writeToCSV("inserted keys", "keysInserted_1003.csv", input1, 1000);

    // Allocate memory for an array of 100 data points from the input array for searching in the hash table
    long *searchinput = malloc(sizeof(long) * 100);

    // Generate 100 data points from the input array for searching in the hash table
    subArray(adharNumber, searchinput, 1000, 100);
    writeToCSV("searched keys", "keysSearched_1003.csv", searchinput, 100);
    // Insert the input array in the hash table and get the probing value
    hashChainArrayInsert(table, adharNumber, size);

    // Allocate memory for an array of 100 data points from the remaining values for searching in the hash table
    long *searchinput_remaining = malloc(sizeof(long) * 100);

    // Generate 100 data points from the remaining values for searching in the hash table
    subArray(adharNumber_remaining, searchinput_remaining, size, 100);
    writeToCSV("remaining keys", "keysRemainingSearched_1003.csv", searchinput_remaining, 100);
    // Print the probing value after 100 insertions on a hash table of size 1000
   
   
   
   
   
   
   
   
   
   
   
   
   
   printf("The probing value after 100 insertions on a hash table of size 1000 is %d\n", prob1);
   writeToCSV("probing value", "probingValue_1003.csv", &prob1, 1);