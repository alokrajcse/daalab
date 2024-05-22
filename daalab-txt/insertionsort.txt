#include <stdio.h>

int main() {
    int arr[100], size, pos, i, j, temp, index;

    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    if (size > 100) {
        printf("Size exceeds the maximum allowed size of 100.\n");
        return 1;
    }

    for (index = 0; index < size; index++) {
        printf("Enter value for element %d:\n", index + 1);
        scanf("%d", &arr[index]);
    }

    printf("Before sorting, elements of the array are:\n");
    for (index = 0; index < size; index++) {
        printf("%d\t", arr[index]);
    }
    printf("\n");

    for (i = 1; i < size; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }

    printf("After sorting, elements of the array are:\n");
    for (index = 0; index < size; index++) {
        printf("%d\t", arr[index]);
    }
    printf("\n");

    return 0;
}
