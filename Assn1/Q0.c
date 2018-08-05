/* CS261- Assignment 1 - Q. 0*/
/* Name:  R. Hayden Anderson
 * Date:  1/9/2016
 * Solution description: printing through functions and pointers
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value of iptr = %i\n", *iptr);
	 
     /*Print the address pointed to by iptr*/
     printf("The address of iptr's value is %p\n", iptr);

     /*Print the address of iptr itself*/
	 printf("The address of iptr is %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x;
    /*print the address of x*/
	printf("The address of x is %p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
   	 printf("The value of x is %d\n", x);


    return 0;
}
