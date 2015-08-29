#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdlib.h>


typedef struct myNode {
	int element;
	struct myNode *next;
	struct myNode *prev;
} Node;

typedef struct {
	int size;
	Node *head;
	Node *tail;
} LinkedList;

LinkedList *init_list() {
	LinkedList *list = malloc(sizeof(*list));
	return list;
}

void prepend(LinkedList *list, int element) {
	Node *temp = malloc(sizeof(*temp));
	temp->element = element;
	temp->next = list->head;
	if (0 == list->size) {
		list->tail = temp;
	} else {
		temp->next->prev = temp;
	}
	list->head = temp;
	list->size++;
}

void append(LinkedList *list, int element) {
	Node *temp = malloc(sizeof(*temp));
	temp->element = element;
	temp->prev = list->tail;
	if (0 == list->size) {
		list->head = temp;
	} else {
		list->tail->next = temp;
	}
	list->tail = temp;
	list->size++;
}

#endif
