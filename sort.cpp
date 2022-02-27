//
// Created by ksmil on 2/27/2022.
//

#include <cstdint>
#include <algorithm>
#include "sort.h"


template<class T>
void selectionSort(T *a, int64_t n) {
    for (int i = 0; i < n - 1; ++i) {
        int64_t min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(a[i], a[min]);
        }
    }
}

template<class T>
void bubbleSort(T *a, int64_t n) {
    int64_t t = n;
    // Первое условие Айверсона:
    for (int64_t i = 0; i < n - 2 && t > 0; ++i) {
        int64_t j = 0;
        t = 0;
        for (; j <= t; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                t = n;
            }
        }

    }
}

template<class T>
void bubbleSortFirstAverson(T *a, int64_t n) {
    int64_t t = n;
    // Первое условие Айверсона:
    for (int64_t i = 0; i < n - 2 && t > 0; ++i) {
        int64_t j = 0;
        t = 0;
        for (; j <= t; ++j) {
            if (a[j] > a[j + 1]) {
                t = n;
                std::swap(a[j], a[j + 1]);
            }
        }

    }
}

template<class T>
void bubbleSortFullAverson(T *a, int64_t n) {
    int64_t t = n;
    // Первое условие Айверсона:
    for (int64_t i = 0; i < n - 2 && t > 0; ++i) {
        int64_t j = 0;
        t = 0;
        // Второе условие Айверсона:
        for (; j < n - i - 1 && j <= t; ++j) {
            if (a[j] > a[j + 1]) {
                t = n;
                std::swap(a[j], a[j + 1]);
            }
        }

    }
}

template<class T>
void insertionSort(T *a, int64_t n) {
    for (int index = 1; index < n; ++index) {
        int64_t key = a[index];
        int64_t j = index - 1;
        while (j > -1 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        if (j != index - 1) {
            a[j + 1] = key;
        }
    }
}

template<class T>
void binaryInsertionSort(T *a, int64_t n) {
    for (int index = 1; index < n; ++index) {
        int64_t key = a[index];
        // Вот бинарный поиск:
        int64_t left = -1, right = index;
        while (left < right - 1) {
            int64_t middle = (right - left) / 2 + left;
            if (a[middle] <= key) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if (right != index) {
            for (int i = index; i > right; --i) {
                a[i] = a[i - 1];
            }
            a[right] = key;
        }
    }
}

template<class T>
void countSort(T *a, int64_t n) {
    T *b = new T[n];
    int64_t min = INT64_MAX, max = INT64_MIN;
    for (int i = 0; i < n; ++i) {
        min = min > a[i] ? a[i] : min;
        max = max < a[i] ? a[i] : max;
    }
    T *c = new T[max - min + 1];
    for (int i = 0; i < n; ++i) {
        ++c[a[i] - min];
    }
    for (int64_t i = 1; i < max - min + 1; ++i) {
        c[i] += c[i - 1];
    }
    for (int64_t i = n - 1; i >= 0; --i) {
        --c[a[i] - min];
        b[c[a[i] - min]] = a[i];
    }
    delete[]a;
    a = b;
    delete[] c;
}

template<class Item>
Item *merge(Item *a1, Item *a2, int32_t ind1, int32_t ind2) {
    Item *ret = new Item[ind1 + ind2];
    int32_t n = 0;
    while (ind1 && ind2) {
        if (*a1 < *a2) {
            ret[n] = *a1;
            a1++;
            --ind1;
        } else {
            ret[n] = *a2;
            ++a2;
            --ind2;
        }
        ++n;
    }
    if (ind1 == 0) {
        for (int32_t i = 0; i < ind2; ++i) {
            ret[n++] = *a2++;
        }
    } else {
        for (int32_t i = 0; i < ind1; ++i) {
            ret[n++] = *a1++;
        }
    }
    return ret;
}

template<class T>
void mergeSort(T *a, int64_t n) {
    T *sorted;
    int32_t left, border;
    for (int32_t index = 1; index < n; index *= 2) {
        left = 0;
        while (index < n) {
            if (left + index >= n) {
                break;
            }
            border = left + index * 2 > n ? n - left - index : index;
            sorted = merge(a + left, a + left + index, index, border);
            for (int32_t i = 0; i < index + border; ++i) {
                a[left + i] = sorted[i];
            }
            delete[] sorted;
            left += index * 2;
        }
    }
}

template<class T>
void hoarSortHelp(T *a, int low, int high) {
    int32_t i = low, j = high;
    double tmp, middle = a[(low + high) / 2];
    do {
        while (a[i] < middle) {
            ++i;
        }
        while (a[j] > middle) {
            --j;
        }
        if (i <= j) {
            if (i < j) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            ++i;
            --j;
        }
    } while (i <= j);

    if (i < high) {
        hoarSortHelp(a, i, high);
    }
    if (low < j) {
        hoarSortHelp(a, low, j);
    }
}

template<class T>
void hoarQuickSort(T *a, int64_t n) {
    hoarSortHelp(a, 0, n - 1);
}

int32_t partition(int32_t *a, int32_t low, int32_t high) {
    int32_t pivot = a[high];
    int32_t i = low - 1;
    for (int32_t j = low; j <= high - 1; ++j) {
        if (a[j] <= pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return (i + 1);
}

template<class T>
void lomutoSortHelp(T *a, int32_t low, int32_t high) {
    if (low < high) {
        int32_t p = partition(a, low, high);
        lomutoSortHelp(a, low, p - 1);
        lomutoSortHelp(a, p + 1, high);
    }
}

template<class T>
void lomutoQiuckSort(T *a, int64_t n) {
    lomutoSortHelp(a, 0, n - 1);
}

//// TODO:
//template<class T>
//void radixSort(T *a, int n) {
//    T *b;
//    T exp = 1, max = 0;
//    for (int64_t i = 0; i < n; ++i) {
//        if (a[i] > max) {
//            max = a[i];
//        }
//    }
//
//    b = new T[n * sizeof(int)];
//    while (max / exp > 0) {
//        T box[256] = {0};
//        for (int64_t i = 0; i < n; ++i) {
//            box[a[i] / exp % 256]++;
//        }
//        for (int64_t i = 1; i < 256; ++i) {
//            box[i] += box[i - 1];
//        }
//        for (int64_t i = n - 1; i >= 0; --i) {
//            b[--box[a[i] / exp % 256]] = a[i];
//        }
//        for (int64_t i = 0; i < n; ++i) {
//            a[i] = b[i];
//        }
//        exp *= 256;
//    }
//    delete[] b;
//}
