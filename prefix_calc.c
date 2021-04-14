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


// Метод, преобразующий входную строку с выражением в стек с операторами и значениями
Expr *GetOperations(char *input)
{   
    static Expr operations[100];
    int top_of_stack = 0;
    int inputLength = strlen(input);
    int i;
    for (i=0; i<inputLength; i++){

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            Expr operation;
            sscanf(input+i, "%s %d", &operation.operator, &operation.value);
            push_operations(operation, operations, top_of_stack);
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


int Reduce(Expr *operations, int last_number){
    
}


// добавить элемент в стек
void push_operations(Expr data, Expr *stack, int index)
{
    stack[index] = data;
}


int Calculate(char operator, int num1, int num2){
    int result = 0;
      	switch(operator)
  	{
  		case '+':
  			result = num1 + num2;
  			break;
  		case '-':
  			result = num1 - num2;
  			break;  			
  		case '*':
  			result = num1 * num2;
  			break;
  		case '/':
  			result = num1 / num2;
  			break;
		default:
			printf("\n You have enetered an Invalid Operator ");				    			
	}
    return result;
}

int main()
{
    char *input = "(- 10 (/ 8 (* 2 (+ 2 2)))";
    Reduce(GetOperations(input), GetLastNumber(input));
}