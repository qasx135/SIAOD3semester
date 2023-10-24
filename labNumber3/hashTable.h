//
// Created by qasx1 on 21.10.2023.
//

#ifndef SIAODCILION_HASHTABLE_H
#define SIAODCILION_HASHTABLE_H
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
struct rec
{
    char nameOfOwner[16] = {};
    char nameOfCompany[16] = {};
    int number = -1;
    rec* nextRecord = nullptr;

    rec(const std::string& nameOfOwner,
        const std::string& nameOfCompany,
        int number);

};

struct hashTable
{

    //  ---|| Variables ||--- //
    int sizeOfTable = 10;
    int countOfElements = 0;
    std::vector<rec*> arr = std::vector<rec*>(10, nullptr);

    //  ---|| Methods ||--- //
    hashTable();
    void insert(rec* newRecord);
    void find(int number);
    int findForRemove(int number);
    void show();
    void rehash();
    int hash(rec record) const;
    void remove(int number);
};
#endif //SIAODCILION_HASHTABLE_H
