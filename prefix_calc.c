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

    int inputLength = strlen(input);
    char tmp_string[100];
    int tmp_index = 0;
    Expr object;
    int k;
    int previous_bracket_index;
    for (i = 0; i < inputLength; i++)
    {
        if (input[i] == '(' || input[i] == ')'){
            if (i > 0) {
               for (k = previous_bracket_index+1; k < i; k++){
                    push_tmp(input[k], tmp_string, tmp_index);
                    tmp_index++;
               } 
            }
            previous_bracket_index = i;
        }
    }
    printf("%s", tmp_string);
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

void push_tmp(int data, char *stack, int index)
{
    stack[index] = data;
}

// Редьюсер нашего стека алгебраических операций
double Counting(char *input) {}
