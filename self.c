/*
 * Студент: Пылинский Даниил Максимович
 * Группа: ПИ 1-1
 * Лабораторная работа № 17
 * Назначение: Самостоятельная работа. Сортировка выбором по убыванию и проверка порядка функцией is_descending
 */

#include <stdio.h>

void sort_desc(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        int t = a[i];
        a[i] = a[max_index];
        a[max_index] = t;
    }
}

int is_descending(const int a[], int n) {
    if (n <= 1) return 1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void print_array(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main(void) {
    int a1[] = {4, -2, 7, 4, 0};
    sort_desc(a1, 5);
    print_array(a1, 5);
    printf("; проверка %d\n", is_descending(a1, 5));

    int a2[] = {5};
    sort_desc(a2, 1);
    print_array(a2, 1);
    printf("; проверка %d\n", is_descending(a2, 1));

    int a3[] = {3, 1, 2};
    printf("Проверка без сортировки 3 1 2 -> Проверка %d\n", is_descending(a3, 3));

    printf("Пустой массив n=0 -> Проверка %d\n", is_descending(a1, 0));

    return 0;
}
