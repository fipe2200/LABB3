//
// Created by Filip Persson on 2024-05-07.
//

#include "binary_search.h"

bool binary_search(std::vector<int>::iterator first,std::vector<int>::iterator last, int target){
    while (first <= last) {
        auto mid = first + (last - first) / 2;
        if (*mid == target) {
            return true;
        }
        if (*mid < target) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    return false;
}
