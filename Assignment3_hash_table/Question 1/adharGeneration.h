#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#define MAX 10000000LL
#define MIN 1LL
#define DIGITS 12

long long generateRandomNumber(long long min, long long max) {
    return (rand() % (max - min + 1)) + min;
}

bool isAdhaarNumber(long long num) {
    return num >= MIN * (long long)pow(10, DIGITS - 1) && num <= MAX * (long long)pow(10, DIGITS - 1) - 1;
}

void generateAdhaar(long long adhaarNumbers[], int count) {
    srand(time(NULL)); // seed the random number generator with current time

    for (int i = 0; i < count; i++) {
        long long adhaarNumber = generateRandomNumber(MIN * (long long)pow(10, DIGITS - 1), 9999999LL * (long long)pow(10, DIGITS - 6) + 999999LL);
        while (!isAdhaarNumber(adhaarNumber)) {
            adhaarNumber = generateRandomNumber(MIN * (long long)pow(10, DIGITS - 1), 9999999LL * (long long)pow(10, DIGITS - 6) + 999999LL);
        }
        adhaarNumbers[i] = adhaarNumber;
    }
}
