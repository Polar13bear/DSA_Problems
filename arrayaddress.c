#include <stdio.h>
int main() {
    int arr[] = {2, 2, 3, 4};
    // Printing address of the array
    printf("Address of array (arr): %p\n", arr);
    // Printing address of the first element
    printf("Address of first element (&arr[0]): %p\n", &arr[0]);
    return 0;
}
