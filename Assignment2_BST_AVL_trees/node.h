#include "stdio.h"
#include "stdlib.h"

struct node{
    int key;
   struct node *left;
   struct node *right;
   struct node *parent;
};

typedef struct node node;

