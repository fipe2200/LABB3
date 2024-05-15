//
// Created by Filip Persson on 2024-05-07.
//

#include "sequential_search.h"

bool sequential_search(std::vector<int> &arr, int target){
    for (int i = 0; i < arr.size(); ++i) {
        if (i == target) {
            return true;
        }
    }
    return false;
}

/*
bool sequential_search(std::vector<int> &arr, int target){
    return std::any_of(arr.begin(), arr.end(), [target](int i){
        return i == target;
    });
}
 */
