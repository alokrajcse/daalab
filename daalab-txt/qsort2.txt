#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;

    printf("Enter number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    int originalArr[n]; // Array to store original unsorted elements

    for(i=0; i<n; i++)
    {
        arr[i]=rand()%1000;
        originalArr[i] = arr[i]; // Copy elements to the original array
    }

    printf("Original array:\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Time taken to sort the original array
    start = clock();
    quickSort(arr, 0, n-1);
    end = clock();
    double cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sorted array: \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Time required for sorting original array: %f seconds\n", cpu_time_used);

    // Time taken to sort the sorted array
    start = clock();
    quickSort(originalArr, 0, n-1);
    end = clock();
    cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time required for sorting already sorted array: %f seconds\n", cpu_time_used);

    return 0;
}

