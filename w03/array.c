#include <stdio.h>

#define MAX 5

void display(int* array)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");

    for(int i = 0; i < MAX; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
void init(int* array)
{
    for(int i = 0; i < MAX; i++)
    {
        array[i]=0;
    }
    
}

void insert(int* array, int pos, int num)
{
    int i;
    for(i = MAX-1; i >= pos; i--)
    {
        array[i] = array[i-1];
    }
    array[i] = num;
    
}

void update(int* array, int pos, int num){
    if(pos<MAX)
    {
        array[pos] = num;
    }
}

void delete(int *array, int pos)
{
    int i;
    for( i = pos; i < MAX; i++)
    {
        array[i-1] = array[i];
    }
    array[i] = 0;
    
}
void reverse(int * array)
{
    for(int i = 0; i < MAX/2; i++)
    {
        int temp = array[i];
        array[i]= array[MAX-1-i];
        array[MAX-1-i]=temp;
    }
    
}
void search(int *array, int val)
{
    int i;
    for( i = 0; i < MAX; i++)
    {
        if (array[i] == val) 
        {
            printf("%d found in pos %d\n", val, i+1);
            return;
        }
        
    }
    if(i == MAX)
        printf("%d not found\n", val);
}
int main(void)
{
    int array[MAX];
    init(array);
    insert(array,1,11);
    insert(array,2,12);
    insert(array,3,13);
    insert(array,4,14);
    insert(array,5,15);
    display(array);
    reverse(array);
    search(array, 11);
    search(array,666);
    display(array);
    return 0;
}