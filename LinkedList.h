#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* Structures for Creating a Doubly Linked List */
typedef struct listNode
{
	void* value;
	struct listNode* next;
	struct listNode* prev;
} listNode;

typedef struct
{
	listNode* head;
	listNode* tail;
	int count;
} linkedList;

typedef char* (*toStringFunc)(void*);
typedef void(*freeFunc)(void*);

/* Forward Declaration/First Use Declaration */
linkedList* createLinkedList();
void insertFirst(linkedList*, void*);
void insertLast(linkedList*, void*);

void* removeFirst(linkedList*);
void* removeLast(linkedList*);

void printLinkedList(linkedList*, toStringFunc*);
void freeLinkedList(linkedList*, freeFunc*);

#endif
