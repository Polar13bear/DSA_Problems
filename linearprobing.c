#include<stdlib.h>
#include<stdio.h>
int * t;
int SIZE;
void init(int *t)
{
    for (int i = 0; i < SIZE; i++)
    {
        t[i] = -1;
    }
}
void insert(int k)
{
    int i = k % SIZE;
    int count = 0;
    if (t[i] != -1 && t[i] != k && count < SIZE)
    {
        i = (i+1) % SIZE;
        count++;
    }
    if(count < SIZE)
    {
         t[i] = k;
    }
}
int search(int k)
{
    int i = k % SIZE;
    int count = 0;
    while(t[i] != -1 && t[i] != k && count < SIZE)
    {
        i = (i+1) % SIZE;
       count++;
    }
    if (count < SIZE)
    {
         return (t[i] == k);
    }
}
int main(int argc, char const *argv[])
{
    printf("Enter the hash table size : \n");
    scanf("%d", &SIZE);
    t = (int *)malloc(SIZE * sizeof(int));
    init(t);
    int n,x;
    printf("Enter the no. of elements to insert:\n");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    printf("Enter the element you want to be searched:\n");
    scanf("%d",&x);
    printf("Search %d: %s\n", x, search(x) ? "Found" : "Not Found");   
    free(t);
    return 0;
}
