#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem
{
    int data;
    int key;
};

void display(struct DataItem **hashArray)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashArray[i] != NULL)
        {
            printf(" (k:%d,v:%d)", hashArray[i]->key,hashArray[i]->data);
        }else
        {
            printf(" ~,~");
        }
        
    }
    printf("\n");
}

int hashCode(int key)
{
    return key % SIZE;
}

void insert(struct DataItem **hashArray, int key, int data)
{
    struct DataItem *item = malloc(sizeof(*item));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
    printf("%d\n", hashArray[hashIndex]);
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}






int main()
{
    struct DataItem** hArray= malloc(SIZE * sizeof **hArray);
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", hArray[i]);
    
    //struct DataItem *tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    //tempItem->data = -1;
    //tempItem->key = -1;
    
    //display(hArray);
   insert(hArray,1,20);
    //insert(hArray,2,30);
    //insert(hArray,42,79);
   // insert(hArray,4,25);
   display(hArray);
    return 0;
}