#include "sortlib.h"

// Обмен двух элементов местами.
static void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// Пузырьковая сортировка.
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Сортировка вставками.
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Сортировка выбором.
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}

// Вспомогательная функция для быстрой сортировки.
static int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

static void quickSortRec(int* arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortRec(arr, low, p - 1);
        quickSortRec(arr, p + 1, high);
    }
}

// Быстрая сортировка.
void quickSort(int* arr, int n) {
    quickSortRec(arr, 0, n - 1);
}

// Вспомогательная функция для сортировки слиянием.
static void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

static void mergeSortRec(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid);
        mergeSortRec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Сортировка слиянием.
void mergeSort(int* arr, int n) {
    mergeSortRec(arr, 0, n - 1);
}

// Вспомогательная функция для пирамидальной сортировки.
static void heapify(int* arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка.
void heapSort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}