#include <time.h>
#include <stdio.h>
typedef struct
{
    int id;
    char name[30];
} employee;


void timing(){
    for(int i = 0; i < 10000; i++)
    {
        printf(".");
    }
    printf("\n");
}
int main()
{
    int a[100];
    employee e1 ={1, "Roxanne"};
    printf("%d\n %s\n",e1.id,e1.name);
    size_t num = sizeof(a)/sizeof(int);
    printf("%zu elems\n", num);

    clock_t t;
    printf("start: %d\n", (int)(t=clock()));
    timing();

    printf (" stop : %d \n", (int) (t = clock() -t));
    printf (" Elapsed : %f seconds \n", (double) t/CLOCKS_PER_SEC );
    return 0;
}