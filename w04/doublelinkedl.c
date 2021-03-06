#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void append(struct node **list, int num)
{
    struct node *temp, *current = *list;
    if(*list == NULL)
    {
        *list = (struct node *) malloc(sizeof(struct node));
        (*list)->prev = NULL;
        (*list)->data = num;
        (*list)->next = NULL;
    }else
    {
        while(current->next != NULL)
            current = current->next;
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = num;
        temp->prev = current;
        temp->next = NULL;
        current->next =temp;
    }
    
}
//adds at start instead of end(shocking)
void prepend(struct node **list, int num)
{
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->prev = NULL;
    temp ->data = num;
    temp->next = *list;
    
    (*list)->prev = temp;
    *list = temp;
}

void insert_after(struct node *list, int location, int num)
{
    struct node *temp, *r;
    int i;
    temp = list;
    for( i = 0; i < location; i++)
    {
        temp = temp->link;
        if(temp == NULL)
        {
            printf("Length of list is %d but location gived is %d, which is too far dummy.\n",i,location);
            return;
        }
    }
    r = (struct node *) malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;
}

void delete(struct node **list, int num)
{
    struct node *old,*temp;
    temp = *list;

    while(temp != NULL)
    {
        if (temp->data == num) 
        {
            if (temp == *list) 
            {
                *list = temp->link;
            }else
            {
                old->link=temp->link;
            }
            free(temp);
            return;
        }else
        {
            old = temp;
            temp = temp->link;
        }
    }
    printf("Element %d not found in the list, but I suppose that's ok since you didn't want it there to begin with\n", num);
}

int count(struct node *list)
{
    int count =0;
    while(list != NULL)
    {
        list=list->next;
        count++;
    }
    return count;
}

void display(struct node *list)
{
    while(list != NULL)
    {
        printf("%d ", list->data);
        list = list ->next;
    }
    printf("\n");
}
int main()
{
    struct node *list;
    list = NULL;
    printf("elements: %d\n", count(list));

    append(&list, 14);
    append(&list, 30);
    append(&list, 69);
    append(&list, 420);
    append(&list, 666);
    printf("elements: %d\n", count(list));
    display(list);

    prepend(&list, 321);
    prepend(&list, 221);
    prepend(&list, 121);
    printf("elements: %d\n", count(list));
    display(list);

    insert_after(list,1,0);
    insert_after(list,2,1);
    insert_after(list,5,65);
    printf("elements: %d\n", count(list));
    display(list);

    insert_after(list,99,10);
    printf("elements: %d\n", count(list));
    display(list);

    delete(&list, 99);
    delete(&list, 14);
    printf("elements: %d\n", count(list));
    display(list);

    return 0;
}