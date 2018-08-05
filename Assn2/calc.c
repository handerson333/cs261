#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
   if(sizeDynArr(stack) < 2){
         printf("Incorrect arguments. \n");
         return;
     }
    double x;
    double y;
    x = topDynArr(stack);
    popDynArr(stack);
    y = topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, x+y);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
    if(sizeDynArr(stack) < 2){
         printf("Incorrect arguments \n");
         return;
     }
    double x;
    double y;
    x=topDynArr(stack);
    popDynArr(stack);
    y=topDynArr(stack);
    popDynArr(stack);
    pushDynArr(stack, x-y);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack) < 2){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	double y;
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, x/y);
}


void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack) < 2){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	double y;
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, x*y);
}


void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack) < 2){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	double y;
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(x,y));
}

void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(x,2));
}

void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, pow(x,4));
}

void absoluteValue(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, abs(x));
}

void squareRoot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, sqrt(x));
}


void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, exp(x));
}

void naturalLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log(x));
}

void logTen(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	if (sizeDynArr(stack)<1){
		printf("Incorrect arguments \n");
		return;
	}
	double x;
	x = topDynArr(stack);
	popDynArr(stack);
	pushDynArr(stack, log10(x));
}


double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double isNum;

	//set up the stack
	stack = createDynArr(20);
		// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		printf( "Arguments: %s\n", inputString[i] );
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if (strcmp(s, "/") == 0)
			divide(stack);
		else if (strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if (strcmp(s, "^") == 0)
			power(stack);
		else if (strcmp(s, "^2") == 0)
			square(stack);
		else if (strcmp(s, "^3") == 0)
			cube(stack);
		else if (strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absoluteValue(stack);
		else if (strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if (strcmp(s, "exp") == 0)
			exponential(stack);
		else if (strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if (strcmp(s, "log") == 0)
			logTen(stack);
		else if (strcmp(s, "pi") == 0)
			pushDynArr(stack, 3.14159265);
		else if (strcmp(s, "e") == 0)
			pushDynArr(stack, 2.7182818);
		else if(isNumber(s, &isNum))
			pushDynArr(stack, isNum);			
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if (sizeDynArr(stack) == 1){
		result = topDynArr(stack);
		return result;
	}
	else {
		return 0;
	}
		
		
	
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	double result=calculate(argc,argv);
	printf("Result= %f\n", result);
	return 0;
}