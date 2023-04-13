// How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int size;
    int max;
    int min;
    int minIndex;
} mStack;

mStack *mStackCreate(void)
{
    mStack* stack = (mStack*)malloc(sizeof(mStack));
    stack->array = NULL;
    stack->size = 0;
    stack->max = -1;
    stack->min = -1;
    stack->minIndex = -1;
    return stack;
}
int mStackPush(mStack* stack, int x)
{
    if (stack->max + 1 >= stack->size)
    {
        stack->size = stack->size == 0 ? 1 : stack->size * 2;
        stack->array = (int*)realloc(stack->array, stack->size * sizeof(int));
        if (stack->array == NULL)
        {
            free(stack->array);
            stack->size = 0;
            stack->max = -1;
            stack->min = -1;
            printf("Memory allocation error\n");
            return -1;
        }
    }
    stack->array[++stack->max] = x;
    if (stack->max == 0 || x < stack->min)
    {
        stack->min = x;
        stack->minIndex = stack->max;
    }
    return 0;
}
int mStackPop(mStack* stack)
{
    if (stack->max < 0)
        return -1;
    if (stack->max == stack->minIndex)
    {
        stack->min = stack->array[0];
        stack->minIndex = 0;
        for (int i=1; i<stack->max; i++)
        {
            if (stack->array[i] < stack->array[i-1])
            {
                stack->min = stack->array[i];
                stack->minIndex = i;
            }
        }
    }
    stack->max--;
    if ((stack->size > 1) && (stack->max < (stack->size/2)))
    {
        stack->size /= 2;
        stack->array = (int*)realloc(stack->array, stack->size * sizeof(int));
        if (stack->array == NULL)
        {
            free(stack->array);
            stack->size = 0;
            stack->max = -1;
            stack->min = -1;
            printf("Memory allocation error\n");
            return -1;
        }
    }
    return 0;
}
int mStackPrintMin(mStack* stack)
{
    if (stack->min < 0 || stack->array == NULL)
    {
        printf("Error. Minimum element is not found or stack is empty\n");
        return -1;
    }
    return stack->array[stack->minIndex];
}
void mStackFree(mStack* stack)
{
    free(stack->array);
    free(stack);
    stack->array = NULL;
    stack = NULL;
}
int main(void)
{
    mStack* stack = mStackCreate();
    mStackPush(stack, 10);
    mStackPush(stack, 7);
    mStackPush(stack, 5);
    mStackPush(stack, 3);
    mStackPop(stack);
    printf("Minimum element is %d\n", mStackPrintMin(stack));
    mStackFree(stack);
    return 0;
}
