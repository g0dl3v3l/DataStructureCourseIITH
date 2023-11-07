# main.c

## files discription

- `probingValue_2003_(Q d).csv`: This file contains a single value representing the probing value after 100 unsuccessful searches on a hash table of size 2003.

- `keysInserted_2003.csv`: This file contains a list of 1000 keys that were inserted into a hash table of size 2003.

- `keysSearched_2003_(Q a).csv`: This file contains a list of 100 keys that were searched for in a hash table of size 2003.

- `keysRemainingSearched_2003_(Q d).csv`: This file contains a list of 100 keys that were not inserted into a hash table of size 2003 and were searched for unsuccessfully.

- `keysSearched_2003_(Q c).csv`: This file contains a list of 100 keys that were searched for in a hash table of size 2003 after 100 successful searches and deletions.

- `probingValue_2003_(Q a).csv`: This file contains a single value representing the probing value after 100 searches on a hash table of size 2003.

- `probingValue_2003_(Q c).csv`: This file contains a single value representing the probing value after 100 searches on a hash table of size 2003 following 100 successful searches and deletions.

- `probingValue_2003_(Q d).csv`: This file contains a single value representing the probing value after 100 unsuccessful searches on a hash table of size 2003.

Each CSV file likely contains a header row indicating the type of data contained in the file, followed by the relevant data.

# adharGeneration.h

1. `generateRandomNumber(long long min, long long max)`: This function takes two arguments, `min` and `max`, both of type `long long`. It generates a random number between `min` and `max` (inclusive) using the `rand()` function from the `stdlib.h` library. It then returns the generated random number.

2. `isAdhaarNumber(long long num)`: This function takes a single argument, `num`, of type `long long`. It checks whether the given number is a valid Aadhaar number or not. A valid Aadhaar number is a 12-digit number that lies between `MIN * (long long)pow(10, DIGITS - 1)` and `MAX * (long long)pow(10, DIGITS - 1) - 1`, where `MIN` and `MAX` are defined as preprocessor macros and `DIGITS` is a constant. The function returns `true` if the given number is a valid Aadhaar number, and `false` otherwise.

3. `generateAdhaar(long long adhaarNumbers[], int count)`: This function takes two arguments, `adhaarNumbers` and `count`. `adhaarNumbers` is an array of `long long` integers, and `count` is an integer that specifies the number of Aadhaar numbers to be generated. The function generates `count` random Aadhaar numbers using the `generateRandomNumber()` function and checks whether each generated number is a valid Aadhaar number using the `isAdhaarNumber()` function. If a generated number is not a valid Aadhaar number, the function generates a new random number until a valid Aadhaar number is generated. The generated Aadhaar numbers are stored in the `adhaarNumbers` array.This program defines three functions:

4. `generateRandomNumber(long long min, long long max)`: This function takes two arguments, `min` and `max`, both of type `long long`. It generates a random number between `min` and `max` (inclusive) using the `rand()` function from the `stdlib.h` library. It then returns the generated random number.

5. `isAdhaarNumber(long long num)`: This function takes a single argument, `num`, of type `long long`. It checks whether the given number is a valid Aadhaar number or not. A valid Aadhaar number is a 12-digit number that lies between `MIN * (long long)pow(10, DIGITS - 1)` and `MAX * (long long)pow(10, DIGITS - 1) - 1`, where `MIN` and `MAX` are defined as preprocessor macros and `DIGITS` is a constant. The function returns `true` if the given number is a valid Aadhaar number, and `false` otherwise.

6. `generateAdhaar(long long adhaarNumbers[], int count)`: This function takes two arguments, `adhaarNumbers` and `count`. `adhaarNumbers` is an array of `long long` integers, and `count` is an integer that specifies the number of Aadhaar numbers to be generated. The function generates `count` random Aadhaar numbers using the `generateRandomNumber()` function and checks whether each generated number is a valid Aadhaar number using the `isAdhaarNumber()` function. If a generated number is not a valid Aadhaar number, the function generates a new random number until a valid Aadhaar number is generated. The generated Aadhaar numbers are stored in the `adhaarNumbers` array.
