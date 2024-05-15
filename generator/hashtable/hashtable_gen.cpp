//
// Created by Filip Persson on 2024-05-07.
//
#include "hashtable_gen.h"

std::vector<node *> HashTable::hashtable(size_t reserved_size) {
    return {reserved_size * 4, nullptr};
}

void HashTable::insert(int data) {
    size_t index = data % table.size();
    node* new_node = new node{data, nullptr};
    if(table[index] == nullptr){
        table[index] = new_node;
    } else {
        node* current = table[index];
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new_node;
    }
}
