// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2)))) = 9, (+ 2 2 (* 3 1) 4 5 (- 6 3)) = 19, (+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2)) = 17
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Expr {
    char operator;
    int result;
} Expr;

int calculate(char operator, int num1, int num2){
    /*
    * Чтобы не получалось деления на ноль, и т.п.
    */
    if (num2 == NULL){
        return num1;
    }
    /*
    * Чтобы положительные числа не становились отрицательными
    */
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

int calculateTreeDepth(char *input, int inputLength){
    /*
    * вычисляет глубину дерева, куда будем класть оператор 
    * и результат вычисления каждого уровня
    */
    int i;
    int treeDepth = 0;
    for (i=0;i<inputLength;i++){
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            treeDepth++;
        }
    }
    return treeDepth;
}

// Метод обхода дереваa
int reduceTree(char *input, int treeDepth, int inputLength)
{   
    int i;
    Expr tree[treeDepth];
    int level = -1;
    int result = NULL;
    int value = NULL;

    for (i=0;i<inputLength;i++) {
        if (input[i] == '('){
            level++;
            /*
            * чтобы при операторе '-' первое число в токене не стало отрицательным
            */
            tree[level].result = NULL;
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            tree[level].operator = input[i];
        }
        if (input[i] == ')'){
            /*
             * подсчитываем итоговый результат токена 
             * с учетом последнего числа перед закрывающей скобкой
             */
            tree[level].result = calculate(tree[level].operator, tree[level].result, value);
            /*
             * Всегда выставляем NULL для value, чтобы метод calculate()
             * смог корректно подсчитать результат, при попадании на пробел
             */ 
            value = NULL;
            level--;
            if (level == -1){
                return tree[0].result;
            }
            /*
            * подсчитываем результат верхнего уровня, с учетом результата нижнего
            */
            tree[level].result = calculate(tree[level].operator, tree[level].result, tree[level+1].result);
        }
        if (isdigit(input[i])){
            value = value*10 + (input[i] - '0');
        }
        if (input[i] == ' '){
            tree[level].result = calculate(tree[level].operator, tree[level].result, value);
            value = NULL;
        }
    }
    return result;
}

int main()
{
    char *input = "(- 10 (/ 8 (* 2 (+ 2 2))))";
    char inputLength = strlen(input);
    int result = reduceTree(input, calculateTreeDepth(input, inputLength), inputLength);
    int a = 0;

}