#include <stdio.h>
#include <stdlib.h> // Include this for abs function

#define MAX 100

int x[MAX]; // Global array to store the positions of queens

int Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0;
        }
    }
    return 1;
}

void NQueens(int k, int n) { 
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    NQueens(1, n);
    return 0;
}
