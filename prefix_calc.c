// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2)))) = 9, (+ 2 2 (* 3 1) 4 5 (- 6 3)) = 19, (+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2)) = 17
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Expr {
    char op;
    int result;
} Expr;

int calculate(char operator, int num1, int num2){
    if (num2 == NULL){
        return num1;
    }
    else if (num1 == NULL){
        return num2;
    }
    switch(operator)
  	{
  		case '+':
  			return num1 + num2;
  		case '-':
  			return num1 - num2;			
  		case '*':
  			return num1 * num2;
  		case '/':
  			return  num1 / num2;
		default:
			printf("\n You have enetered an Invalid Operator ");		    			
	}
    return 0;
}

int calculateStackSize(char *input, int inputLength){
    // вычисляет размер стека, куда будем класть оператор и результат вычисления каждого уровня дерева
    int i;
    int stackSize = 0;
    for (i=0;i<inputLength;i++){
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            stackSize++;
        }
    }
    return stackSize;
}

// Метод обхода дерева
int reduceTree(char *input, int stackSize, int inputLength)
{   
    int i;
    Expr tree[stackSize];
    int level = -1;
    int result = NULL;
    int value = NULL;

    for (i=0;i<inputLength;i++) {
        if (input[i] == '('){
            level++;
            // чтобы при операторе '-' первое число в токене не стало отрицательным
            tree[level].result = NULL;
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            tree[level].op = input[i];
        }
        if (input[i] == ')'){
            // подсчитываем итоговый результат токена с учетом последнего числа перед закрывающей скобкой
            tree[level].result = calculate(tree[level].op, tree[level].result, value); 
            value = NULL;
            level--;
            if (level == -1){
                return tree[0].result;
            }
            // подсчитываем результат верхнего уровня, с учетом результата нижнего
            tree[level].result = calculate(tree[level].op, tree[level].result, tree[level+1].result);
        }
        if (isdigit(input[i])){
            value = value*10 + (input[i] - '0');
        }
        if (input[i] == ' '){
            tree[level].result = calculate(tree[level].op, tree[level].result, value);
            value = NULL;
        }
    }
    return result;
}

int main()
{
    char *input = "(+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2))";
    char inputLength = strlen(input);
    int result = reduceTree(input, calculateStackSize(input, inputLength), inputLength);
    int a = 0;

}