// Написать префиксный калькулятор (- 10 (/ 8 (* 2 (+ 2 2))), (+ 2 2 (* 3 1) 4 5 (- 6 3)), (+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2))
// На вход дается строка, состоящая из +, -, *, /, числа и корректных скобок. На выходе - результат операции.
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Метод обхода дерева снизу
int reduceTree(char *input, int i, int k, int bracket)
{   
    int inputLength = strlen(input);
    int firstBracket = 0;

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
    char *input = "(+ (- 4 2) (* 2 2 (+ 1 1)) 3 (/ 8 2))";
    int length = strlen(input);
    int pairIndex = findPairBracket(input+3, length);
    printf("RESULT IS: %s", &input[9]);
    
}