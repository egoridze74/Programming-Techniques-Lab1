#include "sorts.h"


void selection_sort(std::vector<ZagsRecord>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

void shaker_sort(std::vector<ZagsRecord>& arr) {
    bool swapped;
    size_t start = 0, end = arr.size() - 1;
    do {
        swapped = false;
        for (size_t i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        --end;
        for (size_t i = end; i > start; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++start;
    } while (swapped);
}

void quick_sort(std::vector<ZagsRecord>& arr, int low, int high) {
    if (low >= high) return;
    
    int i = low, j = high;
    ZagsRecord pivot = arr[low + (high - low) / 2];
    
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    if (low < j) quick_sort(arr, low, j);
    if (i < high) quick_sort(arr, i, high);
}
