#include <stdio.h>
#include <stdlib.h>

void merge(int left ,int middle ,int rigth);
void mergeSort(int left, int rigth);

int arr[100];
int length;
int i;

int main()
{
    printf("Enter the length: ");
    scanf("%d", &length);

    printf("\nEnter the sequence: ");

    for(i=0 ; i<length ;i++)
        scanf("%d" , &arr[i]);

    mergeSort(0, length - 1);

    printf("\n");

    for(i = 0 ; i < length ; i++)
        printf("%d " , arr[i]);

}

void merge(int left, int middle, int rigth)
{
    int i;
    int j;
    int terms = left;
    int arrowLeft = middle - left + 1;
    int arrowRigth = rigth - middle;

    int l[arrowLeft];
    int r[arrowRigth];

    for(i=0 ; i<arrowLeft ;i++)
        l[i]=arr[left + i];

    for(j=0; j<arrowRigth; j++)
        r[j] = arr[middle + 1 + j];

    i = j = 0;

    for(i=0 && j==0; i < arrowLeft && j < arrowRigth ; terms++)
    {
        if(l[i] <= r[j])
        {
            arr[terms]=l[i];
            i++;
        }
        else
        {
            arr[terms]=r[j];
            j++;
        }
    }

    while(i<arrowLeft)
    {
        arr[terms]=l[i];
        i++;
        terms++;
    }
    while(j < arrowRigth)
    {
        arr[terms]=r[j];
        j++;
        terms++;
    }
}

void mergeSort(int left, int rigth)
{
    int middle;

    if(left < rigth)
    {
        middle = (left + rigth) / 2;

        mergeSort(left, middle);
        mergeSort(middle + 1, rigth);

        merge(left, middle, rigth);
   }
}
