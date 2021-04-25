// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2)))) = 9, (+ 2 2 (* 3 1) 4 5 (- 6 3)) = 19, (+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2)) = 17
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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


typedef struct Expr {
    char op;
    int result;
} Expr;

// Метод обхода дерева
int reduceTree(char *input, int opsStackSize)
{   
    int i;
    int inputLength = strlen(input);
    Expr ops[opsStackSize];
    int bracket = -1;
    int result = 0;
    char operator;

    for (i=0;i<inputLength;i++) {
        if (input[i] == '('){
            bracket++;
            ops[bracket].op = input[i+1];
            ops[bracket].result = parseToken(input+i, inputLength);
        }
        if (input[i] == ')'){
            bracket--;
            if (bracket == -1){
                result = ops[0].result;
                return result;
            }
            ops[bracket].result = calculate(ops[bracket].op, ops[bracket].result, ops[bracket+1].result);
        }
    }
    return result;
}


int deepestBracketIndex(char *input, int length){
    int a, b, deepest;
    int openedCount = 0;
    int maxOpened = 0;
    for (a=0;a<length;a++){
        if (input[a] == '('){
            openedCount++;
            if (openedCount > maxOpened){
                maxOpened=openedCount;
                deepest=a;
            }   
        }
        if (input[a] == ')'){
            openedCount--;
        }
    }
    return deepest;
}

int findPairBracket(char *input, int length){
    int a;
    int b=0;
    for (a=0;a<length;a++){
        if (input[a] == '('){
            b++;
        }
        else if (input[a] == ')'){
            b--;
        }
        else if (b == 0){
            return a;
        }  
    }

}


int parseToken(char *input, int length){
    int i;
    int value=NULL;
    int result=NULL;
    int bracket=0;
    char operator;
    for (i=0;i<length;i++){
        if (bracket > 1 && input[i] != ')'){
            if (input[i] == '('){
                bracket++;
            }
            continue;
        }
        if (input[i] == '('){
            bracket++;
        }
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            operator = input[i];
        }
        if (input[i] == ')'){
            bracket--;
            if (bracket == 0){
                result = calculate(operator, result, value);
                return result;
            }
        }
        if (isdigit(input[i])){
            value = value*10 + (input[i] - '0');
        }
        if (input[i] == ' '){
            result = calculate(operator, result, value);
            value = NULL;
        }
    }
    return result;
}

int stackSize(char *input){
    int i;
    int stackSize = 0;
    int length = strlen(input);
    for (i=0;i<length;i++){
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            stackSize++;
        }
    }
    return stackSize;
}

int main()
{
    char *input = "(- 10 (/ 8 (* 2 (+ 2 2))))";
    int result = reduceTree(input, stackSize(input));
    int a = 0;

    
}