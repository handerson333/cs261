#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.
	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
  	assert(q != NULL);
	struct DLink* sent = malloc(sizeof(struct DLink));
	sent->next = sent;
	sent->prev = sent;
	q->Sentinel = sent;
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.
	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
	struct DLink* temp = malloc(sizeof(struct DLink));
	
	temp->value = val;
	
	return temp;

}

/* Adds a link after another link
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
	assert(q != NULL);
	
	struct DLink* temp = _createLink(v);
	
	temp->next = lnk->next;
	lnk->next->prev = temp;
	temp->prev = lnk;
	lnk->next = temp;
	
	q->size++;
}

/* Adds a link to the back of the deque
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
	/* FIXME: you must write this */
	assert(q != NULL);

	_addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	assert(q != NULL);

	_addLinkAfter(q, q->Sentinel, val);
}

/* Get the value of the front of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
	assert(q != NULL);
	assert(q->size != 0);

	return q->Sentinel->next->value;
}

/* Get the value of the back of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	assert(q != NULL);
	assert(q->size != 0);
	
	return q->Sentinel->prev->value;
}

/* Remove a link from the deque
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	assert(q != NULL);
	assert(q->size != 0);
	
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;
	
	q->size--;
	
	free(lnk);
}

/* Remove the front of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	assert(q != NULL);
	assert(q->size != 0);
	
	_removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
	assert(q != NULL);
	assert(q->size != 0);
	
	_removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque
	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink* iter = q->Sentinel->next;

	while(iter != q->Sentinel){
		_removeLink(q, iter);
		iter = q->Sentinel->next;
	}
}

/* 	Deallocate all the links and the deque itself. 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	freeCirListDeque(q);
	free(q);
}

/* Check whether the deque is empty
	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	assert(q != NULL);
	
	if(q->size == 0)
		return 1;
	else
		return 0;
}

/* Print the links in the deque from front to back
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	struct DLink* iter = q->Sentinel->next;

	while(iter != q->Sentinel){
		printf("%.2f\n", iter->value);
		iter = iter->next;
	}
}

/* Reverse the deque
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	struct DLink* iter = q->Sentinel;
	struct DLink* temp;
	int flag = 1;

	while((iter != q->Sentinel) || (flag == 1)){
		flag = 0;
		temp = iter->next;
		iter->next = iter->prev;
		iter->prev = temp;
		iter = iter->prev;
	}
}