#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
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

LinkedList *list_init() {
	LinkedList *list = malloc(sizeof(*list));
	return list;
}

void list_prepend(LinkedList *list, int element) {
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

void list_append(LinkedList *list, int element) {
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

int list_get(LinkedList *list, int index) {
	Node *temp = list->head;
	for (int ii = 0; ii < index; ++ii) {
		temp = temp->next;
	}
	return temp->element;
}

void list_remove(LinkedList *list, int index) {
	Node *temp = list->head;
	for (int ii = 0; ii < index; ++ii) {
		temp = temp->next;
	}
	if (0 == temp->prev) {
		list->head = temp->next;
		free(list->head->prev);
		list->head->prev = 0;
	}
	list->size--;
}

#endif
