#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void fill_array(int* arr, int size);
void print_array(int* arr, int size);
void insertion_sort(int* ptr_array, int count);


int main() {
    setlocale(LC_ALL, "RUS");
    int *ptr_array;
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    ptr_array = (int*)malloc(size * sizeof(int));

    fill_array(ptr_array, size);
    printf("Изначальный массив:\n");
    print_array(ptr_array, size);

    clock_t t = clock();
    insertion_sort(ptr_array, size);
    t = clock() - t;
    double time = (double)t / CLOCKS_PER_SEC;

    printf("Сортирвока вставками:\n");
    print_array(ptr_array, size);
    printf("Время: %.18f секунд\n", time);

    free(ptr_array);

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