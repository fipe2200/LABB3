//
// Created by Filip Persson on 2024-05-07.
//

#include "hash_table_search.h"

bool hash_table_search(HashTable& hash_table, int target){
    size_t index = target % hash_table.getTable().size();
    node* current = hash_table.getTable()[index];
    while(current != nullptr){
        if(current->data == target) return true;
        current = current->next;
    }
    return false;
}
