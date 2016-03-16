//
//  main.cpp
//  Data Structures
//
//  Created by Salvador Guerrero on 3/15/16.
//  Copyright © 2016 ByteApps. All rights reserved.
//

#include <iostream>
#include "List.h"

void list_test()
{
    struct list *list = (struct list *)calloc(1, sizeof(struct list));
    list->item = 10;

    // insert

    list_insert(&list, 11);
    list_insert(&list, 12);
    list_insert(&list, 13);
    list_insert(&list, 14);
    list_insert(&list, 15);

    list_delete(&list, 13);

    // will print in inverse because insert happens in the head of the list.

    list_description(list);

    list_free(list);
}

int main(int argc, const char * argv[])
{
    list_test();

    return 0;
}
