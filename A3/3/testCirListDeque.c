#include "cirListDeque.h"
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
        
	printf("Creating new cirLinkedList\n");
	struct cirListDeque* cll = createCirListDeque();
	assertTrue(isEmptyCirListDeque(cll), "Circular linked list made");
	
	printf("\nAdding values - the circular linked list contains {1,2,3,4,5}\n");
	addFrontCirListDeque(cll, 3);
	addFrontCirListDeque(cll, 2);
	addFrontCirListDeque(cll, 1);
	addBackCirListDeque(cll, 4);
	addBackCirListDeque(cll, 5);

	printf("\nCircular Linked List:\n");
	printCirListDeque(cll);
	
	printf("\nNow using functions to test order\n");
	assertTrue(frontCirListDeque(cll) == 1, "Testing list contains 1 ");
	removeFrontCirListDeque(cll);
	assertTrue(frontCirListDeque(cll) == 2, "Testing list contains 2 ");
	removeFrontCirListDeque(cll);
	assertTrue(frontCirListDeque(cll) == 3, "Testing list contains 3 ");
	removeFrontCirListDeque(cll);
	assertTrue(backCirListDeque(cll) == 5, "Testing list contains 5 ");
	removeBackCirListDeque(cll);
	assertTrue(backCirListDeque(cll) == 4, "Testing list contains 4 ");
	freeCirListDeque(cll);
	
	printf("\nReversing the CLL\n");
	addFrontCirListDeque(cll, 3);
	addFrontCirListDeque(cll, 2);
	addFrontCirListDeque(cll, 1);
	addBackCirListDeque(cll, 4);
	addBackCirListDeque(cll, 5);
	reverseCirListDeque(cll);
	
	printf("\nCircular Linked List Reverse:\n");
	printCirListDeque(cll);

	printf("\nNow using functions to test order of newly reversed CLL\n");
	assertTrue(frontCirListDeque(cll) == 5, "Testing list contains 5 ");
	removeFrontCirListDeque(cll);
	assertTrue(frontCirListDeque(cll) == 4, "Testing list contains 4 ");
	removeFrontCirListDeque(cll);
	assertTrue(frontCirListDeque(cll) == 3, "Testing list contains 3 ");
	removeFrontCirListDeque(cll);
	assertTrue(backCirListDeque(cll) == 1, "Testing list contains 1 ");
	removeBackCirListDeque(cll);
	assertTrue(backCirListDeque(cll) == 2, "Testing list contains 2 ");	
	
	printf("\nDeleting/freeing the Circular Linked List\n");
	deleteCirListDeque(cll);

	return 0;
}