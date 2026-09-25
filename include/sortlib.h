#pragma once

// Библиотека сортировок массива целых чисел.
// Автор: <ваше имя>
// Группа: <номер>

// Пузырьковая сортировка. Сложность O(n^2).
void bubbleSort(int* arr, int n);

// Сортировка вставками. Сложность O(n^2).
void insertionSort(int* arr, int n);

// Сортировка выбором. Сложность O(n^2).
void selectionSort(int* arr, int n);

// Быстрая сортировка. Средняя сложность O(n log n).
void quickSort(int* arr, int n);

// Сортировка слиянием. Сложность O(n log n).
void mergeSort(int* arr, int n);

// Пирамидальная сортировка. Сложность O(n log n).
void heapSort(int* arr, int n);