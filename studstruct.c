#include <stdio.h>
#include <string.h>
#define SIZE 5
struct student {
    char name[30];
    int roll_no;
    float total_marks;
};
void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}
void display(struct student s[], int n) {
    printf("\nName\tRoll No\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll_no, s[i].total_marks);
    }
}
// Insertion Sort
int insertionSort(struct student s[], int n) {
    int swaps = 0;
    for (int i = 1; i < n; i++) {
        struct student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].roll_no > key.roll_no) {
            s[j + 1] = s[j];
            swaps++;
            j--;
        }
        s[j + 1] = key;
    }
    return swaps;
}
// Bubble Sort
int bubbleSort(struct student s[], int n) {
    int swaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll_no > s[j+1].roll_no) {
                swap(&s[j], &s[j+1]);
                swaps++;
            }
        }
    }
    return swaps;
}
// Merge Sort helper
int merge(struct student s[], int l, int m, int r) {
    int swaps = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct student L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = s[l + i];
    for (int j = 0; j < n2; j++) R[j] = s[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].roll_no <= R[j].roll_no) {
            s[k++] = L[i++];
        } else {
            s[k++] = R[j++];
            swaps++;
        }
    }
    while (i < n1) s[k++] = L[i++];
    while (j < n2) s[k++] = R[j++];
    
    return swaps;
}
int mergeSort(struct student s[], int l, int r) {
    int swaps = 0;
    if (l < r) {
        int m = (l + r) / 2;
        swaps += mergeSort(s, l, m);
        swaps += mergeSort(s, m + 1, r);
        swaps += merge(s, l, m, r);
    }
    return swaps;
}
int main() {
    struct student students[SIZE] = {
        {"Alice", 104, 78.5},
        {"Bob", 102, 85.0},
        {"Charlie", 105, 67.5},
        {"David", 101, 90.0},
        {"Eve", 103, 82.0}
    };
    struct student s_copy[SIZE];
    int choice, swaps;
    do {
        printf("\nMenu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Merge Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        memcpy(s_copy, students, sizeof(students));  // Reset array for each sort
        switch (choice) {
            case 1:
                swaps = insertionSort(s_copy, SIZE);
                printf("\nSorted using Insertion Sort:\n");
                display(s_copy, SIZE);
                printf("Number of swaps: %d\n", swaps);
                break;
            case 2:
                swaps = bubbleSort(s_copy, SIZE);
                printf("\nSorted using Bubble Sort:\n");
                display(s_copy, SIZE);
                printf("Number of swaps: %d\n", swaps);
                break;
            case 3:
                swaps = mergeSort(s_copy, 0, SIZE - 1);
                printf("\nSorted using Merge Sort:\n");
                display(s_copy, SIZE);
                printf("Number of data moves (merge steps): %d\n", swaps);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }

    } while (choice != 4);
    return 0;
}
