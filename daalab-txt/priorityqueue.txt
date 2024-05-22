#include<stdio.h>
#include<stdlib.h>


int PQ[50];
int HeapSize = 0;


void MaxHeapify(int i);


int HeapMax() {
    if (HeapSize == 0) {
        printf("\nqueue is empty.\n");
        return -1;
    }
    return PQ[0];
}


int ExtractMax() {
    if (HeapSize == 0) {
        printf(" queue is empty.\n");
        return 0;
    }

    int max = PQ[0];
    PQ[0] = PQ[HeapSize - 1];
    HeapSize--;
    MaxHeapify(0);
    return max;
}


void IncreaseKey(int i, int key) {
    PQ[i] = key;
    while (i > 0 && PQ[i] > PQ[(i - 1) / 2]) {
        int temp = PQ[i];
        PQ[i] = PQ[(i - 1) / 2];
        PQ[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}


void Insert(int key) {
    HeapSize++;
    PQ[HeapSize - 1] = key;
    int i = HeapSize - 1;
    while (i > 0 && PQ[i] > PQ[(i - 1) / 2]) {
        int temp = PQ[i];
        PQ[i] = PQ[(i - 1) / 2];
        PQ[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}


void MaxHeapify(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;


    if (left < HeapSize && PQ[left] > PQ[largest]) {
        largest = left;
    }


    if (right < HeapSize && PQ[right] > PQ[largest]) {
        largest = right;
    }


    if (largest != i) {
        int temp = PQ[i];
        PQ[i] = PQ[largest];
        PQ[largest] = temp;
        MaxHeapify(largest);
    }
}


int main() {
    int ch, key, i;


    while (1) {
        printf("\n1. Heap Max");
        printf("\n2. Extract Max");
        printf("\n3. Increase Key");
        printf("\n4. Insert");
        printf("\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);


        switch (ch) {
            case 1:
                key = HeapMax();
                if (key != -1) {
                    printf("maximum element in the priority queue: %d\n", key);
                }
                break;
            case 2:
                key = ExtractMax();
                if (key != -1) {
                    printf("maximum element extracted from the priority queue: %d\n", key);
                }
                break;
            case 3:
                printf("enter the index of the element to increase the key: ");
                scanf("%d", &i);
                printf("enter the new key: ");
                scanf("%d", &key);
                IncreaseKey(i, key);
                break;
            case 4:
                printf("enter the key to insert: ");
                scanf("%d", &key);
                Insert(key);
                break;
            case 5:
                exit(0);
            default:
                printf("wrong choice.\n");
        }
    }


    return 0;
}



