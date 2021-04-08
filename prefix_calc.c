// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2)))
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
// [+, 101, -, 545, *, 234, /, 29] - итоговый стек для редьюсера, -1 элемент всегда число, -2 всегда оператор, и т.д.
// [{+, 101}, {-, 545}, {*, 234}] - еще один вариант итогового стека
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Expr
{
    char operator;
    int value;
} Expr;

int main()
{
    char *input = "(- 10 (/ 8 (* 2 (+ 2 2)))";
    // printf("write ur expression");
    GetExpression(input);
}

// Метод, преобразующий входную строку с выражением в стек с операторами и значениями
void GetExpression(char *input)
{   
    Expr operations[100];
    int top_of_stack = 0;
    int inputLength = strlen(input);
    int i;
    for (i=0; i<inputLength; i++){

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            Expr object;
            sscanf(input+i, "%s %d", &object.operator, &object.value);
            printf("operator: %s\nvalue: %d\n---------\n", &object.operator, &object.value);
        }
    }

}

// добавить элемент в стек
void push_operations(Expr data, Expr *stack, int index)
{
    stack[index] = data;
}

void push_tmp(int data, char *stack, int index)
{
    stack[index] = data;
}