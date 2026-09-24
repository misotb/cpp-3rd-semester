#include "sortlib.h"
#include <iostream>

// Печать массива в одну строку.
static void printArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

// Копирование массива-источника в приёмник.
static void copyArray(const int* src, int* dst, int n) {
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}

int main() {
    int n = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Размер должен быть положительным.\n";
        return 1;
    }

    int* original = new int[n];
    int* work     = new int[n];

    std::cout << "Введите " << n << " целых чисел через пробел:\n";
    for (int i = 0; i < n; ++i)
        std::cin >> original[i];

    std::cout << "\nИсходный массив:\n";
    printArray(original, n);
    std::cout << '\n';

    copyArray(original, work, n);
    bubbleSort(work, n);
    std::cout << "bubbleSort:    ";
    printArray(work, n);

    copyArray(original, work, n);
    insertionSort(work, n);
    std::cout << "insertionSort: ";
    printArray(work, n);

    copyArray(original, work, n);
    selectionSort(work, n);
    std::cout << "selectionSort: ";
    printArray(work, n);

    copyArray(original, work, n);
    quickSort(work, n);
    std::cout << "quickSort:     ";
    printArray(work, n);

    copyArray(original, work, n);
    mergeSort(work, n);
    std::cout << "mergeSort:     ";
    printArray(work, n);

    copyArray(original, work, n);
    heapSort(work, n);
    std::cout << "heapSort:      ";
    printArray(work, n);

    delete[] original;
    delete[] work;

    return 0;
}