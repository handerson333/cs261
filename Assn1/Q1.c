/* CS261- Assignment 1 - Q.1*/
/* Name: Hayden Anderson
 * Date: 1/9/16
 * Solution description:  Allocating memory for a struct and then freeing it
 */
 
#include <stdio.h>
#include <stdlib.h>   
#include <math.h>
#include <time.h>    

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    int num = 10;
    struct student *ptr = malloc(num * sizeof(struct student));
     
     /*return the pointer*/
    return ptr;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int i, j;           // loop counters
    int unique_id = 0;  // flag to indicate whether id given is unique with 0 or 1

    //random number
    srand(time(NULL));

    // set an ID and a score for first student
    students[0].id = rand() % 10 + 1;
    students[0].score = rand() % 100 + 1;
    
    // loop through each successive student and assign an id and score
    for (i = 1; i < 10; i++) 
    {
        // check if id is unique
        while (unique_id == 0) 
        {
            students[i].id = rand() % 10 + 1;

            //make sure the id isnt already taken
            for (j = 0; j < i; j++) 
            {
                if (students[i].id == students[j].id) 
                {
                    unique_id = 0;
                    break;
                }
                else
                {
                    unique_id = 1;
                }
            }
        }

        unique_id = 0;
        students[i].score = rand() % 100 + 1;
    }
}


void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    int i;   // counter

    // Find the ID and score of each student
    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
}


void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;                 // counter
    int min, max, sum;     
    double avg;

    min = 100;
    max = 0;
    sum = 0;

    // Loop through all of the scores finding the min and max
    for (i = 0; i < 10; i++) 
    {
        if (students[i].score > max)  
        {
            max = students[i].score;
        }

        if (students[i].score < min)  
        {
            min = students[i].score;
        }

        sum += students[i].score;
    }

    // average
    avg = sum / 10.0; 
    
    printf("Minimum score is: %d\n", min);
    printf("Maximum score is: %d\n", max);
    printf("Average score is: %.2f\n", avg);
}


void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != 0) 
    {
        free(stud); 
    }
    return;
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
