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
    //printf("%d\n", hashArray[hashIndex]);
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

struct DataItem* search(struct DataItem **hashArray, int key)
{
    int hashIndex = hashCode(key);
    while(hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key) 
        {
            return hashArray[hashIndex];
        }
        hashIndex++;
        hashIndex %= SIZE;
        
    }
    return NULL;
}
struct DataItem* delete(struct DataItem **hashArray, struct DataItem* item)
{
    int key = item->key;
    int hashIndex = hashCode(key);

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->key == key)
        {
            struct DataItem *temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}



int main()
{
    struct DataItem** hArray= calloc(SIZE, sizeof **hArray);
    struct DataItem *tempItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    tempItem->data = -1;
    tempItem->key = -1;
    
    display(hArray);
    insert(hArray,1,20);
    insert(hArray,2,30);
    insert(hArray,42,79);
    insert(hArray,4,25);
    insert(hArray,0,25);
    display(hArray);
    tempItem = search(hArray,42);
    if(tempItem != NULL)
    {
        printf("elem found: %d\n", tempItem->data);
    }else
    {
        printf("nope");
    }
    tempItem = delete(hArray, tempItem);
    display(hArray);
    
    return 0;
}