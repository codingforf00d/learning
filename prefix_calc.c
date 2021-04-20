// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2))), (+ 2 2 (* 3 1) 4 5 (- 6 3)), (+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2))
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Ret {
    int bracket;
    int i;
    int k;
} Ret;


// Метод обхода дерева снизу
Ret reduceTree(char *input, Ret obj)
{   
    int inputLength = strlen(input);
    int firstBracket = 0;
    int i = obj.i;
    int k = obj.k;
    int bracket = obj.bracket;

    for (i=0;i<inputLength;i++) {
        if (input[i] == '(' && i != 0){
            firstBracket = i;
            continue;
        }

    }
    
}

int findDeepestBracket(char *input, int length){
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

int calculate(char operator, int num1, int num2){
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
    char *input = "(+ 2 2)";
    char operator;
    Ret initObj;
    initObj.bracket = 0;
    initObj.i = 0;
    initObj.k = 0;
    int deepest = findDeepestBracket(input, strlen(input));
    printf("DEEPEST IS: %d", &deepest);
    
}