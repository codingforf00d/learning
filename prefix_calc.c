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

int parseToken(char *input, int length){
    int i;
    int value=0;
    int result=0;
    int bracket=0;
    char operator;
    for (i=0;i<length;i++){
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
            value = 0;
        }
    }
    return result;
}



int main()
{
    char *input = "(+ 234 123)";
    int length = strlen(input);
    int result = parseToken(input, length);
    printf("RESULT IS: %d", &result);
    
}