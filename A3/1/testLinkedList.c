#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char* message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(int argc, char* argv[]) {
        
	printf("Creating new linkedList\n");
	struct linkedList* ll = createLinkedList();
	assertTrue(isEmptyList(ll), "Testing linkedList has been initialized");
	
	printf("\nAdding values - the LL contains {1,2,3,4,5}\n");
	addFrontList(ll, 3);
	addFrontList(ll, 2);
	addList(ll, 1);
	addBackList(ll, 4);
	addBackList(ll, 5);
	
	assertTrue(containsList(ll, 1) == 1, "Testing list contains 1");
	assertTrue(containsList(ll, 2) == 1, "Testing list contains 2");
	assertTrue(containsList(ll, 3) == 1, "Testing list contains 3");
	assertTrue(containsList(ll, 4) == 1, "Testing list contains 4");
	assertTrue(containsList(ll, 5) == 1, "Testing list contains 5");
	
	printf("\nPrinting array, verify order by eye\n");
	printList(ll);
	
	printf("\nNow using functions to test order\n");
	assertTrue(frontList(ll) == 1, "Testing list contains 1 via removal");
	removeFrontList(ll);
	assertTrue(frontList(ll) == 2, "Testing list contains 2 via removal");
	removeList(ll, 2);
	assertTrue(frontList(ll) == 3, "Testing list contains 3 via removal");
	removeFrontList(ll);
	assertTrue(backList(ll) == 5, "Testing list contains 5 via removal");
	removeBackList(ll);
	assertTrue(backList(ll) == 4, "Testing list contains 4 via removal");
	
	printf("\nDeleting the LL\n");
	deleteLinkedList(ll);

	return 0;
}