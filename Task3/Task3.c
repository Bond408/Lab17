#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void fill_array(int* arr, int size);
void print_array(int* arr, int size);
int* sort_shell(int* ptrarr, int n);
void copy_array(int* source, int* dest, int size);
int generate_shell_steps(int* steps, int size);
int generate_hibbard_steps(int* steps, int size);
int generate_ciura_steps(int* steps);
int generate_fibonacci_steps(int* steps, int size);

void main() {
    const int size = 100000;
    int* arr = (int*)malloc(size * sizeof(int));
    int* temp_arr = (int*)malloc(size * sizeof(int));
    int steps[100];
    int step_count;
    clock_t t;
    double time;

    fill_array(arr, size);

    printf("Сравнение производительности сортировки Шелла:\n");

    step_count = generate_shell_steps(steps, size);
    copy_array(arr, temp_arr, size);
    t = clock();
    sort_shell(temp_arr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Стандартная последовательность Шелла: %.6f секунд\n", time);

    step_count = generate_hibbard_steps(steps, size);
    copy_array(arr, temp_arr, size);
    t = clock();
    sort_shell(temp_arr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Последовательность Хиббарда: %.6f секунд\n", time);

    step_count = generate_ciura_steps(steps);
    copy_array(arr, temp_arr, size);
    t = clock();
    sort_shell(temp_arr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Последовательность Циура: %.6f секунд\n", time);

    step_count = generate_fibonacci_steps(steps, size);
    copy_array(arr, temp_arr, size);
    t = clock();
    sort_shell(temp_arr, size);
    time = (double)(clock() - t) / CLOCKS_PER_SEC;
    printf("Последовательность Фибоначчи: %.6f секунд\n", time);

    free(arr);
    free(temp_arr);


}

void fill_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copy_array(int* source, int* dest, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}


int* sort_shell(int* ptrarr, int n) {
    int j, temp;

    for (int h = n / 2; h > 0; h /= 2)
    {
        for (int k = 0; k < h; k++)
        {
            for (int i = 0; i < n / h; i++) {
                j = i;
                while ((j > 0) && ptrarr[j * h + k] < ptrarr[(j - 1) * h + k])
                {
                    temp = ptrarr[j * h + k];
                    ptrarr[j * h + k] = ptrarr[(j - 1) * h + k];
                    ptrarr[(j - 1) * h + k] = temp;
                    j = j - 1;
                }
            }
        }
    }
    return ptrarr;
}

int generate_shell_steps(int* steps, int size) {
    int count = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        steps[count++] = gap;
    }
    return count;
}

int generate_hibbard_steps(int* steps, int size) {
    int count = 0;
    int k = 1;
    while ((1 << k) - 1 < size) {
        steps[count++] = (1 << k) - 1; // 2^k - 1
        k++;
    }
    return count;
}

int generate_ciura_steps(int* steps) {
    int ciura[] = { 1, 4, 10, 23, 57, 132, 301, 701, 1750 };
    int count = sizeof(ciura) / sizeof(ciura[0]);
    for (int i = 0; i < count; i++) {
        steps[i] = ciura[i];
    }
    return count;
}

int generate_fibonacci_steps(int* steps, int size) {
    int count = 0;
    steps[0] = 1;
    steps[1] = 1;
    count = 2;
    while (steps[count - 1] + steps[count - 2] < size) {
        steps[count] = steps[count - 1] + steps[count - 2];
        count++;
    }
    return count;
}
