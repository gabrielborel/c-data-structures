#include <stdio.h>

int main() {
    int numbers[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (int i = 0; i < 10; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    putchar('\n');

    int chars[4][4] = {
            {'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l'},
            {'m', 'n', 'o', 'p'}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c \n", chars[i][j]);
        }
    }
    putchar('\n');

    int selected_number;
    printf("Enter a number: ");
    scanf("%d", &selected_number);
    int found = 0;
    for (int i = 0; i < 10; i++) {
        if (numbers[i] == selected_number) {
            printf("Found %d at index %d\n", selected_number, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Could not find %d\n", selected_number);
    }
    putchar('\n');

    int three_numbers_matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    for (int i = 0; i < 3; i++) {
        int line_sum = 0;
        for (int j = 0; j < 3; j++) {
            line_sum += three_numbers_matrix[i][j];
        }
        printf("The sum of line %d is %d", i, line_sum);
        line_sum = 0;
        putchar('\n');
    }

    int five_number_matrix[5][5] = {
            {399,  22,  35, 46, 58},
            {6,   7,   8,  9,  10},
            {144, 124, 13, 14, 15},
            {165, 17,  18, 19, 20},
            {21,  -22, 23, 24, 25}
    };
    int highest_number = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (five_number_matrix[i][j] > highest_number) {
                highest_number = five_number_matrix[i][j];
            }
        }
    }
    printf("The highest number is %d", highest_number);
}
