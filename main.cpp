#include <iostream>
#include "sort.h"

void print(int32_t *a, int32_t n) {
    for (int32_t i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
}

int main() {
    int sort_number = 10, elements_to_copy = 4100;
    void (*func[10])(int32_t *, int64_t) = {selectionSort, bubbleSort, bubbleSortFirstAverson, bubbleSortFullAverson,
                                            insertionSort, binaryInsertionSort, countSort, mergeSort, hoarQuickSort,
                                            lomutoQiuckSort};
    int32_t a[4100];
    for (int i = 0; i < 4100; i++) {
        a[i] = 0 + rand() % 5;
    }
    int32_t *b;
    for (int sort_ind = 0; sort_ind < sort_number; ++sort_ind) {
        std::copy(a,
                  a + 0 + elements_to_copy,
                  b);
        print(b, 4100);
        func[sort_ind](b, elements_to_copy);
        print(b, 4100);
        std::cout << std::endl;
        delete[] b;
    }
    return 0;
}
