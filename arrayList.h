#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <math.h>

    // The initial for an array in a newly created array list.
    #define INIT_CAPACITY 16

    /*
        Array List Structures and Functions Documentation:

        struct ArrayList:
            Description:
                Stores the needed variables for an array list.

            unsigned int length:
                The amount of items in the list.
                This variable should not typically
                be altered by the user and instead
                only accessed.
            
            unsigned int capacity:
                The current size of the array.
                This variable should not typically
                be altered by the user and instead
                only accessed.
            
            type* arr:
                The array that will be used to store the items.
                Do not resize manualy.
        
        void newAL_##name:
            Description:
                Creates and returns a new array list structure.
            
            Returns:
                ArrayList_##name:
                    A newly created list structure.
        
        void trimAL_##name:
            Trims the array down to the array's length and
            removes all the empty/unitialized items.

            ArrayList_##name list:
                The list that will be trimmed.
        
        int isRestoredAL_##name:
            Description:
                Checks if the array is restored or not,
                by checking if the capacity is equal to
                some power of 2.

            ArrayList_##name list:
                The list that will checked.
            
            Returns:
                int:
                    1 if the list is restored and 0 if not.

        void restoreAL_##name:
            Description:
                Restore the array up to the next number that is
                equal to some power of 2 after the list's current length and
                adds all the needed empty/unitialized items.

            ArrayList_##name list:
                The list that will be trimmed.

        void _resizeAL_##name:
            !WARNING!:
                This function is not meant to be used by users of this macro,
                so caution is advised.

            Description:
                Checks if the array list should be resized or not.
                If so, then resize it and set it's new capacity to be double it's original value.
                It also resizes the array to some power of 2 that is above 16 if it is not that.

            ArrayList_##name list:
                The list that will be resized.
        
        void _downsizeAL_##name:
            !WARNING!:
                This function is not meant to be used by users of this macro,
                so caution is advised.

            Description:
                Checks if the array list should be downsized or not.
                If so, then it downsizes it and set it's new capacity to be double it's original value.
                It also resizes the array to some power of 2 that is above 16 if it is not that.
            
            ArrayList_##name list:
                The list that will be downsized.
        
        void addItemAL_##name:
            Description:
                Adds in the item to the list and resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            type item:
                The item that will be added to the list.
        
        void addItemsAL_##name:
            Description:
                Adds in all the inputted items to the array and resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            ...:
                The items that will be added into the list.
        
        void addItemArrAL_##name:
            Description:
                Adds in the array of items to the list's array and resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            type* items:
                The array of items that will be added into the list.
        
        void addItemAtAL_##name:
            Description:
                Adds in the item to the list at a specific index. It also resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            unsigned int index:
                The index/position to add the item into.

            type item:
                The item that will be added to the list.
        
        void addItemsAtAL_##name:
            Description:
                Adds in all the inputted items to the array starting at the specified index/position. It also resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            unsigned int index:
                The index/position to start adding all the items into.

            unsigned int count:
                The count/number of items being added into the list.

            ...:
                The items that will be added into the list.
        
        void addItemArrAtAL_##name:
            Description:
                Adds in an array of items to the list's array starting at the specified index/position. It also resizes the list if it needs to.

            ArrayList_##name list:
                The list that the item will be added to.
            
            unsigned int index:
                The index/position to start adding all the items into.

            unsigned int count:
                The count/number of items being added into the list.

            type* items:
                The array of items that will be added into the list.
        
        removeItemAL_##name:
            Description:
                Removes an item at the end of the list. It also downsizes the array if it needs to.

            ArrayList_##name list:
                The list that the item will be removed from.
        
        removeItemsAL_##name:
            Description:
                Removes a specified count/amount of items at the end of the list. It also downsizes the array if it needs to.

            ArrayList_##name list:
                The list that the item will be removed from.
            
            unsigned int count:
                The count/amount of items to remove at the end of the list.

        removeItemAtAL_##name:
            Description:
                Removes an item at the specified index/position in the list. It also downsizes the array if it needs to.

            ArrayList_##name list:
                The list that the item will be removed from.
            
            unsigned int index:
                The index/position of the item that will be removed.
        
        removeItemsAtAL_##name:
            Description:
                Removes a specified count/amount of items after the specified index/position of the list.
                It also downsizes the array if it needs to.

            ArrayList_##name list:
                The list that the item will be removed from.
            
            unsigned int index:
                The index/position of the first item that will be removed.
            
            unsigned int count:
                The count/amount of items to remove starting at the index/position.
        
        freeAL_##name:
            Description:
                Frees the list's array alongside the pointer to the list itself.
                This does not free up the possible pointers contained within the list.
                That action is done by the users.
    */

    /*
        This defines all the prototypes for the functions and structures with the correct types for the array list.
        This should be used within header files.

        name:
            The name that will be inserted for every time ##name appears.
            An example of this would be addItemAL_##name turning into addItem_int,
            if name was inputted as int. This is seperate from type,
            as if type names like int* are used to insert for ##name,
            errors will occur. Instead, something like intP can be used.
            The same goes for types like unsigned int that have spaces in the name.
            So use something uInt for the name.

        type:
            The type of the variable that will be stored in the arraylist.
    */
    #define DEF_HEADER_ARRAY_LIST_TYPE_FULL(name, type) \
        typedef struct arrList_##name ArrayList_##name; \
        \
        ArrayList_##name* newAL_##name(); \
        void trimAL_##name(ArrayList_##name* list); \
        int isRestoredAL_##name(ArrayList_##name* list); \
        void restoreAL_##name(ArrayList_##name* list); \
        void _resizeAL_##name(ArrayList_##name* list); \
        void _downsizeAL_##name(ArrayList_##name* list); \
        void addItemAL_##name(ArrayList_##name* list, type item); \
        void addItemsAL_##name(ArrayList_##name* list, unsigned int count, ...); \
        void addItemArrAL_##name(ArrayList_##name* list, unsigned int count, type* items); \
        void addItemAtAL_##name(ArrayList_##name* list, unsigned int index, type item); \
        void addItemsAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count, ...); \
        void addItemArrAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count, type* items); \
        void removeItemAL_##name(ArrayList_##name* list); \
        void removeItemsAL_##name(ArrayList_##name* list, unsigned int); \
        void removeItemAtAL_##name(ArrayList_##name* list, unsigned int index); \
        void removeItemsAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count); \
        void freeAL_##name(ArrayList_##name* list);
    
    /*
        This does the same thing as DEF_HEADER_ARRAY_LIST_TYPE_FULL,
        but instead does not require the name of the type to be inputted.
        Instead, the name of the type is used as the name for the structure and functions.
    */
    #define DEF_HEADER_ARRAY_LIST_TYPE(type) DEF_HEADER_ARRAY_LIST_TYPE_FULL(type, type);

    /*
        This defines all the contents of the functions and structures with the correct types for the array list.
        This should be used within c files.

        name:
            The name that will be inserted for every time ##name appears.
            An example of this would be addItemAL_##name turning into addItem_int,
            if name was inputted as int. This is seperate from type,
            as if type names like int* are used to insert for ##name,
            errors will occur. Instead, something like intP can be used.
            The same goes for types like unsigned int that have spaces in the name.
            So use something uInt for the name.

        type:
            The type of the variable that will be stored in the arraylist.
    */
    #define DEF_ARRAY_LIST_TYPE_FULL(name, type) \
        typedef struct arrList_##name ArrayList_##name; \
        \
        struct arrList_##name \
        { \
            unsigned int length; \
            unsigned int capacity; \
            type* arr; \
        }; \
        \
        ArrayList_##name* newAL_##name() \
        { \
            ArrayList_##name* list = (ArrayList_##name*)malloc(sizeof(ArrayList_##name)); \
            list->length = 0; \
            list->capacity = INIT_CAPACITY; \
            list->arr = (type*)malloc(list->capacity * sizeof(type)); \
            return list; \
        } \
        \
        void trimAL_##name(ArrayList_##name* list) \
        { \
            list->capacity = list->length; \
            list->arr = (type*)realloc(list->arr, list->capacity * sizeof(type)); \
        } \
        \
        int isRestoredAL_##name(ArrayList_##name* list) \
        { \
            if (list->capacity >= INIT_CAPACITY) \
            { \
                /* \
                    Gets the next number to the power of 2 after the list's capacity. \
                    If the list's capacity is equal to this number. Then the array is restored or \
                    has a capacity that is to the power of two. \
                */ \
                double exponent = log2((double)list->capacity); \
                int ceilExp = (int)ceil(exponent); \
                int capacityResult = (int)pow(2.0, exponent); \
                int correctResult = (int)pow(2.0, (int)ceilExp); \
                \
                if (capacityResult == correctResult) \
                    return 1; \
            } \
            \
            return 0; \
        } \
        \
        void restoreAL_##name(ArrayList_##name* list) \
        { \
            if (list->capacity < INIT_CAPACITY) \
                list->capacity = INIT_CAPACITY; \
            else \
            { \
                int exponent = (int)ceil(log2((double)list->length)); \
                list->capacity = (int)pow(2.0, (double)exponent); \
            } \
            \
            list->arr = (type*)realloc(list->arr, list->capacity * sizeof(type)); \
        } \
        \
        void _resizeAL_##name(ArrayList_##name* list) \
        { \
            if (list->length > list->capacity) \
                restoreAL_##name(list); \
        } \
        \
        void _downsizeAL_##name(ArrayList_##name* list) \
        { \
            /* \
                Get a number that is to the power two and less than the list's capacity. \
                If the list's length is below this, then resize the array appropiatley \
            */ \
            int exponent = (int)ceil(log2((double)list->length)); \
            int lowerCapacity = (int)pow(2.0, (double)exponent); \
            \
            if (list->capacity > INIT_CAPACITY && list->length <= lowerCapacity) \
                restoreAL_##name(list); \
        } \
        \
        void addItemAL_##name(ArrayList_##name* list, type item) \
        { \
            list->length++; \
            _resizeAL_##name(list); \
            list->arr[list->length - 1] = item; \
        } \
        \
        void addItemsAL_##name(ArrayList_##name* list, unsigned int count, ...) \
        { \
            int prevLength = list->length; \
            list->length += count; \
            _resizeAL_##name(list); \
            \
            va_list args; \
            va_start(args, count); \
            \
            /* Add all the items to the end of the array */ \
            for (unsigned int i = prevLength; i < list->length; i++)\
                list->arr[i] = va_arg(args, type); \
            \
            va_end(args); \
        } \
        \
        void addItemArrAL_##name(ArrayList_##name* list, unsigned int count, type* items) \
        { \
            int prevLength = list->length; \
            list->length += count; \
            _resizeAL_##name(list); \
            \
            /* Add all the items to the end of the array */ \
            for (unsigned int i = prevLength; i < list->length; i++)\
                list->arr[i] = items[i - prevLength]; \
        } \
        \
        void addItemAtAL_##name(ArrayList_##name* list, unsigned int index, type item) \
        { \
            list->length++; \
            _resizeAL_##name(list); \
            \
            /* Shifts all the elements forward by 1. This is to make room for the item to add. */ \
            for (unsigned int i = list->length - 1; i > index; i--) \
                list->arr[i] = list->arr[i - 1]; \
            \
            list->arr[index] = item; \
        } \
        \
        void addItemsAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count, ...) \
        { \
            /* Resize the array if necessary */ \
            list->length += count; \
            _resizeAL_##name(list); \
            \
            /* Shift all the items in front of the inset index to make room for the items to add. */ \
            for (unsigned int i = list->length - 1; i >= index + count; i--) \
                list->arr[i] = list->arr[i - count]; \
            \
            va_list args; \
            va_start(args, count); \
            \
            /* Add in all the needed items starting at the index */ \
            for (unsigned int i = index; i < index + count; i++) \
                list->arr[i] = va_arg(args, type); \
            \
            va_end(args); \
        } \
        \
        void addItemArrAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count, type* items) \
        { \
            /* Resize the array if necessary */ \
            list->length += count; \
            _resizeAL_##name(list); \
            \
            /* Shift all the items in front of the inset index to make room for the items to add. */ \
            for (unsigned int i = list->length - 1; i >= index + count; i--) \
                list->arr[i] = list->arr[i - count]; \
            \
            /* Add in all the needed items starting at the index */ \
            for (unsigned int i = index; i < index + count; i++) \
                list->arr[i] = items[i - index]; \
        } \
        \
        void removeItemAL_##name(ArrayList_##name* list) \
        { \
            list->length--; \
            _downsizeAL_##name(list); \
        } \
        \
        void removeItemsAL_##name(ArrayList_##name* list, unsigned int removeCount) \
        { \
            list->length -= removeCount; \
            _downsizeAL_##name(list); \
        } \
        \
        void removeItemAtAL_##name(ArrayList_##name* list, unsigned int index) \
        { \
            /* Shift all the elements at and after the index/position back by 1*/ \
            for (unsigned int i = index; i < list->length - 1; i++) \
                list->arr[i] = list->arr[i + 1]; \
            \
            /* Decrement the list's length. Effectively removing the last element. */ \
            list->length--; \
            _downsizeAL_##name(list); \
        } \
        \
        void removeItemsAtAL_##name(ArrayList_##name* list, unsigned int index, unsigned int count) \
        { \
            /* Shift items after the index/position by the count value. */ \
            for (unsigned int i = index; i < list->length - 1; i++) \
                list->arr[i] = list->arr[i + count]; \
            \
            /* Decrease the list's length by the count value. */ \
            list->length -= count; \
            _downsizeAL_##name(list); \
        } \
        \
        void freeAL_##name(ArrayList_##name* list) \
        { \
            free(list->arr); \
            free(list); \
        }
    
    /*
        This does the same thing as DEF_ARRAY_LIST_TYPE_FULL,
        but instead does not require the name of the type to be inputted.
        Instead, the name of the type is used as the name for the structure and functions.
    */
    #define DEF_ARRAY_LIST_TYPE(type) DEF_ARRAY_LIST_TYPE_FULL(type, type)
#endif