#pragma once
#include <iostream>
#include <vector>

template <typename T>
int partition(std::vector<T>& vec, int left, int right) {
    auto temporaryPivot = vec[right];
    auto leftElementIndex = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (vec[j] <= temporaryPivot) {
            leftElementIndex++;
            std::swap(vec[leftElementIndex], vec[j]);
        }
    }
    std::swap(vec[leftElementIndex + 1], vec[right]);

    return leftElementIndex + 1;
}
template <typename T>
void quickSort(std::vector<T>& vec, int left, int right) {
    if (left < right) {
        auto pivot = partition(vec, left, right);
        quickSort(vec, left, pivot - 1);
        quickSort(vec, pivot + 1, right);
    }
}

template <typename T>
void quickSort(std::vector<T>& vec) {
    quickSort(vec, 0, vec.size() - 1);
}
