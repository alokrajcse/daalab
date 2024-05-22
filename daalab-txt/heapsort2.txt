#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(int arr[], int n, int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;

	if(l<n&& arr[l]>arr[largest])
		largest=l;
	if(r<n&&arr[r]>arr[largest])
	largest=r;
	if(largest!=i)
	{
		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);
	}
}
void heapSort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n, i);
	for(int i=n-1;i>0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr, i, 0);
	}
}
void  main()
{
	int n, i;
	clock_t start, end;
	printf("enter no. of elements:\n");
	scanf("%d",&n);
	int arr[n];
	int originalArr[n];

	for(i=0;i<n;i++)
	{
		arr[i]=rand()%1000;
		originalArr[i]=arr[i];

	}
	printf("\n original array: \n");
		for(i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}

		printf("\n");
	start=clock();
	heapSort(arr,n);
	end=clock();
	double cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time required for sorting original array: %f \n",cpu_time_used);

	start=clock();
	heapSort(originalArr,n);
	end=clock();


    printf("\nSorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	 cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time for sorting sorted array: %f \n",cpu_time_used);

	


}
