# main.c

- `keysInserted_1003.csv`: This file contains a list of 1000 unique random numbers that were generated and inserted into the hash table.

- `keysSearched_1003_(Q a).csv`: This file contains a list of 100 data points that were randomly selected from the input array for searching in the hash table.

- `keysRemainingSearched_1003_(Q d).csv`: This file contains a list of 100 data points that were randomly selected from the remaining values that were not inserted into the hash table for searching in the hash table.

- `keysSearched_1003_(Q c).csv`: This file contains a list of 100 data points that were randomly selected from the input array for searching in the hash table after deleting 100 data points from the input array.

- `probingValue_1003_(Q a).csv`: This file contains a single value which is the sum of all the probing values obtained during the 100 successful searches in the hash table.

- `probingValue_1003_(Q c).csv`: This file contains a single value which is the sum of all the probing values obtained during the 100 unsuccessful searches in the hash table.

# openAddress.h

## Functions

### `hashFunction(key, tableSize, i)`

This function takes a `key`, the `tableSize`, and an integer `i` as input and returns the index of the hash table where the key should be inserted. It uses the open addressing method to resolve collisions.

### `hashInsert(table, key, probes)`

This function takes a `table`, a `key`, and a pointer to an integer `probes` as input. It inserts the key into the hash table using the open addressing method. It also updates the value of the integer pointed to by the input pointer with the number of probes required to insert the key.

### `hashInsertArray(table, keys, size)`

This function takes a `table`, an array of `keys`, and the `size` of the array as input. It inserts all the keys in the array into the hash table using the `hashInsert` function. It returns the total number of probes required to insert all the keys.

### `hashSearch(table, key, probes)`

This function takes a `table`, a `key`, and a pointer to a pointer to a long integer `probes` as input. It searches for the key in the hash table using the open addressing method. It updates the value of the long integer pointed to by the input pointer with the number of probes required to search for the key. If the key is found, it returns the index of the hash table where the key is stored. Otherwise, it returns -1.

### `hashDelete(table, key)`

This function takes a `table` and a `key` as input. It searches for the key in the hash table using the `hashSearch` function. If the key is found, it marks the corresponding node as deleted by setting the `isDeleted` flag to 1.
