#include <stdio.h>
#include <stdlib.h>

typedef struct stack_element {
    char value;
    struct stack_element *next;
} Stack_Element;

typedef struct stack {
    Stack_Element *top;
    int size;
} Stack;

Stack* init();
void push(Stack *p, char value);
char top(Stack *p);
int empty(Stack *p);
int size(Stack *p);
char pop(Stack *p);

int main() {
    Stack *st = init();
    printf("size of stack %d\n", size(st));
    push(st, 10);
    printf("size of stack %d\n", size(st));
    push(st, 15);
    printf("size of stack %d\n", size(st));
    push(st, 20);
    printf("size of stack %d\n", size(st));
    printf("the value on the top is %d\n", top(st));
    printf("the element on the top is %d\n", pop(st));
    printf("the size of the stack %d\n", size(st));
    printf("the element on the top is %d\n", pop(st));
    printf("the size of the stack %d\n", size(st));
    return 0;
}

Stack* init() {
    Stack *st = malloc(sizeof(Stack));
    st->top = NULL;
    st->size = 0;
    return st;
}

void push(Stack *p, char value) {
    Stack_Element *ste = malloc(sizeof(Stack_Element));
    ste->value = value;
    ste->next = p->top;
    p->top = ste;
    p->size += 1;
}

char top(Stack *p) {
    if (empty(p)) {
        return '\0';
    }
    return p->top->value;
}

int empty(Stack *p) {
    return p->size == 0;
}

int size(Stack *p) {
    return p->size;
}

char pop(Stack *p) {
    Stack_Element *element;
    char value;

    if (!empty(p)) {
        element = p->top;
        value = element->value;

        p->top = p->top->next;
        p->size -= 1;

        free(element);
        element = NULL;
        return value;
    } else {
        return '\0';
    }
}
