#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define SIZE 10

void fill_array(int* arr, int size);
void print_array(int* arr, int size);
void bubble_sort(int* ptr_array, int count);
void shaker_sort(int* ptr_array, int count);
void selection_sort(int* ptr_array, int count);
void insertion_sort(int* ptr_array, int count);

int main() {
    setlocale(LC_ALL, "RUS");
    int ptr_array[SIZE];

    fill_array(ptr_array, SIZE);
    print_array(ptr_array, SIZE);

    bubble_sort(ptr_array, SIZE);

    printf("Сортировка пузырьком:\n");
    print_array(ptr_array, SIZE);

    shaker_sort(ptr_array, SIZE);

    printf("Шейкерная сортировка:\n");
    print_array(ptr_array, SIZE);

    selection_sort(ptr_array, SIZE);

    printf("Сортировка выбором:\n");
    print_array(ptr_array, SIZE);

    insertion_sort(ptr_array, SIZE);

    printf("Сортирвока вставками:\n");
    print_array(ptr_array, SIZE);

}
void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int* ptr_array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;

            if (ptr_array[j] > ptr_array[j + 1]) {
                swap = 1;
            }

            if (swap == 1) {
                int temp = ptr_array[j];
                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = temp;
            }
        }
    }
}

void shaker_sort(int* ptr_array, int count) {
    int left = 0;
    int right = count - 1;
    int x, i;

    while (left < right) {
        for (i = left; i < right; i++) {
            if (ptr_array[i] > ptr_array[i + 1]) {
                x = ptr_array[i];
                ptr_array[i] = ptr_array[i + 1];
                ptr_array[i + 1] = x;
            }
        }
        right--;

        for (i = right; i > left; i--) {
            if (ptr_array[i - 1] > ptr_array[i]) {
                x = ptr_array[i - 1];
                ptr_array[i - 1] = ptr_array[i];
                ptr_array[i] = x;
            }
        }
        left++;
    }
}

void selection_sort(int* ptr_array, int count) {
    int i, j, max_idx, temp;

    for (i = 0; i < count - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < count; j++) {
            if (ptr_array[j] > ptr_array[max_idx]) {
                max_idx = j;
            }
        }
        temp = ptr_array[i];
        ptr_array[i] = ptr_array[max_idx];
        ptr_array[max_idx] = temp;
    }
}

void insertion_sort(int* ptr_array, int count) {
    int i, j, temp;

    for (i = 1; i < count; i++) {
        temp = ptr_array[i]; 
        j = i - 1;

        while (j >= 0 && ptr_array[j] > temp) {
            ptr_array[j + 1] = ptr_array[j];
            j--;
        }
        ptr_array[j + 1] = temp;
    }
}