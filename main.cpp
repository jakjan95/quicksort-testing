#include <iostream>
#include <vector>
#include "quicksort.hpp"

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    //{7, 4, 3, 9, 1, 3, 12, 19, 2, 25, 17}
    //std::vector<int> vec{6, 1, 3, 7, 5, 2, 4, 9};
    std::vector<int> vec{7, 4, 3, 9, 1, 3, 12, 19, 2, 25, 17, 99, 5};
    std::vector<int> vec2{2, 8, 7, 1, 3, 5, 6, 4};
    printVector(vec);
    quickSort(vec, 0, vec.size() - 1);
    printVector(vec);
    printVector(vec2);
    quickSort(vec2);
    printVector(vec2);

    return 0;
}
