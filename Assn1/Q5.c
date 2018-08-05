/* CS261- Assignment 1 - Q.5*/
/* Name: Hayden Anderson
 * Date: 1/9/16
 * Solution description:  Working with character arrays to convert an input
 * string to studly case.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for toupper and tolower

/*converts character to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts character to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}



void studly(char* word){
     /*Convert to studly caps*/
    int i = 0;                     // counter

    // loop in character array until terminator found
    while (word[i] != '\0') 
    {
        if (i % 2 == 0)   //even count in the array go to upper case
        {
            word[i] = toupper(word[i]);
        }
        else              // odd count in the array go to lower case
        {
            word[i] = tolower(word[i]);
        }
        i++; 
    }
}


int main(){
    /*Read word from the keyboard using scanf*/
    char input[20];
    printf("\nPlease input a word less than 20 characters: ");
    scanf("%s", input);
    
    /*Call studly*/
    studly(input); 

    /*Print the new word*/
    printf("\nStudly case word is: %s\n", input);
    
    return 0;
}
