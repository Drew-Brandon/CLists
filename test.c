#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

DEF_ARRAY_LIST_TYPE(int);

int main(void)
{
    ArrayList_int* list = newAL_int();

    for (int i = 0; i < 96; i++)
        addItemAL_int(list, i);

    trimAL_int(list);
    printf("Is Restored: %d\n", isRestoredAL_int(list));
    printf("Current Capacity: %u\n", list->capacity);
    printf("Current Length: %u\n", list->length);

    for (int i = 96; i < 129; i++)
        addItemAL_int(list, i);
    
    printf("Is Restored: %d\n", isRestoredAL_int(list));
    printf("Current Capacity: %u\n", list->capacity);
    printf("Current Length: %u\n", list->length);

    removeItemAL_int(list);
    removeItemsAL_int(list, 40);
    removeItemAtAL_int(list, 2);
    removeItemsAtAL_int(list, 20, 9);

    addItemAL_int(list, -40);
    addItemsAL_int(list, 3, 21, 23, 40);

    int ARR0[3] = {2, 1, 0};
    addItemArrAL_int(list, 3, ARR0);

    addItemAtAL_int(list, 0, 7);
    addItemsAtAL_int(list, 3, 3, 2, 10, 3);

    int ARR1[3] = {34, 8, 93};
    addItemArrAtAL_int(list, 10, 3, ARR1);

    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->arr[i]);
    }

    printf("\n");
    printf("Current Capacity: %u\n", list->capacity);
    printf("Current Length: %u\n", list->length);
    freeAL_int(list);

    return 0;
}