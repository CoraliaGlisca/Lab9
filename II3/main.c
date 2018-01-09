#include <stdio.h>
#include <stdlib.h>

int *array;
int length;
int i;

void swap(int *a, int *b);
void quickSort(int *array , int first , int last);

int main()
{
    printf("Enter the length: ");
    scanf("%d" , &length);

    array = (int *) malloc(length * sizeof( int ));

    printf("\nEnter the numbers: ");
    for(i=0 ; i<length; i++)
        scanf("%d", array + i);

    quickSort(array , 0 , length - 1);

    printf("\n");
    for(i = 0 ; i < length ; i++)
        printf("%d " , *(array + i));
}

void swap(int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

void quickSort(int *array , int first , int last)
{
    int i;
    int j;
    int arrow;

    i = first;
    j = last;
    arrow = array[(first + last) / 2];

    while(i <= j)
    {
        while(array[i] < arrow)
            i++;

        while(array[j] > arrow)
            j--;

        if(i <= j)
        {
            swap((array + i) , (array + j));
            i++;
            j--;
        }
    }

    if(first < j)
        quickSort(array , first , j);
    if(i < last)
        quickSort(array , i , last);
}
