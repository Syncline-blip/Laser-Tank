/**************************************************************************** 
*   Author: John Lumagbas
*	Purpose: Create an ADT Generic Linked List to store player movements
*   Comments: Adapted from Lecture 6 implementation
****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

/* createLinkedList(): Creates linked list pointers, allocates memory, sets head and tail to null as initials */
linkedList* createLinkedList()
{
	/* create new list*/
	linkedList* list = (linkedList*)malloc(sizeof(linkedList));
	
	list->head = NULL;
	list->tail = NULL;
	list->count = 0;

	return list;
}

/* insertFirst() :Inserts new node at start of the list with given value */
void insertFirst(linkedList *list, void*inValue)
{

	listNode* inNode = (listNode*)malloc(sizeof(listNode));

	/* previous head of list, set to nNode */
	listNode* prevHead;

	inNode->value = inValue;
	inNode->next = NULL;
	inNode->prev = NULL;

	/*isEmpty(): Similar to DSA's */
	if(list->head == NULL)
	{
		list->head = inNode;
		list->tail = inNode;
	}
	/* If the list has atleast one node in it */
	else
	{
		inNode->next = list->head;
		prevHead = inNode->next;
		prevHead->prev = inNode;

		list->head = inNode;
	}
	list->count += 1;
}



/* Function: removeFirst(): removes value from front */
void* removeFirst(linkedList *inList)
{
	void* nodeValue;

	listNode* prevHead;

	/*isEmpty(): SImilar to DSA's */
	if(inList->count == 0)
	{
		nodeValue = NULL;
	}

	else if(inList -> count == 1)
	{
		nodeValue = (inList->head)->value;
		prevHead = inList->head;

		inList->head = NULL;
		inList->tail = NULL;
		free(prevHead);
	}
	else
	{
		/* If list has one element left*/
		nodeValue = (inList->head)->value;
		prevHead = inList->head;

		inList->head = (inList->head)->next;
		inList->head->prev = NULL;
		free(prevHead); /*removal*/
	}
	inList->count -= 1;
	return nodeValue;
}

/* insertLast() : insert value at front */
void insertLast(linkedList* list,void* inValue)
{
	listNode* inNode = (listNode*)malloc(sizeof(listNode));
	listNode* prevTail;

	/* Variable Fields*/
	inNode->value = inValue;
	inNode->next = NULL;
	inNode->next = NULL;
	
	/*if list is empty, node will be head and tail*/
	if(list->head == NULL)
	{
		list->head = inNode;
		list->tail = inNode;
	}
	/* If the list has atleast one node in it */
	else
	{
		inNode->prev = list->tail;
		prevTail = inNode->prev;
		prevTail->next = inNode;

		list->tail = inNode;
	}
	list->count += 1;
}		

/*  removelast(): Remove node from rear */
void* removeLast(linkedList* list)
{
	void* nodeValue;

	listNode* prevTail;

	if(list->count == 0)
	{
		nodeValue = NULL;
	}
	else if(list->count == 1)
	{
		nodeValue = (list->tail)->value;
		prevTail = list->tail;

		list->head = NULL;
		list ->tail = NULL;

		free(prevTail);
	}
	else
	{
		nodeValue = (list->tail)->value;
		prevTail = list->tail;

		list->tail = (list->tail)->prev;
		list->tail->next = NULL;
		free(prevTail);
	}
	list->count -= 1;
	return nodeValue;
}

/* freeLList() : free function */
void freeLL(linkedList* list, freeFunc* freeVal)
{
	/*free */
	listNode* currNode;		
	listNode* nxtNode;


	if(list->count > 0)
	{
		currNode = list->head;
		while(currNode != NULL)
		{
			nxtNode = currNode->next;
			(*freeVal)(currNode->value);
			free(currNode);
			currNode = nxtNode;
		}
	}
	free(list);
}

/* printLinkedList(): shows the list of nodes */
void printLinkedList(linkedList* list, toStringFunc* toString )
{
    listNode* currNode;
    if( list->count == 0 )
    {
        printf( "[]\n" );
    }
    else
    {
        currNode = list->head;
        printf( "[" );
        while( currNode != NULL )
        {
            if( currNode->next == NULL )
            {
                /*if currnode is last node */
                printf( " %s ]\n", (*toString)( currNode->value ) );
            }
            else
            {
                /*if more nodes exist */
                printf( " %s,", (*toString)( currNode->value ) );
            }

            currNode = currNode->next;
        }
    }
}


