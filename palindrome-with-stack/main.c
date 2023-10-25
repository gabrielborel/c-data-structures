#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Stack *s = init();
    char *str = malloc(sizeof(char) * 100);

    printf("type something and discover if its a palindrome or not: ");
    scanf("%s", str);
    int len = (int) strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        push(s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(s)) {
            printf("it is not a palindrome\n");
            free(s);
            free(str);
            return 0;
        }
    }

    printf("its is a palindrome\n");

    free(s);
    free(str);
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
