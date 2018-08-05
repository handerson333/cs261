/* CS261- Assignment 1 - Q.2*/
/* Name: Hayden Anderson
 * Date: 1/9/16
 * Solution description:  passing by pointers and passing by value
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2 * (*a);
    
    /*Set b to half its original value*/
    *b = (*b) / 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    int result;   //will hold the value returned by the function
    
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    result = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("value returned by foo = %d\n", result);
    
    /*Print the values of x, y and z again*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    /*yes, because when you pass by value youre really just passing
	  a copy of that value, and then when you return it, the value of z never changes. 
	 */
    return 0;
}
    
    
