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
    Expr *ops = GetOperations(input);
    GetLastNumber(input);
}

// Метод, преобразующий входную строку с выражением в стек с операторами и значениями
int GetOperations(char *input)
{   
    Expr operations[100];
    int top_of_stack = 0;
    int inputLength = strlen(input);
    int i;
    for (i=0; i<inputLength; i++){

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            Expr object;
            sscanf(input+i, "%s %d", &object.operator, &object.value);
            push_operations(object, operations, top_of_stack);
            top_of_stack++;
        }
    }
    return operations;

}

// Получить последнее число стека, которое положим в дефолтное значение для редьюсера
int GetLastNumber(char *input){
    int i, j, k, bracket_index, number;
    int inputLength = strlen(input);
    for (i=0; i<inputLength; i++){

        if (input[i] == '('){
            bracket_index = i;
        }
        
        if (input[i] == ')'){
            sscanf(input+bracket_index+1, "%s %d %d", &j, &k, &number);
            return number;
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