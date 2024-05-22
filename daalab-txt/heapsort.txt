//heapsort
#include<stdio.h>
void max_heapify(int arr[],int index,int size)
{
  int largest=index;
  int left,right;
  left=2*index+1;
  right=2*index+2;
  if(left<size && arr[left]>arr[largest])
  {
     largest=left;
  }
  if(right<size && arr[right]>arr[largest])
  {
     largest=right;
  }
  if(largest!=index)
  {
    int temp=arr[index];
    arr[index]=arr[largest];
    arr[largest]=temp;
    max_heapify(arr,largest,size);
  }
}
void heapsort(int arr[],int size)
{
    int index,newsize;
    for(index=(size/2)-1;index>=0;index--)
    {
        max_heapify(arr,index,size);
    }
    for(newsize=size-1;newsize>0;newsize--)
    {
        int temp1=arr[0];
        arr[0]=arr[newsize];
        arr[newsize]=temp1;
        max_heapify(arr,0,newsize);
    }
}

int main()
{
   int size,i,arr[30];
   printf("Enter size of array:");
   scanf("%d",&size);
   printf("Enter valuesin array:");
   for(i=0;i<size;i++)
   {
      scanf("%d",&arr[i]);
   }
   printf("\nThe array before sorting is:");
   for(i=0;i<size;i++)
   {
      printf("%d ",arr[i]);
   }
   heapsort(arr,size);
   printf("\nThe array after sorting is:");
   for(i=0;i<size;i++)
   {
      printf("%d ",arr[i]);
   }
}
