#include <stdio.h>

int main() {
    int arr[] = {2, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count[100] = {0}; // Assuming elements are < 100

    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Count elements that appear exactly once
    int uniqueCount = 0;
        // Count smallest unique element
    for (int i = 0; i < 100; i++) {
        if (count[i] == 1) {
            printf("Output: 1\n"); // Only the smallest unique
            return 0;
        }
    }


    printf("Output: %d\n", uniqueCount);

    return 0;
}
