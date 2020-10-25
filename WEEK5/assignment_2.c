#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 2

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = STACK_CAPACITY;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// deallocates the dynamic memory to prevent memory leak
void deallocStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);

}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void resize(struct Stack* stack)
{
    stack->capacity *= 2;
    stack->array = (int*)realloc(stack->array,stack->capacity * sizeof(int));

}

void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        resize(stack);
    stack->array[++stack->top] = item;

}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

bool checkBalanced(char str[]){
    
    struct Stack* stack = createStack();
    
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '[' || str[i] == '{' || str[i] == '('){
            push(stack, str[i]);
        }
        else if(str[i] == ']'){
            if(peek(stack) != '[') return false;
            else pop(stack);
        }
        else if(str[i] == '}'){
            if(peek(stack) != '{') return false;
            else pop(stack);
        }
        else if(str[i] == ')'){
            if(peek(stack) != '(') return false;
            else pop(stack);
        }
        else return false;
    }
    
    if(!isEmpty(stack)) return false;
    
    return true;
}
int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        if(checkBalanced(argv[1])) printf("Yes\n");
        else printf("No\n");
    }
    
    else if(argc > 2) printf("Too many arguments supplied\n");

    else printf("One argument expected\n");

    return 0;
}
