// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2)))
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
// [+, 101, -, 545, *, 234, /, 29] - итоговый стек для редьюсера, -1 элемент всегда число, -2 всегда оператор, и т.д.
// [{+, 101}, {-, 545}, {*, 234}] - еще один вариант итогового стека
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char operators[4] = {'-', '+', '*', '/'};

typedef struct Expr
{
    char operator;
    int value;
} Expr;

void main()
{
    char input[1000];
    printf('write ur expression');
    gets(input);
    GetExpression(input);
}

// Принимает оператор и члены алгебраического выражения
int Calculate(int first_member, int second_member, char operator)
{
    switch (operator)
    {
    case '+':
        return first_member + second_member;
    case '-':
        return first_member - second_member;
    case '/':
        return first_member / second_member;
    case '*':
        return first_member * second_member;
    }
}

// Метод, преобразующий входную строку с выражением в стек с операторами и значениями
void GetExpression(char *input)
{
    int i;
    Expr operations[100];
    int top_of_stack = 0;

    int inputLength = sizeof(input) / sizeof(char);

    for (i = 0; i < inputLength; i++)
    {
        if (input[i] == '(')
        {
            i++;
            char tmp = input[i];
            char *tmp_string;
            int k = 0;
            while (tmp != '(' || tmp != ')')
            {
                push_tmp(tmp, tmp_string, k);
                k++;
                i++;
                tmp = input[i];
            }
            Expr object;
            sscanf(tmp_string, "%s %d", &object.operator, & object.value);
            push_operations(object, operations, top_of_stack);
            top_of_stack++;
        }
    }
    printf(operations);
}

// достать верхний элемент стека
int pop(int index, char *stack)
{
    int data;
    data = stack[index];
    return data;
}

// добавить элемент в стек
void push_operations(Expr data, Expr *stack, int index)
{
    stack[index] = data;
}

void push_tmp(char *data, char *stack, int index)
{
    stack[index] = data;
}

// Редьюсер нашего стека алгебраических операций
double Counting(char *input) {}
