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
            if (arr[i] > arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++start;
    } while (swapped);
}

int partition(std::vector<ZagsRecord>& arr, int low, int high) {
    ZagsRecord pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[++i], arr[high]);
    return i;
}

void quick_sort(std::vector<ZagsRecord>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
