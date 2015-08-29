#include <assert.h>
#include <stdio.h>

#include "linked_list.h"


extern int errno;

void test_init() {
	LinkedList *list = list_init();
	assert(0 != list);
	assert(0 == list->size);
	assert(0 == list->head);
	assert(0 == list->tail);
}

void test_list_prepend_one() {
	LinkedList *list = list_init();
	list_prepend(list, 5);
	assert(1 == list->size);
	assert(0 != list->head);
	assert(5 == list->head->element);
	assert(list->tail == list->head);
}

void test_list_prepend_two() {
	LinkedList *list = list_init();
	list_prepend(list, 3);
	list_prepend(list, 8);
	assert(2 == list->size);
	assert(list->tail != list->head);
	assert(8 == list->head->element);
	assert(list->tail == list->head->next);
	assert(list->head == list->tail->prev);
	assert(3 == list->tail->element);
}

void test_list_prepend_three() {
	LinkedList *list = list_init();
	list_prepend(list, 3);
	list_prepend(list, 8);
	list_prepend(list, 1);
	assert(8 == list->tail->prev->element);
	assert(1 == list->tail->prev->prev->element);
}

void test_list_append_one() {
	LinkedList *list = list_init();
	list_append(list, 7);
	assert(7 == list->head->element);
	assert(list->head == list->tail);
	assert(1 == list->size);
}

void test_list_append_two() {
	LinkedList *list = list_init();
	list_append(list, 1);
	list_append(list, 72);
	assert(2 == list->size);
	assert(1 == list->head->element);
	assert(72 == list->head->next->element);
	assert(list->tail->prev == list->head);
}

void test_list_append_three() {
	LinkedList *list = list_init();
	list_append(list, 5);
	list_append(list, 12);
	list_append(list, 32);
	assert(12 == list->head->next->element);
	assert(32 == list->head->next->next->element);
}

void test_list_get_element() {
	LinkedList *list = list_init();
	list_append(list, 2);
	assert(2 == list_get(list, 0));
	list_append(list, 3);
	assert(3 == list_get(list, 1));
	list_prepend(list, 12);
	assert(12 == list_get(list, 0));
}

void test_remove() {
	LinkedList *list = list_init();
	list_append(list, 2);
	list_append(list, 5);
	list_remove(list, 0);
	assert(5 == list_get(list, 0));
	assert(0 == list->tail->prev);
	assert(1 == list->size);
}

int main() {
	test_init();
	test_list_prepend_one();
	test_list_prepend_two();
	test_list_prepend_three();
	test_list_append_one();
	test_list_append_two();
	test_list_append_three();
	test_list_get_element();
	test_remove();
	exit(EXIT_SUCCESS);
}
