#include <assert.h>
#include <stdio.h>

#include "linked_list.h"

void test_init() {
	LinkedList *list = initList();
	assert(0 != list);
	assert(0 == list->size);
	assert(0 == list->head);
	assert(0 == list->tail);
}

void test_prepend_one() {
	LinkedList *list = initList();
	prepend(list, 5);
	assert(1 == list->size);
	assert(0 != list->head);
	assert(5 == list->head->element);
	assert(list->tail == list->head);
}

void test_prepend_two() {
	LinkedList *list = initList();
	prepend(list, 3);
	prepend(list, 8);
	assert(2 == list->size);
	assert(list->tail != list->head);
	assert(8 == list->head->element);
	assert(list->tail == list->head->next);
	assert(list->head == list->tail->prev);
	assert(3 == list->tail->element);
}

void test_prepend_three() {
	LinkedList *list = initList();
	prepend(list, 3);
	prepend(list, 8);
	prepend(list, 1);
	assert(8 == list->tail->prev->element);
	assert(1 == list->tail->prev->prev->element);
}

void test_append_one() {
	LinkedList *list = initList();
	append(list, 7);
	assert(7 == list->head->element);
	assert(list->head == list->tail);
	assert(1 == list->size);
}

void test_append_two() {
	LinkedList *list = initList();
	append(list, 1);
	append(list, 72);
	assert(2 == list->size);
	assert(1 == list->head->element);
	assert(72 == list->head->next->element);
	assert(list->tail->prev == list->head);
}

void test_append_three() {
	LinkedList *list = initList();
	append(list, 5);
	append(list, 12);
	append(list, 32);
	assert(12 == list->head->next->element);
	assert(32 == list->head->next->next->element);
}

int main() {
	test_init();
	test_prepend_one();
	test_prepend_two();
	test_prepend_three();
	test_append_one();
	test_append_two();
	test_append_three();
	return 0;
}
