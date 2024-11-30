#include <stdio.h>

#define SIZE 10

// Function to find the maximum value in the array
int find_max(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

// Function to find the minimum value in the array
int find_min(int *arr, int size) {
    int min = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }
    return min;
}

// Function to reverse the array
void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// Function to print the array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    printf("Original Array: ");
    print_array(arr, SIZE);

    // Find and print the maximum and minimum values
    int max_value = find_max(arr, SIZE);
    int min_value = find_min(arr, SIZE);
    printf("Maximum Value: %d\n", max_value);
    printf("Minimum Value: %d\n", min_value);

    // Reverse the array and print it
    reverse_array(arr, SIZE);
    printf("Reversed Array: ");
    print_array(arr, SIZE);

    return 0;
}

