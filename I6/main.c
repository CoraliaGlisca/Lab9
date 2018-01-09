#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b);
void quickSort(char* str, int first , int last);

int main()
{
    char str[100];
    int n;

    printf("Enter the string: \n");
    gets(str);

    n = strlen(str);

    quickSort(str, 0, n - 1);

    printf("\n%s\n", str);

}

void swap(char* a, char* b)
{
    char aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
void quickSort(char *str ,int first, int last)
{
    int i;
    int j;
    int arrow;

    i = first;
    j = last;
    arrow = i / 2  + j / 2;


    while (i <= j)
    {
        while( str[i] < str[arrow] )
            i++;
        while( str[j] > str[arrow] )
            j--;

        if (i <= j)
        {
            swap((str + i), (str + j));
            i++;
            j--;
        }
    }
    if(first < j)
        quickSort(str, first, j);

    if(i < last)
        quickSort(str, i, last);
}
