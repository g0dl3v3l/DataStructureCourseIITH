#include "stdio.h"
#include "stdlib.h"

struct nodeAVL{
    int key;
   struct nodeAVL *left;
   struct nodeAVL *right;
   struct nodeAVL *parent;
};

typedef struct nodeAVL nodeAVL;

