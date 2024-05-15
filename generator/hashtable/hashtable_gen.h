//
// Created by Filip Persson on 2024-05-07.
//

#ifndef LABB3_HASHTABLE_GEN_H
#define LABB3_HASHTABLE_GEN_H

#include <vector>
#include <list>
#include <string>

struct node{
    int data;
    node* next;
};

class HashTable {
        std::vector <node*> table;
public:
    HashTable(size_t reserved_size){
       table = hashtable(reserved_size);
    };
    std::vector <node*> hashtable(size_t reserved_size);

    void insert(int data);

    const std::vector <node*>& getTable() const {
        return table;
    }


};


#endif //LABB3_HASHTABLE_GEN_H
