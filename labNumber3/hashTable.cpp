//
// Created by qasx1 on 21.10.2023.
//

#include "hashTable.h"

rec::rec(const std::string &nameOfOwner, const std::string &nameOfCompany, int number) {
    strcpy(this->nameOfOwner, nameOfOwner.c_str());
    strcpy(this->nameOfCompany, nameOfCompany.c_str());
    this->number = number;
}

hashTable::hashTable() = default;

int hashTable::hash(rec record) const { return (record.number % sizeOfTable); }

void hashTable::rehash()
{
    std::vector<rec*> vec = std::vector<rec*>(sizeOfTable*2);
    for(int i = 0; i < sizeOfTable; i++)
    {
        if(arr.at(i) == nullptr)
            continue;
        else
        {
            rec* pointer = arr.at(i);
            while(pointer != nullptr)
            {
                int index = pointer->number % (sizeOfTable*2);
                if (vec.at(index) == nullptr)
                    vec.at(index) = pointer;
                else {
                    rec* nPointer = pointer;
                    while (nPointer->nextRecord != nullptr)
                        nPointer = nPointer->nextRecord;
                    nPointer->nextRecord = pointer;
                }
                pointer = pointer->nextRecord;
            }
        }
    }
    arr = vec;
    sizeOfTable *= 2;
}

void hashTable::insert(rec *newRecord) {
    int index = hash(*newRecord);
    if (arr.at(index) == nullptr)
        this->arr.at(index) = newRecord;
    else {
        rec *pointer = arr.at(index);
        while (pointer->nextRecord != nullptr)
            pointer = pointer->nextRecord;
        pointer->nextRecord = newRecord;
    }
    countOfElements++;
    if ((double) countOfElements / ((double) sizeOfTable - 1) > 0.75) {
        rehash();
    }

}

void hashTable::show() {
    for (int i = 0; i < sizeOfTable; i++) {
        if (arr.at(i) != nullptr) {
            rec *pointer = arr.at(i);
            std::cout << pointer->nameOfCompany << " -> " << i;
            pointer = pointer->nextRecord;
            while (pointer != nullptr) {
                std::cout << " || " << pointer->nameOfCompany << " -> " << i << " || ";
                pointer = pointer->nextRecord;
            }
            std::cout << std::endl;
        } else
            std::cout << "----------------------------" << std::endl;
    }
}

void hashTable::find(int number) {
    int index = number % sizeOfTable;
    int collisionIndex = -1;
    int count = 0;
    rec *current = arr.at(index);
    while (current != nullptr) {
        if (current->number == number) {
            collisionIndex = count;
            break;
        } else {
            count++;
            current = current->nextRecord;
        }
    }
    if (collisionIndex == -1)
    {
        std::cout << "Element not in table" << std::endl;
    }
    else {
        std::cout << "Element found in table with index: " << index << " and collisionIndex: " << collisionIndex
                  << std::endl;
    }
}

int hashTable::findForRemove(int number)
{
    int index = number % sizeOfTable;
    int collisionIndex = -1;
    int count = 0;
    rec *current = arr.at(index);
    while (current != nullptr) {
        if (current->number == number) {
            collisionIndex = count;
            break;
        } else {
            count++;
            current = current->nextRecord;
        }
    }
    if (collisionIndex == -1)
    {
        return 0;
    }
    else {
        return 1;
    }
}

void hashTable::remove(int number)
{
    if(!findForRemove(number))
        std::cout << "Nothing to delete" << std::endl;
    else
    {
        int index = number % sizeOfTable;
        rec *current = arr.at(index);
        if (current->number == number)
        {
            arr.at(index) = current->nextRecord;
            delete current;
        }
        else
        {
            rec* nextCur = current->nextRecord;
            while (nextCur->number != number) {
                current = current->nextRecord;
                nextCur = nextCur->nextRecord;
            }
            current->nextRecord = nextCur->nextRecord;
            delete nextCur;
        }
    }
    countOfElements--;
}