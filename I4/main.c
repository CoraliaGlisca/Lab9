#include <stdio.h>
#include <stdlib.h>

int *array;
int length;
int i;
int j;

void swap(int * a, int * b);

int main()
{
    printf("Enter the length: \n");
    scanf("%d" , &length);

    array = (int *) malloc(length * sizeof(int));

    printf("Enter the sequence: \n");

    for(i = 0 ; i < length ; i++)
        scanf("%d" , (array + i));

    for(i = 0 ; i <length ; i++)
    {
          for(j = i + 1 ; j< length ; j++)
          {
            if(*(array + i) > *(array + j))
                swap((array + i),(array + j));
          }
    }

    printf("The sequence sorted: \n");

    for(i = 0 ; i < length ; i++)
        printf("%d " , *(array + i));
}

void swap(int * a, int * b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
