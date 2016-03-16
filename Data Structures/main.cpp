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
    printf("\nlist test:\n");

    list_insert(list, 11);
    list_insert(list, 12);
    list_insert(list, 13);
    list_insert(list, 14);
    list_insert(list, 15);

    list_delete(list, 13);

    // will print in inverse because insert happens in the head of the list.

    list_description(*list);
}

int main(int argc, const char * argv[])
{
    struct list *list = (struct list *)calloc(1, sizeof(struct list));
    list->item = 10;

    list_test(&list);
    stack_test(&list);
    queue_test(&list);

    list_free(list);

    return 0;
}
