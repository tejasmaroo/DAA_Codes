#include <stdio.h>

void minMax(int arr[], int low, int high, int minmax[]) {
    int mid, min1, min2, max1, max2;

    if (low == high) {
        minmax[0] = arr[low];
        minmax[1] = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax[0] = arr[high];
            minmax[1] = arr[low];
        } else {
            minmax[0] = arr[low];
            minmax[1] = arr[high];
        }
        return;
    }

    mid = (low + high) / 2;
    minMax(arr, low, mid, minmax);
    min1 = minmax[0];
    max1 = minmax[1];
    minMax(arr, mid + 1, high, minmax);
    min2 = minmax[0];
    max2 = minmax[1];

    minmax[0] = (min1 < min2) ? min1 : min2;
    minmax[1] = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minmax[2];

    minMax(arr, 0, n - 1, minmax);

    printf("Minimum element is %d\n", minmax[0]);
    printf("Maximum element is %d\n", minmax[1]);

    return 0;
}
