//
// Created by qasx1 on 21.10.2023.
//
#include "hashTable.h"

int thirdTaskFunction()
{
    hashTable Table = hashTable();
    Table.insert(new rec("name1", "name1", 110));
    Table.insert(new rec("name2", "name2", 111));
    Table.insert(new rec("name3", "name3", 112));
    Table.insert(new rec("name4", "name4", 113));
    Table.insert(new rec("name5", "name5", 114));
    Table.insert(new rec("name6", "name6", 115));
    Table.show();
    Table.insert(new rec("name7", "name7", 116));
    Table.insert(new rec("name8", "name8", 117));
    Table.insert(new rec("name9", "name9", 118));
    Table.insert(new rec("name10", "name10", 2110));
    std::cout << std::endl;
    Table.show();
    Table.remove(110);
    std::cout << std::endl;
    Table.show();
    Table.find(110);
    return 0;
}