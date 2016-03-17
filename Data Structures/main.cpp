//
//  main.cpp
//  Data Structures
//
//  Created by Salvador Guerrero on 3/15/16.
//  Copyright © 2016 ByteApps. All rights reserved.
//

#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"

void queue_test(Queue **queue)
{
    printf("\nstack test:\n");

    Queue *dequeued_node = dequeue(*queue);
    printf("dequeued_node 1: %d\n", dequeued_node->item);
    list_free(dequeued_node);

    dequeued_node = dequeue(*queue);
    printf("dequeued_node 2: %d\n", dequeued_node->item);
    list_free(dequeued_node);

    enqueue(queue, 21);
    enqueue(queue, 22);
    enqueue(queue, 23);
    enqueue(queue, 24);
    enqueue(queue, 25);

    dequeued_node = dequeue(*queue);
    printf("dequeued_node 3: %d\n", dequeued_node->item);
    list_free(dequeued_node);

    list_description(*queue);
}

void stack_test(Stack **stack)
{
    printf("\nstack test:\n");

    stack_push(stack, 16);
    stack_push(stack, 17);
    stack_push(stack, 18);
    stack_push(stack, 19);
    stack_push(stack, 20);

    Stack *poppped_node = stack_pop(stack);
    printf("poppped_node: %d\n", poppped_node->item);
    list_free(poppped_node);

    list_description(*stack);
}

void list_test(struct list **list)
{
    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert(list, 14);
    list_insert(list, 15);

    list_delete(list, 13);

    // will print in inverse because insert happens in the head of the list.

    list_description(*list);
}

void list_tests()
{
    printf("\nLists tests:\n");

    struct list *list = (struct list *)calloc(1, sizeof(struct list));
    list->item = 10;

    list_test(&list);
    stack_test(&list);
    queue_test(&list);

    list_free(list);
}

void tree_tests()
{
    printf("\nTrees tests:\n");

    struct Tree *tree = NULL;

    tree_insert(&tree, 2);
    tree_insert(&tree, 1);
    tree_insert(&tree, 7);
    tree_insert(&tree, 4);
    tree_insert(&tree, 8);
    tree_insert(&tree, 3);
    tree_insert(&tree, 6);
    tree_insert(&tree, 5);
    tree_traverse(tree);

    printf("delete 3:\n");
    tree_delete(&tree, 3);
    tree_traverse(tree);

    printf("delete 6:\n");
    tree_delete(&tree, 6);
    tree_traverse(tree);

    printf("delete 4:\n");
    tree_delete(&tree, 4);
    tree_traverse(tree);

    printf("insert 9:\n");
    tree_insert(&tree, 9);
    tree_traverse(tree);

    tree_free(tree);
}

int main(int argc, const char * argv[])
{
    list_tests();

    tree_tests();

    return 0;
}
